find_package(OpenGL REQUIRED)

file(GLOB_RECURSE src
    ${CMAKE_CURRENT_SOURCE_DIR}/../common/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../common/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_executable(BossEyebrow ${src})
target_include_directories(BossEyebrow PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../common)
target_link_libraries(BossEyebrow 
asio 
glew 
glfw
${OPENGL_LIBRARY})