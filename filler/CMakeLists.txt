add_executable(${PROJECT_NAME}
		source/main.c)
target_link_libraries(${PROJECT_NAME} ft)
target_include_directories(${PROJECT_NAME} PRIVATE ../libft/include)
target_include_directories(${PROJECT_NAME} PRIVATE include)
