cmake_minimum_required(VERSION 2.8)
 
PROJECT(polygon-collision-detection)
add_definitions(-DDEBUG_INFORMATION)
add_definitions(-DOPENCL_COMPILE_OPTIONS="-Werror" )
add_definitions(-DBOOST_COMPUTE_DEBUG_KERNEL_COMPILATION)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0 COMPONENTS log )
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK=0)

include_directories(${Boost_INCLUDE_DIRS})

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
find_package(OpenCL)
include_directories(${OpenCL_INCLUDE_DIR})   
include_directories(lib/embed-resource)
add_subdirectory(lib/embed-resource)

embed_resources(MyResources lib/embed-resource/Kernels.cl)


SET(MY_GCC_COMPILE_FLAGS "-w")
add_definitions(${MY_GCC_COMPILE_FLAGS})
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${MY_GCC_COMPILE_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${MY_GCC_COMPILE_FLAGS}" )

set(OPENCL_SOURCES

)
set(LIB_HEADERS

    src/gjk/gjk.h
    src/algorithm/algorithm.h
    src/core/Point.h
    src/core/Polygon.h
    src/core/constants.h
    src/IO/Reader.h
 )
set(LIB_SOURCES

    src/gjk/gjk.c
    src/algorithm/algorithm.cxx
    src/core/Point.cxx
    src/core/Polygon.cxx
    src/IO/Reader.cxx
)
embed_resources(MyResources ${OPENCL_SOURCES})
 include_directories(${PROJECT_SOURCE_DIR}/src)
 ADD_LIBRARY( libSearch STATIC ${LIB_SOURCES} ${LIB_HEADERS} )





add_executable(polygon-collision-detection src/core/main.cxx )
target_link_libraries(polygon-collision-detection ${VTK_LIBRARIES} -lpthread -lboost_log -lstdc++fs  -lOpenCL libSearch )
