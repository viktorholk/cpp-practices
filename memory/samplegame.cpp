
#include <iostream>
#include "windows.h"
int main (){
    SetConsoleTitle("samplegame");
    const int sleep_time = 100;
    // Variable that we are going to change through writing to the memory
    int level   = 1234;
    while (true){
        std::cout << "Level:  " << level << std::endl;
        std::cout << std::endl;
        Sleep(sleep_time);
    }
}