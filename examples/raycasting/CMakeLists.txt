PROJECT(rayCasting LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-std=c++20 -ftest-coverage -fprofile-arcs -fstandalone-debug ${CMAKE_CXX_FLAGS}")

#find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
#find_package(GLEW REQUIRED)
#find_package(Bullet REQUIRED)
#find_package(PUGIXML REQUIRED)

#add_definitions(-DGLM_ENABLE_EXPERIMENTAL)

set (include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include
				 #${PUGIXML_DIR}
				 ${CMAKE_SOURCE_DIR}
				 #${OPENGL_INCLUDE_DIR}
				 ${SDL2_INCLUDE_DIR}
				 #${BULLET_INCLUDE_DIR}
)

set (libs_def #${CMAKE_SOURCE_DIR}/bin/libChimeraCore.a
			 #${OPENGL_LIBRARIES}
			 ${SDL2_LIBRARY}
			 #${BULLET_LIBRARIES}
			 #${GLEW_LIBRARIES}
			 -lSDL2
			 #-lSDL2_image
			 #-lSDL2_ttf
			 #-lpugixml
			 -lpthread
)

add_executable (${PROJECT_NAME} src/raycasting.cpp
								src/game.cpp
								src/main.cpp
)

target_link_libraries(${PROJECT_NAME} ${libs_def})
target_include_directories (${PROJECT_NAME} PRIVATE ${include_dir})

#add_dependencies(${PROJECT_NAME} ChimeraCollada)
#INSTALL(FILES ${SimpleRayCasting_BINARY_DIR}/${PROJECT_BINARY_DIR} DESTINATION bin)
