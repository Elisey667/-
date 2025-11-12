import random

Number = random.randint(1, 100)
while True:
    input_number = int(input("Введите число:"))
    if input_number > Number:
        print("Слишком много!")
    elif input_number < Number:
         print("Слишком мало!")
    elif input_number == Number:
         print("Ты угадал!", end="")
         break
