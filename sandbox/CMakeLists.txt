cmake_minimum_required(VERSION 3.10)

project(sendbox)

file(GLOB_RECURSE tasks_dirs LIST_DIRECTORIES true ".")

foreach(dir ${tasks_dirs})
    IF(IS_DIRECTORY ${dir})
        IF(NOT ${dir} MATCHES ".*src.*" AND NOT ${dir} MATCHES ".*tests.*")
            IF(EXISTS ${dir}/CMakeLists.txt)
                add_subdirectory(${dir})
            ENDIF()
        ENDIF()
    ENDIF()
endforeach()