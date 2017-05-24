# Declare variables for binaries' names

set(CTEST_TEST_TIMEOUT 17)
set(DART_TESTING_TIMOUT 18)
set(CTEST_TIME_LIMIT 19)

get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(MODULE      "${DIR_NAME}")
set(LIBRARY     "lib_${MODULE}")
set(TESTS       "test_${MODULE}")
set(APPLICATION "app_${MODULE}")

# Include directory with public headers
include_directories("./")

# Add all submodules
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(application)

#############################################
##### Testing
#############################################

include("CTestTests.txt")