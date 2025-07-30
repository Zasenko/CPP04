#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat default constructor called" <<std::endl;

    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy)
{
    std::cout << "WrongCat copy constructor called" <<std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" <<std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    std::cout << "WrongCat assignment operator called" <<std::endl;
    if (this != &src) {
        WrongAnimal::operator=(src);
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" <<std::endl;
}
