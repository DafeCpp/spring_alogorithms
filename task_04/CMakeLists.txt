include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_04
  SOURCES
    src/main.cpp
    src/stack.cpp
  TEST_SOURCES
    src/stack.cpp
    src/test.cpp
)
