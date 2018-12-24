cmake_minimum_required(VERSION 3.0)
project(BossEyebrow)
set(CMAKE_CXX_STANDARD 17)

add_definitions(-DASIO_STANDALONE=1)
if (NOT APPLE)
  add_definitions(-DGLEW_STATIC)
endif()

# Windows specific ASIO definitions
if (NOT APPLE)
  add_definitions(-DWINVER=0x0A00)
  add_definitions(-D_WIN32_WINNT=0x0A00)
  add_definitions(-DBOOST_ASIO_DISABLE_IOCP=1)
endif()

add_subdirectory(contrib)
add_subdirectory(apps)