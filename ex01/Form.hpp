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

#ifndef FORM_HPP
# define FORM_HPP

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
		const std::string   _name;
		bool                _signed;
		const int           _gradeToSign;
		const int           _gradeToExec;

		Form();

	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& src);
		~Form();

		Form& operator=(const Form& src);

		void                beSigned(Bureaucrat& Bureau);


		std::string         getName() const;
		bool                getSigned() const;
		void                setSigned(bool status);
		int                 getGradeToSign() const;
		int                 getGradeToExec() const;


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

std::ostream& operator<<(std::ostream& os, const Form& src);



#endif