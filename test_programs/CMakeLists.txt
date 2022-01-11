# within test_programs

file(GLOB MY_FILES "*.txt" ${MyProject_SOURCE_DIR}/proprietary_files)
file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# I assume you want to use LibProject as a library in MainProject.
link_directories(${MyProject_SOURCE_DIR}/src)
add_executable(test_programs testProgram.cpp)
target_link_libraries(test_programs src)

