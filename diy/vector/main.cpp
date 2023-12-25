#include<iostream>
#include"myvector.h"


template<typename T>
void PrintVector(const MyVector<T>&vector)
{
   for (size_t i = 0; i < vector.Size(); i++)
   {
    std::cout << vector[i] << std::endl;
   }
   std::cout << "-----------------------\n"; 
}

struct Point
{
   double x = 0.;
   double y = 0.;
   Point() {
    x = 0.;
    y=0.;
    }
   Point(double x, double y): x(x) , y(y){}
   // copy constructor
   Point(const Point & other) 
   {
     if (this != &other)
     {
        x = other.x;
        y = other.y;
     }
     std::cout << "Copy\n";
   }
  // copy assign
   Point & operator =(const Point & other) 
   {
     if (this != &other)
     {
        x = other.x;
        y = other.y;
     }
     std::cout << "Assign\n";
     return *this;
   }
   // move constructor
   Point(Point && other): x(other.x), y(other.y)
   {
    std::cout << "Move\n";
   }
   ~Point()
   {
    std::cout << "Destroy\n";
   }
   
};


void PrintVector(const MyVector<Point>&vector)
{
   for (size_t i = 0; i < vector.Size(); i++)
   {
    std::cout << vector[i].x << "," << vector[i].y << std::endl;
   }
   std::cout << "-----------------------\n"; 
}


int main()
{
    MyVector<std::string> vector;
    vector.PushBack("Xiaoping");
    vector.PushBack("C++");
    vector.PushBack("Vector");
    PrintVector(vector);
    MyVector<Point> pointVec;
    pointVec.PushBack(Point(1.1,2.1));
    pointVec.PushBack(Point());
    PrintVector(pointVec);
    return 0;
}