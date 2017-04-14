#include "location.h"

namespace viagogo {
namespace eventfinder {

Location::Location(): event_(nullptr) { }

Location::Location(Coordinate<int> coordinate)
	: Location(coordinate, nullptr) { }

Location::Location(Coordinate<int> coordinate, Event* event)
	: coordinate_(coordinate), event_(event) { }

Location::~Location() {
	if (event_) {
		delete event_;
	}
}

bool Location::set_event(Event* event) {
	if (event_ == nullptr) {
		this->event_ = event;
		return true;
	}
	return false;
}

Event* Location::get_event() const {
	return event_;
}

}
}
