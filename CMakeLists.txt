cmake_minimum_required( VERSION 2.8 )
project(zkys_fence)

add_subdirectory(fence)
list(APPEND EXTRA_LIBS fence)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/fence")


add_executable(zkys_fence  main.c)
add_executable(read_kml read_kml_boundary.c)

target_link_libraries(zkys_fence PUBLIC ${EXTRA_LIBS})
target_include_directories(zkys_fence PUBLIC "${PROJECT_BINARY_DIR}" ${EXTRA_INCLUDES})
#link math library
target_link_libraries(zkys_fence  m) 


