PROJECT(entity_test LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-std=c++20 -ftest-coverage -fprofile-arcs -fstandalone-debug ${CMAKE_CXX_FLAGS}")

find_package(SDL3 REQUIRED)

set (include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include
				 ${CMAKE_BINARY_DIR}/configured_files/include
				 ${CMAKE_SOURCE_DIR}
)

set (libs_def -lSDL3
			  -lpthread
)

add_executable (${PROJECT_NAME} main.cpp)


target_link_libraries(${PROJECT_NAME} ${libs_def})
target_include_directories (${PROJECT_NAME} PRIVATE ${include_dir})
