/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-24 07:56:59 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-24 07:56:59 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
    	std::cout << "=== Create a bureaucrat with a high enough grade === " << std::endl;
        Bureaucrat highLevel("Alice", 1);
		std::cout << std::endl;

        std::cout << "=== Create a ShrubberyCreationForm and test signing and executing === " << std::endl;
        ShrubberyCreationForm shrubForm("home");
        std::cout << shrubForm << std::endl;
        
        highLevel.signForm(shrubForm);
        highLevel.executeForm(shrubForm);
		std::cout << std::endl;

        std::cout << "=== Create a RobotomyRequestForm and test signing and executing === " << std::endl;
        RobotomyRequestForm robotForm("Bender");
        std::cout << robotForm << std::endl;
		std::cout << std::endl;
        
        highLevel.signForm(robotForm);
        highLevel.executeForm(robotForm);
		std::cout << std::endl;

        std::cout << "=== Create a PresidentialPardonForm and test signing and executing === " << std::endl;
        PresidentialPardonForm pardonForm("Ford Prefect");
        std::cout << pardonForm << std::endl;
		std::cout << std::endl;
        
        highLevel.signForm(pardonForm);
        highLevel.executeForm(pardonForm);
		std::cout << std::endl;

        std::cout << "=== Create a bureaucrat with a low grade for testing exceptions === " << std::endl;
        Bureaucrat lowLevel("Bob", 150);
		std::cout << std::endl;
		
        std::cout << "=== Attempt to execute the form with a low-level bureaucrat === " << std::endl;
        lowLevel.executeForm(shrubForm);   
    } 
	// Note: this catch block will only catch exceptions thrown by functions such as
	//       constructors, which don’t have a try-catch block inside them.
	catch (std::exception &e) 
	{
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}