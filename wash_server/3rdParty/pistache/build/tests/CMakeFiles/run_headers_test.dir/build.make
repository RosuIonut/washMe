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
include tests/CMakeFiles/run_headers_test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/run_headers_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/run_headers_test.dir/flags.make

tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o: tests/CMakeFiles/run_headers_test.dir/flags.make
tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o: ../tests/headers_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/incu/work/pistache/pistache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o"
	cd /home/incu/work/pistache/pistache/build/tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_headers_test.dir/headers_test.cc.o -c /home/incu/work/pistache/pistache/tests/headers_test.cc

tests/CMakeFiles/run_headers_test.dir/headers_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_headers_test.dir/headers_test.cc.i"
	cd /home/incu/work/pistache/pistache/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/incu/work/pistache/pistache/tests/headers_test.cc > CMakeFiles/run_headers_test.dir/headers_test.cc.i

tests/CMakeFiles/run_headers_test.dir/headers_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_headers_test.dir/headers_test.cc.s"
	cd /home/incu/work/pistache/pistache/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/incu/work/pistache/pistache/tests/headers_test.cc -o CMakeFiles/run_headers_test.dir/headers_test.cc.s

tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o.requires:

.PHONY : tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o.requires

tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o.provides: tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o.requires
	$(MAKE) -f tests/CMakeFiles/run_headers_test.dir/build.make tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o.provides.build
.PHONY : tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o.provides

tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o.provides.build: tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o


# Object files for target run_headers_test
run_headers_test_OBJECTS = \
"CMakeFiles/run_headers_test.dir/headers_test.cc.o"

# External object files for target run_headers_test
run_headers_test_EXTERNAL_OBJECTS =

tests/run_headers_test: tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o
tests/run_headers_test: tests/CMakeFiles/run_headers_test.dir/build.make
tests/run_headers_test: googletest-release-1.7.0/libgtest.a
tests/run_headers_test: googletest-release-1.7.0/libgtest_main.a
tests/run_headers_test: src/libnet_static.a
tests/run_headers_test: googletest-release-1.7.0/libgtest.a
tests/run_headers_test: tests/CMakeFiles/run_headers_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/incu/work/pistache/pistache/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable run_headers_test"
	cd /home/incu/work/pistache/pistache/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_headers_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/run_headers_test.dir/build: tests/run_headers_test

.PHONY : tests/CMakeFiles/run_headers_test.dir/build

tests/CMakeFiles/run_headers_test.dir/requires: tests/CMakeFiles/run_headers_test.dir/headers_test.cc.o.requires

.PHONY : tests/CMakeFiles/run_headers_test.dir/requires

tests/CMakeFiles/run_headers_test.dir/clean:
	cd /home/incu/work/pistache/pistache/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/run_headers_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/run_headers_test.dir/clean

tests/CMakeFiles/run_headers_test.dir/depend:
	cd /home/incu/work/pistache/pistache/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/incu/work/pistache/pistache /home/incu/work/pistache/pistache/tests /home/incu/work/pistache/pistache/build /home/incu/work/pistache/pistache/build/tests /home/incu/work/pistache/pistache/build/tests/CMakeFiles/run_headers_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/run_headers_test.dir/depend

