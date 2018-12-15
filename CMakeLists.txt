cmake_minimum_required(VERSION 3.0)
project(BossEyebrow)

add_definitions(-DASIO_STANDALONE=1)
add_definitions(-DGLEW_STATIC)

# Windows specific ASIO definitions
add_definitions(-DWINVER=0x0A00)
add_definitions(-D_WIN32_WINNT=0x0A00)
add_definitions(-DBOOST_ASIO_DISABLE_IOCP=1)

add_subdirectory(contrib)
add_subdirectory(apps)