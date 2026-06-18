def add(a, b): return a + b
def subtract(a, b): return a - b
def multiply(a, b): return a * b
def divide(a, b): return a / b if b != 0 else "Error: Division by zero"

def calculator_menu():
    while True:
        print("\n--- Basic Calculator ---")
        print("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit")
        choice = input("Select an option (1-5): ")
        
        if choice == '5':
            print("Exiting calculator.")
            break
            
        if choice in ['1', '2', '3', '4']:
            try:
                num1 = float(input("Enter first number: "))
                num2 = float(input("Enter second number: "))
            except ValueError:
                print("Invalid input! Please enter numbers only.")
                continue
                
            if choice == '1': print(f"Result: {add(num1, num2)}")
            elif choice == '2': print(f"Result: {subtract(num1, num2)}")
            elif choice == '3': print(f"Result: {multiply(num1, num2)}")
            elif choice == '4': print(f"Result: {divide(num1, num2)}")
        else:
            print("Invalid choice! Please select between 1 and 5.")

if __name__ == "__main__":
    calculator_menu()
