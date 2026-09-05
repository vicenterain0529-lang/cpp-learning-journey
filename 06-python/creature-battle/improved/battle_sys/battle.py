import random
import time

from creatures import Pyron, Randolf
from ui.menus import show_methods

player = Pyron()
enemy = Randolf()


def enemy_checker():
    if enemy.hp <= 0:
        print(f"{enemy.name} fainted!")
        print(f"You gained {enemy.exp_reward} EXP!")
        player.exp += enemy.exp_reward
        player.check_level_up()
        return True
    return False


def handle_player_turn():
    print("\n--- YOUR TURN ---")

    while True:
        show_methods()
        answer = input("Choose: ").strip()

        if answer == "1":
            player.attack_enemy(enemy)
            return True

        elif answer == "2":
            player.heal()
            return True

        elif answer == "3":
            player.show_stats()
            return True

        elif answer == "4":
            print("You retreat from the battle.")
            player.hp = 0
            return False

        else:
            print("Invalid choice. Please pick 1, 2, 3, or 4.")


def handle_enemy_turn():
    print("\n--- ENEMY TURN ---")

    action = random.randint(1, 100)

    if action <= 70:
        enemy.attack_enemy(player)

    elif action <= 90:
        enemy.heal()

    else:
        print("Enemy skipped its turn.")


def show_round_intro():
    print("\n" + "=" * 30)
    print("NEW ROUND")
    print("=" * 30)


def main_program():
    print(f"YOU ENCOUNTERED {enemy.name} ({enemy.__class__.__name__})")

    while player.hp > 0 and enemy.hp > 0:
        show_round_intro()

        first_turn = random.choice(["player", "enemy"])

        print("Deciding turn...")
        for _ in range(10):
            print(".", end="", flush=True)
            time.sleep(0.2)

        print(f"\nFirst turn is {first_turn}\n")

        if first_turn == "player":
            if not handle_player_turn():
                break

            if enemy_checker():
                break

            handle_enemy_turn()

        else:
            handle_enemy_turn()

            if player.hp <= 0:
                print("You lost the battle!")
                break

            if not handle_player_turn():
                break

            if enemy_checker():
                break

        if player.hp <= 0:
            print("You lost the battle!")
            break
