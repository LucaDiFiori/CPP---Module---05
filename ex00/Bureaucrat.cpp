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
	std::cout << YELLOW << "Bureaucrat copy constructor called" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << YELLOW << "Bureaucrat assignation operator called" << RESET << std::endl;
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
	return ("Error:" RED " Grade too high" RESET);
}

const char* 	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error:" RED " Grade too low" RESET);
}



//ostream_______________________________________________________________________
std::ostream& operator<<(std::ostream& os, const Bureaucrat& src)
{
	os << "Bureaucrat " << src.getName() << ", grade " << src.getGrade();
	return os;
}