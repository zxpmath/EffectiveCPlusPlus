#include<iostream>
#include<vector>
#include<algorithm>

void HelloWorld(int a)
{
    std::cout << "Hello World value :" <<  a <<  std::endl;
}

void PrintValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}
void ForEach(const std::vector<int> & values, void(*func)(int))
{
    for (int value : values)
    {
        func(value);
    }
}

// Lamba : anoynomous function. 

int main()
{
    
    typedef void(*HelloWorldFunction)(int);

    HelloWorldFunction function = HelloWorld;

    function(8);
    function(5);

    std::vector<int> values = {1,2,4,5,3};
    auto lambda = [] (int value){std::cout << "Value:" << value << std::endl;};
    // [] captures
    // [a, &b] a is captured by copy and b is captured by reference.
    // [this] capture the current object by reference.
    // [&] captures all automatic variables used in the body of the lambda by reference and current object by references if exists.
    // [=] captures all automatic variables used in the body of the lambda by the copy and current object by reference if exists.
    // [] captures nothing.
    ForEach(values,[](int value){std::cout << "Value: "<< value << std::endl;});
    std::sort(values.begin(),values.end(),[](int a, int b){return a < b;});
    for (int v : values)
    {
        std::cout << v << std::endl;
    }
    return 0;
}