""""
Brandon Wong
Sources: None
"""
"""
A anagram game with 20 Halloween themed words, each with 5 letters or more. 
The program will pick one word randomly from them and create all permutations in a list. 
From there, a randomly selected permutation will be displayed and The user will try to guess 
the original word based on this one permutation. The user will be told whether 
they guessed correctly or not. 
"""
import random
from itertools import permutations
# Tuple of of 20 Halloween themed words
Halloween = ("pumpkin", "skeleton", "candy", "haunted", "tombstone",
             "ghost", "zombie", "witch", "spider", "vampire",
             "crypt", "coffin", "werewolf", "magic", "trick-or-treat",
             "cauldron", "costume", "lantern", "banshee", "exorcist",)
choice = ""
score = 0
print("Halloween Anagram Guessing Game\n")
while (choice != "q"):
    word = random.choice(Halloween)
    word_Permutations = permutations(word)
    word_Permutations = random.choice(list(word_Permutations))
    word_Permutations = "".join(word_Permutations)
    for i in range(3):
        print(word_Permutations)
        choice = input("\nEnter your guess(q to quit):\n")
        if (choice == "q"):
            break
        elif (choice == word):
            print("\nThat is correct\n")
            score += 10 * (3-i)
            break
        else:
            print("\nthat is incorect. you have", 3-i-1, "guess left\n")
            if (i == 2):
                print("the word was",word)
    print("\nYour current score is", score, "\n")
    print("\nYour next word is: ")
print("\nYour final score is", score)