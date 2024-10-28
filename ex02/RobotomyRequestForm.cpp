/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 11:33:59 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-28 11:33:59 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//canonical form________________________________________________________________
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	std::cout << GREEN << "RobotomyRequestForm constructor called" << RESET <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
	AForm(src),
	_target(src._target)
{
	std::cout << GREEN << "RobotomyRequestForm copy constructor called" << RESET <<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET <<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << GREEN << "RobotomyRequestForm assignation operator called" << RESET <<std::endl;
	if (this == &src)
		return *this;
	this->_target = src._target;
	return (*this);
}



//Methods_______________________________________________________________________
void RobotomyRequestForm::useForm() const
{
	std::srand(std::time(0)); // initialize random seed
	int randomValue = std::rand() % 2; // generate random number between 0 and 1

	std::cout << "Drilling noises..." << std::endl;
	if (randomValue == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomization failed" << std::endl;
} 