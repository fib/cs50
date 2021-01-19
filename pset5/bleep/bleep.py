from cs50 import get_string
from sys import argv


def main():
    # if the amount of arguments is above 2 we can safely exit
    if len(argv) > 2:
        exit(1)
    else:
        # trying to read the file. if it fails, the exception is caught and the program safely prints the usage info and exits
        try:
            blacklist = open(argv[1], "r").read().split()
        except Exception as e:
            print("Usage: python bleep.py dictionary")
            exit(1)

        text = get_string("What message would you like to censor?\n").split()
        
        for i in range(len(text)):
            if text[i].lower() in blacklist:  # replacing words that exist in the blacklist with asterisks
                text[i] = '*' * len(text[i])

    print(" ".join(text))
    
    
if __name__ == "__main__":
    main()

