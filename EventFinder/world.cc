#include "world.h"

#include <algorithm>
#include <iostream>
#include <iomanip>

namespace viagogo {
namespace eventfinder {

int World::next_event_id_ = 0;

World::World(const Coordinate<int>& top_left, const Coordinate<int>& bottom_right)
	: top_left_(top_left), bottom_right_(bottom_right) {
	width_ = bottom_right_.get_x() - top_left_.get_x() + 1;
	depth_ = top_left_.get_y() - bottom_right_.get_y() + 1;
	locations_.reserve(width_ * depth_);
	for (auto x = top_left_.get_x(); x <= bottom_right_.get_x(); x++) {
		for (auto y = bottom_right_.get_y(); y <= top_left_.get_y(); y++) {
			locations_.push_back(Location(Coordinate<int>(x, y)));
		}
	}
}

World::~World() { }

void World::add_event(std::vector<Ticket>& tickets, int x, int y) {
	auto location = get_location(x, y);
	auto event = new Event(next_event_id_++, tickets);
	location->set_event(event);
}

std::vector<Location*> World::find_events(Coordinate<int> location, int limit) {
	std::vector<Location*> closest_locations;
	closest_locations.reserve(limit);
	// Check boundaries and limit. If out of bounds return empty list
	if (limit <= 0 || location.get_x() < top_left_.get_x() || location.get_y() > top_left_.get_y() ||
		location.get_x() > bottom_right_.get_x() || location.get_y() < bottom_right_.get_y()) {
		return closest_locations;
	}
	// Check if there is something going on in users location
	auto scan_location = get_location(location.get_x(), location.get_y());
	if (scan_location->get_event() != nullptr) {
		closest_locations.push_back(scan_location);
		--limit;
	}
	//Scan boundaries
	auto left_x = location.get_x(), right_x = location.get_x(),
			bottom_y = location.get_y(), top_y = location.get_y();
	auto left_x_changed = true, right_x_changed = true, top_y_changed = true, bottom_y_changed = true;
	auto previous_distance = 1;
	while (limit != 0 && (left_x_changed || right_x_changed || top_y_changed || bottom_y_changed)) {
		if (left_x_changed) {
			--left_x;
			if (left_x < top_left_.get_x()) {
				left_x_changed = false;
				left_x = top_left_.get_x();
			}
		}
		if (right_x_changed) {
			++right_x;
			if (right_x > bottom_right_.get_x()) {
				right_x_changed = false;
				right_x = bottom_right_.get_x();
			}
		}
		if (top_y_changed) {
			++top_y;
			if (top_y > top_left_.get_y()) {
				top_y_changed = false;
				top_y = top_left_.get_y();
			}
		}
		if (bottom_y_changed) {
			--bottom_y;
			if (bottom_y < bottom_right_.get_y()) {
				bottom_y_changed = false;
				bottom_y = bottom_right_.get_y();
			}
		}
		Coordinate<int> top_left(left_x, top_y), bottom_right(right_x, bottom_y);
		auto max_distance = std::max(location.distance_to(top_left), location.distance_to(bottom_right));
		for (auto d = previous_distance; d < max_distance; d++) {
			for (auto i = 0; i < d + 1; i++) {
				auto x1 = location.get_x() - d + i;
				auto y1 = location.get_y() - i;
				scan_location = get_location(x1, y1);
				if (scan_location != nullptr) {
					if (scan_location->get_event() != nullptr && limit != 0) {
						closest_locations.push_back(scan_location);
						--limit;
					}
				}
				auto x2 = location.get_x() + d - i;
				auto y2 = location.get_y() + i;
				scan_location = get_location(x2, y2);
				if (scan_location != nullptr) {
					if (scan_location->get_event() != nullptr && limit != 0) {
						closest_locations.push_back(scan_location);
						--limit;
					}
				}

			}
			for (auto i = 1; i < d; i++) {
				auto x1 = location.get_x() - i;
				auto y1 = location.get_y() + d - i;
				scan_location = get_location(x1, y1);
				if (scan_location != nullptr) {
					if (scan_location->get_event() != nullptr && limit != 0) {
						closest_locations.push_back(scan_location);
						--limit;
					}
				}
				auto x2 = location.get_x() + d - i;
				auto y2 = location.get_y() - i;
				scan_location = get_location(x2, y2);
				if (scan_location != nullptr) {
					if (scan_location->get_event() != nullptr && limit != 0) {
						closest_locations.push_back(scan_location);
						--limit;
					}
				}
			}
		}
		previous_distance = max_distance;
	}
	return closest_locations;
}

Location* World::get_location(int x, int y) {
	// Map to internal storage representation
	x -= top_left_.get_x();
	y -= bottom_right_.get_y();
	if (x < 0 || y < 0 || x >= width_ || y >= depth_) {
		return nullptr;
	}
	auto index = x * depth_ + y;
	return &locations_[index];
}

std::ostream& operator<<(std::ostream& os, const World& world) {
	std::cout << "World Events Map" << std::endl << "      ";
	for (auto x = world.top_left_.get_x(); x <= world.bottom_right_.get_x(); x++) {
		std::cout << "(" << std::setfill(' ') << std::setw(3) << x << ")";
	}
	std::cout << std::endl;
	auto bottom_y = world.bottom_right_.get_y();
	for (auto x = 0; x < world.width_; x++) {
		std::cout << "(" << std::setfill(' ') << std::setw(3) << bottom_y++ << ") ";
		for (auto y = 0; y < world.depth_; y++) {
			auto event = world.locations_[x * world.width_ + y].get_event();
			if (event == nullptr) {
				os << " -=- ";
			} else {
				os << " " << std::setfill('0') << std::setw(3) << event->get_id() << " ";
			}
		}
		os << std::endl;
	}
	return os;
}

}
}
