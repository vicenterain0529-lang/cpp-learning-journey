cart = []
prices = []
products = {
"apple": 25,
"banana": 15,
"orange": 20,
"bread": 45,
"milk": 60,
"eggs": 90,
"rice": 55,
"chicken": 180,
"coffee": 120,
"water": 20
}
def shop_cart():
    while True:
        display_menu()
        choice = input("Enter your choice (1-6): ").strip()
        
        if choice == "1":
            add_item(cart)
        elif choice == "2":
            remove_item(cart)
            
        elif choice == "3":
            view_cart(cart)
        elif choice == "4":
            total_price(cart)
        elif choice == "5":
            checkout(cart)
        elif choice == "6":
            print("Thank you for shopping!")
            break
        else: 
            print('INVALID')


def display_menu():
    print("""
1. Add Item
2. Remove Item
3. View Cart
4. Total Price
5. Checkout
6. Exit
        """)
    

def add_item(cart):
    show_products()
    choice = input('What item would you like? ').strip().lower()
    if choice in products:
        cart.append(choice)
        print(f'ITEM ADDED SUCCESSFULLY: {choice.capitalize()}')
    else:
        print('ERROR, item does not exist')

def view_cart(cart):
    if not cart:
        print('Your cart is empty!')
        return
    
    for item in cart:
        price = products[item]
        print(f'{item.capitalize()} - {price}')
            

def show_products():
    print('\nAvailable Products:')
    for item, price in products.items():
        print(f"{item.capitalize():<12} - ₹{price}")


def remove_item(cart):
    if not cart:
        print('Cart is empty')
        return
    view_cart(cart)
    rem_item = input("Which item do you want to remove? ").strip().lower()
    if rem_item in cart:
        cart.remove(rem_item)
    else: 
        print('ERROR, item not found')




def total_price(cart):
    if not cart:
        print('Your cart is empty! total = 0')
        return
    total = 0
    print('\n Cart total:')
    for item in cart:
        price = products[item]
        total += price
        print(f"{item.capitalize():} - {price}")
    print(f"** TOTAL: ₹{total} **")
    
    

def checkout(cart):
    if not cart:
        print('Your cart is empty')
        view_cart(cart)
    pay_out = input('Do you want to check out? ').lower()
    if pay_out == 'yes':
        total_price(cart)
    else:
        print('Waiting...')
shop_cart()