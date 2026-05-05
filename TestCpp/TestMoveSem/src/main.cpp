#include "main.h"

#include <iostream>
#include <stdio.h>

int main() {
    // int a = 3;
    // int & ref1 = a;
    

    // int b = 1;
    // int && ref2 = (int &&)b;




    // printf("%i\n", a);
    // printf("%i\n", ref1);
    // printf("%i\n", a);

    // printf("%i\n", b);
    // printf("%i\n", ref2);

    // int c = std::move(ref2);

    // printf("%i\n", b);

std::string a = "Data A";
    std::string & ref1 = a;
    
    // --- Move Semantics Example ---
    std::string b = "Data B";
    
    // We cast 'b' to an rvalue reference AND pass it into a new object 'c'.
    // This triggers the std::string Move Constructor.
    std::string c = std::move(b);

    // Printing 'a' (Nothing changed here)
    std::cout << "a: " << a << "\n";
    std::cout << "ref1: " << ref1 << "\n";
    std::cout << "a: " << a << "\n\n";

    // Printing 'b' and 'c'
    std::cout << "c (The new owner): " << c << "\n";
    
    // 'b' has been gutted. Its internal pointer was stolen by 'c'.
    // This will print an empty string!
    std::cout << "b (Moved out): " << b << "\n";

    return 0;
}
