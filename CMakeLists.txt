cmake_minimum_required(VERSION 3.24)
project(emf)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_TOOLCHAIN_FILE})
add_executable(emf main.cpp)
set(CMAKE_PREFIX_PATH $ENV{VCPKG_TOOLCHAIN_SHARE})

# message(STATUS "CMAKE_PREFIX_PATH: " ${CMAKE_PREFIX_PATH})
# message(STATUS "CMAKE_TOOLCHAIN_FILE: " ${CMAKE_TOOLCHAIN_FILE})

# find_package(argparse CONFIG REQUIRED)
# find_package(asio CONFIG REQUIRED)

# target_link_libraries(emf
#         PRIVATE
#             asio asio::asio
#             argparse argparse::argparse)
