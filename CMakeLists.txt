# CMakeList.txt : CMake project for Graph, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Graph")

set(BOOST_ROOT "C:/Develop/boost_1_81_0")
set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib")

find_package(Boost REQUIRED)


# Add source to this project's executable.
add_executable (Graph "Graph.cpp" "Graph.h")

target_link_libraries(Graph Boost::boost)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Graph PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
