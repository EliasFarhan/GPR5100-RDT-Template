include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB TEST_FILES *.cpp)
add_executable(runTests ${TEST_FILES})
find_package(GTest CONFIG REQUIRED)
target_link_libraries(runTests GTest::gtest GTest::gtest_main)
target_link_libraries(runTests RDT_LIB RDT_TEST_LIB)
