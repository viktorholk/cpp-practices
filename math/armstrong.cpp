#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>

// Count the digits in a number. Returns a list since we both get the number in the correct oreder, and to get the total count of digits you can _list.size()
std::vector<int> get_digits(int n){
    std::vector<int> _list;
    while (n){
        int digit = n % 10;
        n /= 10;
        _list.push_back(digit);
    }
    std::reverse(_list.begin(), _list.end());
    return _list;
}

// Compare armstrong number and return boolean
bool check_armstrong(int n){
    std::vector<int> digits = get_digits(n);
    int temp = n, sum = 0;
    for (int i = 0; i < digits.size(); i++)
    {
       sum += round(pow(digits[i], digits.size()));
    }
    if (temp == sum){
        return true;
    }
    return false;
}

// Go through all numbers between start and stop and return the list of armstrong numbers.
// The passed function is checking if its a valid armstrong number
std::vector<int> get_armstrong(int start, int stop, std::function<bool(int)> func){
    std::vector<int> _list;
    for (int i = start; i < stop; i++){
        if (func(i)){
            _list.push_back(i);
        }
    }
    return _list;
}

int main(){
    // Get start and stop numbers
    int start, stop;
    std::cout << "Input a start number:" << std::endl;
    std::cout << " > ";
    std::cin >> start;
    std::cout << std::endl;
    std::cout << "Input a start number:" << std::endl;
    std::cout << " > ";
    std::cin >> stop;

    std::vector<int> _ = get_armstrong(start, stop, check_armstrong);
    for (int i = 0; i < _.size(); i++){
        std::cout << _[i] << ", ";
    }
}