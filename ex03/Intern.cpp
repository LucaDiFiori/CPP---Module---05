/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:30:22 by luca              #+#    #+#             */
/*   Updated: 2024/10/29 15:16:44 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//Canonical form________________________________________________________________
Intern::Intern()
{
    formNames[0] = "presidential pardon";
    formNames[1] = "robotomy request";
    formNames[2] = "shrubbery creation";    
    
    std::cout << GREEN << "Intern constructor called" << RESET << std::endl;
    std::cout << "Hi, I'm the " << GREEN 
        << "intern." << RESET <<  " I'm here to help you create the following forms:\n"
        << "- presidential pardon form\n" 
        << "- robotomy request form\n"
        << "- shrubbery creation form\n"
        << std::endl;

}

Intern::Intern(const Intern& src)
{
    formNames[0] = "presidential pardon";
    formNames[1] = "robotomy request";
    formNames[2] = "shrubbery creation";
    
    std::cout << GREEN << "Intern copy constructor called" << RESET << std::endl;
    *this = src;
}

Intern::~Intern()
{
    std::cout << RED << "Intern destructor called" << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& src)
{
    std::cout << GREEN << "Intern assignation operator called" << RESET << std::endl;
    (void)src;
    return (*this);
}





//getter "utils"________________________________________________________________
/**
 * @brief Determines the type of form based on the given form name.
 * 
 * This function iterates through the predefined form names and compares
 * each one with the provided form name. If a match is found, it returns
 * the corresponding FormType. If no match is found, it returns UNKNOWN.
 * 
 * @param formName The name of the form to determine the type of.
 * @return The FormType corresponding to the given form name, or UNKNOWN if no match is found.
 */
FormType Intern::getFormType(const std::string& formName)
{
    for (int i = 0; i < 3; i++)
    {
        if (formName == this->formNames[i])
            return (static_cast<FormType>(i));
    }
    return (UNKNOWN);
}



//Form creation "utils"_________________________________________________________
/**
 * @brief Creates a new RobotomyRequestForm with the specified target.
 * 
 * This function dynamically allocates a new RobotomyRequestForm object
 * with the given target and returns a pointer to it.
 * 
 * @param target The target for the RobotomyRequestForm.
 * @return A pointer to the newly created RobotomyRequestForm.
 */
AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}




//Form creation_________________________________________________________________
/**
 * @brief Creates a form based on the given form name and target.
 * 
 * This function determines the type of form to create based on the provided
 * form name. It then creates the corresponding form with the specified target
 * and returns a pointer to the newly created form. If the form name is not
 * recognized, it prints an error message and returns NULL.
 * 
 * @param formName The name of the form to create.
 * @param target The target for the form.
 * @return A pointer to the newly created form, or NULL if the form name is not recognized.
 */
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    FormType formType = getFormType(formName);

    switch(formType)
    {
        case PRESIDENTIAL_PARDON:
            std::cout << PURPLE << "Intern creates a presidential pardon form" 
                << RESET << std::endl;
            return (createPresidentialPardonForm(target));
        case ROBOTOMY_REQUEST:
            std::cout << PURPLE << "Intern creates a robotomy request form" 
                << RESET << std::endl;
            return (createRobotomyRequestForm(target));
        case SHRUBBERY_CREATION:
            std::cout << PURPLE << "Intern creates a shrubbery creation form" 
                << RESET << std::endl;
            return (createShrubberyCreationForm(target));
        case UNKNOWN:
            std::cout << "Error: Form \"" << RED << formName << "\" not found." 
                << RESET << std::endl;
            return (NULL);        
    }
    return (NULL);
}