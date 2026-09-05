import sqlite3



DB_FILE = "inventory.db"


def get_db_connection():
    connection = sqlite3.connect(DB_FILE, timeout=30)
    connection.execute("PRAGMA busy_timeout = 5000")
    return connection


def main_program():
    while True:
        display_menu()
        choice = input("Enter your choice: ")

        if choice == "1":
            show_products()

        elif choice == "2":
            product_insert()

        elif choice == "3":
            search_product()      # You'll create this next

        elif choice == "4":
            update_product()      # You'll create this later

        elif choice == "5":
            delete_product()      # You'll create this later

        elif choice == "6":
            print("Thank you for using the Inventory System!")
            break

        else:
            print("❌ Invalid choice. Please try again.")



def show_products():
    with get_db_connection() as connection:
        cursor = connection.cursor()
        cursor.execute("SELECT * FROM Products ORDER BY ID")
        products = cursor.fetchall()

    print(f"{'ID':<5}{'Code':<10}{'Name':<30}{'Price':<12}{'Stock':<10}{'Categories':<20}")
    print("-" * 87)

    for product in products:
        print(
            f"{product[0]:<5}"
            f"{product[1]:<10}"
            f"{product[2]:<30}"
            f"₱{product[3]:<11.2f}"
            f"{product[4]:<10}"
            f"{product[5]:<20}"
        )





def get_input():
    name = input("Product Name: ")
    price = float(input("Price: "))
    stock = int(input("Stock: "))
    print("""Categories:
            1. Electronics
            2. Furniture
            3. Office Supplies
            4. Accessories
            5. Storage
                    """)
    categories = {
        "1": "Electronics",
        "2": "Furniture",
        "3": "Office Supplies",
        "4": "Accessories",
        "5": "Storage"
    }

    while True:
        choice = input("Categories: ").strip()
        category = categories.get(choice)
        if category:
            break
        print("Invalid category selection. Please enter a number from 1 to 5.")

    return name, price, stock, category




def product_insert():
    name, price, stock, category = get_input()

    with get_db_connection() as connection:
        cursor = connection.cursor()
        product_code = generate_code(category, connection)
        cursor.execute(
            """
            INSERT INTO Products
            (ProductCode, Name, Price, Stock, Categories)
            VALUES (?, ?, ?, ?, ?)
            """,
            (product_code, name, price, stock, category)
        )
        connection.commit()

    print(f"\nProduct added successfully!")
    print(f"Generated Product Code: {product_code}")

def display_menu():
    print("""
========================================
        BUSINESS INVENTORY SYSTEM
========================================
1. View Products
2. Add Product
3. Search Product
4. Update Product
5. Delete Product
6. Exit
========================================
""")

def search_product():

    product_code = input("Enter product code: ").strip().upper()

    with get_db_connection() as connection:
        cursor = connection.cursor()

        cursor.execute(
            """
            SELECT *
            FROM Products
            WHERE ProductCode = ?
            """,
            (product_code,)
        )

        product = cursor.fetchone()


    if product:
        print("\nProduct Found!")
        print("-" * 40)

        print(f"ID: {product[0]}")
        print(f"Code: {product[1]}")
        print(f"Name: {product[2]}")
        print(f"Price: ₱{product[3]:.2f}")
        print(f"Stock: {product[4]}")
        print(f"Category: {product[5]}")

    else:
        print("\nProduct not found.")
    


def generate_code(category, connection=None):
    prefixes = {
        "Electronics": "ELC",
        "Furniture": "FUR",
        "Office Supplies": "OFF",
        "School Supplies": "SCH",
        "Accessories": "ACC",
        "Storage": "STO"
    }

    prefix = prefixes.get(category, "GEN")

    if connection is None:
        with get_db_connection() as connection:
            cursor = connection.cursor()
            cursor.execute("""
                SELECT ProductCode
                FROM Products
                WHERE ProductCode LIKE ?
                ORDER BY ProductCode DESC
                LIMIT 1
            """, (f"{prefix}-%",))
            result = cursor.fetchone()
    else:
        cursor = connection.cursor()
        cursor.execute("""
            SELECT ProductCode
            FROM Products
            WHERE ProductCode LIKE ?
            ORDER BY ProductCode DESC
            LIMIT 1
        """, (f"{prefix}-%",))
        result = cursor.fetchone()

    if result is None:
        return f"{prefix}-001"

    last_code = result[0]
    number = int(last_code.split("-")[1])
    number += 1

    return f"{prefix}-{number:03}"


def update_product():
    pass


def delete_product():
    pass



if __name__ == "__main__":
    main_program()
