cmake_minimum_required(VERSION 3.21)
project(cplusplus_better_c)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG        8.1.1
)
FetchContent_MakeAvailable(fmt)

add_executable(cplusplus_better_c main.cpp)

target_link_libraries(cplusplus_better_c fmt::fmt)
