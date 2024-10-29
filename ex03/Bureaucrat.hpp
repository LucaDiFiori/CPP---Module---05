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
#include "AForm.hpp"


class Bureaucrat
{
	private:
		const std::string   _name;
		int                 _grade;

		Bureaucrat();

	public:
	    //Canonical form________________________________________________________
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();


		//methods_______________________________________________________________
		void            promotion();
		void            demotion();
		void            signForm(AForm& form);
		void            executeForm(const AForm& form); //Add a function called executeForm to the Bureaucrat class.

		//getters_______________________________________________________________
		std::string     getName() const;
		int             getGrade() const;

		//exceptions____________________________________________________________
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
