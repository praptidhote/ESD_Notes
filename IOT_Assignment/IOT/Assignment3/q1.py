def count_vowels(text):
    vowels = "aeiouAEIOU"
    return sum(1 for char in text if char in vowels)

def count_consonants(text):
    vowels = "aeiouAEIOU"
    return sum(1 for char in text if char.isalpha() and char not in vowels)

def calculate_ratio(text):
    v_count = count_vowels(text)
    c_count = count_consonants(text)
    
    if c_count == 0:
        return float('inf') if v_count > 0 else 0.0
    return round(v_count / c_count, 2)

# User Input
user_str = input("Enter a string: ")
ratio = calculate_ratio(user_str)
print(f"Vowel to Consonant Ratio: {ratio}")
