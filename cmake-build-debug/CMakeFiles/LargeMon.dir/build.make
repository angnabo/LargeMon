# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/angelica/opt/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/angelica/opt/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/angelica/CLionProjects/LargeMon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/angelica/CLionProjects/LargeMon/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LargeMon.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LargeMon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LargeMon.dir/flags.make

CMakeFiles/LargeMon.dir/src/main.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/CLionProjects/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LargeMon.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/main.cpp.o -c /home/angelica/CLionProjects/LargeMon/src/main.cpp

CMakeFiles/LargeMon.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/CLionProjects/LargeMon/src/main.cpp > CMakeFiles/LargeMon.dir/src/main.cpp.i

CMakeFiles/LargeMon.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/CLionProjects/LargeMon/src/main.cpp -o CMakeFiles/LargeMon.dir/src/main.cpp.s

CMakeFiles/LargeMon.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/main.cpp.o.requires

CMakeFiles/LargeMon.dir/src/main.cpp.o.provides: CMakeFiles/LargeMon.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/main.cpp.o.provides

CMakeFiles/LargeMon.dir/src/main.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/main.cpp.o


CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o: ../src/LargeMon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/CLionProjects/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o -c /home/angelica/CLionProjects/LargeMon/src/LargeMon.cpp

CMakeFiles/LargeMon.dir/src/LargeMon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/LargeMon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/CLionProjects/LargeMon/src/LargeMon.cpp > CMakeFiles/LargeMon.dir/src/LargeMon.cpp.i

CMakeFiles/LargeMon.dir/src/LargeMon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/LargeMon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/CLionProjects/LargeMon/src/LargeMon.cpp -o CMakeFiles/LargeMon.dir/src/LargeMon.cpp.s

CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o.requires

CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o.provides: CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o.provides

CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o


CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o: ../src/LargeMonGenerator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/CLionProjects/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o -c /home/angelica/CLionProjects/LargeMon/src/LargeMonGenerator.cpp

CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/CLionProjects/LargeMon/src/LargeMonGenerator.cpp > CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.i

CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/CLionProjects/LargeMon/src/LargeMonGenerator.cpp -o CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.s

CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o.requires

CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o.provides: CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o.provides

CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o


CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o: ../src/BattleInstance.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/CLionProjects/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o -c /home/angelica/CLionProjects/LargeMon/src/BattleInstance.cpp

CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/CLionProjects/LargeMon/src/BattleInstance.cpp > CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.i

CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/CLionProjects/LargeMon/src/BattleInstance.cpp -o CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.s

CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o.requires

CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o.provides: CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o.provides

CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o


CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o: ../src/DescriptGen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/CLionProjects/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o -c /home/angelica/CLionProjects/LargeMon/src/DescriptGen.cpp

CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/CLionProjects/LargeMon/src/DescriptGen.cpp > CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.i

CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/CLionProjects/LargeMon/src/DescriptGen.cpp -o CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.s

CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o.requires

CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o.provides: CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o.provides

CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o


# Object files for target LargeMon
LargeMon_OBJECTS = \
"CMakeFiles/LargeMon.dir/src/main.cpp.o" \
"CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o" \
"CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o" \
"CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o" \
"CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o"

# External object files for target LargeMon
LargeMon_EXTERNAL_OBJECTS =

LargeMon: CMakeFiles/LargeMon.dir/src/main.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/build.make
LargeMon: CMakeFiles/LargeMon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/angelica/CLionProjects/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable LargeMon"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LargeMon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LargeMon.dir/build: LargeMon

.PHONY : CMakeFiles/LargeMon.dir/build

CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/main.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/LargeMon.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/LargeMonGenerator.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/BattleInstance.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/DescriptGen.cpp.o.requires

.PHONY : CMakeFiles/LargeMon.dir/requires

CMakeFiles/LargeMon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LargeMon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LargeMon.dir/clean

CMakeFiles/LargeMon.dir/depend:
	cd /home/angelica/CLionProjects/LargeMon/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/angelica/CLionProjects/LargeMon /home/angelica/CLionProjects/LargeMon /home/angelica/CLionProjects/LargeMon/cmake-build-debug /home/angelica/CLionProjects/LargeMon/cmake-build-debug /home/angelica/CLionProjects/LargeMon/cmake-build-debug/CMakeFiles/LargeMon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LargeMon.dir/depend

