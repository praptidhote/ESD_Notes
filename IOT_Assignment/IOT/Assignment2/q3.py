def overlapping(list1, list2):
    # Set intersection is highly efficient for membership testing
    return len(set(list1) & set(list2)) > 0

# Test cases
print(overlapping([1, 2, 3], [4, 5, 6]))  # Returns False
print(overlapping([1, 2, 3], [3, 4, 5]))  # Returns True



