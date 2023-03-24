
# project(main)

# include_directories(../include)
# aux_source_directory(. SRC_LISTS)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)

# add_executable(RBTree RBTree.cpp)


# CMake_minimum_required(3.0)

project(main)

include_directories(../include)
aux_source_directory(. SRC_LISTS)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)

add_executable(main ${SRC_LISTS})
