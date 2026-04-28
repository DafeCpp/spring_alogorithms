include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_14
  SOURCES
    src/main.cpp
    src/nondecreasing_segment.cpp
    src/nondecreasing_segment.h
  TEST_SOURCES
    src/nondecreasing_segment.cpp
    src/nondecreasing_segment.h
    src/test.cpp
)
