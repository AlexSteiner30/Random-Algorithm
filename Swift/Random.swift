import Foundation

func generateSeed() -> UInt64 {
    var x = UInt64(Date().timeIntervalSince1970)
    x ^= x >> 2;
    x ^= x << 5;
    x ^= x >> 7;
    return x * 26858
}

func randomRange(min: UInt64, max: UInt64) -> UInt64 {
    let n = max - min + 1
    let remainder = UInt64.max % n
    var x: UInt64
    repeat {
        x = generateSeed()
    } while x >= UInt64.max - remainder
    
    return min + x % n
}

func Main() {
    print(randomRange(min: 1, max: 10))
}

Main();