/*
1. Can you explain the concept of encapsulation in C++?
Additionally, could you provide an example of how you would use encapsulation to protect the integrity of an object's internal state?
2. How does inheritance work in C++? 
Please illustrate this with an example where a derived class inherits from a base class, 
and explain how access specifiers affect inheritance.
3.What is polymorphism in the context of C++ programming, and why is it important? 
Can you demonstrate with a code example showing both compile-time and run-time polymorphism?
Also, can you tell me whether you have used polymorphism in your project ?
*/

#include<iostream>

// Derived class for circle
// public, private, protected.
// public: public -> public, protected -> protected, private -> not accessible "is-a" relation e.g. a Car is-a Vehicle.
// protected: public and protected -> protected.
// private: public and protected -> private has a : Stack has a list.

//************************************************************************
// Example for difference of composition and private inheritance
class Logger {
public:
    void log(const std::string& message) {
        std::cout << "Log: " << message << std::endl;
    }
};

class FileProcessor : private Logger {
public:
    void processFile(const std::string& file) {
        // Use Logger's functionality
        log("Processing file: " + file);
        // File processing logic...
    }
};

class Logger2 {
public:
    void log(const std::string& message) {
        std::cout << "Log: " << message << std::endl;
    }
};

class FileProcessor2 {
private:
    Logger2 logger; // Composition: FileProcessor has-a Logger

public:
    void processFile(const std::string& file) {
        // Use Logger's functionality
        logger.log("Processing file: " + file);
        // File processing logic...
    }
};


//*****************************************************************
// Example of the inheritance.

class Shape {
    public:
     Shape() {}

     // virtual method for calculating area
     virtual double area() const = 0;

     // virtual method for calculating perimeter
     virtual double perimeter() const = 0;

     // virtual destructor
     virtual ~Shape() {}
};

class Circle : public Shape{
    private:
    double radius;
    public:
    Circle(double r) : radius(r) {}

    double area() const override{
        return 3.14159* radius * radius;
    }

    double perimeter() const override{
        return 2*3.14159*radius;
    }
};

// Derived class for rectangle
class Rectangle : public Shape{
    private:
    double width;
    double length;
    public:
    Rectangle(double w, double l): width(w), length(l){}

    double area() const override{
        return width * length;
    }

    double perimeter() const override{
        return 2*width + 2*length;
    }
};

//*******************************************************
//Run-time polymorphism (virtual functions)

class Base{
public:
    virtual void display(){
        std::cout << "Display of Base" << std::endl;
    }
};

class Derived: public Base
{
public:
    void display() override{
        std::cout << "Display of Derived" << std::endl;
    }
};

void demonstrateRuntimePolymorphism(){
    Base *basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;
    basePtr->display();
}
//***************************************
//Example of Compile-time Polymorphism(Function Overloading)
class CompileTimePolymorphism{
    public: 
       void display(){
        std::cout << "Display without parameters " << std::endl;
       }
       void display(int i){
        std::cout << "Display with int parameter " << i << std::endl;
       }
};

int main()
{
    Shape* shape1 = new Circle(5.0);
    Shape* shape2 = new Rectangle(2.0,3.0);

    std::cout << "Circle Area: " << shape1->area() << std::endl;
    std::cout << "Rectangle Area: " << shape2->area() << std::endl;

    delete shape1;
    delete shape2;
    demonstrateRuntimePolymorphism();
    CompileTimePolymorphism obj;
    obj.display();
    obj.display(5);
    return 0;
}
