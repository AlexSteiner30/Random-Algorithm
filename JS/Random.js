function generateSeed(){
    var x = Date.now();
    x ^= x >> 12;
    x ^= x << 25;
    x ^= x >> 27;
    return x * 2685821657736338717;
}

function randomRange(min, max){
    var n = max - min + 1;
    var remainder = Number.MAX_VALUE % n;
    var x;
    do{
        x = generateSeed();
    } while (x >= Number.MAX_VALUE - remainder);
    
    if((min + x % n) < min){
        return Math.abs((min + x % n));
    }
    else{
        return (min + x % n);
    }
}

function Main() {
    seed = generateSeed();
    
    console.log(randomRange(1,10));
}

Main();
