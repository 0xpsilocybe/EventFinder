#include <iostream>

#include "ticket.h"
#include "configuration.h"
#include "worldcreator.h"

viagogo::eventfinder::Configuration get_default_config() {
	viagogo::eventfinder::Configuration configuration;
	//configuration.seed = 1;
	configuration.top_left_x = -10;
	configuration.top_left_y = 10;
	configuration.bottom_right_x = 10;
	configuration.bottom_right_y = -10;
	configuration.event_density = 0.5;
	configuration.min_ticket_price = 100.0; // US Cent
	configuration.max_ticket_price = 50000.0; // US Cent
	configuration.max_tickets = 10;
	configuration.max_event_result = 5;
	return configuration;
}

int main() {
	// Set up application
	auto configuration = get_default_config();
	auto world = viagogo::eventfinder::WorldCreator::build(configuration);
	std::cout << *world << std::endl;
	// Process user query
	viagogo::eventfinder::Coordinate<int> user_location;
	std::cout << "Please input coordinates (separated by whitespace): ";
	std::cin >> user_location;
	auto locations = world->find_events(user_location, configuration.max_event_result);
	for (auto i = 0; i < locations.size(); i++) {
		auto event = locations[i]->get_event();
		auto ticket = event->get_cheapest_ticket();
		auto coordinate = locations[i]->get_coordinate();
		std::cout << *event << " - ";
		if (ticket == nullptr) {
			std::cout << "No tickets";
		} else {
			std::cout << *ticket;
		}
		std::cout << ", Distance " << user_location.distance_to(coordinate) << std::endl;
	}
	// Cleanup and return
	delete world;
	return 0;
}
