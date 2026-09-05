import random

options = ('rock', 'paper', 'scissors')

player_score = 0
computer_score = 0
win_score = 3
round_num = 0  # CHANGED: renamed from round (round is a built-in Python function)


def main_game():
    global round_num

    # CHANGED: use < and and instead of != and or
    # Game continues while BOTH scores are below win_score
    while player_score < win_score and computer_score < win_score:

        round_num += 1  # CHANGED: track rounds

        print(f'\n===== ROUND {round_num} =====')

        answer = input('Proceed to next round? (yes/no): ').lower()

        if answer == 'yes':
            determine_winner()
        else:
            print('Okay, thanks for playing!')
            return

    # CHANGED: announce match winner after loop ends
    if player_score == win_score:
        print('\n🏆 PLAYER WINS THE MATCH!')
    else:
        print('\n🏆 COMPUTER WINS THE MATCH!')


def get_user_choice():

    # CHANGED: input validation loop
    while True:

        print(f'These are your options: {options}')

        user_choice = input('Enter your choice: ').lower()

        if user_choice in options:
            return user_choice

        print('Invalid choice! Try again.')


def get_computer_choice():

    computer = random.choice(options)

    print(f'The computer chose: {computer}')

    return computer


def determine_winner():

    global player_score, computer_score

    player_choice = get_user_choice()
    computer_choice = get_computer_choice()

    if player_choice == computer_choice:

        print("IT'S A TIE!")

    # CHANGED: combined all winning conditions into one elif
    elif (
        (player_choice == "rock" and computer_choice == "scissors")
        or
        (player_choice == "paper" and computer_choice == "rock")
        or
        (player_choice == "scissors" and computer_choice == "paper")
    ):

        print("YOU WON!")
        player_score += 1

    else:

        print("YOU LOST!")
        computer_score += 1

    # CHANGED: use display_score() instead of repeating print code
    display_score()


def display_score():

    print(f"""
PLAYER SCORE = {player_score}
COMPUTER SCORE = {computer_score}
""")


main_game()