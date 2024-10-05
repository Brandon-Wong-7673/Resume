"""Brandon Wong
    sources: none"""
"""
The program can do the following 
 
-Add entries to the password manager by inputting the Name of Service, Username, and Password
-View the unencrypted username and password for a particular service
-Update the password or username of an existing entry

    the actual password is not stored in a dictionary. Instead, there is a very basic encryption 
algorithm to “encrypt” the passwords entered by a user before adding it to the dictionary. 
When a user needs to view the password, the progrsm will “decrypt” the stored version and 
print out the actual password. The basic encryption algorithm is to create a 1 to 1 mapping 
of one letter to another and simply swap the letters to encrypt or decrypt. For example, if 
The word “cab” would be encrypted to “xzw” by simply replacing the letter on the left with the 
letter on the right. To then decrypt the string “xzw” it would swap the letter on the right with 
the letter on the left to recover the original word “cab.” The program continues prompting 
the user to select options from the menu until they decide to quit.
"""
import random
passwords = {}
encrypt = {}
choice = ""
# making a random encrypt alogrium
inputlist = ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$&")
#copy list that I can remove things from
copylist = []
# makes copylist a list version of inputlist
for letter in inputlist:
    copylist.append(letter) 
# randomly encrypts each letter
for letter in inputlist:
    randomLetter = copylist.pop(random.randint(0, len(copylist)-1))
    encrypt[letter] = randomLetter
print(encrypt)
# list to unencrypt
# start of password part
print("Welcome to the password manager\n")
while (choice != "quit"):
    choice = input("Do you want to add, view or update a password(type ether add, view, update or quit): ")
    if(choice == "add" or choice == "update"):
        service = input("What service is the username and password for?: ")
        username = input("What is the username?: ")
        unEncryptedPassword = input("What is the password?: ")
        password = ""
        for letters in unEncryptedPassword:
            password +=  encrypt.get(letters)
        unEncryptedPassword = ""
        passwords[service] = [username, password]
    if(choice == "view"):
        service = input("What is the service?: ")
        unEncryptedPassword = ""
        for letters in passwords[service][1]:
            # x to count the num of loops
            x = 0
            for encryptedLetters in encrypt:
                if(encrypt[encryptedLetters] == letters):
                    unEncryptedPassword += inputlist[x]
                x += 1
        print(service,end=":\n")
        print("     username:",passwords[service][0])
        print("     passward:",unEncryptedPassword)
        print()

