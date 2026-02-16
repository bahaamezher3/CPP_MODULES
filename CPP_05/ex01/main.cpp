#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 25);
        Form form("Application", 50, 30);
        
        std::cout << bob << std::endl;
        std::cout << form << std::endl;
        bob.signForm(form);
        std::cout << form << std::endl;
        
        Bureaucrat alice("Alice", 100);
        Form secret("Secret", 20, 10);
        std::cout << alice << std::endl;
        alice.signForm(secret);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
