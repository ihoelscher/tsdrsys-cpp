# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ihoelscher/ClionProjects/TSDRS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ihoelscher/ClionProjects/TSDRS

# Include any dependencies generated for this target.
include CMakeFiles/csegmt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/csegmt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/csegmt.dir/flags.make

CMakeFiles/csegmt.dir/main.cpp.o: CMakeFiles/csegmt.dir/flags.make
CMakeFiles/csegmt.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ihoelscher/ClionProjects/TSDRS/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/csegmt.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/csegmt.dir/main.cpp.o -c /home/ihoelscher/ClionProjects/TSDRS/main.cpp

CMakeFiles/csegmt.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/csegmt.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ihoelscher/ClionProjects/TSDRS/main.cpp > CMakeFiles/csegmt.dir/main.cpp.i

CMakeFiles/csegmt.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/csegmt.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ihoelscher/ClionProjects/TSDRS/main.cpp -o CMakeFiles/csegmt.dir/main.cpp.s

CMakeFiles/csegmt.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/csegmt.dir/main.cpp.o.requires

CMakeFiles/csegmt.dir/main.cpp.o.provides: CMakeFiles/csegmt.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/csegmt.dir/build.make CMakeFiles/csegmt.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/csegmt.dir/main.cpp.o.provides

CMakeFiles/csegmt.dir/main.cpp.o.provides.build: CMakeFiles/csegmt.dir/main.cpp.o

CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o: CMakeFiles/csegmt.dir/flags.make
CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o: colorseg/lookup.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ihoelscher/ClionProjects/TSDRS/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o -c /home/ihoelscher/ClionProjects/TSDRS/colorseg/lookup.cpp

CMakeFiles/csegmt.dir/colorseg/lookup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/csegmt.dir/colorseg/lookup.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ihoelscher/ClionProjects/TSDRS/colorseg/lookup.cpp > CMakeFiles/csegmt.dir/colorseg/lookup.cpp.i

CMakeFiles/csegmt.dir/colorseg/lookup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/csegmt.dir/colorseg/lookup.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ihoelscher/ClionProjects/TSDRS/colorseg/lookup.cpp -o CMakeFiles/csegmt.dir/colorseg/lookup.cpp.s

CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o.requires:
.PHONY : CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o.requires

CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o.provides: CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o.requires
	$(MAKE) -f CMakeFiles/csegmt.dir/build.make CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o.provides.build
.PHONY : CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o.provides

CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o.provides.build: CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o

CMakeFiles/csegmt.dir/mser/mser.cpp.o: CMakeFiles/csegmt.dir/flags.make
CMakeFiles/csegmt.dir/mser/mser.cpp.o: mser/mser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ihoelscher/ClionProjects/TSDRS/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/csegmt.dir/mser/mser.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/csegmt.dir/mser/mser.cpp.o -c /home/ihoelscher/ClionProjects/TSDRS/mser/mser.cpp

CMakeFiles/csegmt.dir/mser/mser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/csegmt.dir/mser/mser.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ihoelscher/ClionProjects/TSDRS/mser/mser.cpp > CMakeFiles/csegmt.dir/mser/mser.cpp.i

CMakeFiles/csegmt.dir/mser/mser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/csegmt.dir/mser/mser.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ihoelscher/ClionProjects/TSDRS/mser/mser.cpp -o CMakeFiles/csegmt.dir/mser/mser.cpp.s

CMakeFiles/csegmt.dir/mser/mser.cpp.o.requires:
.PHONY : CMakeFiles/csegmt.dir/mser/mser.cpp.o.requires

CMakeFiles/csegmt.dir/mser/mser.cpp.o.provides: CMakeFiles/csegmt.dir/mser/mser.cpp.o.requires
	$(MAKE) -f CMakeFiles/csegmt.dir/build.make CMakeFiles/csegmt.dir/mser/mser.cpp.o.provides.build
.PHONY : CMakeFiles/csegmt.dir/mser/mser.cpp.o.provides

