#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        AForm();
        AForm(const std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        virtual ~AForm();
        AForm &operator=(const AForm &other);
        
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);
        void execute(Bureaucrat const & executor) const;
        virtual void executeAction() const = 0;
        
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade is too high!";
                }
        };
        
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade is too low!";
                }
        };
        
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Form is not signed!";
                }
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
