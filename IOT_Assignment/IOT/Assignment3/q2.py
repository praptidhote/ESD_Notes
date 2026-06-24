def add(a, b): return a + b
def subtract(a, b): return a - b
def multiply(a, b): return a * b
def divide(a, b): return a / b if b != 0 else "Error: Division by zero"

def menu():
    while True:
        print("\n--- Calculator Menu ---")
        print("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit")
        choice = input("Enter choice (1-5): ")
        
        if choice == '5':
            print("Exiting...")
            break
            
        if choice in ['1', '2', '3', '4']:
            num1 = float(input("Enter first number: "))
            num2 = float(input("Enter second number: "))
            
            if choice == '1': print("Result:", add(num1, num2))
            elif choice == '2': print("Result:", subtract(num1, num2))
            elif choice == '3': print("Result:", multiply(num1, num2))
            elif choice == '4': print("Result:", divide(num1, num2))
        else:
            print("Invalid Choice!")

menu()
