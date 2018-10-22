cmake_minimum_required(VERSION 3.12)
project(modnosum.filler C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${CMAKE_C_FLAGS} -g -DDEBUG")

add_subdirectory(libft)

add_executable(${PROJECT_NAME}
		source/filler_algo.c
		source/filler_main.c
		source/filler_parse.c
		source/main.c)
target_link_libraries(${PROJECT_NAME} ft)
target_include_directories(${PROJECT_NAME} PRIVATE ./include)
target_include_directories(${PROJECT_NAME} PRIVATE ${ft_INCLUDES})
