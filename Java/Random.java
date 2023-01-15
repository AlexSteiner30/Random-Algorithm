import java.util.Date;
import java.util.concurrent.TimeUnit;

class RandomGenerator{
    public static void main(String[] args) {
        System.out.println(Random());
        System.out.println(Random());
        System.out.println(Random());
        System.out.println(Random());
    }

    static long Random(){
        long x = TimeUnit.NANOSECONDS.toMicros(System.nanoTime());;
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;
        return x * 268582165;
    }
}