#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void testDogWithBrain();
void testCatWithBrain();

int main(void)
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;
    delete i;

    int size = 4;
    Animal *animals[size];

    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Animal " << i << " type: " << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }

    for (int i = 0; i < size; ++i)
        delete animals[i];

    testDogWithBrain();
    testCatWithBrain();
   
    return 0;
}

void testDogWithBrain()
{
    std::cout << "Test: Dog constructors and brain (deep copy)" << std::endl;

    Dog dog;
    dog.setBrainIdea(0, "Wanna walk");
    dog.setBrainIdea(1, "I want food");
    dog.setBrainIdea(2, "I hate cats");

    Dog dog2(dog);

    Dog dog3;
    dog3 = dog2;

    std::cout << "Types:" << std::endl;
    std::cout << "dog: " << dog.getType() << std::endl;
    std::cout << "dog2: " << dog2.getType() << std::endl;
    std::cout << "dog3: " << dog3.getType() << std::endl;

    std::cout << "Sounds:" << std::endl;
    dog.makeSound();
    dog2.makeSound();
    dog3.makeSound();

    std::cout << "Brain ideas before change:" << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(0) << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(1) << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(2) << std::endl;
    std::cout << "dog2: " << dog2.getBrainIdea(0) << std::endl;
    std::cout << "dog2: " << dog2.getBrainIdea(1) << std::endl;
    std::cout << "dog2: " << dog2.getBrainIdea(2) << std::endl;
    std::cout << "dog3: " << dog3.getBrainIdea(0) << std::endl;
    std::cout << "dog3: " << dog3.getBrainIdea(1) << std::endl;
    std::cout << "dog3: " << dog3.getBrainIdea(2) << std::endl;

    dog.setBrainIdea(0, "Dig holes");
    dog2.setBrainIdea(3, "Guard house");

    std::cout << "Brain ideas after change:" << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(0) << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(1) << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(2) << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(3) << std::endl;

    std::cout << "dog2: " << dog2.getBrainIdea(0) << std::endl;
    std::cout << "dog2: " << dog2.getBrainIdea(1) << std::endl;
    std::cout << "dog2: " << dog2.getBrainIdea(2) << std::endl;
    std::cout << "dog2: " << dog2.getBrainIdea(3) << std::endl;

    std::cout << "dog3: " << dog3.getBrainIdea(0) << std::endl;
    std::cout << "dog3: " << dog3.getBrainIdea(1) << std::endl;
    std::cout << "dog3: " << dog3.getBrainIdea(2) << std::endl;
    std::cout << "dog3: " << dog3.getBrainIdea(3) << std::endl;
}

// [Test] Dog constructors and brain (deep copy)  
// Animal default constructor called  
// [Brain] Constructor called  
// Dog constructor called  
// Animal copy constructor called  
// [Brain] Copy constructor called  
// Dog copy constructor called  
// Animal default constructor called  
// [Brain] Constructor called  
// Dog constructor called  
// Dog assignment operator called  
// Animal assignment operator called  
// [Brain] Assignment operator called

// Types:  
// dog:   Dog  
// dog2:  Dog  
// dog3:  Dog  

// Sounds:  
// Woof!  
// Woof!  
// Woof!  

// Brain ideas before change:  
// dog:   Chase cats  
// dog2:  Chase cats  
// dog3:  Chase cats  

// Brain ideas after change:  
// dog:   Dig holes  
// dog2:  Guard house  
// dog3:  Chase cats

void testCatWithBrain()
{
    std::cout << "Test: Cat constructors and brain (deep copy)" << std::endl;

    Cat cat;
    cat.setBrainIdea(0, "Milk!");
    cat.setBrainIdea(1, "I wanna be alone");

    Cat cat2(cat);

    Cat cat3;
    cat3 = cat2;

    std::cout << "Types:" << std::endl;
    std::cout << "cat: " << cat.getType() << std::endl;
    std::cout << "cat2: " << cat2.getType() << std::endl;
    std::cout << "cat3: " << cat3.getType() << std::endl;

    std::cout << "Sounds:" << std::endl;
    cat.makeSound();
    cat2.makeSound();
    cat3.makeSound();

    std::cout << "Brain ideas before change:" << std::endl;
    std::cout << "cat: " << cat.getBrainIdea(0) << std::endl;
    std::cout << "cat: " << cat.getBrainIdea(1) << std::endl;
    std::cout << "cat2: " << cat2.getBrainIdea(0) << std::endl;
    std::cout << "cat2: " << cat2.getBrainIdea(1) << std::endl;
    std::cout << "cat3: " << cat3.getBrainIdea(0) << std::endl;
    std::cout << "cat3: " << cat3.getBrainIdea(1) << std::endl;

    cat.setBrainIdea(0, "Clean my fur");
    cat2.setBrainIdea(2, "Play with me");

    std::cout << "Brain ideas after change:" << std::endl;
    std::cout << "cat: " << cat.getBrainIdea(0) << std::endl;
    std::cout << "cat: " << cat.getBrainIdea(1) << std::endl;
    std::cout << "cat: " << cat.getBrainIdea(2) << std::endl;

    std::cout << "cat2: " << cat2.getBrainIdea(0) << std::endl;
    std::cout << "cat2: " << cat2.getBrainIdea(1) << std::endl;
    std::cout << "cat2: " << cat2.getBrainIdea(2) << std::endl;

    std::cout << "cat3: " << cat3.getBrainIdea(0) << std::endl;
    std::cout << "cat3: " << cat3.getBrainIdea(1) << std::endl;
    std::cout << "cat3: " << cat3.getBrainIdea(2) << std::endl;
}