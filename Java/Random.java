import java.util.Date;
import java.util.concurrent.TimeUnit;

class RandomGenerator{
    public static void main(String[] args) {
        System.out.println(randomRange(1,10));
    }

    static long generateSeed(){
        long x = TimeUnit.NANOSECONDS.toMicros(System.nanoTime());;
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;
        return x * 268582165;
    }
    
    public static int randomRange(int min, int max){
        int n = max - min + 1;
        int remainder = Integer.MAX_VALUE % n;
        int x;
        do{
            x = (int)generateSeed();
        } while (x >= Integer.MAX_VALUE - remainder);
    
        if((min + x % n) < min){
            return Math.abs((min + x % n));
        }
        else{
            return (min + x % n);
        }
    }
}
