project(StateManager)

cmake_minimum_required(VERSION 2.8)

# Add source directories to source list
aux_source_directory(. SRC_LIST)
aux_source_directory(./StateManager SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})

# Add c++11 features
set(CMAKE_CXX_FLAGS "-std=c++11")
