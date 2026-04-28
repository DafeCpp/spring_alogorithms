include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_11
  SOURCES
    src/main.cpp
    src/permutation_substring.cpp
    src/permutation_substring.h
  TEST_SOURCES
    src/permutation_substring.cpp
    src/permutation_substring.h
    src/test.cpp
)
