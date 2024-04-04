#include <iostream>
#include "Date.h"

int main() {
    
    Date date1(3, 27, 2024);
    Date date2(15, 40, 2025);

    std::cout << "Fecha 1: ";
    date1.displayDate();
    
    std::cout << "Fecha 2: ";
    date2.displayDate();

    return 0;
}
