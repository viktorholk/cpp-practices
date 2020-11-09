#include <iostream>


int main(){
    int factorial = 1;
    int x;
    std::cout << "Type a number: ";
    std::cin >> x;
    std::cout << std::endl;

    for (int i = 1; i <= x; i++){
        factorial = factorial * i;
    }

    printf("Factorial of %d = %d \n", x, factorial);

    return 0;
}