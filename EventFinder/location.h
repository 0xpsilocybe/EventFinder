#pragma once

#include "event.h"
#include "Coordinate.h"

namespace viagogo {
namespace eventfinder {

class Location {
public:

	/**** Construction ****/

	Location();
	explicit Location(Coordinate<int> coordinate);
	Location(Coordinate<int> coordinate, Event* event);
	~Location();

	/**** Properties ****/

	bool add_event(Event* event);
	bool holds_event() const;

private:
	Coordinate<int> coordinate_;
	Event* event_;
};

}
}
