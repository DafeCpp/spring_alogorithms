include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_10
  SOURCES
    src/hash_table.cpp
    src/hash_table.h
    src/main.cpp
  TEST_SOURCES
    src/hash_table.cpp
    src/hash_table.h
    src/test.cpp
)
