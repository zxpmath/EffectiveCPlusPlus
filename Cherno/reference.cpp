#include<iostream>

void Increment(int* value)
{
    (*value)++;
}

int main()
{
    int a = 5;
    int *b = & a;
    int& ref = a; // ref is a reference and is a alias.
    ref = 2;
    Increment(&a);
    std::cout << a << std::endl;
    return 0;
}