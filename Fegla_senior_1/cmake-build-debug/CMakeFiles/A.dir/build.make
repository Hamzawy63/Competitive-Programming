# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "F:\CP\Competitive Programming Repo\Fegla_senior_1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/A.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A.dir/flags.make

CMakeFiles/A.dir/A.cpp.obj: CMakeFiles/A.dir/flags.make
CMakeFiles/A.dir/A.cpp.obj: ../A.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A.dir/A.cpp.obj"
	C:\PROGRA~2\MINGW-~1\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\A.dir\A.cpp.obj -c "F:\CP\Competitive Programming Repo\Fegla_senior_1\A.cpp"

CMakeFiles/A.dir/A.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A.dir/A.cpp.i"
	C:\PROGRA~2\MINGW-~1\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\CP\Competitive Programming Repo\Fegla_senior_1\A.cpp" > CMakeFiles\A.dir\A.cpp.i

CMakeFiles/A.dir/A.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A.dir/A.cpp.s"
	C:\PROGRA~2\MINGW-~1\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "F:\CP\Competitive Programming Repo\Fegla_senior_1\A.cpp" -o CMakeFiles\A.dir\A.cpp.s

# Object files for target A
A_OBJECTS = \
"CMakeFiles/A.dir/A.cpp.obj"

# External object files for target A
A_EXTERNAL_OBJECTS =

A.exe: CMakeFiles/A.dir/A.cpp.obj
A.exe: CMakeFiles/A.dir/build.make
A.exe: CMakeFiles/A.dir/linklibs.rsp
A.exe: CMakeFiles/A.dir/objects1.rsp
A.exe: CMakeFiles/A.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\A.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A.dir/build: A.exe

.PHONY : CMakeFiles/A.dir/build

CMakeFiles/A.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\A.dir\cmake_clean.cmake
.PHONY : CMakeFiles/A.dir/clean

CMakeFiles/A.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\CP\Competitive Programming Repo\Fegla_senior_1" "F:\CP\Competitive Programming Repo\Fegla_senior_1" "F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug" "F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug" "F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug\CMakeFiles\A.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/A.dir/depend

