/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-24 07:57:37 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-24 07:57:37 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Canonical form________________________________________________________________
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();

	std::cout << GREEN << "Bureaucrat " << Bureaucrat::getName() << ", grade: " 
		<< Bureaucrat::getGrade() << " created" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
	std::cout << GREEN  << "Bureaucrat copy constructor called" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << GREEN << "Bureaucrat assignation operator called" << RESET << std::endl;
	if (this == &src)
		return *this;
	this->_grade = src._grade;

	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat " << Bureaucrat::getName() << " destroyed" 
		<< RESET << std::endl;
}


//Methods_______________________________________________________________________
void Bureaucrat::promotion()
{
	if (_grade == 1)
		throw GradeTooHighException();
	this->_grade--;

	std::cout << PURPLE << "Bureaucrat " << Bureaucrat::getName() << " promoted to grade " 
		<< Bureaucrat::getGrade() << RESET << std::endl;
}

void Bureaucrat::demotion()
{
	if (_grade == 150)
		throw GradeTooLowException();
	this->_grade++;

	std::cout << CYAN << "Bureaucrat " << Bureaucrat::getName() << " demoted to grade " 
		<< Bureaucrat::getGrade() << RESET << std::endl;
}



/**
 * @brief Attempts to sign a form.
 *
 * This method checks if the form is already signed. If it is, it prints a message
 * indicating that the form is already signed and returns. If the form is not signed,
 * it attempts to sign the form. If the signing is successful, it prints a message
 * indicating that the bureaucrat has signed the form. If a GradeTooHighException is
 * thrown during the signing process, it catches the exception, prints the exception
 * message, and prints an additional message indicating that the form cannot be signed
 * by the bureaucrat.
 *
 * @param form The form to be signed.
 * 
 * @throws Form::GradeTooHighException If the bureaucrat's grade is too high to sign the form.
 */
void Bureaucrat::signForm(Form& form)
{
	if (form.getSigned())
	{
		std::cout << RED << "Form " << form.getName() << " is already signed" << RESET << std::endl;
		return ;
	}

	try
	{
		form.beSigned(*this);
		std::cout << CYAN << "Bureaucrat " << Bureaucrat::getName() << " signs " 
			<< form.getName() << RESET << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		std::cout << RED << "Form " << form.getName() << " cannot be signed by " 
			<< Bureaucrat::getName() << RESET << std::endl;
	}
}



//Getters_______________________________________________________________________
std::string		Bureaucrat::getName() const
{
	return _name;
}

int		Bureaucrat::getGrade() const
{
	return _grade;
}


//Exceptions____________________________________________________________________
const char*		Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat_Error:" RED " Grade too high" RESET);
}

const char* 	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat_Error:" RED " Grade too low" RESET);
}



//ostream_______________________________________________________________________
std::ostream& operator<<(std::ostream& os, const Bureaucrat& src)
{
	os << "Bureaucrat " << src.getName() << ", grade " << src.getGrade();
	return os;
}