cmake_minimum_required (VERSION 2.6)

Project(Trevinklar)

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "-std=c++11 -g -O0")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(BOX2D_DIR ${PROJECT_SOURCE_DIR}/box2d/Box2D)
set(BOX2D_BUILD_STATIC ON CACHE BOOL "Build Box2D library statically")
set(BOX2D_BUILD_EXAMPLES OFF CACHE BOOL "Build Box2D examples")
set(BOX2D_INSTALL OFF CACHE BOOL "Build Box2D library")

add_subdirectory(${BOX2D_DIR})
include_directories(${BOX2D_DIR})

set(TRE_SOURCES
	EntityServiceProvider.cpp
	Main.cpp
	TreWindow.cpp
)

link_directories(${CMAKE_BINARY_DIR})
add_executable(Trevinklar ${TRE_SOURCES})
target_link_libraries(Trevinklar Box2D sfml-graphics sfml-window sfml-system)
