#pragma once

#include "configuration.h"
#include "world.h"

namespace viagogo {
namespace eventfinder {

class WorldCreator {
public:
	static World* build(Configuration configuration);
};

}
}
