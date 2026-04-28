include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_12
  SOURCES
    src/coin_change.cpp
    src/coin_change.h
    src/main.cpp
  TEST_SOURCES
    src/coin_change.cpp
    src/coin_change.h
    src/test.cpp
)
