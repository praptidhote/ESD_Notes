# Import only the required functions
from geometry import area_of_circle, area_of_rectangle

# User interaction
rad = float(input("Enter radius of the circle: "))
print(f"Area of Circle: {area_of_circle(rad):.2f}")

length = float(input("Enter length of the rectangle: "))
width = float(input("Enter width of the rectangle: "))
print(f"Area of Rectangle: {area_of_rectangle(length, width):.2f}")
