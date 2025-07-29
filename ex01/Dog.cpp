#include "Dog.hpp"

Dog::Dog(): Animal()
{
    std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &copy): Animal(copy)
{
    std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
    std::cout << GREEN << "Dog destructor called" << RESET << std::endl;
    delete brain;
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << GREEN << "Dog assignment operator called" << RESET << std::endl;
    if (this != &src) {
        Animal::operator=(src);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << GREEN << "Bark! Bark! Bark!" << RESET << std::endl;
}

void Dog::setBrainIdea(int i, const std::string &idea)
{
    brain->setIdea(i, idea);
}

std::string Dog::getBrainIdea(int i) const
{
    return brain->getIdea(i);
}