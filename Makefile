# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/cmake-3.27.2-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.27.2-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yanboh/dev/private/machine_learning/Digit_Recognition

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yanboh/dev/private/machine_learning/Digit_Recognition

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/opt/cmake-3.27.2-linux-x86_64/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/opt/cmake-3.27.2-linux-x86_64/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/yanboh/dev/private/machine_learning/Digit_Recognition/CMakeFiles /home/yanboh/dev/private/machine_learning/Digit_Recognition//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/yanboh/dev/private/machine_learning/Digit_Recognition/CMakeFiles 0
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
# Target rules for targets named Digit_Recognition

# Build rule for target.
Digit_Recognition: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Digit_Recognition
.PHONY : Digit_Recognition

# fast build rule for target.
Digit_Recognition/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/build
.PHONY : Digit_Recognition/fast

implementation/Layer.o: implementation/Layer.cpp.o
.PHONY : implementation/Layer.o

# target to build an object file
implementation/Layer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/Layer.cpp.o
.PHONY : implementation/Layer.cpp.o

implementation/Layer.i: implementation/Layer.cpp.i
.PHONY : implementation/Layer.i

# target to preprocess a source file
implementation/Layer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/Layer.cpp.i
.PHONY : implementation/Layer.cpp.i

implementation/Layer.s: implementation/Layer.cpp.s
.PHONY : implementation/Layer.s

# target to generate assembly for a file
implementation/Layer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/Layer.cpp.s
.PHONY : implementation/Layer.cpp.s

implementation/MNIST_initializer.o: implementation/MNIST_initializer.cpp.o
.PHONY : implementation/MNIST_initializer.o

# target to build an object file
implementation/MNIST_initializer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/MNIST_initializer.cpp.o
.PHONY : implementation/MNIST_initializer.cpp.o

implementation/MNIST_initializer.i: implementation/MNIST_initializer.cpp.i
.PHONY : implementation/MNIST_initializer.i

# target to preprocess a source file
implementation/MNIST_initializer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/MNIST_initializer.cpp.i
.PHONY : implementation/MNIST_initializer.cpp.i

implementation/MNIST_initializer.s: implementation/MNIST_initializer.cpp.s
.PHONY : implementation/MNIST_initializer.s

# target to generate assembly for a file
implementation/MNIST_initializer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/MNIST_initializer.cpp.s
.PHONY : implementation/MNIST_initializer.cpp.s

implementation/Network.o: implementation/Network.cpp.o
.PHONY : implementation/Network.o

# target to build an object file
implementation/Network.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/Network.cpp.o
.PHONY : implementation/Network.cpp.o

implementation/Network.i: implementation/Network.cpp.i
.PHONY : implementation/Network.i

# target to preprocess a source file
implementation/Network.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/Network.cpp.i
.PHONY : implementation/Network.cpp.i

implementation/Network.s: implementation/Network.cpp.s
.PHONY : implementation/Network.s

# target to generate assembly for a file
implementation/Network.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/Network.cpp.s
.PHONY : implementation/Network.cpp.s

implementation/Neuron.o: implementation/Neuron.cpp.o
.PHONY : implementation/Neuron.o

# target to build an object file
implementation/Neuron.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/Neuron.cpp.o
.PHONY : implementation/Neuron.cpp.o

implementation/Neuron.i: implementation/Neuron.cpp.i
.PHONY : implementation/Neuron.i

# target to preprocess a source file
implementation/Neuron.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/Neuron.cpp.i
.PHONY : implementation/Neuron.cpp.i

implementation/Neuron.s: implementation/Neuron.cpp.s
.PHONY : implementation/Neuron.s

# target to generate assembly for a file
implementation/Neuron.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/implementation/Neuron.cpp.s
.PHONY : implementation/Neuron.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Digit_Recognition.dir/build.make CMakeFiles/Digit_Recognition.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Digit_Recognition"
	@echo "... implementation/Layer.o"
	@echo "... implementation/Layer.i"
	@echo "... implementation/Layer.s"
	@echo "... implementation/MNIST_initializer.o"
	@echo "... implementation/MNIST_initializer.i"
	@echo "... implementation/MNIST_initializer.s"
	@echo "... implementation/Network.o"
	@echo "... implementation/Network.i"
	@echo "... implementation/Network.s"
	@echo "... implementation/Neuron.o"
	@echo "... implementation/Neuron.i"
	@echo "... implementation/Neuron.s"
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

