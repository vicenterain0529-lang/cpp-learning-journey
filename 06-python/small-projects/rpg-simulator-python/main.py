characters = []


class Character:
    def __init__(self, name):
        self.name = name
        self.hp = 100
        self.mana = 100
        self.attack_power = 10
        self.level = 1
        self.exp = 1

    def show_stats(self):
        print(f"""
Name: {self.name} ({self.__class__.__name__})
HP: {self.hp}
MP: {self.mana}
Attack: {self.attack_power}
Level: {self.level}
Exp: {self.exp}
""")

    def level_up(self):
        self.level += 1
        self.hp += 20
        self.mana += 10
        self.attack_power += 5
        print(f'{self.name} has leveled up to level {self.level}!')


class Warrior(Character):
    def __init__(self, name):
        super().__init__(name)
        self.hp = 150
        self.mana = 50


class Mage(Character):
    def __init__(self, name):
        super().__init__(name)
        self.hp = 80
        self.mana = 150


class Archer(Character):
    def __init__(self, name):
        super().__init__(name)
        self.hp = 100
        self.mana = 100


def main_program():
    while True:
        display_menu()
        answer = input('What would you like to do? (1-6): ').strip()
        if answer == '1':
            create_character()
        elif answer == '2':
            show_characters()
        elif answer == '3':
            level_up_character()
        elif answer == '4':
            attack_character()
        elif answer == '5':
            heal_character()
        elif answer == '6':
            break
        else:
            print('ERROR')


def display_menu():
    print("""
--------- RPG SIMULATOR ---------

1. Create Character
2. Show Characters
3. Level Up Character
4. Attack Character
5. Heal Character
6. Exit
        """)


def display_class_menu():
    print("""
1. Warrior
2. Mage
3. Archer
    """)


def create_character():
    if len(characters) >= 3:
        print('You have already created 3 characters. Please choose another option.')
        return
    print('What class would you like to create? ')
    display_class_menu()
    choice = input('Enter your choice (1-3): ').strip()

    if choice == '1':
        char_name = input('what would be the name of your Warrior? ')
        new_character = Warrior(char_name)
        characters.append(new_character)
        print(f'Your character {new_character.name} has been created!')
        answer = input('Do you want to see stats? (y/n): ').strip().lower()
        if answer == 'y':
            new_character.show_stats()

    elif choice == '2':
        char_name = input('what would be the name of your Mage? ')
        new_character = Mage(char_name)
        characters.append(new_character)
        print(f'Your character {new_character.name} has been created!')
        answer = input('Do you want to see stats? (y/n): ').strip().lower()
        if answer == 'y':
            new_character.show_stats()

    elif choice == '3':
        char_name = input('what would be the name of your Archer? ')
        new_character = Archer(char_name)
        characters.append(new_character)
        print(f'Your character {new_character.name} has been created!')
        answer = input('Do you want to see stats? (y/n): ').strip().lower()
        if answer == 'y':
            new_character.show_stats()


def show_characters():
    if not characters:
        print('No characters created yet. Please create a character first.')
        return
    for index, character in enumerate(characters, start=1):
        print(f'{index}. {character.name} ({character.__class__.__name__}) - Level: {character.level}')


def level_up_character():
    if not characters:
        print('No characters created yet. Please create a character first.')
        return
    print('Select a character to level up:')
    selected_character = select_character()
    if selected_character:
        selected_character.level_up()
        selected_character.show_stats()


def attack_character():
    if not characters:
        print('No characters created yet. Please create a character first.')
        return


def select_character():
    show_characters()
    choice = input('Select a character by number: ').strip()
    if choice.isdigit() and 1 <= int(choice) <= len(characters):
        selected_character = characters[int(choice) - 1]
        return selected_character
    else:
        print('Invalid choice.')
        return


def heal_character():
    pass


main_program()
