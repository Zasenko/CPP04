#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = copy.ideas[i];
    }
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &src) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = src.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(int i, const std::string &idea)
{
    if (i >= 0 && i < 100) {
        ideas[i] = idea;
    }
}

std::string Brain::getIdea(int i) const
{
    return (i >= 0 && i < 100) ? ideas[i] : "";
}
