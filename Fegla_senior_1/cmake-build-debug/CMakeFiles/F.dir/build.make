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
include CMakeFiles/F.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/F.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/F.dir/flags.make

CMakeFiles/F.dir/F.cpp.obj: CMakeFiles/F.dir/flags.make
CMakeFiles/F.dir/F.cpp.obj: ../F.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/F.dir/F.cpp.obj"
	C:\PROGRA~2\MINGW-~1\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\F.dir\F.cpp.obj -c "F:\CP\Competitive Programming Repo\Fegla_senior_1\F.cpp"

CMakeFiles/F.dir/F.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/F.dir/F.cpp.i"
	C:\PROGRA~2\MINGW-~1\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\CP\Competitive Programming Repo\Fegla_senior_1\F.cpp" > CMakeFiles\F.dir\F.cpp.i

CMakeFiles/F.dir/F.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/F.dir/F.cpp.s"
	C:\PROGRA~2\MINGW-~1\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "F:\CP\Competitive Programming Repo\Fegla_senior_1\F.cpp" -o CMakeFiles\F.dir\F.cpp.s

# Object files for target F
F_OBJECTS = \
"CMakeFiles/F.dir/F.cpp.obj"

# External object files for target F
F_EXTERNAL_OBJECTS =

F.exe: CMakeFiles/F.dir/F.cpp.obj
F.exe: CMakeFiles/F.dir/build.make
F.exe: CMakeFiles/F.dir/linklibs.rsp
F.exe: CMakeFiles/F.dir/objects1.rsp
F.exe: CMakeFiles/F.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable F.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\F.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/F.dir/build: F.exe

.PHONY : CMakeFiles/F.dir/build

CMakeFiles/F.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\F.dir\cmake_clean.cmake
.PHONY : CMakeFiles/F.dir/clean

CMakeFiles/F.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\CP\Competitive Programming Repo\Fegla_senior_1" "F:\CP\Competitive Programming Repo\Fegla_senior_1" "F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug" "F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug" "F:\CP\Competitive Programming Repo\Fegla_senior_1\cmake-build-debug\CMakeFiles\F.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/F.dir/depend

