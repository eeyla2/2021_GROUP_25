# Within src (remember our src is what will be the library)

#project(the_model_library)
add_library(the_model_library material.cpp vector.cpp cell.cpp model.cpp matrix.cpp)
