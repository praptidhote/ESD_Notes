# Lambda functions for conversions
km_to_m = lambda x: x * 1000
m_to_cm = lambda x: x * 100
cm_to_mm = lambda x: x * 10
ft_to_in = lambda x: x * 12
in_to_cm = lambda x: x * 2.54

# Conversion orchestrator function
def distance_converter(distance, type_str, conversion_func):
    result = conversion_func(distance)
    print(f"{distance} {type_str.split(' to ')[0]} = {result:.2f} {type_str.split(' to ')[1]}")

# User input simulation
user_distance = float(input("Enter distance value to convert: "))

# Executing all conversions
distance_converter(user_distance, "km to m", km_to_m)
distance_converter(user_distance, "m to cm", m_to_cm)
distance_converter(user_distance, "cm to mm", cm_to_mm)
distance_converter(user_distance, "ft to in", ft_to_in)
distance_converter(user_distance, "in to cm", in_to_cm)
