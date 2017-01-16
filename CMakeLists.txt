cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
project(TSDRS)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-O3")        ## Optimize
    set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
endif()

add_executable(csegmt main.cpp colorseg/lookup.cpp mser/mser.cpp)
target_link_libraries( csegmt ${OpenCV_LIBS} )