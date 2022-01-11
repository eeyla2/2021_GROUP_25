# 2021_GROUP_25

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