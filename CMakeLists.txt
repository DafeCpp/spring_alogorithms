cmake_minimum_required(VERSION 3.10)

project(homeworks)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sandbox)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/additional_tasks)

file(GLOB_RECURSE tasks_dirs LIST_DIRECTORIES true ".")

foreach(dir ${tasks_dirs})
    IF(IS_DIRECTORY ${dir})
        IF(${dir} MATCHES "task_[0-9][0-9]$" AND NOT ${dir} MATCHES "build")
            add_subdirectory(${dir})
        ENDIF()
    ELSE()
        CONTINUE()
    ENDIF()
endforeach()
