#include <iostream>

int Random(){
    static int x = std::time(0);
    x ^= x >> 12;
    x ^= x << 25;
    x ^= x >> 27;
    return x * 0x2545F4914F6CDD1DULL;
}

int main(){
    std::cout << "Hello, this is a random algorithm developed by Alex Steiner!" << std::endl;

    std::cout << "Random number generate: " << Random() << std::endl;

    return 0;
}