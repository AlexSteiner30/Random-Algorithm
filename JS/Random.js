function Random(){
    var x = Date.now();
    x ^= x >> 12;
    x ^= x << 25;
    x ^= x >> 27;
    return x * 2685821657736338717;
}

console.log(Random());