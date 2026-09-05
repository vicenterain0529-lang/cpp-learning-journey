from .Parent_creature import Creature

class WaterCreature(Creature):
    def __init__(self, name, hp, attack, defense):
        super().__init__(name, hp, attack, defense)
        self.type = "Water"


class Aquata(WaterCreature):
    def __init__(self):
        super().__init__(
            "Aquata",
            110,
            16,
            8
        )
        self.exp_reward = 25
