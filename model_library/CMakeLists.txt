# Within src (remember our src is what will be the library)

include(CTest)
#project(the_model_library)
add_library(the_model_library material.cpp vector.cpp cell.cpp model.cpp matrix.cpp)


file(GLOB MY_FILES "*.txt" ${ModelViewer25_SOURCE_DIR}/files)
file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(the_test_programs testProgram.cpp)

target_link_libraries(the_test_programs the_model_library)

add_test(Library_test the_test_programs)
