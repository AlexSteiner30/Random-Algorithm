import math
from datetime import datetime

def generateSeed():
    dt = datetime.now()
    x = dt.microsecond
    x ^= x >> 12
    x ^= x << 25
    x ^= x >> 27
    return x * 2685821657736338717

def random_range(min, max):
    n = max - min + 1
    remainder = math.inf % n
    x = generateSeed()
    
    while x >= math.inf - remainder:
        x = generateSeed()

    if (min + x % n) < min:
        return abs(min + x % n)
    else:
        return min + x % n
        
print(random_range(1, 10))
