import random
import string
chars = " "+ string.punctuation + string.digits + string.ascii_letters
chars = list(chars)
key = chars.copy()

random.shuffle(key)





#encrypt

plain_text = input('Message to encrypt: ')
cipher_text = ''
decryption = ''
for letter in plain_text:
    index = chars.index(letter)
    cipher_text += key[index]
print(f"Original Message: {plain_text}")
print(f"Encrypted message: {cipher_text}")

for letter in cipher_text:
    index = key.index(letter)
    decryption += chars[index] 
print(f" decrypted {decryption}")