CMakeFiles/csegmt.dir/mser/mser.cpp.o.provides.build: CMakeFiles/csegmt.dir/mser/mser.cpp.o

# Object files for target csegmt
csegmt_OBJECTS = \
"CMakeFiles/csegmt.dir/main.cpp.o" \
"CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o" \
"CMakeFiles/csegmt.dir/mser/mser.cpp.o"

# External object files for target csegmt
csegmt_EXTERNAL_OBJECTS =

csegmt: CMakeFiles/csegmt.dir/main.cpp.o
csegmt: CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o
csegmt: CMakeFiles/csegmt.dir/mser/mser.cpp.o
csegmt: CMakeFiles/csegmt.dir/build.make
csegmt: /usr/local/lib/libopencv_calib3d.so.3.1.0
csegmt: /usr/local/lib/libopencv_core.so.3.1.0
csegmt: /usr/local/lib/libopencv_features2d.so.3.1.0
csegmt: /usr/local/lib/libopencv_flann.so.3.1.0
csegmt: /usr/local/lib/libopencv_highgui.so.3.1.0
csegmt: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
csegmt: /usr/local/lib/libopencv_imgproc.so.3.1.0
csegmt: /usr/local/lib/libopencv_ml.so.3.1.0
csegmt: /usr/local/lib/libopencv_objdetect.so.3.1.0
csegmt: /usr/local/lib/libopencv_photo.so.3.1.0
csegmt: /usr/local/lib/libopencv_shape.so.3.1.0
csegmt: /usr/local/lib/libopencv_stitching.so.3.1.0
csegmt: /usr/local/lib/libopencv_superres.so.3.1.0
csegmt: /usr/local/lib/libopencv_video.so.3.1.0
csegmt: /usr/local/lib/libopencv_videoio.so.3.1.0
csegmt: /usr/local/lib/libopencv_videostab.so.3.1.0
csegmt: /usr/local/lib/libopencv_objdetect.so.3.1.0
csegmt: /usr/local/lib/libopencv_calib3d.so.3.1.0
csegmt: /usr/local/lib/libopencv_features2d.so.3.1.0
csegmt: /usr/local/lib/libopencv_flann.so.3.1.0
csegmt: /usr/local/lib/libopencv_highgui.so.3.1.0
csegmt: /usr/local/lib/libopencv_ml.so.3.1.0
csegmt: /usr/local/lib/libopencv_photo.so.3.1.0
csegmt: /usr/local/lib/libopencv_video.so.3.1.0
csegmt: /usr/local/lib/libopencv_videoio.so.3.1.0
csegmt: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
csegmt: /usr/local/lib/libopencv_imgproc.so.3.1.0
csegmt: /usr/local/lib/libopencv_core.so.3.1.0
csegmt: CMakeFiles/csegmt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable csegmt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/csegmt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/csegmt.dir/build: csegmt
.PHONY : CMakeFiles/csegmt.dir/build

CMakeFiles/csegmt.dir/requires: CMakeFiles/csegmt.dir/main.cpp.o.requires
CMakeFiles/csegmt.dir/requires: CMakeFiles/csegmt.dir/colorseg/lookup.cpp.o.requires
CMakeFiles/csegmt.dir/requires: CMakeFiles/csegmt.dir/mser/mser.cpp.o.requires
.PHONY : CMakeFiles/csegmt.dir/requires

CMakeFiles/csegmt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/csegmt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/csegmt.dir/clean

CMakeFiles/csegmt.dir/depend:
	cd /home/ihoelscher/ClionProjects/TSDRS && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ihoelscher/ClionProjects/TSDRS /home/ihoelscher/ClionProjects/TSDRS /home/ihoelscher/ClionProjects/TSDRS /home/ihoelscher/ClionProjects/TSDRS /home/ihoelscher/ClionProjects/TSDRS/CMakeFiles/csegmt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/csegmt.dir/depend
