#include "Dog.hpp"

Dog::Dog(): Animal()
{
    std::cout << "Dog default constructor called" <<std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &copy): Animal(copy)
{
    std::cout << "Dog copy constructor called" <<std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" <<std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Dog assignment operator called" <<std::endl;
    if (this != &src) {
        Animal::operator=(src);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark! Bark! Bark!" <<std::endl;

}