##############################################
################ Build Target ################
##############################################

list(APPEND PRIVATE_MODULE_INCLUDE_DIR_LIST ${SRC_ROOT})


include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(concurrency)


