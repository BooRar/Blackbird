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

# Utility rule file for blackbird_pch.

# Include the progress variables for this target.
include CMakeFiles/blackbird_pch.dir/progress.make

CMakeFiles/blackbird_pch: cotire/blackbird_CXX_prefix.hxx.gch


cotire/blackbird_CXX_prefix.hxx.gch: cotire/blackbird_CXX_prefix.hxx
cotire/blackbird_CXX_prefix.hxx.gch: /usr/bin/c++
cotire/blackbird_CXX_prefix.hxx.gch: cotire/blackbird_CXX_prefix.hxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/JonoBird/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX precompiled header cotire/blackbird_CXX_prefix.hxx.gch"
	cd /home/ubuntu/JonoBird && /usr/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/ubuntu/JonoBird/cmake/Modules/cotire.cmake precompile /home/ubuntu/JonoBird/build/blackbird_CXX_cotire.cmake /home/ubuntu/JonoBird/build/cotire/blackbird_CXX_prefix.hxx /home/ubuntu/JonoBird/build/cotire/blackbird_CXX_prefix.hxx.gch /home/ubuntu/JonoBird/src/bitcoin.cpp

cotire/blackbird_CXX_prefix.hxx: cotire/blackbird_CXX_prefix.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/JonoBird/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating CXX prefix header cotire/blackbird_CXX_prefix.hxx"
	/usr/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/ubuntu/JonoBird/cmake/Modules/cotire.cmake combine /home/ubuntu/JonoBird/build/blackbird_CXX_cotire.cmake /home/ubuntu/JonoBird/build/cotire/blackbird_CXX_prefix.hxx /home/ubuntu/JonoBird/build/cotire/blackbird_CXX_prefix.cxx

cotire/blackbird_CXX_prefix.cxx: cotire/blackbird_CXX_unity.cxx
cotire/blackbird_CXX_prefix.cxx: /usr/bin/c++
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/JonoBird/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating CXX prefix source cotire/blackbird_CXX_prefix.cxx"
	cd /home/ubuntu/JonoBird && /usr/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/ubuntu/JonoBird/cmake/Modules/cotire.cmake prefix /home/ubuntu/JonoBird/build/blackbird_CXX_cotire.cmake /home/ubuntu/JonoBird/build/cotire/blackbird_CXX_prefix.cxx /home/ubuntu/JonoBird/build/cotire/blackbird_CXX_unity.cxx

cotire/blackbird_CXX_prefix.cxx.log: cotire/blackbird_CXX_prefix.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate cotire/blackbird_CXX_prefix.cxx.log

cotire/blackbird_CXX_unity.cxx: blackbird_CXX_cotire.cmake
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/JonoBird/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating CXX unity source cotire/blackbird_CXX_unity.cxx"
	cd /home/ubuntu/JonoBird && /usr/bin/cmake -DCOTIRE_BUILD_TYPE:STRING=Release -DCOTIRE_VERBOSE:BOOL=$(VERBOSE) -P /home/ubuntu/JonoBird/cmake/Modules/cotire.cmake unity /home/ubuntu/JonoBird/build/blackbird_CXX_cotire.cmake /home/ubuntu/JonoBird/build/cotire/blackbird_CXX_unity.cxx

blackbird_pch: CMakeFiles/blackbird_pch
blackbird_pch: cotire/blackbird_CXX_prefix.hxx.gch
blackbird_pch: cotire/blackbird_CXX_prefix.hxx
blackbird_pch: cotire/blackbird_CXX_prefix.cxx
blackbird_pch: cotire/blackbird_CXX_prefix.cxx.log
blackbird_pch: cotire/blackbird_CXX_unity.cxx
blackbird_pch: CMakeFiles/blackbird_pch.dir/build.make

.PHONY : blackbird_pch

# Rule to build all files generated by this target.
CMakeFiles/blackbird_pch.dir/build: blackbird_pch

.PHONY : CMakeFiles/blackbird_pch.dir/build

CMakeFiles/blackbird_pch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/blackbird_pch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/blackbird_pch.dir/clean

CMakeFiles/blackbird_pch.dir/depend:
	cd /home/ubuntu/JonoBird/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/JonoBird /home/ubuntu/JonoBird /home/ubuntu/JonoBird/build /home/ubuntu/JonoBird/build /home/ubuntu/JonoBird/build/CMakeFiles/blackbird_pch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/blackbird_pch.dir/depend

