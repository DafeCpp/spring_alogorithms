include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_05
  SOURCES
    src/main.cpp
    src/topology_sort.cpp
  TEST_SOURCES
    src/test.cpp
    src/topology_sort.cpp
)
