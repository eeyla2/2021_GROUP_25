# 2021_GROUP_25

![Testing Status](https://github.com/Daniel-Ischebeck/2021_GROUP_25/actions/workflows/cmake-test.yml/badge.svg)


# Documentation
[Project Documentation](https://daniel-ischebeck.github.io/2021_GROUP_25/)


# Program Functionality

- Integration of shrink, clip filter + at least 2 other VTK visual effect filters(**Pisit**)			
- Load STL models and apply any combination of all filters(**Pisit**)					
- Load MOD models (**Daniel**)						
- Load/combine multiple models into same "world"(**Daniel**)						
- Display .mod file statisitics (num. vectors, cell & vol)(**Daniel**)					
- Modify model geometry/materials. Slice model / modify coordinates	(**Afolabi**)		
- Use of multiple tabs/windows for parallel viewing/editing of multiple models.(**Laith**)
- Lists of recent and current STLs in the same world.(**Laith**)					
- All GUI features work consistently without crashing, etc (**Pisit**,**Daniel**)		
- GUI appearance: excellent include use of features such as: toolsbars, recent file lists, splash screen, etc(**Pisit**,**Laith**)	
- Documentation (**Laith**,**Daniel**)					




# Build instructions (from source):

* The directory 'build' is not uploaded to github. After cloning the repository create a build folder.
* The local environment needs to be initialised before you can build the project.(vcvarsall.bat)
* Navigate to build folder and run **command:** cmake ..
* Now run **command:** msbuild ModelViewer25.sln
* Navigate to the executable, **command:** cd ModelViewer/Debug
* Run the executable, **command:** ModelViewer25.exe


# To build installer:
* In build directory: **command:** cmake --build . --target package
* (Creation of package may take up to a minute)
* A ModelViewer25 installer application will have been generated in the build folder
* Double click installer and follow installation instructions

-------------------------------------------------------------------------------------------
What the test program shows:

Reading data from file, allocating materials, vectors & cells with appropriate data & storing.
Showing that this stored data can be retrieved and the relevant operations & functions performed.
e.g. volume, centre & weight of shapes (Note: Assumed weight = mass * 9.81).
Save the model data to a new file in the same format as original.

Capabilites of the matrix class.
Creating various standard matricies, performing rotations of vectors, matrix multiplication etc..
Determinant, inverse & transpose of matrix.


# Screen Clippings
  * ModelViewer25 display a .mod and .stl file
![alt text](https://github.com/Daniel-Ischebeck/2021_GROUP_25/blob/main/ModelViewer/images/mod_and_stl.png "ModelViewer25 display a .mod and .stl file")

  * Displaying two stls with filters applied
![alt text](https://github.com/Daniel-Ischebeck/2021_GROUP_25/blob/main/ModelViewer/images/two_planes.png "Displaying two stls with filters applied")



# Group members:
  * Azim Adebisi  (Afolabi)
  * Laith Al Far  (Laith)
  * Daniel Ischebeck (Daniel)
  * Pisitpong Tiwatmuncharoen (Best)