# Define basic arithmetic functions
def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def divide(a, b):
    if b == 0:
        return "Error: Division by zero"
    return a / b

# Higher-order function
def calculate(operand1, operand2, operation_func):
    return operation_func(operand1, operand2)

# Testing the functions
inputs = [(10, 5), (20, 0), (8, 4)]

for op1, op2 in inputs:
    print(f"Inputs: {op1}, {op2}")
    print(f"  Addition: {calculate(op1, op2, add)}")
    print(f"  Subtraction: {calculate(op1, op2, subtract)}")
    print(f"  Multiplication: {calculate(op1, op2, multiply)}")
    print(f"  Division: {calculate(op1, op2, divide)}")
    print("-" * 30)
