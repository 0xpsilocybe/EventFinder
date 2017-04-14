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

	/**** Accessors ****/

	Coordinate<int> get_coordinate() const { return coordinate_; }

	Event* get_event() const; 
	bool set_event(Event* event);
	
private:
	Coordinate<int> coordinate_;
	Event* event_;
};

}
}
