using System;

class RandomGenerator{
    static long seed;
    
    static void Main() {
        seed = GenerateSeed();
        
        Console.WriteLine(randomRange(1,10));
    }
    
    static long GenerateSeed(){
        DateTime now = DateTime.UtcNow;
        long unixTimeMilliseconds = new DateTimeOffset(now).ToUnixTimeMilliseconds();
        long x = unixTimeMilliseconds;
        
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;
        return x * 2685821657736338717;
    }
    
    static long randomRange(long min, long max){
        long n = max - min + 1;
        long remainder = Int32.MaxValue % n;
        long x;
        do{
            x = GenerateSeed();
        } while (x >= Int32.MaxValue - remainder);
        
        if((min + x % n) < min){
            return Math.Abs((min + x % n));
        }
        else{
            return (min + x % n);
        }
    }
}
