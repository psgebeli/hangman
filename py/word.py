import random

def generate_random_word():
    # open file 
    with open('../txt/words_skimmed.txt') as f:
        # read lines from file and store in a list
        words = [line.strip() for line in f.readlines()]
    
    # generate random index based on size of file 
    index = random.randint(0, len(words) - 1)

    # get the word at the generated index
    random_word = words[index]

    return random_word
