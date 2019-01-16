cmake_minimum_required(VERSION 3.12)
project(server_client_project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(server_client_project
        main.cpp server_side.h MySerialServer.cpp MySerialServer.h ClientHandler.h MatrixClientHandler.cpp MatrixClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h CoreState.h Searchable.h Searcher.h Node.cpp Node.h Matrix.cpp Matrix.h BestFS_Astar.h MinHeap.h PriorityQueue.h Queue.h Stack.h SearcherWrapper.h BFS_DFS.h AstarApproxHeuristic.h Interpreter.cpp Interpreter.h HeuristicState.h State.h SearchableSolver.cpp SearchableSolver.h MatrixCacheManager.cpp MatrixCacheManager.h ParallelServer.cpp ParallelServer.h)
