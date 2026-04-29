function(add_homework_task)
  set(options)
  set(one_value_args NAME)
  set(multi_value_args SOURCES TEST_SOURCES INCLUDE_DIRS)
  cmake_parse_arguments(TASK "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})

  if(NOT TASK_NAME)
    message(FATAL_ERROR "add_homework_task requires NAME")
  endif()

  if(NOT TASK_SOURCES)
    message(FATAL_ERROR "add_homework_task(${TASK_NAME}) requires SOURCES")
  endif()

  add_executable(${TASK_NAME} ${TASK_SOURCES})
  target_compile_features(${TASK_NAME} PRIVATE cxx_std_23)
  target_include_directories(
    ${TASK_NAME}
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/src"
      ${TASK_INCLUDE_DIRS}
  )
  target_link_libraries(${TASK_NAME} PRIVATE Utils)

  if(BUILD_TESTING AND TASK_TEST_SOURCES)
    add_executable(${TASK_NAME}_tests ${TASK_TEST_SOURCES})
    target_compile_features(${TASK_NAME}_tests PRIVATE cxx_std_23)
    target_include_directories(
      ${TASK_NAME}_tests
      PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        ${TASK_INCLUDE_DIRS}
    )
    target_link_libraries(${TASK_NAME}_tests PRIVATE GTest::gtest_main Utils)
    gtest_discover_tests(${TASK_NAME}_tests)
  endif()
endfunction()
