# There should be seperate directories for libraries & host executables
# This is the master CMakeLists.txt
# Each directory (ones with executables?) should have thier own CMakeLists.txt which is invoked from this

# Master CmakeLists.txt

# Minimum version requirement
cmake_minimum_required( VERSION 2.8 )

# Create project with specified name
project( shape_project )

# This project contains a library
add_library( myLib src/model.cpp)

if( NOT BUILD_SHARED_LIBS )
add_definitions( -Dmaths_STATIC )
endif()

# It also contains an executable
add_executable( myExe executables/modelTestProgram.cpp )

# The executable uses the library
target_link_libraries( myExe myLib )