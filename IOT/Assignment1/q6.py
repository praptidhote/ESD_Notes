def calculator():
    print("--- Four Function Calculator ---")
    print("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit")
    choice = input("Select an option (1-5): ")
    
    if choice in ['1', '2', '3', '4']:
        n1 = float(input("Enter first number: "))
        n2 = float(input("Enter second number: "))
        if choice == '1': print(f"Result: {n1 + n2}")
        elif choice == '2': print(f"Result: {n1 - n2}")
        elif choice == '3': print(f"Result: {n1 * n2}")
        elif choice == '4': print(f"Result: {n1 / n2}")

calculator()
