
set(CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "CURRENT_DIR: ${CURRENT_DIR}")


#########################################
################ Library ################
#########################################


file(GLOB_RECURSE SOURCES
  ${CURRENT_DIR}/*.cpp  #
  )

#file(GLOB TEST_FILES ${SRC_ROOT}/../test/*_test.cpp)
set(TEST_FILES "")
set(BENCHMARK_FILES "")
# Extract test file, by find _test in filename.
foreach (SOURCE_FILE ${SOURCES})
  string(FIND ${SOURCE_FILE} "Test.cpp" FIND_RESULT)
  if (NOT ${FIND_RESULT} STREQUAL "-1")
    list(APPEND TEST_FILES ${SOURCE_FILE})
    list(REMOVE_ITEM SOURCES ${SOURCE_FILE})
  endif ()
  
  string(FIND ${SOURCE_FILE} "Benchmark.cpp" FIND_RESULT)
  if (NOT ${FIND_RESULT} STREQUAL "-1")
    list(APPEND BENCHMARK_FILES ${SOURCE_FILE})
    list(REMOVE_ITEM SOURCES ${SOURCE_FILE})
  endif ()
endforeach ()


message(STATUS "Sources: ${SOURCES}")
message(STATUS "TEST_FILES: ${TEST_FILES}")
message(STATUS "BENCHMARK_FILES: ${BENCHMARK_FILES}")


##############################################
################ Build Target ################
##############################################

############################################
################ Build Test ################
############################################
if (ENABLE_TEST)
  list(LENGTH TEST_FILES FILE_NUM)
  message(STATUS "TEST_FILES Number: ${FILE_NUM}")
  
  foreach (FILE ${TEST_FILES})
    get_filename_component(target ${FILE} NAME_WLE)
    add_executable(${target} ${FILE})
    
    target_include_directories(${target}
      PUBLIC
      ${PUBLIC_MODULE_INCLUDE_DIR_LIST}
      
      PRIVATE
      ${PRIVATE_MODULE_INCLUDE_DIR_LIST}
      )
    
    
    target_link_directories(${target}
      PUBLIC
      ${PUBLIC_MODULE_LIBRARY_DIR_LIST}
      
      PRIVATE
      ${PRIVATE_MODULE_LIBRARY_DIR_LIST}
      )
    
    target_link_libraries(${target}
      PUBLIC
      GTest::gtest)
    include(GoogleTest)
    #    gtest_discover_tests(${target})
  endforeach ()
endif ()


#################################################
################ Build Benchmark ################
#################################################
if (ENABLE_BENCHMARK)
  
  list(LENGTH BENCHMARK_FILES FILE_NUM)
  message(STATUS "BENCHMARK_FILES Number: ${FILE_NUM}")
  
  foreach (FILE ${BENCHMARK_FILES})
    get_filename_component(target ${FILE} NAME_WLE)
    add_executable(${target} ${FILE})
    
    target_include_directories(${target}
      PUBLIC
      ${PUBLIC_MODULE_INCLUDE_DIR_LIST}
      
      PRIVATE
      ${PRIVATE_MODULE_INCLUDE_DIR_LIST}
      )
    
    
    target_link_directories(${target}
      PUBLIC
      ${PUBLIC_MODULE_LIBRARY_DIR_LIST}
      
      PRIVATE
      ${PRIVATE_MODULE_LIBRARY_DIR_LIST}
      )
    
    
    target_link_libraries(${target}
      PUBLIC
      benchmark::benchmark)
  endforeach ()
endif ()


# add_executable(bug bug.cpp)
# target_link_libraries(bug PRIVATE pthread)