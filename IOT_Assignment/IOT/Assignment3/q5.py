prices = [105, 110, 108, 112, 115, 116, 114]
window_size = 3

print("3-Day Rolling Averages:")
for i in range(len(prices) - window_size + 1):
    # Use slicing to get the 3-day window
    window = prices[i : i + window_size]
    avg = sum(window) / window_size
    print(f"Day {i+1}-{i+3}: {round(avg, 2)}")
