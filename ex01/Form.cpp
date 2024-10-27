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

#include "Form.hpp"
#include "Bureaucrat.hpp"

//Canonical form________________________________________________________________
Form::Form(std::string name, int gradeToSign, int gradeToExec) :
	_name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	if (this->_gradeToSign < MAX_GRADE || this->_gradeToExec < MAX_GRADE)
		throw GradeTooHighException();
	if (this->_gradeToSign > MIN_GRADE || this->_gradeToExec > MIN_GRADE)
		throw GradeTooLowException();

	std::cout << GREEN << "Form " << Form::getName() << " created" << RESET << std::endl;
}

Form::Form(const Form& src) : 
	_name(src._name),
	_signed(src._signed),
	_gradeToSign(src._gradeToSign),
	_gradeToExec(src._gradeToExec)
{
	std::cout << GREEN  << "Form copy constructor called" << RESET << std::endl;
}

Form& Form::operator=(const Form& src)
{
	std::cout << GREEN << "Form assignation operator called" << RESET << std::endl;
	if (this == &src)
		return (*this);

	this->_signed = src._signed;
	return (*this);
}

Form::~Form()
{
	std::cout << RED << "Form " << Form::getName() << " destroyed" << RESET << std::endl;
}



//Methods_______________________________________________________________________
void Form::beSigned(Bureaucrat& Bureau)
{
	if (this->getGradeToSign() < Bureau.getGrade())
		throw GradeTooLowException();

	this->setSigned(true);
}



//Getters & setters_____________________________________________________________
std::string Form::getName() const
{
return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

void Form::setSigned(bool status)
{
	this->_signed = status;
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}



//Exceptions____________________________________________________________________
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form_Error:" RED " Grade too high" RESET);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form_Error:" RED " Grade too low" RESET);
}


//ostream_______________________________________________________________________
std::ostream& operator<<(std::ostream& os, const Form& src)
{
	os << "Form " << src.getName() << " \nstatus: ";
	if (src.getSigned())
		os << "signed";
	else
		os << "not signed.\n";
	os << " required grade to sign: " << src.getGradeToSign() 
	<< "\n required grade to execute: " << src.getGradeToExec() << std::endl;

	return (os);
} 