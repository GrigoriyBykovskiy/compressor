# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/grigoriy/Загрузки/CLion-2019.3/clion-2019.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/grigoriy/Загрузки/CLion-2019.3/clion-2019.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/grigoriy/CLionProjects/compressor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/grigoriy/CLionProjects/compressor/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/compressor_tmp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/compressor_tmp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/compressor_tmp.dir/flags.make

CMakeFiles/compressor_tmp.dir/HuffmanCode.c.o: CMakeFiles/compressor_tmp.dir/flags.make
CMakeFiles/compressor_tmp.dir/HuffmanCode.c.o: ../HuffmanCode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grigoriy/CLionProjects/compressor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/compressor_tmp.dir/HuffmanCode.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/compressor_tmp.dir/HuffmanCode.c.o   -c /home/grigoriy/CLionProjects/compressor/HuffmanCode.c

CMakeFiles/compressor_tmp.dir/HuffmanCode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/compressor_tmp.dir/HuffmanCode.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grigoriy/CLionProjects/compressor/HuffmanCode.c > CMakeFiles/compressor_tmp.dir/HuffmanCode.c.i

CMakeFiles/compressor_tmp.dir/HuffmanCode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/compressor_tmp.dir/HuffmanCode.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grigoriy/CLionProjects/compressor/HuffmanCode.c -o CMakeFiles/compressor_tmp.dir/HuffmanCode.c.s

CMakeFiles/compressor_tmp.dir/HUFFMAN.c.o: CMakeFiles/compressor_tmp.dir/flags.make
CMakeFiles/compressor_tmp.dir/HUFFMAN.c.o: ../HUFFMAN.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grigoriy/CLionProjects/compressor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/compressor_tmp.dir/HUFFMAN.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/compressor_tmp.dir/HUFFMAN.c.o   -c /home/grigoriy/CLionProjects/compressor/HUFFMAN.c

CMakeFiles/compressor_tmp.dir/HUFFMAN.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/compressor_tmp.dir/HUFFMAN.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grigoriy/CLionProjects/compressor/HUFFMAN.c > CMakeFiles/compressor_tmp.dir/HUFFMAN.c.i

CMakeFiles/compressor_tmp.dir/HUFFMAN.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/compressor_tmp.dir/HUFFMAN.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grigoriy/CLionProjects/compressor/HUFFMAN.c -o CMakeFiles/compressor_tmp.dir/HUFFMAN.c.s

# Object files for target compressor_tmp
compressor_tmp_OBJECTS = \
"CMakeFiles/compressor_tmp.dir/HuffmanCode.c.o" \
"CMakeFiles/compressor_tmp.dir/HUFFMAN.c.o"

# External object files for target compressor_tmp
compressor_tmp_EXTERNAL_OBJECTS =

compressor_tmp: CMakeFiles/compressor_tmp.dir/HuffmanCode.c.o
compressor_tmp: CMakeFiles/compressor_tmp.dir/HUFFMAN.c.o
compressor_tmp: CMakeFiles/compressor_tmp.dir/build.make
compressor_tmp: CMakeFiles/compressor_tmp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grigoriy/CLionProjects/compressor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable compressor_tmp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compressor_tmp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/compressor_tmp.dir/build: compressor_tmp

.PHONY : CMakeFiles/compressor_tmp.dir/build

CMakeFiles/compressor_tmp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/compressor_tmp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/compressor_tmp.dir/clean

CMakeFiles/compressor_tmp.dir/depend:
	cd /home/grigoriy/CLionProjects/compressor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grigoriy/CLionProjects/compressor /home/grigoriy/CLionProjects/compressor /home/grigoriy/CLionProjects/compressor/cmake-build-debug /home/grigoriy/CLionProjects/compressor/cmake-build-debug /home/grigoriy/CLionProjects/compressor/cmake-build-debug/CMakeFiles/compressor_tmp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/compressor_tmp.dir/depend

