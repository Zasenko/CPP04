#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" <<std::endl;
}

Animal::Animal(const Animal &copy): type(copy.getType())
{
    std::cout << "Animal copy constructor called" <<std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" <<std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    std::cout << "Animal assignment operator called" <<std::endl;
    if (this != &src) {
        type = src.getType();
    }
    return *this;
}

void Animal::makeSound() const {}

std::string Animal::getType() const
{
    return this->type;
}