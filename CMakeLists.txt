cmake_minimum_required(VERSION 3.12)
project(modnosum.filler C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(libft)
add_subdirectory(filler)

add_custom_target(test-abanlin
		COMMAND ./resources/filler_vm -p1 ./resources/players/abanlin.filler -p2 ./build/filler/modnosum.filler -f ./resources/maps/map00
		DEPENDS ${PROJECT_NAME}
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})