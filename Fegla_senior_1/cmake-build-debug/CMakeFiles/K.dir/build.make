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
include CMakeFiles/K.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/K.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/K.dir/flags.make

CMakeFiles/K.dir/K.cpp.obj: CMakeFiles/K.dir/flags.make
CMakeFiles/K.dir/K.cpp.obj: ../K.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/K.dir/K.cpp.obj"
	C:\PROGRA~2\MINGW-~1\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\K.dir\K.cpp.obj -c "F:\CP\Competitive Programming Repo\Fegla_senior_1\K.cpp"

CMakeFiles/K.dir/K.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/K.dir/K.cpp.i"
	C:\PROGRA~2\MINGW-~1\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\CP\Competitive Programming Repo\Fegla_senior_1\K.cpp" > CMakeFiles\K.dir\K.cpp.i

CMakeFiles/K.dir/K.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/K.dir/K.cpp.s"
	C:\PROGRA~2\MINGW-~1\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "F:\CP\Competitive Programming Repo\Fegla_senior_1\K.cpp" -o CMakeFiles\K.dir\K.cpp.s

# Object files for target K
K_OBJECTS = \
"CMakeFiles/K.dir/K.cpp.obj"

# External object files for target K
K_EXTERNAL_OBJECTS =

K.exe: CMakeFiles/K.dir/K.cpp.obj
K.exe: CMakeFiles/K.dir/build.make
K.exe: CMakeFiles/K.dir/linklibs.rsp
K.exe: CMakeFiles/K.dir/objects1.rsp
K.exe: CMakeFiles/K.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable K.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\K.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/K.dir/build: K.exe

.PHONY : CMakeFiles/K.dir/build

CMakeFiles/K.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\K.dir\cmake_clean.cmake
.PHONY : CMakeFiles/K.dir/clean

CMakeFiles/K.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\CP\Competitive Programming Repo\Fegla_senior_1" "F:\CP\Competitive Programming Repo\Fegla_senior_1" "F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug" "F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug" "F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug\CMakeFiles\K.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/K.dir/depend

