cmake_minimum_required(VERSION 3.10)

project(bowling)

enable_testing()

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

add_executable(${PROJECT_NAME} main.cpp bowling.cpp)
add_executable(${PROJECT_NAME}-ut bowling.cpp test.cpp)

target_link_libraries(${PROJECT_NAME}-ut PRIVATE Catch2::Catch2WithMain)