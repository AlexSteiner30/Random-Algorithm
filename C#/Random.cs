using System;

class RandomGenerator{
    private static void Main(){
        Console.WriteLine(Random());
        Console.WriteLine(Random());
        Console.WriteLine(Random());
        Console.WriteLine(Random());
    }

    static long Random(){
        DateTime now = DateTime.UtcNow;
        long unixTimeMilliseconds = new DateTimeOffset(now).ToUnixTimeMilliseconds();

        long x = unixTimeMilliseconds;
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;
        return x * 2685821657736338717;
    }

}