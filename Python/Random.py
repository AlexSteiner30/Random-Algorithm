from datetime import datetime

def Random():
    dt = datetime.now()
    x = dt.microsecond
    x ^= x >> 12
    x ^= x << 25
    x ^= x >> 27
    return x * 2685821657736338717

print(Random())