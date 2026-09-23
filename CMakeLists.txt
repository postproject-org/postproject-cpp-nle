cmake_minimum_required(VERSION 3.21)
project(postproject_cpp_nle_validation LANGUAGES CXX)

find_package(PostProject 0.3 REQUIRED CONFIG)

add_executable(postproject-cpp-nle-validation main.cpp)
target_compile_features(postproject-cpp-nle-validation PRIVATE cxx_std_17)
target_link_libraries(postproject-cpp-nle-validation PRIVATE PostProject::postproject)

enable_testing()
add_test(
  NAME cpp-nle-validation
  COMMAND postproject-cpp-nle-validation
    "${CMAKE_CURRENT_BINARY_DIR}/timeline.pproj"
    "${CMAKE_CURRENT_SOURCE_DIR}/fixture.mov"
)
