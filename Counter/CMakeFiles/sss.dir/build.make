# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gmestre/Homomorphic-Vote-Tally/Counter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gmestre/Homomorphic-Vote-Tally/Counter

# Include any dependencies generated for this target.
include CMakeFiles/sss.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sss.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sss.dir/flags.make

CMakeFiles/sss.dir/sss.c.o: CMakeFiles/sss.dir/flags.make
CMakeFiles/sss.dir/sss.c.o: sss.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gmestre/Homomorphic-Vote-Tally/Counter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sss.dir/sss.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sss.dir/sss.c.o   -c /home/gmestre/Homomorphic-Vote-Tally/Counter/sss.c

CMakeFiles/sss.dir/sss.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sss.dir/sss.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gmestre/Homomorphic-Vote-Tally/Counter/sss.c > CMakeFiles/sss.dir/sss.c.i

CMakeFiles/sss.dir/sss.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sss.dir/sss.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gmestre/Homomorphic-Vote-Tally/Counter/sss.c -o CMakeFiles/sss.dir/sss.c.s

# Object files for target sss
sss_OBJECTS = \
"CMakeFiles/sss.dir/sss.c.o"

# External object files for target sss
sss_EXTERNAL_OBJECTS =

libsss.a: CMakeFiles/sss.dir/sss.c.o
libsss.a: CMakeFiles/sss.dir/build.make
libsss.a: CMakeFiles/sss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gmestre/Homomorphic-Vote-Tally/Counter/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libsss.a"
	$(CMAKE_COMMAND) -P CMakeFiles/sss.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sss.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sss.dir/build: libsss.a

.PHONY : CMakeFiles/sss.dir/build

CMakeFiles/sss.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sss.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sss.dir/clean

CMakeFiles/sss.dir/depend:
	cd /home/gmestre/Homomorphic-Vote-Tally/Counter && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gmestre/Homomorphic-Vote-Tally/Counter /home/gmestre/Homomorphic-Vote-Tally/Counter /home/gmestre/Homomorphic-Vote-Tally/Counter /home/gmestre/Homomorphic-Vote-Tally/Counter /home/gmestre/Homomorphic-Vote-Tally/Counter/CMakeFiles/sss.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sss.dir/depend
