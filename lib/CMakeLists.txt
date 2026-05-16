add_library(Utils
  src/util.cpp
)

target_compile_features(Utils PUBLIC cxx_std_23)
target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
