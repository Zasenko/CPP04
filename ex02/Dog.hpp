#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &copy);
        ~Dog();
        Dog &operator=(const Dog &src);
        void makeSound() const;
        void setBrainIdea(int i, const std::string &idea);
        std::string getBrainIdea(int i) const;
};

#endif