def getFib(n):
    """Returns the nth Fibonacci number using iteration."""
    if n == 0:
        return 1
    if n == 1:
        return 2
    a, b = 1, 2
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b

def fibCypher(key, msg):
    """Encodes the message using the Fibonacci Cypher."""
    ords = []   # ASCII values of characters in the message
    ords2 = []  # ASCII values of offset letters
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    boombambop = []  # Encoded values
    uneccessaryextravariable = ""  # Final output string
    
    # Step 1: Store ASCII values of the message
    for char in msg:
        ords.append(ord(char))
    
    # Step 2: Generate offset letters and their ASCII values
    for i in range(len(msg)):
        count = getFib(i) % 26  # Fibonacci offset, wrapped within 26 letters
        key_index = alphabet.index(key)
        new_index = (key_index + count) % 26
        ords2.append(ord(alphabet[new_index]))
    
    # Step 3: Compute the encoded values
    for i in range(len(msg)):
        boombambop.append(str(ords[i] + ords2[i]))
    
    # Step 4: Construct the final output string
    uneccessaryextravariable = " ".join(boombambop)
    
    return uneccessaryextravariable

# Sample input
print(fibCypher("z", "It is 9:30 in the norning."))  # Expected: "170 173 190 185 144 216 149"
