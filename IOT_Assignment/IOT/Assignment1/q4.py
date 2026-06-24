def is_prime(num):
    if num < 2: return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0: return False
    return True

def print_primes_in_range(start, end):
    for num in range(start, end + 1):
        if is_prime(num):
            print(num, end=" ")
    print()

lower = int(input("Enter start range: "))
upper = int(input("Enter end range: "))
print_primes_in_range(lower, upper)
