#include "event.h"

#include <algorithm>
#include <iomanip>

namespace viagogo {
namespace eventfinder {

Event::Event(int id, std::vector<Ticket> tickets)
	: id_(id), tickets_(tickets) {
	std::sort(std::begin(tickets_), std::end(tickets_), &Ticket::SortPriceLowestFirst);
}

Event::~Event() { }

int Event::get_id() const {
	return id_;
}

const Ticket* Event::get_cheapest_ticket() const {
	if (tickets_.size() > 0) {
		return &tickets_[0];
	}
	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Event& event) {
	os << "Event " << std::setfill('0') << std::setw(3) << event.id_;
	return os;
}

}
}
