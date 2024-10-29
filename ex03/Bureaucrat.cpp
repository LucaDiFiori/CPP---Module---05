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

//Canonical AForm________________________________________________________________
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


void Bureaucrat::signForm(AForm& AForm)
{
	if (AForm.getSigned())
	{
		std::cout << RED << "AForm " << AForm.getName() << " is already signed" 
			<< RESET << std::endl;
		return ;
	}

	try
	{
		AForm.beSigned(*this);
		
		std::cout << CYAN << "Bureaucrat " << Bureaucrat::getName() << " signs " 
			<< AForm.getName() << RESET << std::endl;
	}
	catch (AForm::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << RED << "AForm " << AForm.getName() << " cannot be signed by " 
			<< Bureaucrat::getName() << RESET << std::endl;
	}
}

/**
 * @brief Attempts to execute a AForm.
 *
 * This method attempts to execute the given AForm using the current Bureaucrat.
 * If the execution is successful, it prints a message indicating that the Bureaucrat
 * has executed the AForm. If a GradeTooLowException is thrown during the execution process,
 * it catches the exception, prints the exception message, and prints an additional message
 * indicating that the AForm cannot be executed by the Bureaucrat. If a AFormNotSignedException
 * is thrown, it catches the exception, prints the exception message, and prints an additional
 * message indicating that the AForm is not valid for execution.
 *
 * @param AForm The AForm to be executed.
 * 
 * @throws AForm::GradeTooLowException If the Bureaucrat's grade is too low to execute the AForm.
 * @throws AForm::AFormNotSignedException If the AForm has not been signed and thus cannot be executed.
 *
 *
 *
 * @note If I don’t want to catch the exceptions thrown by the AForm::execute() method,
 * I can remove the try-catch block and let the exceptions propagate to the caller 
 * (in this case, the main function), like so:
 * 
 * void Bureaucrat::executeForm(const AForm& AForm) {
 *     AForm.execute(*this);
 *     std::cout << CYAN << "Bureaucrat " << this->getName() << " executes " 
 *               << AForm.getName() << RESET << std::endl;
 * }
 * 
 * Then I can catch the exceptions in the main function.
 */
void Bureaucrat::executeForm(const AForm& AForm)
{
	try
	{
		AForm.execute(*this);
		
		std::cout << CYAN << "Bureaucrat " << this->getName() << " executes " 
			<< AForm.getName() << RESET << std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << YELLOW << "AForm " << AForm.getName() << " cannot be executed by " 
			<< this->getName() << RESET << std::endl;
		std::cout << e.what() << std::endl;
		throw (e);
	}
	catch (AForm::FormNotSignedException& e)
	{
		std::cout << YELLOW << "AForm: " << AForm.getName() << "not valid" << RESET << std::endl;
		std::cout << e.what() << std::endl;
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