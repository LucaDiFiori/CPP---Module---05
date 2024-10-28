/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 09:30:15 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-28 09:30:15 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//canonical form________________________________________________________________
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	AForm("ShrubberyCreationForm", 145, 137), 
	_target(target)
{
	std::cout << GREEN << "ShrubberyCreationForm constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :
	AForm(src),
	_target(src._target)
{
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called" << RESET <<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	std::cout << RED << "ShrubberyCreationForm destructor called" << RESET <<std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << GREEN << "ShrubberyCreationForm assignation operator called" 
		<< RESET <<std::endl;
	if (this == &src)
		return *this;
	this->_target = src._target;
	return (*this);
}




//Methods_______________________________________________________________________
void ShrubberyCreationForm::useForm() const
{
	std::ofstream file;
	std::string filename = _target + "_shrubbery";

	file.open(filename.c_str()); //use c_str() to convert string to char*
	if (!file.is_open())
	{
		std::cout << RED << "Error: could not open file" << RESET << std::endl;
		return ;
	}

	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\" << std::endl;
	
	file.close();
}