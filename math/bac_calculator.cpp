#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <tuple>
int getInput(){
    std::cout << " >";
    int i; // input variable
    std::cin >> i;
    std::cout << std::endl;
    return i;
}

int main(){
    enum genders  {
        male,
        female
    };

    int gender; // 1 for male, 2 for female
    int height;
    int weight;
    int amountOfDrinks;
    
    std::cout << "BAC Calculator" << std::endl;
    std::cout << "First start off with inputing your gender, weight and height" << std::endl;
    std::cout << "Then input the amount of drinks you have been drinking and the program will calculate your BAC.";
    std::cout << std::endl;
    
    std::cout << "Are you male or female?" << std::endl;
    std::cout << "Input 0 for male" << std::endl;
    std::cout << "Input 1 for female" << std::endl;

    while (1){
        gender = getInput();
        if (gender == male || gender == female) break;
    }

    std::cout << "What is your height? (cm)" << std::endl;
    while (1){
        height = getInput();
        if (height > 100) break;
    }

    std::cout << "What is your weight? (kg)" << std::endl;
    while (1){
        weight = getInput();
        if (weight > 45) break;
    }
    std::cout << std::endl;

    std::cout << "How many drinks do you want to calculate?" << std::endl;
    while (1){
        amountOfDrinks = getInput();
        if (amountOfDrinks > 0) break;
    }
    // Calculations from the gender
    std::vector<std::tuple<int, float>> BACHour;
    float BAC;
    if (gender == male){
        BAC = (amountOfDrinks * 12) / (weight * 0.68);
    } else {
        BAC = (amountOfDrinks * 12) / (weight * 0.55);
    }
    float _BAC = BAC;
    float burn_per_hour = weight * 0.15;
    float drink_per_hour = burn_per_hour / 12;
    float BAC_per_hour;
    if (gender == male){
        BAC_per_hour = (drink_per_hour * 12) / (weight * 0.68);
    } else {
        BAC_per_hour = (drink_per_hour * 12) / (weight * 0.55);
    }
    float total_hours = round(_BAC / BAC_per_hour);

    int hours = 0;
    while (1){
        hours++;
        _BAC -= burn_per_hour;
        if (_BAC < 0.0){
            BACHour.push_back(std::make_tuple(hours, 0.0));
            break;
        }
        else {
            BACHour.push_back(std::make_tuple(hours, _BAC));
        }
        std::cout << hours << std::endl;
    }
    
    std::cout << amountOfDrinks << " drinks calculates to a BAC of " << BAC << std::endl;
    std::cout << "It would take " << total_hours << " hours to burn the total BAC" << std::endl;
    for (int i = 0; i < sizeof(BACHour); i++){
        std::cout << std::get<0>(BACHour[i]) << "  -  " << std::get<1>(BACHour[i]) << std::endl;
    }

    
}