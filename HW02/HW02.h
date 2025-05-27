#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual void makeSound();
    virtual ~Animal();
};

class Dog : public Animal {
public:
    void makeSound() override;
};

class Cat : public Animal {
public:
    void makeSound() override;
};

class Cow : public Animal {
public:
    void makeSound() override;
};

class Zoo {
private:
    Animal* animals[10];
    int animalCount = 0;

public:
    void addAnimal(Animal* animal);
    void performActions();
    ~Zoo();
};

Animal* createRandomAnimal();

