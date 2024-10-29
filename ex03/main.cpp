/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:05:38 by luca              #+#    #+#             */
/*   Updated: 2024/10/29 15:19:17 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"

int main() {
    Intern intern;  // Create an instance of Intern
    AForm* form;    // Pointer to hold the created form

    std::cout << "=== Test case 1: Creating a RobotomyRequestForm ===" << std::endl;
    form = intern.makeForm("robotomy request", "Bender");
    if (form) {
        // Successfully created form
        std::cout << "Successfully created: " << form->getName() << std::endl;
        delete form;  // Clean up dynamically allocated memory
    }
    std::cout << std::endl;

    std::cout << "=== Test case 2: Creating a ShrubberyCreationForm ===" << std::endl;
    form = intern.makeForm("shrubbery creation", "Garden");
    if (form) {
        // Successfully created form
        std::cout << "Successfully created: " << form->getName() << std::endl;
        delete form;  // Clean up dynamically allocated memory
    }
    std::cout << std::endl;

    std::cout << "=== Test case 3: Creating a PresidentialPardonForm ===" << std::endl;
    form = intern.makeForm("presidential pardon", "Alice");
    if (form) {
        // Successfully created form
        std::cout << "Successfully created: " << form->getName() << std::endl;
        delete form;  // Clean up dynamically allocated memory
    }
    std::cout << std::endl;

    std::cout << "=== Test case 4: Trying to create an unknown form ===" << std::endl;
    form = intern.makeForm("unknown form", "Target");
    if (!form) {
        std::cout << "Failed to create form due to unknown name." << std::endl;
    }

    return 0;
}
