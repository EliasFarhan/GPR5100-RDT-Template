
## Specify mininum version of CMAKE
cmake_minimum_required(VERSION 2.8)

## Project's Name
project(HW_RDT)


## Check for Windows ##
if (WIN32) # true if windows (32 and 64 bit)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()


set(SOURCE_FILES main.cpp )

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)

