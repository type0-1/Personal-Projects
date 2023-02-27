import random

print("Welcome to my guessing game!")
print()
print("What is your name?")
name = input()
print()
print(f"Hey {name}, would you like to set your minimum and maximum number guess range? (Y/N)")
answer = input()

if answer == "Y" or answer == "y":
  print("Alright! What would you like your minimum guess range to be?")
  minimum = int(input())
  print(f'Great! Your minimum guess range is {minimum}, what would you like your maximum guess range to be?')
  maximum = int(input())
  print(f'Good! You minimum and maximum ranges are {minimum} to {maximum}')
  print()
else:
  minimum = 0
  maximum = 100
  print(f"Okay! Your minimum and maximum guess range is set to {minimum} to {maximum} by default.")
  print()

print("Would you like to set the amount of guesses you have? (Y/N)")
answer = input()
if answer == "Y" or answer == "y":
  print("Perfect, how much guesses do you want?")
  guessAmount = int(input())
  print(f"Okay, you'll have {guessAmount} guesses before losing.")
  print()
  print(f"Goodluck {name}!")
  print()
else:
  guessAmount = 5
  print(f"Alright, your guess amount will be set to {guessAmount} by default.")
  print()
  print(f"Goodluck {name}!")
  print()

correctGuess = random.randint(minimum, maximum)
guessList = []
win = False

while guessAmount > 0:
  layout = print(f'Name: {name} | Guesses: {guessList} | Guesses Left: {guessAmount}')
  guess = int(input())
  if guess < correctGuess:
    print(f"Your guess is lower: {guess}")
    guessList.append(guess)
    print()
  elif guess > correctGuess:
    print(f"Your guess is higher: {guess}")
    guessList.append(guess)
    print()
  elif guess == correctGuess:
    print(f"Congratulations, the correct guess was {correctGuess}")
    win = True
    break
    
  guessAmount-= 1
if guessAmount == 0:
  print(f'You lost, the correct answer was {correctGuess}.')
  
print(f"Would you like to see your statistics for the game? (Y/N)")
answer = input()
if answer == "Y" or answer == "y":
    print(f'User: {name} guessed {len(guessList)} times before guessing the right number.')
  else:
    print(f'User: {name} guessed a total of {len(guessList)} times.')
else:
    print(f'Thank you for playing the game!')
    
  


