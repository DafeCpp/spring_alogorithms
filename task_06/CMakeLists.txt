include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_06
  SOURCES
    src/fish_cost.cpp
    src/fish_cost.h
    src/main.cpp
  TEST_SOURCES
    src/fish_cost.cpp
    src/fish_cost.h
    src/test.cpp
)
