#!/bin/bash

echo "=== Stack Overflow Demo Compilation Script ==="
echo "WARNING: This creates a vulnerable executable!"
echo ""

# Check if g++ is available
if ! command -v g++ &> /dev/null; then
    echo "Error: g++ compiler not found!"
    echo "Please install g++ first."
    exit 1
fi

# Compilation options
echo "Choose compilation method:"
echo "1. Use Makefile (recommended)"
echo "2. Manual g++ command"
echo "3. Show safe compilation (for comparison)"
read -p "Enter choice (1-3): " choice

case $choice in
    1)
        echo "Compiling using Makefile..."
        make unsafe
        ;;
    2)
        echo "Compiling manually with unsafe flags..."
        g++ -g -O0 \
            -fno-stack-protector \
            -fno-stack-check \
            -fno-fortify-source \
            -z execstack \
            -no-pie \
            -fno-PIE \
            -o stack_overflow stack_overflow.cpp
        echo "Manual compilation complete!"
        ;;
    3)
        echo "This is how you would compile safely (with protections):"
        echo "g++ -g -O2 -fstack-protector-strong -D_FORTIFY_SOURCE=2 -o stack_overflow_safe stack_overflow.cpp"
        g++ -g -O2 -fstack-protector-strong -D_FORTIFY_SOURCE=2 -o stack_overflow_safe stack_overflow.cpp
        echo "Safe version compiled as 'stack_overflow_safe'"
        exit 0
        ;;
    *)
        echo "Invalid choice!"
        exit 1
        ;;
esac

# Check if compilation was successful
if [ -f "stack_overflow" ]; then
    echo ""
    echo "Compilation successful!"
    echo "Executable: stack_overflow"
    echo ""
    echo "SECURITY WARNING:"
    echo "- This program contains intentional vulnerabilities"
    echo "- Only run in a controlled environment"
    echo "- May crash your system or cause undefined behavior"
    echo ""
    
    read -p "Do you want to run the program now? (y/N): " run_choice
    if [[ $run_choice =~ ^[Yy]$ ]]; then
        echo "Starting vulnerable program..."
        ./stack_overflow
    else
        echo "Program compiled but not executed."
        echo "Run with: ./stack_overflow"
    fi
else
    echo "Compilation failed!"
    exit 1
fi