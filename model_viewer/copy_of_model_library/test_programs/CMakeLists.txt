# within test_programs

#file(GLOB MY_FILES "*.txt" ${QtVTK_STL_SOURCE_DIR}/copy_of_model_library/proprietary_files)
#file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# I assume you want to use LibProject as a library in MainProject.
#link_directories(${QtVTK_STL_SOURCE_DIR}/copy_of_model_library/model_library)

#add_executable(test_programs testProgram.cpp)
#target_link_libraries(test_programs model_library)



#####################
#file(GLOB MY_FILES "*.txt" ${QtVTK_STL_SOURCE_DIR}/copy_of_model_library/proprietary_files)
#file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# I assume you want to use LibProject as a library in MainProject.
#link_directories(${QtVTK_STL_SOURCE_DIR}/copy_of_model_library/model_library)

#add_executable(test_programs testProgram.cpp)
#target_link_libraries(test_programs model_library)
