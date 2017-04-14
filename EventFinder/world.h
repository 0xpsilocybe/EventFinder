#pragma once

#include <vector>

#include "event.h"
#include "location.h"

namespace viagogo {
namespace eventfinder {

class World {
public:
	World::World(const Coordinate<int> &top_left, const Coordinate<int> &bottom_left);
	~World();

	void add_event(const std::vector<Ticket>& tickets, int x, int y);

private:
	static int next_event_id_;
	const Coordinate<int> &top_left_;
	const Coordinate<int> &bottom_right_;
	int width_;
	int depth_;
	std::vector<Location> locations_;

	Location& get_location(int x, int y);
};

}
}
