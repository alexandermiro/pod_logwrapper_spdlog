cmake_minimum_required(VERSION 3.22)
project(log_pod)

set(CMAKE_CXX_STANDARD 17)

find_package(fmt)

add_executable(log_pod main.cpp AudioMixer.cpp AudioMixer.h LogManager.cpp LogManager.h LogConfig.h Voice.h log.h LogImpl.h LogImpl.cpp LogDriverImpl.cpp LogDriverImpl.h)
target_include_directories(log_pod PUBLIC ${CMAKE_SOURCE_DIR}/)
target_link_libraries(log_pod fmt::fmt)
