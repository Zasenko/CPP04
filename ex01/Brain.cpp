#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy) {
    std::cout << "Brain copy constructor called" << std::endl;
    *ideas = *copy.ideas;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &src) {
        *ideas = *src.ideas;
    }
    return *this;
}
