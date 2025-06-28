# Stack Overflow Demonstration Program

⚠️ **WARNING: This program contains intentional security vulnerabilities!** ⚠️

## Purpose
This program is designed for educational purposes to demonstrate:
- Stack overflow vulnerabilities
- Buffer overflow attacks
- Stack smashing techniques
- Memory corruption issues

## Compilation Instructions

### Method 1: Using Makefile (Recommended)
```
make unsafe
```
### Method 2: Manual Compilation
```
g++ -g -O0 -fno-stack-protector -fno-stack-check -fno-fortify-source -z execstack -no-pie -fno-PIE -o stack_overflow stack_overflow.cpp
```

### Method 3: Using the Script
```
chmod +x compile_and_run.sh
./compile_and_run.sh
```

## Compiler Flags Explained

### Flags that DISABLE Security Features:
- `-fno-stack-protector`: Disables stack canaries
- `-fno-stack-check`: Disables stack overflow checking
- `-fno-fortify-source`: Disables buffer overflow detection
- `-z execstack`: Makes stack executable
- `-no-pie`: Disables Position Independent Executable
- `-fno-PIE`: Disables Position Independent Code

### Why These Flags Are Needed:
Modern compilers include security features by default that would prevent or detect the vulnerabilities this program demonstrates. These flags disable those protections.

## Program Features

1. **Infinite Recursion**: Causes stack overflow through deep recursion
2. **Buffer Overflow**: Demonstrates classic buffer overflow
3. **Vulnerable Input**: Shows unsafe input handling
4. **Stack Smashing**: Demonstrates overwriting stack variables

## Safety Precautions

⚠️ **IMPORTANT SAFETY NOTES:**
- Only run in a virtual machine or isolated environment
- This program may crash your system
- Do not run on production systems
- Use only for educational/research purposes
- The program may behave unpredictably

## Expected Behavior

Depending on your system and compiler:
- The program may crash with segmentation fault
- It may corrupt memory and cause undefined behavior
- Stack overflow may be caught by the OS
- Buffer overflows may overwrite adjacent memory

## Educational Value

This program helps understand:
- How stack overflows occur
- Why compiler protections exist
- Memory layout and stack behavior
- Security vulnerability concepts

## Legal and Ethical Use

This code is provided for:
- Educational purposes
- Security research
- Understanding vulnerabilities
- Learning defensive programming

Do NOT use for malicious purposes!

## Compilation Comparison

### Unsafe (This Program):
```
g++ -fno-stack-protector -fno-stack-check -fno-fortify-source ...
```

### Safe (Normal):
```
g++ -fstack-protector-strong -D_FORTIFY_SOURCE=2 ...
```

## System Requirements

- Linux/Unix system (recommended)
- GCC/G++ compiler
- x86/x64 architecture
- Virtual machine (strongly recommended)

## Troubleshooting

If the program doesn't crash as expected:
- Your system may have additional protections
- Try running in a different environment
- Check if ASLR is enabled (`cat /proc/sys/kernel/randomize_va_space`)
- Some modern systems have hardware-level protections

Remember: The goal is education, not exploitation!
