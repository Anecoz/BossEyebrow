file(GLOB_RECURSE src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_executable(BossServer ${src})
target_link_libraries(BossServer 
asio)