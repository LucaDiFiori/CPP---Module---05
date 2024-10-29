/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 11:49:46 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-28 11:49:46 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	std::cout << GREEN << "PresidentialPardonForm constructor called" << RESET <<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :
	AForm(src),
	_target(src._target)
{
	std::cout << GREEN << "PresidentialPardonForm copy constructor called" << RESET <<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm destructor called" << RESET <<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << GREEN << "PresidentialPardonForm assignation operator called" << RESET <<std::endl;
	if (this == &src)
		return *this;
	this->_target = src._target;
	return (*this);
}




//Methods_______________________________________________________________________
void PresidentialPardonForm::useForm() const
{
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}