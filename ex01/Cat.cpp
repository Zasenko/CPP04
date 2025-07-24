#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" <<std::endl;

    type = "Cat";
}

Cat::Cat(const Cat &copy): Animal(copy)
{
    std::cout << "Cat copy constructor called" <<std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" <<std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Cat assignment operator called" <<std::endl;
    if (this != &src) {
        Animal::operator=(src);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Miiiaaaaauuuuuuu....." <<std::endl;
}
