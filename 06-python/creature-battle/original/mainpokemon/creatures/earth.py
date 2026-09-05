from .Parent_creature import Creature

class EarthCreature(Creature):
    def __init__(self, name, hp, attack, defense):
        super().__init__(name, hp, attack, defense)
        self.type = "Earth"


class Randolf(EarthCreature):
    def __init__(self):
        super().__init__(
            "Randolf",
            150,
            12,
            10
        )
        self.exp_reward = 20
