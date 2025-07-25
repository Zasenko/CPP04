#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define RED         "\e[31m"
#define GREEN       "\e[32m"
#define YELLOW      "\e[33m"
#define BLUE        "\e[34m"
#define CYAN        "\e[36m"
#define RESET       "\e[0m"

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &copy);
        virtual ~Animal();
        Animal &operator=(const Animal &src);
        virtual void makeSound() const;
        std::string getType() const;
};

#endif