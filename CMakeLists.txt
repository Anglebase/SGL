cmake_minimum_required(VERSION 3.15)

project(EGL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
if(NOT MSVC)
    # disable warnings
    add_definitions(-DNOWARN)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -mwindows")
    link_libraries(opengl32 gdi32)
endif()

add_subdirectory(test)