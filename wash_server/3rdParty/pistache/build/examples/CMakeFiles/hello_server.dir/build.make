# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/incu/work/pistache/pistache

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/incu/work/pistache/pistache/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/hello_server.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/hello_server.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/hello_server.dir/flags.make

examples/CMakeFiles/hello_server.dir/hello_server.cc.o: examples/CMakeFiles/hello_server.dir/flags.make
examples/CMakeFiles/hello_server.dir/hello_server.cc.o: ../examples/hello_server.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/incu/work/pistache/pistache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/hello_server.dir/hello_server.cc.o"
	cd /home/incu/work/pistache/pistache/build/examples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hello_server.dir/hello_server.cc.o -c /home/incu/work/pistache/pistache/examples/hello_server.cc

examples/CMakeFiles/hello_server.dir/hello_server.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_server.dir/hello_server.cc.i"
	cd /home/incu/work/pistache/pistache/build/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/incu/work/pistache/pistache/examples/hello_server.cc > CMakeFiles/hello_server.dir/hello_server.cc.i

examples/CMakeFiles/hello_server.dir/hello_server.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_server.dir/hello_server.cc.s"
	cd /home/incu/work/pistache/pistache/build/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/incu/work/pistache/pistache/examples/hello_server.cc -o CMakeFiles/hello_server.dir/hello_server.cc.s

examples/CMakeFiles/hello_server.dir/hello_server.cc.o.requires:

.PHONY : examples/CMakeFiles/hello_server.dir/hello_server.cc.o.requires

examples/CMakeFiles/hello_server.dir/hello_server.cc.o.provides: examples/CMakeFiles/hello_server.dir/hello_server.cc.o.requires
	$(MAKE) -f examples/CMakeFiles/hello_server.dir/build.make examples/CMakeFiles/hello_server.dir/hello_server.cc.o.provides.build
.PHONY : examples/CMakeFiles/hello_server.dir/hello_server.cc.o.provides

examples/CMakeFiles/hello_server.dir/hello_server.cc.o.provides.build: examples/CMakeFiles/hello_server.dir/hello_server.cc.o


# Object files for target hello_server
hello_server_OBJECTS = \
"CMakeFiles/hello_server.dir/hello_server.cc.o"

# External object files for target hello_server
hello_server_EXTERNAL_OBJECTS =

examples/hello_server: examples/CMakeFiles/hello_server.dir/hello_server.cc.o
examples/hello_server: examples/CMakeFiles/hello_server.dir/build.make
examples/hello_server: src/libnet_static.a
examples/hello_server: examples/CMakeFiles/hello_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/incu/work/pistache/pistache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hello_server"
	cd /home/incu/work/pistache/pistache/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/hello_server.dir/build: examples/hello_server

.PHONY : examples/CMakeFiles/hello_server.dir/build

examples/CMakeFiles/hello_server.dir/requires: examples/CMakeFiles/hello_server.dir/hello_server.cc.o.requires

.PHONY : examples/CMakeFiles/hello_server.dir/requires

examples/CMakeFiles/hello_server.dir/clean:
	cd /home/incu/work/pistache/pistache/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/hello_server.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/hello_server.dir/clean

examples/CMakeFiles/hello_server.dir/depend:
	cd /home/incu/work/pistache/pistache/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/incu/work/pistache/pistache /home/incu/work/pistache/pistache/examples /home/incu/work/pistache/pistache/build /home/incu/work/pistache/pistache/build/examples /home/incu/work/pistache/pistache/build/examples/CMakeFiles/hello_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/hello_server.dir/depend
