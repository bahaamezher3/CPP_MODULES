#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));
    
    Intern intern;
    Bureaucrat boss("Boss", 1);
    
    AForm* form1 = intern.makeForm("shrubbery creation", "home");
    AForm* form2 = intern.makeForm("robotomy request", "Bender");
    AForm* form3 = intern.makeForm("presidential pardon", "Arthur");
    
    intern.makeForm("unknown form", "target");
    
    boss.signForm(*form1);
    boss.executeForm(*form1);
    delete form1;
    
    boss.signForm(*form2);
    boss.executeForm(*form2);
    delete form2;
    
    boss.signForm(*form3);
    boss.executeForm(*form3);
    delete form3;
    
    return 0;
}
