# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/jhon/dev/algorithmic_trading_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jhon/dev/algorithmic_trading_engine/cmake

# Include any dependencies generated for this target.
include utils/CMakeFiles/utils.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include utils/CMakeFiles/utils.dir/compiler_depend.make

# Include the progress variables for this target.
include utils/CMakeFiles/utils.dir/progress.make

# Include the compile flags for this target's objects.
include utils/CMakeFiles/utils.dir/flags.make

utils/CMakeFiles/utils.dir/src/logging.cpp.o: utils/CMakeFiles/utils.dir/flags.make
utils/CMakeFiles/utils.dir/src/logging.cpp.o: /home/jhon/dev/algorithmic_trading_engine/utils/src/logging.cpp
utils/CMakeFiles/utils.dir/src/logging.cpp.o: utils/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jhon/dev/algorithmic_trading_engine/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object utils/CMakeFiles/utils.dir/src/logging.cpp.o"
	cd /home/jhon/dev/algorithmic_trading_engine/cmake/utils && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT utils/CMakeFiles/utils.dir/src/logging.cpp.o -MF CMakeFiles/utils.dir/src/logging.cpp.o.d -o CMakeFiles/utils.dir/src/logging.cpp.o -c /home/jhon/dev/algorithmic_trading_engine/utils/src/logging.cpp

utils/CMakeFiles/utils.dir/src/logging.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/utils.dir/src/logging.cpp.i"
	cd /home/jhon/dev/algorithmic_trading_engine/cmake/utils && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jhon/dev/algorithmic_trading_engine/utils/src/logging.cpp > CMakeFiles/utils.dir/src/logging.cpp.i

utils/CMakeFiles/utils.dir/src/logging.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/utils.dir/src/logging.cpp.s"
	cd /home/jhon/dev/algorithmic_trading_engine/cmake/utils && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jhon/dev/algorithmic_trading_engine/utils/src/logging.cpp -o CMakeFiles/utils.dir/src/logging.cpp.s

# Object files for target utils
utils_OBJECTS = \
"CMakeFiles/utils.dir/src/logging.cpp.o"

# External object files for target utils
utils_EXTERNAL_OBJECTS =

utils/libutils.a: utils/CMakeFiles/utils.dir/src/logging.cpp.o
utils/libutils.a: utils/CMakeFiles/utils.dir/build.make
utils/libutils.a: utils/CMakeFiles/utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jhon/dev/algorithmic_trading_engine/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libutils.a"
	cd /home/jhon/dev/algorithmic_trading_engine/cmake/utils && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean_target.cmake
	cd /home/jhon/dev/algorithmic_trading_engine/cmake/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
utils/CMakeFiles/utils.dir/build: utils/libutils.a
.PHONY : utils/CMakeFiles/utils.dir/build

utils/CMakeFiles/utils.dir/clean:
	cd /home/jhon/dev/algorithmic_trading_engine/cmake/utils && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean.cmake
.PHONY : utils/CMakeFiles/utils.dir/clean

utils/CMakeFiles/utils.dir/depend:
	cd /home/jhon/dev/algorithmic_trading_engine/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jhon/dev/algorithmic_trading_engine /home/jhon/dev/algorithmic_trading_engine/utils /home/jhon/dev/algorithmic_trading_engine/cmake /home/jhon/dev/algorithmic_trading_engine/cmake/utils /home/jhon/dev/algorithmic_trading_engine/cmake/utils/CMakeFiles/utils.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : utils/CMakeFiles/utils.dir/depend

