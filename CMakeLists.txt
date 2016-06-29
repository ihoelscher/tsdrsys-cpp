cmake_minimum_required(VERSION 2.8)
project(TSDRS)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set(CMAKE_BUILD_TYPE Release)

add_executable(csegmt main.cpp)
target_link_libraries( csegmt ${OpenCV_LIBS} )