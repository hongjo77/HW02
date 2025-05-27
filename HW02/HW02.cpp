#include "HW02.h"
#include <cstdlib>
#include <ctime>

void Animal::makeSound() {}
Animal::~Animal() {}

void Dog::makeSound() 
{ 
    cout << "港港" << endl; 
}

void Cat::makeSound() 
{ 
    cout << "具克" << endl; 
}
void Cow::makeSound() 
{ 
    cout << "澜皋" << endl; 
}

void Zoo::addAnimal(Animal* animal)
{
    if (animalCount < 10)
    {
        animals[animalCount++] = animal;
    }
    else
    {
        cout << "Full" << endl;
        delete animal;
    }
}

void Zoo::performActions()
{
    for (int i = 0; i < animalCount; i++)
    {
        animals[i]->makeSound();
    }
}

Zoo::~Zoo() {
    for (int i = 0; i < animalCount; i++) {
        delete animals[i];
    }
}

Animal* createRandomAnimal() {
    int random = rand() % 3;

    return random == 0 ? static_cast<Animal*>(new Dog())
        : (random == 1 ? static_cast<Animal*>(new Cat())
            : static_cast<Animal*>(new Cow()));
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Animal* animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cow();

    for (int i = 0; i < 3; ++i) {
        animals[i]->makeSound();
        delete animals[i];
    }
    cout << endl;

    Zoo zoo;

    for (int i = 0; i < 12; i++)
    {
        zoo.addAnimal(createRandomAnimal());
    }

    zoo.performActions();

    return 0;
}