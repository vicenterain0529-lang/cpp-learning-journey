import time

guess_count = 0
guess_limit = 3
secret_number = 9
num_guess = ''
score_count = 0


def slow_print(text, delay=0.05):
    for character in text:
        print(character, end='', flush=True)
        time.sleep(delay)
    print()

def slow_input(prompt, delay=0.05):
    slow_print(prompt, delay)
    return input('> ')

def run_game():
    global is_correct
    global guess_count
    confirmation = slow_input('Would you like to play a guessing game? yes or no?').lower()
    if confirmation == 'yes':
        while is_correct == False and guess_count < guess_limit:
            guess = get_guess()
            is_correct = check_guess(guess)
            validate_guess(guess)
            if is_correct == False:
                guess_count += 1
                guess_left = int(guess_limit) - int(guess_count)
                slow_print(f'You have {guess_left} left')
            

        if is_correct == False:
            confirmation2 = slow_input('You lost! Would you like to try again?').lower()
            if confirmation2 == 'yes':
                guess_count = 0
                is_correct = False
                run_game()
            else:
                slow_print('Thanks, have a good day! skill issue ka boy')
        else:
            slow_print('You won!!! congratulations!!!')
            confirmation3 = slow_input('Would you like to play again?').lower()
            if confirmation3 == 'yes':
                guess_count = 0
                is_correct = False
                run_game()
            else:
                slow_print('Have a good day!!!!')
    else:
        slow_print('Thank you for your time!')

def get_guess():
    num_guess = int(slow_input('Guess the correct number:'))
    return num_guess





def validate_guess(result):
    if result == secret_number:
        slow_print('You are correct!')
    else:
        slow_print('Wrong, try again!')

def check_guess(guess):
    if guess == secret_number:
        is_correct = True
    else:
        is_correct = False
    return is_correct

run_game()