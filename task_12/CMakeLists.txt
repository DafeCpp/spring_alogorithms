include(${CMAKE_SOURCE_DIR}/cmake/AddHomeworkTask.cmake)

# If you add extra implementation files in src/, list them in SOURCES and
# TEST_SOURCES explicitly. CMake will not pick new .cpp files automatically.
add_homework_task(
  NAME task_12
  SOURCES
    src/main.cpp
  TEST_SOURCES
    src/test.cpp
)
