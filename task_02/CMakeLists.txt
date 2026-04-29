include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_02
  SOURCES
    src/main.cpp
  TEST_SOURCES
    src/test.cpp
)
