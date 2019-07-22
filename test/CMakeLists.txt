cmake_minimum_required(VERSION 3.14)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

set(TEST_SOURCE_FILES runAllTests.cpp ModelFixture.cpp XMLFilerepositoryFixture.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core ${wxWidgets_LIBRARIES})