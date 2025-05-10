PROJECT(template_gl VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-std=c++20 -ftest-coverage -fprofile-arcs -fstandalone-debug ${CMAKE_CXX_FLAGS}")

find_package(OpenGL REQUIRED)
find_package(SDL3 REQUIRED)
find_package(GLEW REQUIRED)

add_definitions(-DGLM_ENABLE_EXPERIMENTAL)

set(include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include
                ${CMAKE_BINARY_DIR}/configured_files/include
                ${CMAKE_SOURCE_DIR}
)

set(libs_def ${OPENGL_LIBRARIES}
             ${GLEW_LIBRARIES}
             ${CMAKE_SOURCE_DIR}/bin/libmechanicalGL.a
             -lSDL3
             -lpthread
)

add_executable (${PROJECT_NAME} src/main.cpp
                                src/game.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${include_dir})
target_link_libraries(${PROJECT_NAME} ${libs_def})

add_dependencies(${PROJECT_NAME} mechanicalGL)
