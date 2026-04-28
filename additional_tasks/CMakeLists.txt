cmake_minimum_required(VERSION 3.10)

project(additional_tasks)

file(GLOB additional_entries RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")

foreach(entry ${additional_entries})
  if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${entry}" AND
     EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${entry}/CMakeLists.txt")
    add_subdirectory(${entry})
  endif()
endforeach()
