#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
    std::cout << YELLOW << "Cat default constructor called" << RESET << std::endl;

    type = "Cat";
}

Cat::Cat(const Cat &copy): Animal(copy), brain(new Brain(*copy.brain))
{
    std::cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
    brain = new Brain();
}

Cat::~Cat()
{
    std::cout << YELLOW << "Cat destructor called" << RESET << std::endl;
    delete brain;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << YELLOW << "Cat assignment operator called" << RESET << std::endl;
    if (this != &src) {
        Animal::operator=(src);
        *brain = *src.brain;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << YELLOW << "Meow!" << RESET << std::endl;
}

void Cat::setBrainIdea(int i, const std::string &idea)
{
    brain->setIdea(i, idea);
}

std::string Cat::getBrainIdea(int i) const
{
    return brain->getIdea(i);
}
