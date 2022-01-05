# within executables (equivalent to mainproject in tutorial)

# I assume you want to use LibProject as a library in MainProject.
link_directories(${MyProject_SOURCE_DIR}/src)
add_executable(test_programs modelTestProgram.cpp)
target_link_libraries(test_programs src)