include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

add_homework_task(
  NAME task_08
  SOURCES
    src/main.cpp
    src/order_statistic.cpp
    src/order_statistic.h
  TEST_SOURCES
    src/order_statistic.cpp
    src/order_statistic.h
    src/test.cpp
)
