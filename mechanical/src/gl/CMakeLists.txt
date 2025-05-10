PROJECT(mechanicalGL)

find_package(OpenGL REQUIRED)
find_package(SDL3 REQUIRED)
find_package(GLEW REQUIRED)

# define os includes
set (include_dir ${CMAKE_SOURCE_DIR}
				 ${SDL3_INCLUDE_DIR}
				 ${OPENGL_INCLUDE_DIR}
				 ${GLEW_INCLUDE_DIRS})

# define objetos a compilar
set (source_dir canvas_gl.cpp
				shader.cpp
				shader_manager.cpp
)

# Define o Target
add_library (${PROJECT_NAME} STATIC ${source_dir})

# Define os includes
target_include_directories (${PROJECT_NAME} PUBLIC ${include_dir})
