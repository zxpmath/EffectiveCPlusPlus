#include <iostream>
#include <vector>
#include <string>

class MyString {
private:
    std::string *str;

public:
    // Constructor
    MyString(const std::string &s) : str(new std::string(s)) {
        std::cout << "Copy" << std::endl;
    }
    //Copy Constructor
    MyString(const MyString & other) : str(new std::string(*(other.str)))
    {
        std::cout << "Copy Constructor" << std::endl;
    }

    // Destructor
    ~MyString(){
        delete str;
    }

    // Copy Assignment
    MyString & operator =(const MyString &other)
    {
        if (this !=&other)
        {
            delete str;
            str = new std::string(*(other.str));
        }
        std::cout << "Copy Assignment" << std::endl;
        return *this;
    }

    //Move Constructor
    MyString(MyString && other) : str(std::move(other.str))
    {
        std::cout << "Move Constructor" << std::endl;
        other.str = nullptr;
    }

    // // Move Assignment operator
    MyString & operator = (MyString && other)
    {
        if (this != &other)
        {
            str = std::move(other.str);
            other.str = nullptr;
        }
        std::cout << "Move Assignment" << std::endl;
        return *this;
    }
    

    std::string GetString() const { return *str; }
    void SetString(const std::string & s) {*str = s;}


};

int main() {
    std::vector<MyString> strings;
    
    // Create a MyString object and add it to the vector
    MyString hello("Hello");
    strings.push_back(hello);
    hello.SetString("Modified");
    std::cout << hello.GetString() << std::endl;
    
    // Print the strings stored in the vector
    for (const MyString& s : strings) {
        std::cout << s.GetString() << " ";
    }

    return 0;
}