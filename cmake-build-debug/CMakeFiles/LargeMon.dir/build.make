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
CMAKE_COMMAND = /opt/clion-2017.2.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/angelica/Development/CLion/LargeMon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/angelica/Development/CLion/LargeMon/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LargeMon.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LargeMon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LargeMon.dir/flags.make

CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o: ../src/cpp/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o -c /home/angelica/Development/CLion/LargeMon/src/cpp/main.cpp

CMakeFiles/LargeMon.dir/src/cpp/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/cpp/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/Development/CLion/LargeMon/src/cpp/main.cpp > CMakeFiles/LargeMon.dir/src/cpp/main.cpp.i

CMakeFiles/LargeMon.dir/src/cpp/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/cpp/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/Development/CLion/LargeMon/src/cpp/main.cpp -o CMakeFiles/LargeMon.dir/src/cpp/main.cpp.s

CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o.requires

CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o.provides: CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o.provides

CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o


CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o: ../src/cpp/LargeMon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o -c /home/angelica/Development/CLion/LargeMon/src/cpp/LargeMon.cpp

CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/Development/CLion/LargeMon/src/cpp/LargeMon.cpp > CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.i

CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/Development/CLion/LargeMon/src/cpp/LargeMon.cpp -o CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.s

CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o.requires

CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o.provides: CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o.provides

CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o


CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o: ../src/cpp/LargeMonGenerator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o -c /home/angelica/Development/CLion/LargeMon/src/cpp/LargeMonGenerator.cpp

CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/Development/CLion/LargeMon/src/cpp/LargeMonGenerator.cpp > CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.i

CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/Development/CLion/LargeMon/src/cpp/LargeMonGenerator.cpp -o CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.s

CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o.requires

CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o.provides: CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o.provides

CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o


CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o: ../src/cpp/BattleInstance.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o -c /home/angelica/Development/CLion/LargeMon/src/cpp/BattleInstance.cpp

CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/Development/CLion/LargeMon/src/cpp/BattleInstance.cpp > CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.i

CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/Development/CLion/LargeMon/src/cpp/BattleInstance.cpp -o CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.s

CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o.requires

CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o.provides: CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o.provides

CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o


CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o: ../src/cpp/DescriptGen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o -c /home/angelica/Development/CLion/LargeMon/src/cpp/DescriptGen.cpp

CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/Development/CLion/LargeMon/src/cpp/DescriptGen.cpp > CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.i

CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/Development/CLion/LargeMon/src/cpp/DescriptGen.cpp -o CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.s

CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o.requires

CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o.provides: CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o.provides

CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o


CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o: ../src/cpp/Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o -c /home/angelica/Development/CLion/LargeMon/src/cpp/Controller.cpp

CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/Development/CLion/LargeMon/src/cpp/Controller.cpp > CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.i

CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/Development/CLion/LargeMon/src/cpp/Controller.cpp -o CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.s

CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o.requires

CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o.provides: CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o.provides

CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o


CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o: ../src/cpp/WaterLM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o -c /home/angelica/Development/CLion/LargeMon/src/cpp/WaterLM.cpp

CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/Development/CLion/LargeMon/src/cpp/WaterLM.cpp > CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.i

CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/Development/CLion/LargeMon/src/cpp/WaterLM.cpp -o CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.s

CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o.requires

CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o.provides: CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o.provides

CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o


CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o: ../src/cpp/FireLM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o -c /home/angelica/Development/CLion/LargeMon/src/cpp/FireLM.cpp

CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/Development/CLion/LargeMon/src/cpp/FireLM.cpp > CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.i

CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/Development/CLion/LargeMon/src/cpp/FireLM.cpp -o CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.s

CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o.requires

CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o.provides: CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o.provides

CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o


CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o: ../src/cpp/WoodLM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o -c /home/angelica/Development/CLion/LargeMon/src/cpp/WoodLM.cpp

CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/Development/CLion/LargeMon/src/cpp/WoodLM.cpp > CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.i

CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/Development/CLion/LargeMon/src/cpp/WoodLM.cpp -o CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.s

CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o.requires

CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o.provides: CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o.provides

CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o


CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o: ../src/cpp/Observer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o -c /home/angelica/Development/CLion/LargeMon/src/cpp/Observer.cpp

CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/Development/CLion/LargeMon/src/cpp/Observer.cpp > CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.i

CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/Development/CLion/LargeMon/src/cpp/Observer.cpp -o CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.s

CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o.requires

CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o.provides: CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o.provides

CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o


CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o: CMakeFiles/LargeMon.dir/flags.make
CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o: ../src/cpp/ViewObserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o -c /home/angelica/Development/CLion/LargeMon/src/cpp/ViewObserver.cpp

CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/angelica/Development/CLion/LargeMon/src/cpp/ViewObserver.cpp > CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.i

CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/angelica/Development/CLion/LargeMon/src/cpp/ViewObserver.cpp -o CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.s

CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o.requires:

.PHONY : CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o.requires

CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o.provides: CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o.requires
	$(MAKE) -f CMakeFiles/LargeMon.dir/build.make CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o.provides.build
.PHONY : CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o.provides

CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o.provides.build: CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o


# Object files for target LargeMon
LargeMon_OBJECTS = \
"CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o" \
"CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o" \
"CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o" \
"CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o" \
"CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o" \
"CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o" \
"CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o" \
"CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o" \
"CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o" \
"CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o" \
"CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o"

# External object files for target LargeMon
LargeMon_EXTERNAL_OBJECTS =

LargeMon: CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o
LargeMon: CMakeFiles/LargeMon.dir/build.make
LargeMon: CMakeFiles/LargeMon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable LargeMon"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LargeMon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LargeMon.dir/build: LargeMon

.PHONY : CMakeFiles/LargeMon.dir/build

CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/cpp/main.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/cpp/LargeMon.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/cpp/LargeMonGenerator.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/cpp/BattleInstance.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/cpp/DescriptGen.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/cpp/Controller.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/cpp/WaterLM.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/cpp/FireLM.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/cpp/WoodLM.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/cpp/Observer.cpp.o.requires
CMakeFiles/LargeMon.dir/requires: CMakeFiles/LargeMon.dir/src/cpp/ViewObserver.cpp.o.requires

.PHONY : CMakeFiles/LargeMon.dir/requires

CMakeFiles/LargeMon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LargeMon.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LargeMon.dir/clean

CMakeFiles/LargeMon.dir/depend:
	cd /home/angelica/Development/CLion/LargeMon/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/angelica/Development/CLion/LargeMon /home/angelica/Development/CLion/LargeMon /home/angelica/Development/CLion/LargeMon/cmake-build-debug /home/angelica/Development/CLion/LargeMon/cmake-build-debug /home/angelica/Development/CLion/LargeMon/cmake-build-debug/CMakeFiles/LargeMon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LargeMon.dir/depend

