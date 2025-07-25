#include "Cat.hpp"

Cat::Cat() : Animal(), brain(NULL)
{
    std::cout << YELLOW << "Cat default constructor called" << RESET << std::endl;

    type = "Cat";
    brain = new Brain();
    if (!brain) {
        std::cout << "Malloc error" << std::endl;
        exit(1);
    }
}

Cat::Cat(const Cat &copy): Animal(copy), brain(NULL)
{
    std::cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
    brain = new Brain();
    if (!brain) {
        std::cout << "Malloc error" << std::endl;
        exit(1);
    }
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
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << YELLOW << "Miiiaaaaauuuuuuu....." << RESET << std::endl;
}
