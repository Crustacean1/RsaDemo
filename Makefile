# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/kamil2/Projects/Studia/C++/RsaDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kamil2/Projects/Studia/C++/RsaDemo

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kamil2/Projects/Studia/C++/RsaDemo/CMakeFiles /home/kamil2/Projects/Studia/C++/RsaDemo//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kamil2/Projects/Studia/C++/RsaDemo/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named RsaDemo

# Build rule for target.
RsaDemo: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 RsaDemo
.PHONY : RsaDemo

# fast build rule for target.
RsaDemo/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/build
.PHONY : RsaDemo/fast

Services/DecodeService.o: Services/DecodeService.cpp.o
.PHONY : Services/DecodeService.o

# target to build an object file
Services/DecodeService.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/DecodeService.cpp.o
.PHONY : Services/DecodeService.cpp.o

Services/DecodeService.i: Services/DecodeService.cpp.i
.PHONY : Services/DecodeService.i

# target to preprocess a source file
Services/DecodeService.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/DecodeService.cpp.i
.PHONY : Services/DecodeService.cpp.i

Services/DecodeService.s: Services/DecodeService.cpp.s
.PHONY : Services/DecodeService.s

# target to generate assembly for a file
Services/DecodeService.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/DecodeService.cpp.s
.PHONY : Services/DecodeService.cpp.s

Services/EncodeService.o: Services/EncodeService.cpp.o
.PHONY : Services/EncodeService.o

# target to build an object file
Services/EncodeService.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/EncodeService.cpp.o
.PHONY : Services/EncodeService.cpp.o

Services/EncodeService.i: Services/EncodeService.cpp.i
.PHONY : Services/EncodeService.i

# target to preprocess a source file
Services/EncodeService.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/EncodeService.cpp.i
.PHONY : Services/EncodeService.cpp.i

Services/EncodeService.s: Services/EncodeService.cpp.s
.PHONY : Services/EncodeService.s

# target to generate assembly for a file
Services/EncodeService.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/EncodeService.cpp.s
.PHONY : Services/EncodeService.cpp.s

Services/GenerateService.o: Services/GenerateService.cpp.o
.PHONY : Services/GenerateService.o

# target to build an object file
Services/GenerateService.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/GenerateService.cpp.o
.PHONY : Services/GenerateService.cpp.o

Services/GenerateService.i: Services/GenerateService.cpp.i
.PHONY : Services/GenerateService.i

# target to preprocess a source file
Services/GenerateService.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/GenerateService.cpp.i
.PHONY : Services/GenerateService.cpp.i

Services/GenerateService.s: Services/GenerateService.cpp.s
.PHONY : Services/GenerateService.s

# target to generate assembly for a file
Services/GenerateService.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/GenerateService.cpp.s
.PHONY : Services/GenerateService.cpp.s

Services/IService.o: Services/IService.cpp.o
.PHONY : Services/IService.o

# target to build an object file
Services/IService.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/IService.cpp.o
.PHONY : Services/IService.cpp.o

Services/IService.i: Services/IService.cpp.i
.PHONY : Services/IService.i

# target to preprocess a source file
Services/IService.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/IService.cpp.i
.PHONY : Services/IService.cpp.i

Services/IService.s: Services/IService.cpp.s
.PHONY : Services/IService.s

# target to generate assembly for a file
Services/IService.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Services/IService.cpp.s
.PHONY : Services/IService.cpp.s

Tasks/Executor.o: Tasks/Executor.cpp.o
.PHONY : Tasks/Executor.o

# target to build an object file
Tasks/Executor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/Executor.cpp.o
.PHONY : Tasks/Executor.cpp.o

Tasks/Executor.i: Tasks/Executor.cpp.i
.PHONY : Tasks/Executor.i

# target to preprocess a source file
Tasks/Executor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/Executor.cpp.i
.PHONY : Tasks/Executor.cpp.i

Tasks/Executor.s: Tasks/Executor.cpp.s
.PHONY : Tasks/Executor.s

# target to generate assembly for a file
Tasks/Executor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/Executor.cpp.s
.PHONY : Tasks/Executor.cpp.s

Tasks/PrimeGenerator.o: Tasks/PrimeGenerator.cpp.o
.PHONY : Tasks/PrimeGenerator.o

# target to build an object file
Tasks/PrimeGenerator.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/PrimeGenerator.cpp.o
.PHONY : Tasks/PrimeGenerator.cpp.o

