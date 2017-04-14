#pragma once

#include <cmath>

namespace viagogo {
namespace eventfinder {

template <typename T>
class Coordinate {
public:

	/**** Construction ****/

	Coordinate()
		: Coordinate(T(0), T(0)) { }

	Coordinate(T x, T y)
		: x_(x), y_(y) { }

	Coordinate(const Coordinate& other)
		: x_(other.x_), y_(other.y_) {}

	Coordinate(Coordinate&& other) noexcept
		: x_(std::move(other.x_)), y_(std::move(other.y_)) {}

	Coordinate& operator=(const Coordinate& other) {
		if (this == &other) {
			return *this;
		}
		x_ = other.x_;
		y_ = other.y_;
		return *this;
	}

	Coordinate& operator=(Coordinate&& other) noexcept {
		if (this == &other) {
			return *this;
		}
		x_ = std::move(other.x_);
		y_ = std::move(other.y_);
		return *this;
	}

	~Coordinate() {}

	/**** Accessors ****/

	T get_x() const { return x_; }
	void set_x(T x) { x_ = x; }

	T get_y() const { return y_; }
	void set_y(T y) { y_ = y; }

	/**** Properties ****/

	T distance(const Coordinate& other) {
		return std::abs((this->x_ - other.x_)) + std::abs(this->y_ - other.y_);
	}

	/**** Streams ****/

	friend std::ostream& operator<<(std::ostream& os, const Coordinate<T>& coordinate) {
		os << "(" << coordinate.x_ << ", " << coordinate.y_ << ")";
		return os;
	}

	friend std::istream& operator >>(std::istream& is, Coordinate<T>& coordinate) { 
		is >> coordinate.x_ >> coordinate.y_;
		return is;
	}

private:
	T x_;
	T y_;
};

}
}
