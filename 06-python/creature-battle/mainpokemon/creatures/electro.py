from .Parent_creature import Creature

class ElectroCreature(Creature):
    def __init__(self, name, hp, attack, defense):
        super().__init__(name, hp, attack, defense)
        self.type = "Electro"


class Voltail(ElectroCreature):
    def __init__(self):
        super().__init__(
            "Voltail",
            80,
            24,
            3
        )
        self.exp_reward = 22
