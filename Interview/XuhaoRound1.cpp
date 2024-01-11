//Question:
//(1) You are given a list of integers, and your task is to create a function that processes the list and returns a new list with each integer squared.
// You need to implement this function using a std::vector<int> to store the squared integers.

//Create a function squareAndStore that takes an input vector of integers and returns a new vector of squared integers.

// The function should square each integer from the input vector and store the result in a new vector.

// (2) Write a function sortByDist that takes an input vector of integers and an integer, and sorts the elements
//     in the vector based on their distances from the given integer. In cases where two integers have the same distance
//     to the reference integers, the smaller integer will take precedence in the sorted order.


#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

struct StudentScores
{
    std::string name;
    double score;
    // constructor
    StudentScores(std::string name, double score): name(name), score(score) {}
    // copy constructor
    StudentScores(const StudentScores & other): name(other.name), score(other.score){
        std::cout << "Copy constructor has been called by : " << name << " " << score << std::endl;
    }
    // move constructor
    StudentScores(StudentScores && other) noexcept : name(other.name), score(other.score){
        std::cout << "Move constructor has been called: " <<  name << " " << score << std::endl;
    }
    
    StudentScores & operator = (const StudentScores & other)
    {
        std::cout << "Copy assignment has been called: " <<  other.name << " " << other.score << std::endl;
        if (this != &other)
        {
            name = other.name;
            score = other.score;
        }
        return *this;
    }
    
    StudentScores & operator = (StudentScores && other) noexcept
    {
        std::cout << "Move assignment has been called: " <<  other.name << " " << other.score << std::endl;
        if (this != &other)
        {
           name = std::move(other.name);
           score = std::move(other.score);
        }
        return *this;
    }
  
};


std::vector<StudentScores> sqrtAndTimes10(const std::vector<StudentScores> & input) 
{
   std::vector<StudentScores> res;
   res.reserve(sizeof(input));
   for (auto const & p : input)
   {
     res.emplace_back(StudentScores(p.name,std::sqrt(p.score)*10.0));
   }
   return res;
}

std::vector<StudentScores> sqrtAndTimes10_version2(const std::vector<StudentScores> & input)
{
    std::vector<StudentScores> res;
    res.reserve(sizeof(input));
    for (int i = 0;i<input.size();i++)
    {
        res.emplace_back(StudentScores(input[i].name,std::sqrt(input[i].score)*10.0));
    }
    return res;
}

auto lambda = [](const StudentScores & a,const StudentScores & b){
    if (a.score == b.score)
    {
        return a.name.substr(a.name.find_last_of(' ')+1) < b.name.substr(b.name.find_last_of(' ')+1);
    }
    else{
        return a.score > b.score;
    }
};

std::vector<int> squareAndStore(const std::vector<int>& input)
{
    std::vector<int> res;
    res.reserve(input.size());
    for (auto const & num: input)
    {
        res.emplace_back(num*num);
    }
    return res;
}

int main()
{
    // std::vector<int> input = {1,2,3,4,5};
    // auto res = squareAndStore(input);
    // for (auto const & num : res)
    // {
    //     std::cout << num << std::endl;
    // }
    std::vector<StudentScores> input2 = {StudentScores("Xiaoping Zhu",90.0),StudentScores("Stanley Zhang",90.0)};
    auto res2 = sqrtAndTimes10_version2(input2);
    // for (auto const & p : res2)
    // {
    //     std::cout << p.name << " : " << p.score << std::endl;
    // }
   // std::sort(res2.begin(),res2.end(),lambda);
    for (auto const & p : res2)
    {
        std::cout << p.name << " : " << p.score << std::endl;
    }

    return 0;
}
