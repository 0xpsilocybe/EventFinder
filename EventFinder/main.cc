#include "ticket.h"
#include "configuration.h"
#include "worldcreator.h"

std::locale set_up_locale() {
	std::locale system("");
	std::locale::global(system);
	return system;
}

viagogo::eventfinder::Configuration get_default_config() {
	viagogo::eventfinder::Configuration configuration;
	configuration.seed = 1;
	configuration.top_left_x = -10;
	configuration.top_left_y = 10;
	configuration.bottom_right_x = 10;
	configuration.bottom_right_y = -10;
	configuration.event_density = 0.5;
	configuration.min_ticket_price = 0.1;
	configuration.max_ticket_price = 500.0;
	configuration.max_tickets = 10;
	return configuration;
}

int main() {
	auto app_locale = set_up_locale();
	auto configuration = get_default_config();
	auto world = viagogo::eventfinder::WorldCreator::build(configuration, app_locale);
	delete world;
	return 0;
}
