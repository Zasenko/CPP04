#include "Animal.hpp"

Animal::Animal()
{
    std::cout << RED << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &copy): type(copy.getType())
{
    std::cout << RED << "Animal copy constructor called" << RESET << std::endl;
}

Animal::~Animal()
{
    std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    std::cout << RED << "Animal assignment operator called" << RESET << std::endl;
    if (this != &src) {
        type = src.getType();
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << RED << "Default sound" << RESET << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}