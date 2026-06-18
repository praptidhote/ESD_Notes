num_str = input("Enter a 5-digit number: ")

if len(num_str) == 5 and num_str.isdigit():
    if num_str == num_str[::-1]:
        print(f"{num_str} is a palindrome.")
    else:
        print(f"{num_str} is not a palindrome.")
else:
    print("Error: Invalid input. Please enter exactly 5 digits.")
