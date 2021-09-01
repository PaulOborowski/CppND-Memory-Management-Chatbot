message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_STANDARD 17)

project(Membot)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

file(GLOB project_SRCS src/*.cpp)

add_executable(membot ${project_SRCS})
target_link_libraries(membot ${wxWidgets_LIBRARIES})
target_include_directories(membot PRIVATE ${wxWidgets_INCLUDE_DIRS})

if(CMAKE_BUILD_TYPE MATCHES Debug)
message(STATUS "Seting debug options")    
add_compile_definitions(DEBUG_BUILD)
set( CMAKE_CXX_FLAGS "-g " )
endif()