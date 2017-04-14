#include "world.h"

namespace viagogo {
namespace eventfinder {

int World::next_event_id_ = 0;

World::World(const Coordinate<int> &top_left, const Coordinate<int> &bottom_right)
	: top_left_(top_left), bottom_right_(bottom_right) {
	width_ = bottom_right_.get_x() - top_left_.get_x();
	depth_ = top_left_.get_y() - bottom_right_.get_y();
	locations_.resize(width_ * depth_);
	for (auto x = top_left.get_x(); x < bottom_right.get_x(); x++) {
		for (auto y = bottom_right.get_y(); y < top_left.get_y(); y++) {
			Coordinate<int> coordinate(x, y);
			locations_[x * width_ + y] = Location(coordinate);
		}
	}
}

World::~World() { }

void World::add_event(const std::vector<Ticket>& tickets, int x, int y) {
	auto location = get_location(x, y);
	auto event = new Event(next_event_id_++, tickets);
	location.add_event(event);
}

Location& World::get_location(int x, int y) {
	// Map to internal storage representation
	x -= top_left_.get_x();
	y -= bottom_right_.get_y();
	return locations_[x * width_ + y];
}

}
}
