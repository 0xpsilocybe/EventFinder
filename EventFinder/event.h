#pragma once

#include <vector>

#include "ticket.h"

namespace viagogo {
namespace eventfinder {

class Event {
public:
	Event(int id, const std::vector<Ticket>& tickets);
	~Event();

	const Ticket* get_cheapest_ticket() const;

	friend std::ostream& operator<<(std::ostream& os, const Event& event);

private:
	int id_;
	std::vector<Ticket> tickets_;
};

}
}
