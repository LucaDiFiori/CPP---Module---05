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

#include "Bureaucrat.hpp"

/* TEST 1: unwinding the stack
*
* Output:
* -------
	Bureaucrat Alice, grade: 10 created
	Bureaucrat Alice, grade 10
	Bureaucrat Bob, grade: 50 created
	Bureaucrat Bob, grade 50
	Bureaucrat Bob destroyed
	Bureaucrat Alice destroyed
	Error: Grade too low
*
*
* Explanation:
* ------------
	when an exception is thrown, the local objects created within the try block are 
	destroyed while the program control passes to the catch block. This is part of the "
	unwinding" of the stack, which ensures that all allocated resources are properly released.
		- Bureaucrat bureaucrat_1("Alice", 10); is successfully created.
		- Bureaucrat bureaucrat_2("Bob", 50); is successfully created.
		- Bureaucrat bureaucrat_3("Bob", 151); attempts to be created, but the constructor 
		throws a GradeTooLowException because grade 151 is invalid.
		- When the exception is thrown, control immediately passes to the catch block.
		- Before entering the catch block, the C++ runtime destroys all local objects 
		  created in the try block up to the point where the exception was thrown.
		- This means that bureaucrat_1 and bureaucrat_2 are destroyed, and their 
		  destructors are called.
		- After the local objects have been destroyed, control passes to the 
		  appropriate catch block.
		- The error message is printed: Error: Grade too low.


int main()
{
	try
	{
		Bureaucrat bureaucrat_1("Alice", 10); // Valid grade
		std::cout << bureaucrat_1 << std::endl;

		Bureaucrat bureaucrat_2("Bob", 50); // valide grade
		std::cout << bureaucrat_2 << std::endl;

		Bureaucrat bureaucrat_3("Bob", 151); // Invalid grade, should throw exception
		std::cout << bureaucrat_3 << std::endl; // This line won't be executed

		Bureaucrat bureaucrat_4("Charlie", 0); // Invalid grade, should throw exception
		std::cout << bureaucrat_4 << std::endl; // This line won't be executed
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}
*/



int main() {
	std::cout << "=== TEST 1 = First try/catch block: unwinding the stack ===" << std::endl;
    try {
        Bureaucrat bureaucrat1("Alice", 10); // Valid grade
        std::cout << bureaucrat1 << std::endl;

        Bureaucrat bureaucrat2("Bob", 151); // Invalid grade, should throw exception
        std::cout << bureaucrat2 << std::endl; // This line won't be executed
    } 
	catch (const Bureaucrat::GradeTooHighException& e) 
	{
        std::cerr << e.what() << std::endl;
    } 
	catch (const Bureaucrat::GradeTooLowException& e) 
	{
        std::cerr << e.what() << std::endl;
    }
	std::cout << "The resourcers in the try block have been destroyed when the exception was thrown" << std::endl;
	std::cout << std::endl;

	std::cout << "=== TEST 2 = Second try/catch block: promotion and demotion ===" << std::endl;
    try {
        Bureaucrat bureaucrat3("Charlie", 1);
        std::cout << bureaucrat3 << std::endl;
        
        bureaucrat3.demotion(); // Decrement the grade
        std::cout << bureaucrat3 << std::endl; // Should show grade 2

        bureaucrat3.promotion(); // Increment the grade
        std::cout << bureaucrat3 << std::endl; // Should show grade 1

		bureaucrat3.promotion(); // Should throw GradeTooLowException
        std::cout << bureaucrat3 << std::endl; // This line won't be executed
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}