#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void testAnimalConstructors();
void testDogConstructors();
void testCatConstructors();
void testPolymorphism();
void testWrongAnimal();
void testHeapAllocation();

int main(void)
{
    testAnimalConstructors();
    testDogConstructors();
    testCatConstructors();
    testPolymorphism();
    testWrongAnimal();
    testHeapAllocation();
}

void testAnimalConstructors()
{
    std::cout << "\nTest: Animal constructors" << std::endl;

    Animal a;
    Animal b(a);
    Animal c;
    c = b;
    std::cout << "Type: " << a.getType() << std::endl;
    std::cout << "Type: " << b.getType() << std::endl;
    std::cout << "Type: " << c.getType() << std::endl;
    c.makeSound();
}

void testDogConstructors()
{
    std::cout << "\nTest: Dog constructors" << std::endl;
    Dog dog;
    Dog dog2(dog);
    Dog dog3;
    dog3 = dog2;
    std::cout << "Type: " << dog.getType() << std::endl;
    std::cout << "Type: " << dog2.getType() << std::endl;
    std::cout << "Type: " << dog3.getType() << std::endl;
    dog.makeSound();
    dog2.makeSound();
    dog3.makeSound();
}

void testCatConstructors()
{
    std::cout << "\nTest: Cat constructors" << std::endl;
    Cat cat;
    Cat cat2(cat);
    Cat cat3;
    cat3 = cat2;
    std::cout << "Type: " << cat.getType() << std::endl;
    std::cout << "Type: " << cat2.getType() << std::endl;
    std::cout << "Type: " << cat3.getType() << std::endl;
    cat.makeSound();
    cat2.makeSound();
    cat3.makeSound();
}

void testPolymorphism() {
    std::cout << "\nTest: Polymorphism from subject" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;
}
void testWrongAnimal() {
    std::cout << "\nTest: WrongAnimal test" << std::endl;
    const WrongAnimal *meta = new WrongAnimal();
    const WrongAnimal *i = new WrongCat();
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
}

void testHeapAllocation()
{
    std::cout << "\nTest: Heap allocation and destruction" << std::endl;

    Animal *animal = new Animal();
    Dog *dog = new Dog();
    Cat *cat = new Cat();

    std::cout << "Copying:" << std::endl;

    Animal *animal_copy = new Animal(*animal);
    Animal *dog_copy = new Dog(*(Dog *)dog);
    Animal *cat_copy = new Cat(*(Cat *)cat);

    animal_copy->makeSound();
    dog_copy->makeSound();
    cat_copy->makeSound();

    std::cout << "c: " << animal_copy->getType() << std::endl;
    std::cout << "a: " << dog_copy->getType() << std::endl;
    std::cout << "d: " << cat_copy->getType() << std::endl;

    std::cout << "Assignment:" << std::endl;

    *animal_copy = *animal;
    *dog_copy = *dog;
    *cat_copy = *cat;

    animal_copy->makeSound();
    dog_copy->makeSound();
    cat_copy->makeSound();

    std::cout << "c: " << animal_copy->getType() << std::endl;
    std::cout << "a: " << dog_copy->getType() << std::endl;
    std::cout << "d: " << cat_copy->getType() << std::endl;

    std::cout
        << "Destructors:" << std::endl;

    delete animal;
    delete dog;
    delete cat;
    delete dog_copy; 
    delete cat_copy;
    delete animal_copy;
}
