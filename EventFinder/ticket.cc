#include "ticket.h"

#include <iomanip>

namespace viagogo {
namespace eventfinder {

/**** Construction ****/

Ticket::Ticket(long double price)
	: price_(price) {}

Ticket::Ticket(const Ticket& other)
	: price_(other.price_) {}

Ticket::Ticket(Ticket&& other) noexcept
	: price_(other.price_) {}

Ticket& Ticket::operator=(const Ticket& other) {
	if (this == &other) {
		return *this;
	}
	price_ = other.price_;
	return *this;
}

Ticket& Ticket::operator=(Ticket&& other) noexcept {
	if (this == &other) {
		return *this;
	}
	price_ = other.price_;
	return *this;
}

Ticket::~Ticket() { }

/**** Accessors ****/

inline void Ticket::set_price(long double price) {
	this->price_ = price;
}

inline long double Ticket::get_price() const {
	return this->price_;
}

/**** Sorting ****/

bool Ticket::SortPriceLowestFirst(const Ticket& lhs, const Ticket& rhs) {
	return lhs.price_ < rhs.price_;
}

/**** Streams ****/

std::ostream& operator<<(std::ostream& os, const Ticket& ticket) {
	os << std::showbase << std::setfill(' ') << std::setw(6) << std::setprecision(2) << std::fixed << ticket.price_ / 100 << " USD";
	return os;
}

}
}
