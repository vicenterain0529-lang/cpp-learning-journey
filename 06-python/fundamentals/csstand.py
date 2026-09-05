products = {
    "popcorn": 50,
    "hotdog": 40,
    "burger": 80,
    "fries": 35,
    "nachos": 60,
    "soda": 25,
    "water": 15,
    "candy": 20,
    "ice cream": 45,
    "pizza": 90
}

cart = {}

def main_stand():
    while True:
        print('What do you want to do?')
        display_menu()
        choice = input("Enter your choice (1-7): ").strip()
        
        if choice == "1":
            add_item(cart)
        elif choice == "2":
            remove_item(cart)
            
        elif choice == "3":
            view_cart(cart)
        elif choice == "4":
            total_price(cart)
        elif choice == "5":
            check_out(cart)
        elif choice == "6":
            print("Thank you for shopping!")
            break
        elif choice == "7":
            show_catalog()
        else: 
            print('INVALID')


def show_catalog():
    for item, price in products.items():
        print(f'ITEM: {item} - PRICE: {price}')


def display_menu():
    print("""
1. Add Item
2. Remove Item
3. View Cart
4. Total Price
5. Checkout
6. Exit
7. Show catalog
        """)




def remove_item(cart):
    if not cart:
        print('Cart is empty:')
        return
    show_catalog()
    rem_item = input('what item would you like to remove?: ')
    if rem_item in cart:
        cart[rem_item] -= 1
        print(f"{rem_item.capitalize()} removed.")
        if cart[rem_item] == 0:
            del cart[rem_item]
            
    else:
        print('item does not exist')
        

def view_cart(cart):
    if not cart:
        print('Your cart is empty!')
        return
    
    for item, counter in cart.items():
        price = products[item]
        total = price * counter
        print(f'{item.capitalize()} x{counter}- {total}')


def total_price(cart):
    if not cart:
        print('Cart is empty:')
        return
    total = 0
    print('\n Cart total:')
    for item, counter in cart.items():
        price = products[item]
        total += price * counter
        print(f'{item.capitalize()} {counter}- {price}')
    print(f'TOTAL: {total}')
    return total


def add_item(cart):
    show_catalog()
    choice = input('What would you like to order? ').lower()
    if choice in products:
        if choice in cart:
            cart[choice] += 1
        else:
            cart[choice] = 1         
        print(f'item added successfully! {choice.capitalize()}')
    else:
        print('ERROR that item does not exist')


def check_out(cart):
    if not cart:
        print('Have a nice day!')
        return
    confirmation = input('Do you want to checkout? ').lower()
    
    if confirmation == 'yes':
        print(f'Your total is : {total_price(cart)}')
        print('processing....')
        cart.clear()
        view_cart(cart)
        print('Thanks for shopping!')
    else: 
        view_cart()
        print('What would you like to do?')


main_stand()