include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_03
  SOURCES
    src/main.cpp
    src/phone_combinations.cpp
    src/phone_combinations.h
  TEST_SOURCES
    src/phone_combinations.cpp
    src/phone_combinations.h
    src/test.cpp
)
