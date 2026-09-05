import json


FILE_NAME = "balance.json"


def main():
    balance = load_data()

    while True:
        print(
            "-" * 20,
            "\nBANKING PROGRAM",
            "\n1. Show balance",
            "\n2. Deposit",
            "\n3. Withdraw",
            "\n4. Exit"
        )

        choice = int(input("Enter your choice (1-4): "))

        if choice == 1:
            show_balance(balance)

        elif choice == 2:
            balance = deposit(balance)
            save_balance(balance)

        elif choice == 3:
            balance = withdraw(balance)
            save_balance(balance)

        elif choice == 4:
            print("Thank you for using the banking program!")
            break

        else:
            print("Invalid choice!")


def show_balance(balance):
    print(f"\nYour balance: ${balance:.2f}")


def deposit(balance):
    money_deposit = int(input("How much would you like to deposit? $"))

    if money_deposit <= 0:
        print("Deposit must be greater than 0.")
        return balance

    balance += money_deposit

    print(
        f"\nYou deposited: ${money_deposit}",
        f"\nYour current balance: ${balance:.2f}"
    )

    return balance


def withdraw(balance):
    if balance <= 0:
        print(f"You have ${balance} in your account.")
        return balance

    show_balance(balance)

    money_withdraw = int(input("How much would you like to withdraw? $"))

    if money_withdraw > balance:
        print("Insufficient funds.")
        return balance

    if money_withdraw <= 0:
        print("Withdrawal must be greater than 0.")
        return balance

    balance -= money_withdraw

    print(
        f"\nYou withdrew: ${money_withdraw}",
        f"\nYour current balance: ${balance:.2f}"
    )

    return balance


def load_data():
    try:
        with open(FILE_NAME, "r", encoding="utf-8") as file:
            data = json.load(file)

        return data["balance"]

    except (FileNotFoundError, json.JSONDecodeError):
        return 0


def save_balance(balance):
    data = {
        "balance": balance
    }

    with open(FILE_NAME, "w", encoding="utf-8") as file:
        json.dump(data, file, indent=4)


main()