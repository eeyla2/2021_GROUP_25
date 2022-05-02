
foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()



#set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)
if (MSVC_VERSION EQUAL 1930 AND MSVC_TOOLSET_VERSION EQUAL 142)
	cmake_host_system_information(RESULT VS_DIR QUERY VS_17_DIR)
	file(GLOB MSVC_REDIST_LIBRARIES "${VS_DIR}/VC/Redist/MSVC/*/${MSVC_C_ARCHITECTURE_ID}/Microsoft.VC143.CRT/*.dll")
	list(APPEND CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS "${MSVC_REDIST_LIBRARIES}")
	set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_NO_WARNINGS TRUE)
endif()



include(InstallRequiredSystemLibraries)
   


include(CTest)

if(${BUILD_INSTALLER})
   set(CPACK_GENERATOR "NSIS")
   else()
   set(CPACK_GENERATOR "ZIP")

endif()

include(CPack)

find_package(VTK COMPONENTS 
  vtkCommonColor
  vtkCommonCore
  vtkCommonDataModel
  vtkInteractionStyle
  vtkRenderingContextOpenGL2
  vtkRenderingCore
  vtkRenderingFreeType
  vtkRenderingGL2PSOpenGL2
  vtkRenderingOpenGL2
  QUIET
)

# The CMake build process might generate some new files in the current
# directory. This makes sure they can be found.
set( CMAKE_INCLUDE_CURRENT_DIR ON )


# This allows CMake to run one of Qt's build tools called moc
# if it is needed. moc.exe can be found in Qt's bin directory.
# We'll look at what moc does later.
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

# Find the Qt widgets package. This locates the relevant include and
# lib directories, and the necessary static libraries for linking.
find_package( Qt6Widgets )

set( UIS mainwindow.ui )
qt6_wrap_ui( UI_Srcs ${UIS} )

set( ICONS Icons/icons.qrc )
qt6_add_resources( QRC_Srcs ${ICONS} )


# Also link to VTK
find_package( VTK REQUIRED )
include( ${VTK_USE_FILE} )

# Define the executable output and its sources
add_executable( ModelViewer25 MACOSX_BUNDLE
				main.cpp 
				mainwindow.cpp 
				mainwindow.h 
				mainwindow.ui
                                tabcontent.cpp
                                tabcontent.h
                                tabcontent.ui
				currentstl.cpp
                                currentstl.h
                                recentstl.cpp
                                recentstl.h
				${UI_Srcs}
				${QRC_Srcs}
				)

# Tell CMake that the executable depends on the Qt::Widget libraries.
target_link_libraries( ModelViewer25 Qt6::Widgets )

# Tell CMake that the executable depends on the VTK libraries
target_link_libraries( ModelViewer25 ${VTK_LIBRARIES} )









 


 if ( ${MODELVIEWER25} OR ${BUILD_INSTALLERS} )
# These two lines set the path for the transfer of the libraries needed to run the application it varies from system to system.
#  set(QT_DIR "C:/Qt/6.3.0/msvc2019_64") 
#  set(VTK_DIR "C:/VTK-9.1.0/VTK-9.1.0/build")
 endif()



# Installer code

install(TARGETS ModelViewer25
RUNTIME
DESTINATION applications
COMPONENT applications
        )

install(FILES
        ${QT_DIR}/bin/Qt6Cored.dll
        ${QT_DIR}/bin/Qt6Guid.dll
        ${QT_DIR}/bin/Qt6Widgetsd.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingGL2PSOpenGL2-9.1d.dll
     
        ${VTK_DIR}/bin/Debug/vtkCommonColor-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonComputationalGeometry-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonCore-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonDataModel-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonExecutionModel-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonMath-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonMisc-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonSystem-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonTransforms-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkDICOMParser-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkdoubleconversion-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersCore-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersExtraction-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersGeneral-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersGeometry-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersHybrid-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersModeling-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersSources-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersStatistics-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkfreetype-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkgl2ps-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkglew-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkGUISupportQt-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingColor-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingCore-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingFourier-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingGeneral-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingHybrid-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingSources-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkInteractionStyle-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkInteractionWidgets-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkIOCore-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkIOGeometry-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkIOImage-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkjpeg-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtklz4-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtklzma-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkmetaio-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkpng-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingAnnotation-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingCore-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingFreeType-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingGL2PSOpenGL2-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingOpenGL2-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtksys-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtktiff-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkzlib-9.1d.dll
       
        C:/Windows/SysWOW64/MSVCP140D.dll 
        C:/Windows/SysWOW64/VCRUNTIME140D.dll 
        C:/Windows/SysWOW64/UCRTBASED.dll 
        C:/Windows/SysWOW64/KERNEL32.dll 

	
        DESTINATION bin
        COMPONENT libraries
        )


    install(FILES 
        ${ModelViewer25_SOURCE_DIR}/model_library/model.hpp;
        ${ModelViewer25_SOURCE_DIR}/model_library/model.cpp;
        ${ModelViewer25_SOURCE_DIR}/model_library/matrix.hpp;
        ${ModelViewer25_SOURCE_DIR}/model_library/matrix.cpp;
        ${ModelViewer25_SOURCE_DIR}/model_library/material.hpp;
        ${ModelViewer25_SOURCE_DIR}/model_library/material.cpp;
        ${ModelViewer25_SOURCE_DIR}/model_library/vector.hpp;
        ${ModelViewer25_SOURCE_DIR}/model_library/vector.cpp;
      

        DESTINATION include
        COMPONENT headers
        )

  install(FILES 
        ${ModelViewer25_SOURCE_DIR}/files/a-10-thunderbolt-mk2.stl
        ${ModelViewer25_SOURCE_DIR}/files/airbus_a400m.stl
        ${ModelViewer25_SOURCE_DIR}/files/bawar_plane.stl
        ${ModelViewer25_SOURCE_DIR}/files/cube.stl
        ${ModelViewer25_SOURCE_DIR}/files/he111.stl
        ${ModelViewer25_SOURCE_DIR}/files/sphere.stl
        ${ModelViewer25_SOURCE_DIR}/files/ExampleModel1.mod
        ${ModelViewer25_SOURCE_DIR}/files/ExampleModel2.mod
        ${ModelViewer25_SOURCE_DIR}/files/ExampleModel3.mod
        DESTINATION model_files
        COMPONENT model_files
        )



  



   