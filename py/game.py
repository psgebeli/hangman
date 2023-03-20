from word import generate_random_word
from hangman import print_hangman


# function to print the word / current guesses
def print_word(word, guessed_letters):
    for c in word:
        if c in guessed_letters:
            print(c, end=" ")
        else:
            print("_", end=" ")
    print()

def main():
    word = generate_random_word()
    num_wrong = 0
    max_wrong = 6 
    guessed_letters = set() # set is easier to check for already guessed words

    while num_wrong < max_wrong:
        tries_left = max_wrong - num_wrong 
        print(f"You have {tries_left} tries left.")
        print_hangman(tries_left)
        print_word(word, guessed_letters)

        guess = input("Guess a letter: ").strip().lower()
        if guess in guessed_letters:
            print("You have already guessed that letter.")
            continue
        guessed_letters.add(guess)

        if guess in word:
            print("Correct!")
        else: 
            print("Incorrect!")
            num_wrong += 1
        
        if set(word).issubset(guessed_letters):
            print(f"Congratulations, you guessed the word {word}!")
            return
        
    print_hangman(0)
    print(f"Sorry, you ran out of guesses. The word was {word}.")

if __name__ == "__main__":
    main()
