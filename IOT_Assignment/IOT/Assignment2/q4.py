def histogram(numbers):
    for num in numbers:
        if isinstance(num, int) and num >= 0:
            print(f"{num}: {'*' * num}")

# Test execution
histogram((4, 9, 7))
