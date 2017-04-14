#include "event.h"

#include <iomanip>

namespace viagogo {
namespace eventfinder {

Event::Event(int id, const std::vector<Ticket>& tickets)
	: id_(id), tickets_(tickets) {
	
}

Event::~Event() { }

std::ostream& operator<<(std::ostream& os, const Event& event) {
	os << "Event " << std::setfill('0') << std::setw(3) << event.id_;
	return os;
}

}
}
