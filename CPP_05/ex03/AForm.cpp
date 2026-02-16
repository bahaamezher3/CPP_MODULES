#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) 
    : _name(other._name), _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form " << form.getName() 
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute();
    return out;
}
