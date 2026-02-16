#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));
    
    Bureaucrat boss("Boss", 1);
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur");
    
    boss.signForm(shrub);
    boss.signForm(robot);
    boss.signForm(pardon);
    
    boss.executeForm(shrub);
    boss.executeForm(robot);
    boss.executeForm(pardon);
    
    return 0;
}
