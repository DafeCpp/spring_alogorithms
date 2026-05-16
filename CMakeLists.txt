cmake_minimum_required(VERSION 3.16)

project(homeworks LANGUAGES CXX)

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

add_subdirectory(lib)

include(CTest)

if(BUILD_TESTING)
  find_package(GTest REQUIRED)
  include(GoogleTest)
endif()

if(BUILD_TASK)
  add_subdirectory(${BUILD_TASK})
else()
  foreach(task IN LISTS HOMEWORK_TASKS)
    add_subdirectory(${task})
  endforeach()

  if(BUILD_SANDBOX)
    add_subdirectory(sandbox)
  endif()

  if(BUILD_ADDITIONAL_TASKS)
    add_subdirectory(additional_tasks)
  endif()
endif()
