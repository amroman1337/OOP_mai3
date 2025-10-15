cmake_minimum_required(VERSION 3.14)
project(Figures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(FiguresApp main.cpp Figure.cpp)

add_executable(FiguresTests tests.cpp Figure.cpp)
target_link_libraries(FiguresTests GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME FiguresTests COMMAND FiguresTests)