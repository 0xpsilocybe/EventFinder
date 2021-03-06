#pragma once

namespace viagogo {
namespace eventfinder {

/**
 * \brief Simulated world configuration.
 */
struct Configuration {
	unsigned seed; /** Seed for random number generator. Zero value will initialize generator with time-based value. */
	int top_left_x; /** X-coordinate of top left point of world. */
	int top_left_y; /** Y-coordinate of top left point of world. */
	int bottom_right_x; /** X-coordinate of bottom right point of world. */
	int bottom_right_y; /** Y-coordinate of bottom right point of world. */
	float event_density; /** Percentage of locations holding events. */
	int max_tickets; /** Maximum number of tickets per event. */
	long double min_ticket_price; /** Lowest ticket price. */
	long double max_ticket_price; /** Highest ticket price. */
	int max_event_result; /** Maximum number of results for search query. */
};

}
}
