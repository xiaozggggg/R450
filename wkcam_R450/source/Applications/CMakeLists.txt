cmake_minimum_required(VERSION 3.22)

project(slam_pc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")

add_definitions(-DRUN_ON_PC)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/vins_mono/include)
include_directories(${CMAKE_SOURCE_DIR}/vins_mono/camera_model/include)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
find_package(Ceres REQUIRED)
message("${OpenCV_INCLUDE_DIRS}")

# file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/vins_mono/**/*.cpp")
# add_library(VINS SHARED ${SOURCES})
# target_link_libraries(VINS PUBLIC ${OpenCV_LIBS} ${CERES_LIBRARIES})



# add_executable(slam_pc ${CMAKE_SOURCE_DIR}/main.cpp)
# target_include_directories(slam_pc PUBLIC ${OpenCV_INCLUDE_DIRS})
# target_link_libraries(slam_pc VINS ${OpenCV_LIBS} )



file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/main.cpp ${CMAKE_SOURCE_DIR}/vins_mono/**/*.cpp)
add_executable(SLAM_VINS ${SOURCES})
target_link_libraries(SLAM_VINS PUBLIC ${OpenCV_LIBS} ${CERES_LIBRARIES})




