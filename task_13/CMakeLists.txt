include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_13
  SOURCES
    src/lesson_schedule.cpp
    src/lesson_schedule.h
    src/main.cpp
  TEST_SOURCES
    src/lesson_schedule.cpp
    src/lesson_schedule.h
    src/test.cpp
)
