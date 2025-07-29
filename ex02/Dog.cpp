#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
    std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy), brain(new Brain(*copy.brain))
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
        *brain = *src.brain;
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