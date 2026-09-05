
def weight_conversion():
    weight = float(input('Enter you weight '))
    unit = input('kilograms or pounds? kg or lbs?')
    if unit == 'kg':
        lbs_const = 2.20462
        conversion = weight * lbs_const
        answer = round(conversion, 2)
        print(f'Your weight is {answer}  lbs')
    else:
        kilo_const = 0.453592
        conversion = weight / kilo_const
        answer = round(conversion, 2)
        print(f'Your weight is {answer} kg') 


# compound interest calculator
principal = 0
rate = 0
time = 0
def principal_func(principal):
    while principal <= 0:
        principal = float(input('Principal amount: '))
        if principal <= 0:
            print('Principal cant be less than 0')
            return principal
def rate_function(rate):
    while rate <= 0:
        rate = float(input('rate: '))
        if rate <= 0:
            print('rate cant be less than 0')
            return rate
def time_func(time):
    while time <= 0:
        time = int(input('months: '))
        if time <= 0:
            print('Principal cant be less than 0')
            return time
        
def conversion(principal, rate, time):
    total = principal * (1 + rate / 100)**time

def run_conversion():
    principal = principal_func()
