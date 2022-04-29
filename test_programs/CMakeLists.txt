# within test_programs

file(GLOB MY_FILES "*.txt" ${ModelViewer25_SOURCE_DIR}/files)
file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# I assume you want to use LibProject as a library in MainProject.
link_directories(${ModelViewer25_SOURCE_DIR}/model_library)
add_executable(test_programs testProgram.cpp)
target_link_libraries(test_programs model_library)

