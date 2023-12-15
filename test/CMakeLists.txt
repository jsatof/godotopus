set(godotopus_TEST_SOURCES
    test.cpp)

add_executable(godotopus_test ${godotopus_TEST_SOURCES} ${godotopus_SOURCES})
target_include_directories(godotopus_test PRIVATE ${PROJECT_SOURCE_DIR}/src)

target_link_directories(godotopus_test PRIVATE ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(godotopus_test PRIVATE godotopus_shared fmt::fmt boost_unit_test_framework)

add_custom_target(test COMMAND godotopus_test)
