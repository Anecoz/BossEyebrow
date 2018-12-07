add_library(asio INTERFACE)
#file(GLOB_RECURSE src
#    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
#)
target_include_directories(asio INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)