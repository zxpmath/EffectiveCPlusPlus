#include<iostream>
#include<cstring>

// this is just for raw pointers.

#define LOG(x) std::cout << x << std::endl;

int main()
{
    int var = 8;
    int*  ptr = &var; // 0 is invalid
    *ptr  = 10;
    LOG(var);                  // deference
    char* buffer = new char[8];
    memset(buffer,0,8);
    char ** ptr = &buffer;
    delete [] buffer;
    return 0;
}

