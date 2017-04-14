#pragma once

#include <string>
#include <locale>

namespace viagogo {
namespace eventfinder {

class Ticket {
public:
	Ticket(long double price, std::locale& locale);
	~Ticket();

	void set_price(long double price);
	long double get_price() const;

	void set_locale(std::locale& locale) const;

	friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);

private:
	std::locale& locale_;
	long double price_;
};

}
}
