#include <iostream>
#include <cstring>
#include <iomanip>

// Function that causes stack overflow through infinite recursion
void infiniteRecursion(int depth = 0) {
    char buffer[1024];  // Large local buffer to consume stack space faster
    
    // Fill buffer with some data to prevent optimization
    memset(buffer, 'A', sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    
    std::cout << "Recursion depth: " << depth 
              << " | Stack address: " << std::hex << (void*)buffer << std::dec << std::endl;
    
    // Recursive call - this will eventually overflow the stack
    infiniteRecursion(depth + 1);
}

// Function that causes buffer overflow
void bufferOverflow() {
    char buffer[64];
    char overflow_data[200];
    
    // Fill overflow data
    memset(overflow_data, 'B', sizeof(overflow_data) - 1);
    overflow_data[sizeof(overflow_data) - 1] = '\0';
    
    std::cout << "\nBuffer address: " << std::hex << (void*)buffer << std::dec << std::endl;
    std::cout << "Buffer size: " << sizeof(buffer) << " bytes" << std::endl;
    std::cout << "Overflow data size: " << sizeof(overflow_data) << " bytes" << std::endl;
    
    // This will overflow the buffer - DANGEROUS!
    strcpy(buffer, overflow_data);
    
    std::cout << "Buffer overflow completed (if you see this, the program didn't crash yet)" << std::endl;
}

// Function with vulnerable input handling
void vulnerableFunction() {
    char input[100];
    
    std::cout << "\nEnter some text (try entering more than 100 characters): ";
    
    // Vulnerable - no bounds checking
    std::cin >> input;
    
    std::cout << "You entered: " << input << std::endl;
}

// Function to demonstrate stack smashing
void stackSmashing() {
    char buffer[50];
    int important_variable = 12345;
    
    std::cout << "\nImportant variable before: " << important_variable << std::endl;
    std::cout << "Buffer address: " << std::hex << (void*)buffer << std::dec << std::endl;
    std::cout << "Important variable address: " << std::hex << (void*)&important_variable << std::dec << std::endl;
    
    // Overflow that might overwrite the important_variable
    char malicious_data[100];
    memset(malicious_data, 'X', sizeof(malicious_data) - 1);
    malicious_data[sizeof(malicious_data) - 1] = '\0';
    
    strcpy(buffer, malicious_data);
    
    std::cout << "Important variable after: " << important_variable << std::endl;
}

int main() {
    int choice;
    
    std::cout << "=== Stack Overflow Demonstration Program ===" << std::endl;
    std::cout << "WARNING: This program contains intentional vulnerabilities!" << std::endl;
    std::cout << "Only run in a safe, controlled environment." << std::endl;
    std::cout << "\nChoose a demonstration:" << std::endl;
    std::cout << "1. Infinite Recursion (Stack Overflow)" << std::endl;
    std::cout << "2. Buffer Overflow" << std::endl;
    std::cout << "3. Vulnerable Input Function" << std::endl;
    std::cout << "4. Stack Smashing" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "\nEnter your choice (1-5): ";
    
    std::cin >> choice;
    
    switch(choice) {
        case 1:
            std::cout << "\nStarting infinite recursion..." << std::endl;
            std::cout << "This will cause a stack overflow!" << std::endl;
            try {
                infiniteRecursion();
            } catch(...) {
                std::cout << "Exception caught!" << std::endl;
            }
            break;
            
        case 2:
            std::cout << "\nDemonstrating buffer overflow..." << std::endl;
            bufferOverflow();
            break;
            
        case 3:
            vulnerableFunction();
            break;
            
        case 4:
            stackSmashing();
            break;
            
        case 5:
            std::cout << "Exiting safely..." << std::endl;
            return 0;
            
        default:
            std::cout << "Invalid choice!" << std::endl;
            break;
    }
    
    std::cout << "\nProgram completed (if you see this, no crash occurred)" << std::endl;
    return 0;
}