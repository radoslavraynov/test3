find_package(GTest REQUIRED)
find_library(GMP gmp)
message(" ---- Found GMP: ${GMP}")

add_executable(gmp_test ${CMAKE_CURRENT_SOURCE_DIR}/minimal.t.cpp)
target_link_libraries(gmp_test GTest::Main ${GMP})