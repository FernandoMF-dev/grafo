# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/basis/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/basis/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/basis/Documentos/Grafo/grafo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/basis/Documentos/Grafo/grafo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/grafo.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/grafo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/grafo.dir/flags.make

CMakeFiles/grafo.dir/main.c.o: CMakeFiles/grafo.dir/flags.make
CMakeFiles/grafo.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/basis/Documentos/Grafo/grafo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/grafo.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/grafo.dir/main.c.o -c /home/basis/Documentos/Grafo/grafo/main.c

CMakeFiles/grafo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/grafo.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/basis/Documentos/Grafo/grafo/main.c > CMakeFiles/grafo.dir/main.c.i

CMakeFiles/grafo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/grafo.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/basis/Documentos/Grafo/grafo/main.c -o CMakeFiles/grafo.dir/main.c.s

# Object files for target grafo
grafo_OBJECTS = \
"CMakeFiles/grafo.dir/main.c.o"

# External object files for target grafo
grafo_EXTERNAL_OBJECTS =

grafo: CMakeFiles/grafo.dir/main.c.o
grafo: CMakeFiles/grafo.dir/build.make
grafo: CMakeFiles/grafo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/basis/Documentos/Grafo/grafo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable grafo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/grafo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/grafo.dir/build: grafo
.PHONY : CMakeFiles/grafo.dir/build

CMakeFiles/grafo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/grafo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/grafo.dir/clean

CMakeFiles/grafo.dir/depend:
	cd /home/basis/Documentos/Grafo/grafo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/basis/Documentos/Grafo/grafo /home/basis/Documentos/Grafo/grafo /home/basis/Documentos/Grafo/grafo/cmake-build-debug /home/basis/Documentos/Grafo/grafo/cmake-build-debug /home/basis/Documentos/Grafo/grafo/cmake-build-debug/CMakeFiles/grafo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/grafo.dir/depend

