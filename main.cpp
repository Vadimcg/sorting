#include <iostream>
#include "SortingController.h"

int main() {

    std::cout << "Selectin sort:" << std::endl;

    const short sizeMass=5;
    int mass[]={22,1,44,55,3,32};

    SortingController::getInstance().selectionSortRecursiveStart(mass,sizeMass);

    for(int i=0;i<sizeMass;i++)
        std::cout<<mass[i]<<std::endl;
    return 0;
}