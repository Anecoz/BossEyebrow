cmake_minimum_required(VERSION 3.0)
project(BossEyebrow)

add_definitions(-DASIO_STANDALONE=1)

# Windows specific ASIO definitions
add_definitions(-DWINVER=0x0A00)
add_definitions(-D_WIN32_WINNT=0x0A00)

add_subdirectory(contrib)

find_package(OpenGL REQUIRED)

add_executable(BossEyebrow src/main.cpp)
target_link_libraries(BossEyebrow 
asio 
glew 
glfw
${OPENGL_LIBRARY})