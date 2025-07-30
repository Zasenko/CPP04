#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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
    std::cout << "Test: Animal constructors" << std::endl;

    Animal a;
    Animal b(a);
    Animal c;
    c = b;
    std::cout << "Type: " << a.getType() << std::endl;
    std::cout << "Type: " << b.getType() << std::endl;
    std::cout << "Type: " << c.getType() << std::endl;
    c.makeSound();
}
// Test: Animal constructors  
// Animal default constructor called  
// Animal copy constructor called  
// Animal default constructor called  
// Animal assignment operator called  
// Type:  
// Type:  
// Type:  

void testDogConstructors()
{
    std::cout << "Test: Dog constructors" << std::endl;
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
// Test: Dog constructors  
// Animal default constructor called  
// Dog default constructor called  
// Animal copy constructor called  
// Dog copy constructor called  
// Animal default constructor called  
// Dog default constructor called  
// Dog assignment operator called  
// Animal assignment operator called  
// Type: Dog  
// Type: Dog  
// Type: Dog  
// Bark! Bark! Bark!  
// Bark! Bark! Bark!  
// Bark! Bark! Bark!

void testCatConstructors()
{
    std::cout << "Test: Cat constructors" << std::endl;
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
// Test: Cat constructors  
// Animal default constructor called  
// Cat default constructor called  
// Animal copy constructor called  
// Cat copy constructor called  
// Animal default constructor called  
// Cat default constructor called  
// Cat assignment operator called  
// Animal assignment operator called  
// Type: Cat  
// Type: Cat  
// Type: Cat  
// Meow!  
// Meow!  
// Meow!

void testPolymorphism() {
    std::cout << "Test: Polymorphism from subject" << std::endl;
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
// Test: Polymorphism from subject  
// Animal default constructor called  
// Animal default constructor called  
// Dog default constructor called  
// Animal default constructor called  
// Cat default constructor called  
// Dog  
// Cat  
// Meow!  
// Bark! Bark! Bark!

// Cat destructor called  
// Animal destructor called  
// Dog destructor called  
// Animal destructor called  
// Animal destructor called

void testWrongAnimal() {
    std::cout << "Test: WrongAnimal test" << std::endl;
    const WrongAnimal *meta = new WrongAnimal();
    const WrongAnimal *i = new WrongCat();
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
}

// Test: WrongAnimal test  
// WrongAnimal default constructor called  
// WrongAnimal default constructor called  
// WrongCat default constructor called  
// WrongCat  
// WrongAnimal sound  
// WrongAnimal sound  
// WrongCat destructor called  
// WrongAnimal destructor called  
// WrongAnimal destructor called

// WrongCat::makeSound() не вызывается, потому что в WrongAnimal makeSound() не virtual

void testHeapAllocation()
{
    std::cout << "Test: Heap allocation and destruction" << std::endl;

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

// Test: Heap allocation and destruction  
// Animal default constructor called  
// Animal default constructor called  
// Dog default constructor called  
// Animal default constructor called  
// Cat default constructor called  

// Copying:  
// Animal copy constructor called  
// Animal copy constructor called  
// Dog copy constructor called  
// Animal copy constructor called  
// Cat copy constructor called  

// (makeSound вызывает:)  
// (ничего — Animal)  
// Bark! Bark! Bark!  
// Meow!  

// c:  
// a: Dog  
// d: Cat  

// Assignment:  
// Animal assignment operator called  
// Dog assignment operator called  
// Animal assignment operator called  
// Cat assignment operator called  

// (ещё раз makeSound)  
// (ничего)  
// Bark! Bark! Bark!  
// Meow!  

// c:  
// a: Dog  
// d: Cat  

// Destructors:  
// Animal destructor called  
// Dog destructor called  
// Animal destructor called  
// Cat destructor called  
// Animal destructor called  
// Cat destructor called  
// Animal destructor called