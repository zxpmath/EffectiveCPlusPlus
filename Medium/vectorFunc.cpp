//Question:
//(1) You are given a list of integers, and your task is to create a function that processes the list and returns a new list with each integer squared.
// You need to implement this function using a std::vector<int> to store the squared integers.

//Create a function squareAndStore that takes an input vector of integers and returns a new vector of squared integers.

// The function should square each integer from the input vector and store the result in a new vector.

// (2) Write a function sortByDist that takes an input vector of integers and an integer, and sorts the elements
//     in the vector based on their distances from the given integer. In cases where two integers have the same distance
//     to the reference integers, the smaller integer will take precedence in the sorted order.



#include <iostream>
#include <vector>
#include<algorithm>

// std::vector<int> squareAndStore(const std::vector<int>& input) {
//     std::vector<int> result;
//     result.reserve(input.size());  // Preallocate memory for the result vector

//     for (const int& num : input) {
//         // Use emplace_back to construct the squared integer in-place
//         result.emplace_back(num * num);
//     }

//     return result;
// }

 std::vector<int> squareAndStore(const std::vector<int>& input) {
    std::vector<int> result(input.size());
    for(int i = 0;i<input.size();i++)
    {
        result[i] = input[i]*input[i];
    }
    return result;
}

bool sortByDistComp(int a, int b ,int ref)
{
    int distA = std::abs(a-ref);
    int distB = std::abs(b-ref);
    if (distA == distB)
    {
        return a < b;
    }
    else {
        return distA < distB;
    }
}

void sortByDist(std::vector<int> & input, int ref)
{
    std::sort(input.begin(),input.end(),[&ref](int a, int b){
        return sortByDistComp(a,b,ref);
    });
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> result = squareAndStore(input);

    for (const int& num : result) {
        std::cout << num << " ";
    }
    sortByDist(input, 3);
    for(const int & num : input)
    {
        std::cout << num << " ";
    }
    return 0;
}
