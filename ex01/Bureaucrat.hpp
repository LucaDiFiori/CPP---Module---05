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

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
#  define YELLOW "\033[1;33m"
#  define RESET "\033[0m"
# endif

#include <iostream>
#include <stdexcept>
#include <string>
#include "Form.hpp"


class Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;

		Bureaucrat();

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();

		void			promotion();
		void			demotion();
		void			signForm(Form& form);

		std::string		getName() const;
		int				getGrade() const;


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
