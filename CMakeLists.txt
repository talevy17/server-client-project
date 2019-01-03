cmake_minimum_required(VERSION 3.12)
project(server_client_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(server_client_project
        main.cpp server_side.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyParallelServer.cpp MyParallelServer.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h)
