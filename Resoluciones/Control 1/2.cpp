#include <iostream>

int main() {
    int x = 4356;
    int val;
    while (x) {
        val=x%10;
        x = x/10;
        std::cout<< x << std::endl;

    }

    std::cout << "valor de x:"<< ++x << std::endl;

    return 0;
}
