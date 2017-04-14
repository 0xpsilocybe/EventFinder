#include "world.h"

namespace viagogo {
namespace eventfinder {

int World::next_event_id_ = 0;

World::World(int width, int depth)
	: width_(width), depth_(depth) {
	locations_.resize(width_ * depth_);
	for(int i = 0; i < width_; i++) {
		for (int j = 0; j < depth_; j++) {
			locations_[i] = Location<int>(i, j);
		}
	}
}

World::~World() { }

void World::add_event(const std::vector<Ticket>& tickets, int x, int y) {
	if (x < width_ && y < depth_) {
		auto location = get_location(x, y);
		auto event = new Event(next_event_id_++, tickets);
		location.add_event(event);
	}
}

Location<int>& World::get_location(int x, int y) {
	return locations_[x * width_ + y];
}

}
}
