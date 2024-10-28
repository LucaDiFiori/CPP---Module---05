/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-24 07:57:25 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-24 07:57:25 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define YELLOW "\033[1;33m"
#  define RESET "\033[0m"
# endif

class Bureaucrat
{
	private:
		const std::string   _name;
		int                 _grade;

		Bureaucrat();

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		void    promotion();
		void    demotion();

		std::string    getName() const;
		int            getGrade() const;

		/*
		* what() const throw()
		* --------------------
		* The use of throw() in the method signature indicates that the function 
		* is not expected to throw any exceptions-
		* the throw() specifier is referring specifically to the what() method 
		* of the GradeTooHighException class. It indicates that this function is 
		* not allowed to throw any exceptions when it is called
		* ( https://cplusplus.com/reference/exception/exception/what/ )
		*
		* - So why use try/catch block in the main.cpp file?
			* The throw() (or noexcept) specifier in the context of the what() method 
			* in your exception classes doesn't affect whether exceptions can be thrown 
			* by other parts of your code. Here's a breakdown to clarify the situation
			* The Bureaucrat class can throw exceptions (GradeTooHighException and GradeTooLowException) 
			* in its constructor and member functions (like incrementGrade and decrementGrade) 
			* when invalid grades are encountered. This could throw exceptions of type
			* std::exception (the base class of GradeTooHighException and GradeTooLowException)
			* and we can catch these exceptions in the main.cpp file.
		*
		* example:
		* 	class myexception: public exception
			{
				virtual const char* what() const throw()
				{
					return "My exception happened";
				}
			} myex;

			int main () {
			try
			{
				throw myex;
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}
			return 0;
			}
		*
		  Output:
		  My exception happened
		*
		* When you throw an exception, you must specify its type. In this instance, 
		* I am throwing myex, which is an instance of the myexception class—a derived 
		* class of the base class std::exception. The catch block is designed to catch 
		* exceptions of type std::exception and will invoke the what() method 
		* of the myexception class, allowing it to provide a specific error message.
		*
		*
		*
		* virtual
		* -------
		* This declaration indicates that what() can be overridden in derived classes. 
		* When you call what() on a base class pointer or reference that points to a 
		* derived class object, the derived class’s version of what() will be executed.
		* (In the base class std::exception, the default implementation of the what() 
		* method usually returns a standard error message)
		*
		* In the derived class (GradeTooHighException), you can technically omit 
		* the virtual keyword because the function is already marked as virtual 
		* in the base class. The function remains virtual regardless of whether 
		* you specify it in the derived class or not.
		*
		* The primary reason to use virtual is to enable polymorphism. This means 
		* that you can call the overridden what() function on a pointer or reference 
		* of the base class type (std::exception). 
		* 
		* - Where i use pointers or references to the base class std::exception,
		*   to achieve polymorphism?
			* In the catch block in the main.cpp file, i'm catching the exception of type
			* std::exception&, so i can call the override what() method of the derived class
			* GradeTooHighException or GradeTooLowException.
		*/
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*		what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*		what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);

#endif
