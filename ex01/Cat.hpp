#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &copy);
        ~Cat();
        Cat &operator=(const Cat &src);
        void makeSound() const;
        void setBrainIdea(int i, const std::string &idea);
        std::string getBrainIdea(int i) const;
};

#endif