#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;
    std::string& stringREF = str;

    // Addresses
    std::cout << "Address of string:     " << &str << std::endl;
    std::cout << "Address in stringPTR: " << stringPTR << std::endl;
    std::cout << "Address in stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;

    // Values
    std::cout << "Value of string:      " << str << std::endl;
    std::cout << "Value via stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value via stringREF: " << stringREF << std::endl;

    return 0;
}
