prices = [105, 110, 108, 112, 115, 116, 114]
window_size = 3

# Compute rolling averages using list slicing
rolling_averages = [
    round(sum(prices[i:i+window_size]) / window_size, 2)
    for i in range(len(prices) - window_size + 1)
]

print(f"3-Day Rolling Averages: {rolling_averages}")
