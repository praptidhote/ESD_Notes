def overlapping(list1, list2):
    # Using sets for efficient lookup
    return len(set(list1) & set(list2)) > 0

# Example usage:
print(overlapping([1, 2, 3], [3, 4, 5]))  # Returns True
print(overlapping([1, 2, 3], [4, 5, 6]))  # Returns False
