pets = []
foods = 10

class Pet:
    def __init__(self, name):
        self.name = name
        self.happiness = 10
        self.sadness = 30
        self.hunger = 50


    def feed_me(self):
        self.happiness += 5
        self.sadness -= 5
        self.hunger -= foods
        if self.hunger < 0:
            self.hunger = 0
        return self.hunger
        
    def speak_pet(self):
        print(f'Hello i am {self.name}')
    def pat_me(self):
        self.happiness += 10 
        self.sadness -= 10
        if self.sadness < 0:
            self.sadness = 0 


class Dog(Pet):
    def speak_pet(self):
        print(f'Hello i am {self.name} ')
        print('AWW AWW AWOOO!!!')


class Cat(Pet):
    def speak_pet(self):
        print(f'Hello i am {self.name} ')
        print('MEOW MEOW MEOWIEEE!!!')



def main_program():
    while True:
        display_menu()
        answer = input('What would you like to do? (1-6): ').strip()
        if answer == '1':
            create_pet()
        elif answer == '2':
            show_pets()
        elif answer == '3':
            feed_pets()
        elif answer == '4':
            pet_speak()
        elif answer == '5':
            pat_pet()
        elif answer =='6':
            break
        else:
            print('ERROR')

def create_pet():
    pet_name = ''
    choice = input('What pet would you like? ' ).capitalize()
    if choice == 'Dog':
        pet_name = input('What would be the name of your dog? ')
        new_pet = Dog(pet_name)
        pets.append(new_pet)
        print(f'Your pet {new_pet.name} has been successfully created')

    elif choice == 'Cat':
        pet_name = input('What would be the name of your cat? ')
        new_pet = Cat(pet_name)
        pets.append(new_pet)
        print(f'Your pet {new_pet.name} has been successfully created')


            


def show_pets():
    if not pets:
        print('YOU HAVE NO PETS YET')
        return
    
    for index, pet in enumerate(pets, start=1):
        print(
        f"{index}. "
        f"{pet.name} ({pet.__class__.__name__}) "
        f"- Hunger: {pet.hunger} "
        f"Happiness: {pet.happiness} "
        f"- Sadness: {pet.sadness}"
        )


def feed_pets():
    if not pets:
        print('YOU HAVE NO PETS YET')
        return
    show_pets()
    choice = int(input('Choose a pet:'))
    selected_pet = pets[choice - 1]
    print(f' {selected_pet.name}, Hunger: {selected_pet.hunger}')
    selected_pet.feed_me()    
    print(f'PET FED! {selected_pet.name}, Hunger: {selected_pet.hunger}')
    print(f'')


def pet_speak():
    if not pets:
        print('YOU HAVE NO PETS YET')
        return
    show_pets()
    choice = int(input('Choose a pet:'))
    selected_pet = pets[choice - 1]
    selected_pet.speak_pet()
    

def pat_pet():
    if not pets:
        print('YOU HAVE NO PETS YET')
        return
    show_pets()
    choice = int(input('Choose a pet:'))
    selected_pet = pets[choice - 1]
    print(f' {selected_pet.name}, Happiness: {selected_pet.happiness}, Sadness: {selected_pet.sadness}')   
    selected_pet.pat_me()
    print('+10 Happiness!')
    print(f'You patted {selected_pet.name}')
    print(f' {selected_pet.name}, Happiness: {selected_pet.happiness}, Sadness: {selected_pet.sadness}')       



def display_menu():
    print("""
====== PET SIMULATOR =======
1. Create Pet
2. Show Pets
3. Feed Pets
4. Make pet speak
5. Pat the pet
6. exit
        """)

main_program()