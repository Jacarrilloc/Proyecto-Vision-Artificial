# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial/build"

# Include any dependencies generated for this target.
include CMakeFiles/pr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pr.dir/flags.make

CMakeFiles/pr.dir/proyecto.cxx.o: CMakeFiles/pr.dir/flags.make
CMakeFiles/pr.dir/proyecto.cxx.o: ../proyecto.cxx
CMakeFiles/pr.dir/proyecto.cxx.o: CMakeFiles/pr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pr.dir/proyecto.cxx.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pr.dir/proyecto.cxx.o -MF CMakeFiles/pr.dir/proyecto.cxx.o.d -o CMakeFiles/pr.dir/proyecto.cxx.o -c "/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial/proyecto.cxx"

CMakeFiles/pr.dir/proyecto.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pr.dir/proyecto.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial/proyecto.cxx" > CMakeFiles/pr.dir/proyecto.cxx.i

CMakeFiles/pr.dir/proyecto.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pr.dir/proyecto.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial/proyecto.cxx" -o CMakeFiles/pr.dir/proyecto.cxx.s

# Object files for target pr
pr_OBJECTS = \
"CMakeFiles/pr.dir/proyecto.cxx.o"

# External object files for target pr
pr_EXTERNAL_OBJECTS =

pr: CMakeFiles/pr.dir/proyecto.cxx.o
pr: CMakeFiles/pr.dir/build.make
pr: /usr/local/lib/libopencv_gapi.so.4.6.0
pr: /usr/local/lib/libopencv_highgui.so.4.6.0
pr: /usr/local/lib/libopencv_ml.so.4.6.0
pr: /usr/local/lib/libopencv_objdetect.so.4.6.0
pr: /usr/local/lib/libopencv_photo.so.4.6.0
pr: /usr/local/lib/libopencv_stitching.so.4.6.0
pr: /usr/local/lib/libopencv_video.so.4.6.0
pr: /usr/local/lib/libopencv_videoio.so.4.6.0
pr: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
pr: /usr/local/lib/libopencv_dnn.so.4.6.0
pr: /usr/local/lib/libopencv_calib3d.so.4.6.0
pr: /usr/local/lib/libopencv_features2d.so.4.6.0
pr: /usr/local/lib/libopencv_flann.so.4.6.0
pr: /usr/local/lib/libopencv_imgproc.so.4.6.0
pr: /usr/local/lib/libopencv_core.so.4.6.0
pr: CMakeFiles/pr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pr.dir/build: pr
.PHONY : CMakeFiles/pr.dir/build

CMakeFiles/pr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pr.dir/clean

CMakeFiles/pr.dir/depend:
	cd "/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial" "/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial" "/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial/build" "/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial/build" "/home/julian/Escritorio/Universidad/Proyecto Vision Artificial/Proyecto-Vision-Artificial/build/CMakeFiles/pr.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/pr.dir/depend

