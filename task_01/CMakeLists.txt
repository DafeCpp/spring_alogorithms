include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_01
  SOURCES
    src/main.cpp
    src/task_01.h
  TEST_SOURCES
    src/task_01.h
    src/test.cpp
)
