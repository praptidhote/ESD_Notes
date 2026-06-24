def count_vowels(text):
    vowels = "aeiouAEIOU"
    return sum(1 for char in text if char.isalpha() and char in vowels)

def count_consonants(text):
    vowels = "aeiouAEIOU"
    return sum(1 for char in text if char.isalpha() and char not in vowels)

def calculate_ratio(text):
    vowels_count = count_vowels(text)
    consonants_count = count_consonants(text)
    
    if consonants_count == 0:
        return float('inf') if vowels_count > 0 else 0.0
    return round(vowels_count / consonants_count, 2)

# Main program execution
if __name__ == "__main__":
    user_string = input("Enter a string: ")
    ratio = calculate_ratio(user_string)
    print(f"Vowels: {count_vowels(user_string)}")
    print(f"Consonants: {count_consonants(user_string)}")
    print(f"Ratio of Vowels to Consonants: {ratio}")
