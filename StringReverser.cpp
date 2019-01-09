#include "StringReverser.h"
#include <algorithm>

/**
* reverse the given string.
*/
std::string StringReverser::solve(std::string problem) {
    std::reverse(problem.begin(), problem.end());
    return problem;
}