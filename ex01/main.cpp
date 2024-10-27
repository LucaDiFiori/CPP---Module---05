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
#include "Form.hpp"
#include "Bureaucrat.hpp"

void formToHight()
{
	std::cout << "=== Test 1: Create a form with a grade too high ===" << std::endl;
	try
	{
		Form form("FormA", 0, 0);
	}
	catch (std::exception& e)
	{
		std::cerr << "  Exception caught: " << e.what() << std::endl;
	}
}

void formToLow()
{
	std::cout << "=== Test 2: Create a form with a grade too low ===" << std::endl;
	try
	{
		Form form("FormA", 151, 151);
	}
	catch (std::exception& e)
	{
		std::cerr << "  Exception - 1 caught: " << e.what() << std::endl;
	}
}

int main()
{
	// TEST 1, 2
    formToHight();
    formToLow();
    std::cout << std::endl;


	// TEST 3
    std::cout << "=== Test 3: Create Bureaucrats and valid forms ===" << std::endl;

    try
    {
        Bureaucrat highRank("Alice", 1);
        std::cout << highRank << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while creating highRank: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat lowRank("Bob", 150);
        std::cout << lowRank << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while creating lowRank: " << e.what() << std::endl;
    }

    try
    {
		std::cout << std::endl;
        Form formA("FormA", 50, 25);
        std::cout << formA;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while creating formA: " << e.what() << std::endl;
    }

    try
    {
		std::cout << std::endl;
        Form formB("FormB", 1, 1);
        std::cout << formB;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while creating formB: " << e.what() << std::endl;
    }



	// TEST 4
	std::cout << "\n=== Test 3: Sign forms ===" << std::endl;
    try
    {
		std::cout << "1)" <<std::endl;
        Bureaucrat highRank("Alice", 1);
        Form formA("FormA", 50, 25);
        highRank.signForm(formA);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while highRank signing formA: " << e.what() << std::endl;
    }

    try
    {
		std::cout << "2)" <<std::endl;
        Bureaucrat lowRank("Bob", 150);
        Form formB("FormB", 1, 1);
        lowRank.signForm(formB);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while lowRank signing formB: " << e.what() << std::endl;
    }

    try
    {
		std::cout << "3)" <<std::endl;
        Bureaucrat highRank("Alice", 1);
        Form formB("FormB", 1, 1);
        highRank.signForm(formB);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught while highRank signing formB: " << e.what() << std::endl;
    }

    return 0;
}
