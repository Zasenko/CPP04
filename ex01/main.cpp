#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void testDogWithBrain();
void testCatWithBrain();

int main(void)
{

    std::cout << "Test: from Subject:" << std::endl;

    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;
    delete i;

    std::cout << "\nTest: Array of Animals pointert:" << std::endl;

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
    std::cout << "\nTest: Dog constructors and brain (deep copy)" << std::endl;

    Dog dog;
    dog.setBrainIdea(0, "Wanna walk");
    dog.setBrainIdea(1, "I want food");
    dog.setBrainIdea(2, "I hate cats");

    Dog dog2(dog);

    Dog dog3;
    dog3 = dog2;

    std::cout << "\nTypes:" << std::endl;
    std::cout << "dog: " << dog.getType() << std::endl;
    std::cout << "dog2: " << dog2.getType() << std::endl;
    std::cout << "dog3: " << dog3.getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    dog.makeSound();
    dog2.makeSound();
    dog3.makeSound();

    std::cout << "\nBrain ideas before change:" << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(0) << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(1) << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(2) << std::endl;
    std::cout << "\ndog2: " << dog2.getBrainIdea(0) << std::endl;
    std::cout << "dog2: " << dog2.getBrainIdea(1) << std::endl;
    std::cout << "dog2: " << dog2.getBrainIdea(2) << std::endl;
    std::cout << "\ndog3: " << dog3.getBrainIdea(0) << std::endl;
    std::cout << "dog3: " << dog3.getBrainIdea(1) << std::endl;
    std::cout << "dog3: " << dog3.getBrainIdea(2) << std::endl;

    dog.setBrainIdea(0, "Dig holes");
    dog2.setBrainIdea(3, "Guard house");
    dog3.setBrainIdea(3, "Dig holes");

    std::cout << "\nBrain ideas after change:" << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(0) << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(1) << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(2) << std::endl;
    std::cout << "dog: " << dog.getBrainIdea(3) << std::endl;

    std::cout << "\ndog2: " << dog2.getBrainIdea(0) << std::endl;
    std::cout << "dog2: " << dog2.getBrainIdea(1) << std::endl;
    std::cout << "dog2: " << dog2.getBrainIdea(2) << std::endl;
    std::cout << "dog2: " << dog2.getBrainIdea(3) << std::endl;

    std::cout << "\ndog3: " << dog3.getBrainIdea(0) << std::endl;
    std::cout << "dog3: " << dog3.getBrainIdea(1) << std::endl;
    std::cout << "dog3: " << dog3.getBrainIdea(2) << std::endl;
    std::cout << "dog3: " << dog3.getBrainIdea(3) << std::endl;
}

void testCatWithBrain()
{
    std::cout << "\nTest: Cat constructors and brain (deep copy)" << std::endl;

    Cat cat;
    cat.setBrainIdea(0, "Milk!");
    cat.setBrainIdea(1, "I am beautiful");

    Cat cat2(cat);

    Cat cat3;
    cat3 = cat2;

    std::cout << "\nTypes:" << std::endl;
    std::cout << "cat: " << cat.getType() << std::endl;
    std::cout << "cat2: " << cat2.getType() << std::endl;
    std::cout << "cat3: " << cat3.getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    cat.makeSound();
    cat2.makeSound();
    cat3.makeSound();

    std::cout << "\nBrain ideas before change:" << std::endl;
    std::cout << "cat: " << cat.getBrainIdea(0) << std::endl;
    std::cout << "cat: " << cat.getBrainIdea(1) << std::endl;
    std::cout << "\ncat2: " << cat2.getBrainIdea(0) << std::endl;
    std::cout << "cat2: " << cat2.getBrainIdea(1) << std::endl;
    std::cout << "\ncat3: " << cat3.getBrainIdea(0) << std::endl;
    std::cout << "cat3: " << cat3.getBrainIdea(1) << std::endl;

    cat.setBrainIdea(0, "Time to drink");
    cat2.setBrainIdea(1, "Play with me");
    cat3.setBrainIdea(1, "What a beautiful day");

    std::cout << "\nBrain ideas after change:" << std::endl;
    std::cout << "cat: " << cat.getBrainIdea(0) << std::endl;
    std::cout << "cat: " << cat.getBrainIdea(1) << std::endl;

    std::cout << "\ncat2: " << cat2.getBrainIdea(0) << std::endl;
    std::cout << "cat2: " << cat2.getBrainIdea(1) << std::endl;

    std::cout << "\ncat3: " << cat3.getBrainIdea(0) << std::endl;
    std::cout << "cat3: " << cat3.getBrainIdea(1) << std::endl;
}