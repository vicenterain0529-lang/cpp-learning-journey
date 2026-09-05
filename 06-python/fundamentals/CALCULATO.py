

def operation():
    choice = input(('What operation would you use?')).lower()
    if choice == '-' or choice == 'minus':
        final_answer = number_subtract()
        print(final_answer)
    elif choice == 'power' or choice == 'square':
        final_answer = number_squared()
        print(final_answer)
    elif choice == '*' or choice == 'multiply':
        final_answer = number_multiply()
        print(final_answer)
    elif choice == 'help':
        print("""
                power - raise
                * or multiply = multiplication
                - or minus = subtraction
                / or divide = division
                + or add
                """)
        operation()
    elif choice == 'table':
        output = multiplication_table()
        print(output)
    elif choice == '+' or choice == 'add':
        final_answer = number_add()
        print(final_answer)





def number_multiply():
    number = int(input('What number would you like to multiply? '))
    multiple = int(input('What number would you like to use as multiple?  '))
    answer = number * multiple
    final_answer = f'{number} x {multiple} = {answer}'
    return final_answer
def number_squared():
    number = int(input('What number would you like to square? '))
    power = int(input('What number would you like to power?  '))
    answer = number ** power
    final_answer = f'{number} ** {power} = {answer}'
    return final_answer

def number_subtract():
    number = int(input('What number would you like to minus? '))
    difference = int(input('What number would you like as difference?  '))
    answer = number - difference
    final_answer = f'{number} - {difference} = {answer}'
    return final_answer

def number_add():
    number = int(input('What number would you like to add? '))
    addition = int(input('What number would you like to add it to? '))
    answer = number + addition
    final_answer = f'{number} + {addition} = {answer}'
    return final_answer

def multiplication_table():
    table = int(input('What table would you want? '))
    limit = int(input('What is the limit of the table? '))
    output = ''
    for number in range(1, limit + 1):
        fin_answer = table * number
        output += f'{table} x {number} = {fin_answer}\n'
    return output
    

        
operation()