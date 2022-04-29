# root directory 
cmake_minimum_required( VERSION 3.1 )

project(ModelViewer25)

# We want control over when we build the library & installers
# When testing, we only want to build the library once, 
# and from then on can build only the ModelViewer
#Once we are happy and we also want to build isntaller, can change Boolean

set(BUILD_MODEL_LIBRARY TRUE)	#I would run this once with true, then change to false to reduce build time

set(BUILD_MODELVIEWER25 TRUE)	#while we are developing GUI this is true

set(BUILD_INSTALLER FALSE)	#for now, we don't want to build the installer every time



if(${BUILD_MODEL_LIBRARY})
  add_subdirectory(test_programs)
  add_subdirectory(model_library)
endif()


if(${BUILD_MODELVIEWER25})
  add_subdirectory(ModelViewer)
endif()
  