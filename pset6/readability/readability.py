from cs50 import get_string


def main():
    text = get_string("Text: ")
    l, w, s = 0, 1, 0
    # counting letters, words, and sentences
    for i in range(len(text)):
        l += 1 if text[i].isalpha() else 0
        w += 1 if text[i] == ' ' else 0
        s += 1 if text[i] in ['.', '!', '?'] else 0

    # calculating the Coleman-Liau index
    L = (100 * l) / w
    S = (100 * s) / w
    index = 0.0588 * L - 0.296 * S - 15.8

    # printing out the correct message
    if index < 1:
        print(f'Before Grade 1')
    elif index >= 16:
        print(f'Grade 16+')
    else:
        print(f'Grade {int(round(index))}')
        

if __name__ == "__main__":
    main()

