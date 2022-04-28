cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()

PROJECT( QtVTKExample )

#set(CMAKE_INSTALL_UCRT_LIBRARIES TRUE)
if (MSVC_VERSION EQUAL 1930 AND MSVC_TOOLSET_VERSION EQUAL 142)
	cmake_host_system_information(RESULT VS_DIR QUERY VS_17_DIR)
	file(GLOB MSVC_REDIST_LIBRARIES "${VS_DIR}/VC/Redist/MSVC/*/${MSVC_C_ARCHITECTURE_ID}/Microsoft.VC143.CRT/*.dll")
	list(APPEND CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS "${MSVC_REDIST_LIBRARIES}")
	set(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_NO_WARNINGS TRUE)
endif()
include(InstallRequiredSystemLibraries)


# Add to top of file CPACK stuff
include(CTest)
if(WIN32)
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
add_executable( QtVTKExample MACOSX_BUNDLE
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
target_link_libraries( QtVTKExample Qt6::Widgets )

# Tell CMake that the executable depends on the VTK libraries
target_link_libraries( QtVTKExample ${VTK_LIBRARIES} )

# /calc_cmake/CMakeLists.txt
install(TARGETS QtVTKExample 
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)