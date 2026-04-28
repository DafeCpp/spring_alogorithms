cmake_minimum_required(VERSION 3.10)

project(homeworks CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SANDBOX "Build sandbox targets" OFF)
option(BUILD_ADDITIONAL_TASKS "Build additional tasks" OFF)
set(BUILD_TASK "" CACHE STRING "Build only one task, for example task_07")

set(HOMEWORK_TASKS
    task_01
    task_02
    task_03
    task_04
    task_05
    task_06
    task_07
    task_08
    task_09
    task_10
    task_11
    task_12
    task_13
    task_14)

list(FIND HOMEWORK_TASKS "${BUILD_TASK}" build_task_index)

if(BUILD_TASK AND build_task_index EQUAL -1)
  message(FATAL_ERROR "Unknown BUILD_TASK='${BUILD_TASK}'. Expected one of: ${HOMEWORK_TASKS}")
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

if(BUILD_TASK)
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${BUILD_TASK})
else()
  foreach(task IN LISTS HOMEWORK_TASKS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${task})
  endforeach()

  if(BUILD_SANDBOX)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sandbox)
  endif()

  if(BUILD_ADDITIONAL_TASKS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/additional_tasks)
  endif()
endif()
