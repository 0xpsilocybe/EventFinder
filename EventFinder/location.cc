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

bool Location::add_event(Event* event) {
	if (!holds_event()) {
		this->event_ = event;
		return true;
	}
	return false;
}

bool Location::holds_event() const {
	return event_ != nullptr;
}

}
}
