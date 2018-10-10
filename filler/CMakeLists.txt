add_executable(${PROJECT_NAME}
		source/main.c source/filler_parse.c source/filler_main.c source/filler_algo.c)
target_link_libraries(${PROJECT_NAME} ft)
target_include_directories(${PROJECT_NAME} PRIVATE ${FT_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE include)
