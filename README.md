# 2021_GROUP_25

UPDATED RAEDME 08/04/2022
# Tasks for Gui

- Integration of shrink, clip filter + at least 2 other VTK visual effect filters(**Pisit**)			
- Load STL models and apply any combination of all filters(**Pisit**)						
- Load MOD models and apply any combination of all filters(**Daniel**)						
- Load/combine multiple models into same "world"(**Pisit**)						
- Display model size / volume / weight / number of cell statistics, add measurements(**Afolabi**)					
- Modify model geometry/materials. Could include being able to slice model / modify coordinates, etc.	(**Afolabi**)					
- Save modfied/combined models to STL and MOD file formats(**Daniel**)					
- Use of multiple tabs/windows for parallel viewing/editing of multiple models.(**Laith**)					
- All GUI features work consistently without crashing, etc(**Pisit**)						
- GUI appearance: excellent include use of features such as: toolsbars, recent file lists, splash screen, etc(**Pisit**)						

Build instructions:

The directory 'build' is not uploaded to github.
The local environment needs to be initialised before you can build the project.
This is done with a batch script such as cmake_gen_msvc.bat (recall previous worksheets)
This .bat will be unique to your local system & compiler.
It should be run within the build directory (which you will create locally),
e.g.  C:\Users\Daniel\Git\2021_GROUP_25\build>cmake_gen_msvc.bat ..

Now msbuild can be used, e.g. msbuild MyProject.sln  (The project name is specified in CMakeLists.txt)
Now you can navigate to where the executable is: (cd test_programs\Debug) and then execute
e.g. C:\Users\Daniel\Git\2021_GROUP_25\build\test_programs\Debug>test_programs.exe

To view saved file, go back up one directory from the executable (cd ..\proprietary_files) then open file
C:\Users\Daniel\Git\2021_GROUP_25\build\test_programs\proprietary_files>saveFile.mod

---------------------------------------------------------------------------------------------
What the test program shows:

Reading data from file, allocating materials, vectors & cells with appropriate data & storing.
Showing that this stored data can be retrieved and the relevant operations & functions performed.
e.g. volume, centre & weight of shapes (Note: Assumed weight = mass * 9.81).
Save the model data to a new file in the same format as original.

Capabilites of the matrix class.
Creating various standard matricies, performing rotations of vectors, matrix multiplication etc..
Determinant, inverse & transpose of matrix.





