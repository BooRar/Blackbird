# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ubuntu/JonoBird

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/JonoBird/build

# Include any dependencies generated for this target.
include CMakeFiles/blackbird_unity.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/blackbird_unity.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/blackbird_unity.dir/flags.make

cotire/blackbird_CXX_unity.cxx: blackbird_CXX_cotire.cmake
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/JonoBird/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating CXX unity source cotire/blackbird_CXX_unity.cxx"
	cd /home/ubuntu/JonoBird && /usr/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/ubuntu/JonoBird/cmake/Modules/cotire.cmake unity /home/ubuntu/JonoBird/build/blackbird_CXX_cotire.cmake /home/ubuntu/JonoBird/build/cotire/blackbird_CXX_unity.cxx

CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o: CMakeFiles/blackbird_unity.dir/flags.make
CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o: cotire/blackbird_CXX_unity.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/JonoBird/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o -c /home/ubuntu/JonoBird/build/cotire/blackbird_CXX_unity.cxx

CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/JonoBird/build/cotire/blackbird_CXX_unity.cxx > CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.i

CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/JonoBird/build/cotire/blackbird_CXX_unity.cxx -o CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.s

CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o.requires:

.PHONY : CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o.requires

CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o.provides: CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o.requires
	$(MAKE) -f CMakeFiles/blackbird_unity.dir/build.make CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o.provides.build
.PHONY : CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o.provides

CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o.provides.build: CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o


# Object files for target blackbird_unity
blackbird_unity_OBJECTS = \
"CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o"

# External object files for target blackbird_unity
blackbird_unity_EXTERNAL_OBJECTS =

blackbird: CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o
blackbird: CMakeFiles/blackbird_unity.dir/build.make
blackbird: /usr/lib/x86_64-linux-gnu/libcurl.so
blackbird: /usr/lib/x86_64-linux-gnu/libjansson.so
blackbird: /usr/lib/x86_64-linux-gnu/libssl.so
blackbird: /usr/lib/x86_64-linux-gnu/libcrypto.so
blackbird: /usr/lib/x86_64-linux-gnu/libsqlite3.so
blackbird: CMakeFiles/blackbird_unity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/JonoBird/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable blackbird"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/blackbird_unity.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/blackbird_unity.dir/build: blackbird

.PHONY : CMakeFiles/blackbird_unity.dir/build

CMakeFiles/blackbird_unity.dir/requires: CMakeFiles/blackbird_unity.dir/cotire/blackbird_CXX_unity.cxx.o.requires

.PHONY : CMakeFiles/blackbird_unity.dir/requires

CMakeFiles/blackbird_unity.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/blackbird_unity.dir/cmake_clean.cmake
.PHONY : CMakeFiles/blackbird_unity.dir/clean

CMakeFiles/blackbird_unity.dir/depend: cotire/blackbird_CXX_unity.cxx
	cd /home/ubuntu/JonoBird/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/JonoBird /home/ubuntu/JonoBird /home/ubuntu/JonoBird/build /home/ubuntu/JonoBird/build /home/ubuntu/JonoBird/build/CMakeFiles/blackbird_unity.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/blackbird_unity.dir/depend

