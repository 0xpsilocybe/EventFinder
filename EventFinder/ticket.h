#pragma once

#include <locale>
#include <string>

namespace viagogo {
namespace eventfinder {

class Ticket {
public:
	
	/**** Construction ****/

	Ticket(long double price, std::locale& locale);
	Ticket(const Ticket& other);
	Ticket(Ticket&& other) noexcept;
	Ticket& operator=(const Ticket& other);
	Ticket& operator=(Ticket&& other) noexcept;
	~Ticket();

	/**** Accessors ****/

	void set_price(long double price);
	long double get_price() const;

	void set_locale(std::locale& locale) const;

	/**** Sorting ****/

	static bool SortPriceLowestFirst(const Ticket& lhs, const Ticket& rhs);

	/**** Streams ****/

	friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);

private:
	std::locale& locale_;
	long double price_;
};

}
}
