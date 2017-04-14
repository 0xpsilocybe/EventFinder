#include "worldcreator.h"
#include <random>

namespace viagogo {
namespace eventfinder {

World* WorldCreator::build(Configuration configuration, std::locale &locale) {
	// Initialize random number generator with seed
	if (configuration.seed == 0) {
		srand(time(nullptr));
	} else {
		srand(configuration.seed);
	}
	std::default_random_engine random_engine;
	std::uniform_real_distribution<long double> uniform_tickets(configuration.min_ticket_price, configuration.max_ticket_price);
	std::uniform_real_distribution<long double> uniform_events(0.0, 1.0);
	// Build world
	Coordinate<int> top_left(configuration.top_left_x, configuration.top_left_y);
	Coordinate<int> bottom_right(configuration.bottom_right_x, configuration.bottom_right_y);
	auto world = new World(top_left, bottom_right);
	for (auto x = top_left.get_x(); x < bottom_right.get_x(); x++) {
		for (auto y = bottom_right.get_y(); y < top_left.get_y(); y++) {
			if (uniform_events(random_engine) <= configuration.event_density) {
				std::vector<Ticket> tickets;
				for (auto t = 0; t < configuration.max_tickets; t++) {
					tickets.push_back(Ticket(uniform_tickets(random_engine), locale));
				}
				world->add_event(tickets, x, y);
			}
		}
	}
	return world;
}

}
}
