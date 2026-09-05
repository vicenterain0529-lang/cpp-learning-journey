from .Parent_creature import Creature

class FireCreature(Creature):
    def __init__(self, name, hp, attack, defense):
        super().__init__(name, hp, attack, defense)
        self.type = "Fire"


class Pyron(FireCreature):
    def __init__(self):
        super().__init__(
            "Pyron",
            90,
            22,
            4
        )
        self.exp_reward = 20
