#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called" <<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy): type(copy.getType())
{
    std::cout << "WrongAnimal copy constructor called" <<std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" <<std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    std::cout << "WrongAnimal assignment operator called" <<std::endl;
    if (this != &src) {
        type = src.getType();
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "Bla bla bla!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}