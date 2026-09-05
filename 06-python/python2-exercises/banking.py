import json

FILE_NAME = "balance.json"


def normalize_data(data):
    if not isinstance(data, dict):
        data = {
            "balance": 0,
            "transactions": []
        }

    data.setdefault("balance", 0)
    data.setdefault("transactions", [])

    if not isinstance(data["transactions"], list):
        data["transactions"] = []

    data["balance"] = float(data["balance"])
    return data


def load_data():
    try:
        with open(FILE_NAME, "r", encoding="utf-8") as file:
            data = json.load(file)
    except (FileNotFoundError, json.JSONDecodeError):
        data = {
            "balance": 0,
            "transactions": []
        }

    data = normalize_data(data)
    save_data(data)
    return data


def save_data(data):
    with open(FILE_NAME, "w", encoding="utf-8") as file:
        json.dump(normalize_data(data), file, indent=4)


def deposit(data):
    data = normalize_data(data)
    amount = float(input("How much would you deposit? "))

    data["balance"] += amount

    data["transactions"].append({
        "type": "Deposit",
        "amount": amount
    })

    save_data(data)


def withdraw(data):
    data = normalize_data(data)
    amount = float(input("How much would you like to withdraw? "))

    if amount > data["balance"]:
        print("Insufficient funds.")
        return

    data["balance"] -= amount

    data["transactions"].append({
        "type": "Withdraw",
        "amount": amount
    })

    save_data(data)


def show_balance(data):
    data = normalize_data(data)
    print(f"Current Balance: ₱{data['balance']:.2f}")


def show_transactions(data):
    data = normalize_data(data)
    if not data["transactions"]:
        print("No transactions yet.")
        return

    for transaction in data["transactions"]:
        print(f"{transaction['type']} - ₱{transaction['amount']:.2f}")


def display_menu():
    print("""
========= BANK PROGRAM =========
1. View Balance
2. Deposit
3. Withdraw
4. View Transactions
5. Exit
""")


def main_program():
    data = load_data()

    while True:
        display_menu()
        choice = input("Enter your choice: ")

        if choice == "1":
            show_balance(data)

        elif choice == "2":
            deposit(data)

        elif choice == "3":
            withdraw(data)

        elif choice == "4":
            show_transactions(data)

        elif choice == "5":
            print("Thank you for using the bank program!")
            break

        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main_program()