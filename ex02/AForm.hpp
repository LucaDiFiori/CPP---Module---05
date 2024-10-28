/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-26 17:54:33 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-26 17:54:33 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define YELLOW "\033[1;33m"
#  define RESET "\033[0m"
# endif

# define MAX_GRADE 1
# define MIN_GRADE 150
 
class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

		Form();



	protected:
		// Add a pure virtual function called performAction to the Form class. 
		// This function will be implemented by the derived classes.
    	virtual void useForm() const = 0; 



	public:
		//Canonical form_________________________________________________________
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& src);
		virtual ~Form();  //Add a virtual destructor to the Form class.

		Form& operator=(const Form& src);

		//Methods_______________________________________________________________
		void	beSigned(Bureaucrat& Bureau);
		// Add a new member function called execute. This function will check if the 
		//form is signed and if the bureaucrat's grade is high enough to execute the form. 
		//If both conditions are met, the form will call the performAction function 
		//(which will be implemented by the derived classes).
		void	execute(const Bureaucrat & executor) const;



		//Getters & setters_____________________________________________________
		std::string			getName() const;
		bool				getSigned() const;
		void				setSigned(bool status);
		int					getGradeToSign() const;
		int					getGradeToExec() const;


		//Exceptions____________________________________________________________
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

		//Add a new exception class called FormNotSignedException.
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char*		what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& src);



#endif