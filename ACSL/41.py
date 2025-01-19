def string_stats(sentence):
    """Computes the required string statistics for the given sentence without using Counter or regex."""
    
    # Convert to lowercase for consistent letter counting
    lower_sentence = sentence.lower()
    
    # 1. Number of different letters (a-z)
    seen_letters = set()
    for ch in lower_sentence:
        if 'a' <= ch <= 'z':
            seen_letters.add(ch)
    different_letters = len(seen_letters)
    
    # 2. Number of vowels (a, e, i, o, u)
    vowels = sum(1 for ch in lower_sentence if ch in 'aeiou')
    
    # 3. Number of uppercase letters
    uppercase_letters = sum(1 for ch in sentence if 'A' <= ch <= 'Z')
    
    # 4. Frequency of the most common letter (case-insensitive)
    letter_counts = {}
    for ch in lower_sentence:
        if 'a' <= ch <= 'z':
            if ch not in letter_counts:
                letter_counts[ch] = 1
            else:
                letter_counts[ch] += 1
    most_frequent_count = max(letter_counts.values())
    
    
    punctuation = ",.?!:;\"'"
    cleaned_sentence = ""
    for ch in sentence:
        if ch not in punctuation:
            cleaned_sentence += ch
    words = cleaned_sentence.split()
    max_length = max(len(word) for word in words)
    longest_words = [word for word in words if len(word) == max_length]
    longest_word = min(longest_words, key=str.lower)
    # Print results
    print(different_letters)
    print(vowels)
    print(uppercase_letters)
    print(most_frequent_count)
    print(longest_word)

# Sample input
sample_input = "The quick brown fox, named Roxanne, jumped over Bruno, a lazy dog."
string_stats(sample_input)
