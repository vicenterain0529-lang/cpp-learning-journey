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


def main_program():
    print(f"YOU ENCOUNTERED {enemy.name} ({enemy.__class__.__name__})")

    while player.hp > 0 and enemy.hp > 0:

        print("\n" + "=" * 30)
        print("NEW ROUND")
        print("=" * 30)

        first_turn = random.choice(["player", "enemy"])

        print("Deciding turn...")
        for _ in range(10):
            print(".", end="", flush=True)
            time.sleep(0.2)

        print(f"\nFirst turn is {first_turn}\n")

        # ---------------- PLAYER FIRST ----------------

        if first_turn == "player":

            show_methods()

            answer = input("Choose: ")

            if answer == "1":
                player.attack_enemy(enemy)

            elif answer == "2":
                player.heal()

            elif answer == "3":
                player.show_stats()

            else:
                print("Invalid choice.")
                continue

            if enemy_checker():
                break

            print("\n--- ENEMY TURN ---")

            action = random.randint(1, 100)

            if action <= 70:
                enemy.attack_enemy(player)

            elif action <= 90:
                enemy.heal()

            else:
                print("Enemy skipped its turn.")

            if player.hp <= 0:
                print("You lost the battle!")
                break

        # ---------------- ENEMY FIRST ----------------

        else:

            print("\n--- ENEMY TURN ---")

            action = random.randint(1, 100)

            if action <= 70:
                enemy.attack_enemy(player)

            elif action <= 90:
                enemy.heal()

            else:
                print("Enemy skipped its turn.")

            if player.hp <= 0:
                print("You lost the battle!")
                break

            print("\n--- YOUR TURN ---")

            show_methods()

            answer = input("Choose: ")

            if answer == "1":
                player.attack_enemy(enemy)

            elif answer == "2":
                player.heal()

            elif answer == "3":
                player.show_stats()

            else:
                print("Invalid choice.")
                continue

            if enemy_checker():
                break
