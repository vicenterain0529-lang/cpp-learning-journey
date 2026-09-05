cart = []
price = []


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

def display_menu():
    print("""
1. Add Item
2. Remove Item
3. View Cart
4. Total Price
5. Checkout
6. Exit
        """)
    
def shop_cart():
    display_menu()
    choice = input('What would you like to do? ')
    if choice == '1':
        add_item(cart)
    elif choice == '3':
        view_cart()
    elif choice == '4':
        total_price()
    elif choice == '5':
        checkout() 
    elif choice == '6':
        print('Thanks for shopping')   


def add_item(cart):
    show_products()
    choice = input('What item would you like to add to the cart?').lower()
    if choice in products:
        cart.append(choice)
        print(f'item added successfully! {choice.capitalize()}')
    else:
        print('ERROR, that item does note exist')


    


def view_cart(cart):
    if not cart:
        print('Your cart is empty!')
        return
    
    for item in cart:
        price = products[item]
        print(f'{item.capitalize} - {price}')


def show_products():
    print('\nAvailable Products:')
    for item, price in products.items():
        print(f'{item}: - {price}')


def remove_item(cart):
    if not cart:
        print('Your cart is empty!')
        return
    view_cart(cart)
    rem_item = input('What item would you want to remove? ')
    if rem_item in cart:
        cart.remove(rem_item)
    else:
        print('ERROR NOT FOUND')


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



