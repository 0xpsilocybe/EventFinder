#pragma once

#include <vector>

#include "event.h"
#include "location.h"

namespace viagogo {
namespace eventfinder {

class World {
public:
	World(int width, int depth);
	~World();

	void add_event(const std::vector<Ticket>& tickets, int x, int y);

private:
	static int next_event_id_;
	int width_;
	int depth_;
	std::vector<Location<int>> locations_;

	Location<int>& get_location(int x, int y);
};

}
}
