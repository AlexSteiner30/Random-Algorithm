#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int seed;

int GenerateSeed(){
    int x = time(NULL) * 1000;
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
        return abs((min + x % n));
    }
    else{
        return (min + x % n);
    }
}

int main() {
    seed = GenerateSeed();
    
    printf("%d", randomRange(1,10));

    return 0;
}