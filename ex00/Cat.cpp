#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << YELLOW << "Cat default constructor called" << RESET << std::endl;

    type = "Cat";
}

Cat::Cat(const Cat &copy): Animal(copy)
{
    std::cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
    std::cout << YELLOW << "Cat destructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << YELLOW << "Cat assignment operator called" << RESET << std::endl;
    if (this != &src) {
        Animal::operator=(src);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << YELLOW << "Miiiaaaaauuuuuuu....." << RESET << std::endl;
}
