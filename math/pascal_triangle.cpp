#include <iostream>

int binomialCoeff(int n, int k){
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; i++){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void printPascal(int n){
    for (int i = 0; i < n; i++){
        std::cout << " > ";
        for (int j = 0; j <= i; j++){
            std::cout << binomialCoeff(i, j);
        }
        std::cout << std::endl;
    }
}

int main(){
    int n;
    std:: cout << "Type triangle length: ";
    std::cin >> n;
    std::cout << std::endl;
    printPascal(n);
    return 0;
}