#include <iostream>
#include <string>

class Person {
public:
    // Constructor
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Copy Constructor
    Person(const Person& other) : name(other.name), age(other.age) {}

    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
};

int main() {
    // Create a Person object
    Person person1("Alice", 30);

    // Use the copy constructor to create a new object
    Person person2 = person1;

    // Display both objects
    person1.display();
    person2.display();

    return 0;
}
