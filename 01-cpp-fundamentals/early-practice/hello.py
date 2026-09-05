def calc_func(num1, num2, op):
    results = 0
    if op == 1:
        results = num1 + num2
    elif op == 2:
        results = num1 - num2
    elif op == 3:
        results = num1 * num2
    elif op == 4:
        results = num1 / num2
    return results

def display_menu():
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Exit")
    print("6. Others")

def main():


    
    while True:
        operation = ""
        display_menu()
        op = int(input("Choose 1-5: "))
        if op == 1:
            operation = "+"
        elif op == 2:
            operation = "-"
        elif op == 3:
            operation = "*"
        elif op == 4:
            operation = "/"

            
        num1 = int(input("#1 number: "))
        num2 = int(input("#2 number: "))
        results = calc_func(num1, num2, op)
        print(f"The result is: {num1} {operation} {num2} = {results}")


main()




