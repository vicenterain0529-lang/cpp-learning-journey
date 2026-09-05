class Creature:
    def __init__(self, name, hp, attack, defense):
        self.name = name
        self.hp = hp
        self.max_hp = hp
        self.attack = attack
        self.defense = defense
        self.level = 1
        self.exp = 0
        self.heal_count = 0
        self.heal_limit = 3
        self.exp_reward = 20

    def show_stats(self):
        print(f"""
Name: {self.name} ({self.__class__.__name__})
Type: {getattr(self, "type", "None")}
HP: {self.hp}/{self.max_hp}
Attack: {self.attack}
Defense: {self.defense}
Level: {self.level}
Exp: {self.exp}
""")

    def level_up(self):
        self.level += 1
        self.max_hp += 10
        self.hp = self.max_hp
        self.attack += 2
        self.defense += 1
        print(f"{self.name} has leveled up to level {self.level}!")

    def heal(self):
        if self.heal_count < self.heal_limit:
            heal_amount = int(self.max_hp * 0.60)
            self.hp += heal_amount

            if self.hp > self.max_hp:
                self.hp = self.max_hp

            self.heal_count += 1

            print(f"{self.name} healed {heal_amount} HP!")
            print(f"HP: {self.hp}/{self.max_hp}")
            print(f"Heals remaining: {self.heal_limit - self.heal_count}")
        else:
            print(f"{self.name} has no heals remaining!")

    def attack_enemy(self, enemy):
        if enemy.hp <= 0:
            print(f"{enemy.name} is already defeated!")
            return

        damage = self.attack - enemy.defense

        if damage < 1:
            damage = 1

        enemy.hp -= damage

        if enemy.hp < 0:
            enemy.hp = 0

        print(f"{self.name} attacked {enemy.name}!")
        print(f"{enemy.name} took {damage} damage!")
        print(f"{enemy.name} HP: {enemy.hp}/{enemy.max_hp}")

    def check_level_up(self):
        if self.exp >= 100:
            self.exp -= 100
            self.level_up()
