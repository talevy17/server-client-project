#ifndef SERVER_CLIENT_PROJECT_SOLVER_H
#define SERVER_CLIENT_PROJECT_SOLVER_H

template<class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem problem) = 0;
};

#endif //SERVER_CLIENT_PROJECT_SOLVER_H
