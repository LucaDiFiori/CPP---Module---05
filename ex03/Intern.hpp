/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:27:26 by luca              #+#    #+#             */
/*   Updated: 2024/10/29 15:11:52 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//Form types____________________________________________________________
enum FormType
{
    PRESIDENTIAL_PARDON,
    ROBOTOMY_REQUEST,
    SHRUBBERY_CREATION,
    UNKNOWN
};

class Intern
{
    private:
        std::string formNames[3];
        
        //getter "utils"________________________________________________________
        FormType getFormType(const std::string& formName);

        //Form creation "utils"_________________________________________________
        static AForm* createRobotomyRequestForm(const std::string& target);
        static AForm* createShrubberyCreationForm(const std::string& target);
        static AForm* createPresidentialPardonForm(const std::string& target);

        
    public:
        //Canonical form________________________________________________________
        Intern();
        Intern(const Intern& src);
        ~Intern();
        Intern& operator=(const Intern& src);

        //Form creation_________________________________________________________
        AForm* makeForm(const std::string& formName, const std::string& target);       
};

#endif