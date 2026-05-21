cmake_minimum_required(VERSION 3.10)
project(VideoMotionFilter)

find_package(OpenCV REQUIRED)

add_executable(my_filter main.cpp)
target_include_directories(my_filter PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(my_filter ${OpenCV_LIBS})
