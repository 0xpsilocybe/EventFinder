#include <iostream>

#include "ticket.h"

std::locale set_up_locale() {
	std::locale system("");
	std::locale::global(system);
	return system;
}

int main() {
	auto app_locale = set_up_locale();
	viagogo::eventfinder::Ticket ticket(1250, app_locale);
	std::cout << ticket << std::endl;
	return 0;
}
