cmake_minimum_required( VERSION 3.20 )
project(rayengine)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 20)
# include(FetchContent)
# set(FETCHCONTENT_QUIET FALSE)
# set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
# set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
#
#
# FetchContent_Declare(
#     raylib
#     GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
#     GIT_TAG "master"
#     GIT_PROGRESS TRUE
# )
#
# FetchContent_MakeAvailable(raylib)

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SRCS "src/**/*.cpp")

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

