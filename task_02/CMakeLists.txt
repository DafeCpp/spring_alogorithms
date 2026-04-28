include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_02
  SOURCES
    src/find_zero_one_pair.cpp
    src/find_zero_one_pair.h
    src/main.cpp
  TEST_SOURCES
    src/find_zero_one_pair.cpp
    src/find_zero_one_pair.h
    src/test.cpp
)