Tasks/PrimeGenerator.i: Tasks/PrimeGenerator.cpp.i
.PHONY : Tasks/PrimeGenerator.i

# target to preprocess a source file
Tasks/PrimeGenerator.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/PrimeGenerator.cpp.i
.PHONY : Tasks/PrimeGenerator.cpp.i

Tasks/PrimeGenerator.s: Tasks/PrimeGenerator.cpp.s
.PHONY : Tasks/PrimeGenerator.s

# target to generate assembly for a file
Tasks/PrimeGenerator.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/PrimeGenerator.cpp.s
.PHONY : Tasks/PrimeGenerator.cpp.s

Tasks/PrimeSync.o: Tasks/PrimeSync.cpp.o
.PHONY : Tasks/PrimeSync.o

# target to build an object file
Tasks/PrimeSync.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/PrimeSync.cpp.o
.PHONY : Tasks/PrimeSync.cpp.o

Tasks/PrimeSync.i: Tasks/PrimeSync.cpp.i
.PHONY : Tasks/PrimeSync.i

# target to preprocess a source file
Tasks/PrimeSync.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/PrimeSync.cpp.i
.PHONY : Tasks/PrimeSync.cpp.i

Tasks/PrimeSync.s: Tasks/PrimeSync.cpp.s
.PHONY : Tasks/PrimeSync.s

# target to generate assembly for a file
Tasks/PrimeSync.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/PrimeSync.cpp.s
.PHONY : Tasks/PrimeSync.cpp.s

Tasks/TaskQueue.o: Tasks/TaskQueue.cpp.o
.PHONY : Tasks/TaskQueue.o

# target to build an object file
Tasks/TaskQueue.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/TaskQueue.cpp.o
.PHONY : Tasks/TaskQueue.cpp.o

Tasks/TaskQueue.i: Tasks/TaskQueue.cpp.i
.PHONY : Tasks/TaskQueue.i

# target to preprocess a source file
Tasks/TaskQueue.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/TaskQueue.cpp.i
.PHONY : Tasks/TaskQueue.cpp.i

Tasks/TaskQueue.s: Tasks/TaskQueue.cpp.s
.PHONY : Tasks/TaskQueue.s

# target to generate assembly for a file
Tasks/TaskQueue.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Tasks/TaskQueue.cpp.s
.PHONY : Tasks/TaskQueue.cpp.s

Utility/Parser.o: Utility/Parser.cpp.o
.PHONY : Utility/Parser.o

# target to build an object file
Utility/Parser.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Utility/Parser.cpp.o
.PHONY : Utility/Parser.cpp.o

Utility/Parser.i: Utility/Parser.cpp.i
.PHONY : Utility/Parser.i

# target to preprocess a source file
Utility/Parser.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Utility/Parser.cpp.i
.PHONY : Utility/Parser.cpp.i

Utility/Parser.s: Utility/Parser.cpp.s
.PHONY : Utility/Parser.s

# target to generate assembly for a file
Utility/Parser.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/Utility/Parser.cpp.s
.PHONY : Utility/Parser.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/RsaDemo.dir/build.make CMakeFiles/RsaDemo.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... RsaDemo"
	@echo "... Services/DecodeService.o"
	@echo "... Services/DecodeService.i"
	@echo "... Services/DecodeService.s"
	@echo "... Services/EncodeService.o"
	@echo "... Services/EncodeService.i"
	@echo "... Services/EncodeService.s"
	@echo "... Services/GenerateService.o"
	@echo "... Services/GenerateService.i"
	@echo "... Services/GenerateService.s"
	@echo "... Services/IService.o"
	@echo "... Services/IService.i"
	@echo "... Services/IService.s"
	@echo "... Tasks/Executor.o"
	@echo "... Tasks/Executor.i"
	@echo "... Tasks/Executor.s"
	@echo "... Tasks/PrimeGenerator.o"
	@echo "... Tasks/PrimeGenerator.i"
	@echo "... Tasks/PrimeGenerator.s"
	@echo "... Tasks/PrimeSync.o"
	@echo "... Tasks/PrimeSync.i"
	@echo "... Tasks/PrimeSync.s"
	@echo "... Tasks/TaskQueue.o"
	@echo "... Tasks/TaskQueue.i"
	@echo "... Tasks/TaskQueue.s"
	@echo "... Utility/Parser.o"
	@echo "... Utility/Parser.i"
	@echo "... Utility/Parser.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

