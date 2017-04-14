#include "ticket.h"
#include <iomanip>

namespace viagogo {
namespace eventfinder {

Ticket::Ticket(long double price, std::locale& locale)
	: locale_(locale), price_(price) {}

Ticket::~Ticket() { }

inline void Ticket::set_price(long double price) {
	this->price_ = price;
}

inline long double Ticket::get_price() const {
	return this->price_;
}

void Ticket::set_locale(std::locale& locale) const {
	this->locale_ = locale;
}

std::ostream& operator<<(std::ostream& os, const Ticket& ticket) {
	os.imbue(ticket.locale_);
	os << std::showbase << std::put_money(ticket.price_);
	return os;
}

}
}
