def print_fibonacci(terms):
    if terms <= 0:
        print("Please enter a positive integer.")
        return
    
    a, b = 0, 1

    for _ in range(terms):
        print(a, end=" ")
        a, b = b, a + b

    print()  # Newline


# Example usage:


# print_fibonacci(10)



