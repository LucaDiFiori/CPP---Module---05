/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-26 17:54:40 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-26 17:54:40 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//Canonical form________________________________________________________________
AForm::AForm(std::string name, int gradeToSign, int gradeToExec) :
	_name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	if (this->_gradeToSign < MAX_GRADE || this->_gradeToExec < MAX_GRADE)
		throw GradeTooHighException();
	if (this->_gradeToSign > MIN_GRADE || this->_gradeToExec > MIN_GRADE)
		throw GradeTooLowException();

	std::cout << GREEN << "AForm " << AForm::getName() << " constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm& src) : 
	_name(src._name),
	_signed(src._signed),
	_gradeToSign(src._gradeToSign),
	_gradeToExec(src._gradeToExec)
{
	std::cout << GREEN  << "Form copy constructor called" << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& src)
{
	std::cout << GREEN << "Form assignation operator called" << RESET << std::endl;
	if (this == &src)
		return (*this);

	this->_signed = src._signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << RED << "Form " << AForm::getName() << " destroyed" << RESET << std::endl;
}



//Methods_______________________________________________________________________
void AForm::beSigned(Bureaucrat& Bureau)
{
	if (this->getGradeToSign() < Bureau.getGrade())
		throw GradeTooLowException();

	this->setSigned(true);
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (this->getGradeToExec() < executor.getGrade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw FormNotSignedException();

	this->useForm();
}



//Getters & setters_____________________________________________________________
std::string AForm::getName() const
{
return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

void AForm::setSigned(bool status)
{
	this->_signed = status;
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}



//Exceptions____________________________________________________________________
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form_Error:" RED " Grade too high" RESET);
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form_Error:" RED " Grade too low" RESET);
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form_Error:" RED " Form not signed" RESET);
}


//ostream_______________________________________________________________________
std::ostream& operator<<(std::ostream& os, const AForm& src)
{
	os << "Form " << src.getName() << " \n status: ";
	if (src.getSigned())
		os << "signed";
	else
		os << "not signed.\n";
	os << " required grade to sign: " << src.getGradeToSign() 
	<< "\n required grade to execute: " << src.getGradeToExec() << std::endl;

	return (os);
} 