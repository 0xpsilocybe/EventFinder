#pragma once

#include <cmath>
#include "event.h"

namespace viagogo {
namespace eventfinder {

template <typename T>
class Location {
public:
	Location()
		: Location(T(0), T(0)) { }

	Location(T x, T y)
		: x_(x), y_(y), event_(nullptr) { }

	Location(T x, T y, Event* event)
		: x_(x), y_(y), event_(event) { }

	~Location() {
		if (event_) {
			delete event_;
		}
	}

	bool add_event(Event *event) {
		if (!holds_event()) {
			this->event_ = event;
			return true;
		}
		return false;
	}

	bool holds_event() const {
		return event_ != nullptr;
	}

	T get_x() const { return x_; }
	T get_y() const { return y_; }

	T distance(const Location& other) {
		return std::abs((this->x_ - other.x_)) + std::abs(this->y_ - other.y_);
	}

private:
	T x_;
	T y_;

	Event* event_;
};

}
}
