#include "StringReverser.h"
#include <algorithm>

std::string StringReverser::solve(std::string problem) {
    std::reverse(problem.begin(), problem.end());
    return problem;
}