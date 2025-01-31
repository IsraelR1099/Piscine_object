#pragma once

# define ASSERT(condition, message) \
	do { \
		if (!(condition)) { \
			std::cerr << "Test failed: " << message << " (Line " << __LINE__ << ")" << std::endl; \
		} else { \
			std::cout << "Test passed: " << message << std::endl; \
		} \
	} while(0)
