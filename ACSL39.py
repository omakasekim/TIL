def form_ascending_sequence(s):
    """Forms a sequence of numbers from the input string where each number is larger than the previous."""
    n = len(s) # Length of the input string
    sequence = []  # To store the resulting sequence
    i = 0   # Index to traverse the input string
    # Start with the first digit as the initial number
    current_number = int(s[i])  # Convert the first digit to an integer
    sequence.append(current_number) # Add the first number to the sequence
    i += 1  # Move to the next digit
    while i < n:    # Continue until all digits are processed
        next_number = 0 # Initialize the next number
        while i < n:    # Continue until all digits are processed
            next_number = next_number * 10 + int(s[i])  # Forms the next number by multiplying by 10 and adding the next digit
            i += 1  # Move to the next digit
            if next_number > current_number:    # Check if the next number is larger
                sequence.append(next_number)    # Add the next number to the sequence
                current_number = next_number    # Update the current number
                break   # Break the inner loop
    return sequence # Return the resulting sequence

test_inputs = ["314159265","11223344","25897257","91","9876543210"]
print("Sample Outputs:")
for i, s in enumerate(test_inputs, 1):
    result = form_ascending_sequence(s)
    print(f"{i}.", " ".join(map(str, result)))
