#include <iostream>

#include "ticket.h"
#include "coordinate.h"

int main() {
	std::locale system("");
	std::locale::global(system);
	viagogo::eventfinder::Ticket ticket(1250, system);
	std::cout << ticket << std::endl;
	return 0;
}
