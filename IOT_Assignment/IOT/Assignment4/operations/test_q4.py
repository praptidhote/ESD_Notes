from operations.arithmetic import add, multiply
from operations.string_ops import reverse_string, count_vowels

# Demonstrate arithmetic functions
print("--- Arithmetic Operations ---")
print(f"Addition (12 + 8): {add(12, 8)}")
print(f"Multiplication (6 * 7): {multiply(6, 7)}")

# Demonstrate string operations
print("\n--- String Operations ---")
sample_str = "IoT Assignment"
print(f"Original String: {sample_str}")
print(f"Reversed String: {reverse_string(sample_str)}")
print(f"Vowel Count: {count_vowels(sample_str)}")
