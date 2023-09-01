MAINPROG = app
BIN_DIR = exe
# It is likely that default C compiler is already gcc, but explicitly
# set, just to be sure
CC = g++

#Automatic Variables
#Automatic variables are set by make after a rule is matched. There include:
#
# $@: the target filename.
# $*: the target filename without the file extension.
# $<: the first prerequisite filename.
# $^: the filenames of all the prerequisites, separated by spaces, discard duplicates.
# $+: similar to $^, but includes duplicates.
# $?: the names of all prerequisites that are newer than the target, separated by spaces.
# 
# The CFLAGS variable sets compile flags for gcc:
#  -g          This flag includes debugging information in the compiled binary
#  -Wall       give verbose compiler warnings
#  -O0         do not optimize generated code
#  -O1         This flag specifies optimization level 1. 
#				It enables basic optimizations while still keeping the compilation time reasonable. 
#				This level of optimization is suitable for development and testing.
#  -O2         This flag specifies optimization level 2. 
#  -I
# -MMD 		   This flag tells the compiler to generate dependency files for make. 
#               These files can help automate the build process and ensure that necessary 
#               files are recompiled when dependencies change.
# -m64	 	   This flag instructs the compiler to generate code for a 64-bit target architecture. 
#				This is essential when targeting the x86-64 architecture.
#  -std=gnu99  use the GNU99 standard language definition
CFLAGS = -g -O1 -MMD

# The LDFLAGS variable sets flags for linker
#  -lm   says to link in libm (the math library)
LDFLAGS = -lm

# Print the assembly code.
ASM=-S

TARGET=$(MAINPROG)

# Search for dependencies and targets from "src" and "include" directories
# The directories are separated by space
#VPATH = src include

# Search for .c files in "src" directory; .h files in "include" directory
# The pattern matching character '%' matches filename without the extension
#vpath %.c src
#vpath %.h include

SOURCES=$(wildcard *.cpp)
LINK=$(CC) $(CFLAGS)
OBJECTS=$(SOURCES:%.cpp=%.o)


# String substitution (suffix version without %).
# As an example, ./build/hello.cpp.o turns into ./build/hello.cpp.d
DEPS := $(OBJECTS:.o=.d)
ASMS := $(SOURCES:%.cpp=%.s)



# Here is a Make Macro defined by two Macro Expansions.
# A Macro Expansion may be treated as a textual replacement of the Make Macro.
# Macro Expansions are introduced with $ and enclosed in (parentheses).
REBUILDABLES = $(OBJS) $(ASMS) $(TARGET)


# Applicable for create .o object file.
# '%' matches filename.
# $< is the first pre-requisite
# $^ matches all the pre-requisites (no duplicates)
%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $*.cpp | echo "[+]" $@

%.s: %.cpp
	@$(CC) $(ASM) -o $@  $*.cpp | echo "[+]" $@
	

# The rule for "all" is used to incrementally build your system.
# It does this by expressing a dependency on the results of that system,
# which in turn have their own rules and dependencies.
all: $(TARGET)  
	@echo Job Completed.

asm: $(ASMS)
	@echo Assembly code created.

# Link the object files name to the application
$(TARGET): $(OBJECTS)
	@$(LINK) -o $@ $^  $(LDFLAGS) | echo "[+]" $@

# remove all object files, dependencies, assembly files, and application.
clean:
	@rm -rf *.s *.d *.o $(TARGET)
	@echo Clean Completed.

run:
	@./${MAINPROG}


###
### https://makefiletutorial.com/
###

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
#-include $(DEPS)
