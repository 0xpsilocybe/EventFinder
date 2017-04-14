#include "ticket.h"

#include <iomanip>

namespace viagogo {
namespace eventfinder {

/**** Construction ****/

Ticket::Ticket(long double price, std::locale& locale)
	: locale_(locale), price_(price) {}

Ticket::Ticket(const Ticket& other)
	: locale_(other.locale_),
	  price_(other.price_) {}

Ticket::Ticket(Ticket&& other) noexcept
	: locale_(other.locale_),
	  price_(other.price_) {}

Ticket& Ticket::operator=(const Ticket& other) {
	if (this == &other) {
		return *this;
	}
	locale_ = other.locale_;
	price_ = other.price_;
	return *this;
}

Ticket& Ticket::operator=(Ticket&& other) noexcept {
	if (this == &other) {
		return *this;
	}
	locale_ = other.locale_;
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

void Ticket::set_locale(std::locale& locale) const {
	this->locale_ = locale;
}

/**** Sorting ****/

bool Ticket::SortPriceLowestFirst(const Ticket& lhs, const Ticket& rhs) {
	return lhs.price_ < rhs.price_;
}

/**** Streams ****/

std::ostream& operator<<(std::ostream& os, const Ticket& ticket) {
	os.imbue(ticket.locale_);
	os << std::showbase << std::setfill(' ') << std::setw(7) << std::put_money(ticket.price_);
	return os;
}

}
}
