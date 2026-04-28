include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_07
  SOURCES
        header/mergeSort.h
    src/main.cpp
    src/mergeSort.cpp
  TEST_SOURCES
        header/mergeSort.h
    src/mergeSort.cpp
    src/test.cpp
  INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/header
)
