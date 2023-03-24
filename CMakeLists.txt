cmake_minimum_required(VERSION 3.0.0)
project(STL VERSION 0.1.0)

include(CTest)
enable_testing()

# include_directories(include)
# aux_source_directory(src SRC_LISTS)
# add_executable(main ${SRC_LISTS})
add_subdirectory(src)

# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
