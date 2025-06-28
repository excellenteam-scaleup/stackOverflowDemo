# Makefile for compiling without stack protection

CXX = g++
TARGET = stack_overflow
SOURCE = stack_overflow.cpp

# Flags to disable stack protection and other security features
UNSAFE_FLAGS = -fno-stack-protector \
               -fno-stack-check \
#               -fno-fortify-source \
               -z execstack \
               -no-pie \
               -fno-PIE

# Additional flags for different levels of vulnerability
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2

# Default target
all: unsafe

# Compile without any stack protection (most vulnerable)
unsafe:
	$(CXX) $(DEBUG_FLAGS) $(UNSAFE_FLAGS) -o $(TARGET) $(SOURCE)
	@echo "Compiled with NO stack protection - VERY DANGEROUS!"
	@echo "Use only for educational/research purposes!"

# Compile with some optimizations but still no protection
release:
	$(CXX) $(RELEASE_FLAGS) $(UNSAFE_FLAGS) -o $(TARGET) $(SOURCE)

# Show what a safe compilation would look like (for comparison)
safe:
	$(CXX) -g -O2 -fstack-protector-strong -D_FORTIFY_SOURCE=2 -o $(TARGET)_safe $(SOURCE)
	@echo "Compiled with stack protection enabled"

# Clean up
clean:
	rm -f $(TARGET) $(TARGET)_safe

# Show compiler flags being used
show-flags:
	@echo "Unsafe flags: $(UNSAFE_FLAGS)"
	@echo "Debug flags: $(DEBUG_FLAGS)"

.PHONY: all unsafe release safe clean show-flags