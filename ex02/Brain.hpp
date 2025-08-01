#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &copy);
        virtual ~Brain();
        Brain &operator=(const Brain &src);
        void setIdea(int i, const std::string &idea);
        std::string getIdea(int i) const;
};

#endif