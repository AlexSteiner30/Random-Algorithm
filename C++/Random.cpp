#include <iostream>
#include <ctime>

int seed;

int GenerateSeed(){
    static int x = std::time(nullptr);
    x ^= x >> 12;
    x ^= x << 25;
    x ^= x >> 27;
    return x * 0x2545F4914F6CDD1DULL;
}

int randomRange(int min, int max){
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do{
        x = GenerateSeed();
    } while (x >= RAND_MAX- remainder);
    
    if((min + x % n) < min){
        return std::abs((min + x % n));
    }
    else{
        return (min + x % n);
    }
}

int main() {
    seed = GenerateSeed();
    
    std::cout << randomRange(1,10) << std::endl;

    return 0;
}
