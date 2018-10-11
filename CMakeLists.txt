cmake_minimum_required(VERSION 3.12)
project(modnosum.filler C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g -DDEBUG")

add_subdirectory(libft)
add_subdirectory(filler)

set(RES_DIR ./resources)
set(MAPS_DIR ${RES_DIR}/maps)
set(PLAYERS_DIR ${RES_DIR}/players)
set(FILLER_VM ${RES_DIR}/filler_vm)
set(FILLER_MAP ${MAPS_DIR}/map00)
set(FILLER_ENEMY ${PLAYERS_DIR}/abanlin.filler)
set(FILLER_ME ${CMAKE_CURRENT_BINARY_DIR}/filler/modnosum.filler)
set(FILLER_TIMEOUT 10)

add_custom_target(
		runTest
		COMMAND
			${FILLER_VM}
			-f ${FILLER_MAP}
			-p1 ${FILLER_ENEMY}
			-p2 ${FILLER_ME}
			-t ${FILLER_TIMEOUT}
		DEPENDS
			${PROJECT_NAME}
		WORKING_DIRECTORY
			${CMAKE_CURRENT_SOURCE_DIR})