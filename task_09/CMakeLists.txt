include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_09
  SOURCES
    src/balanced_bst.cpp
    src/balanced_bst.h
    src/main.cpp
  TEST_SOURCES
    src/balanced_bst.cpp
    src/balanced_bst.h
    src/test.cpp
)
