# -*- coding: utf-8 -*-


kalin_unlu = ["a","ı","o","u"]
ince_unlu = ["e","i","ö","ü"]


def state_1(word):
    state_2(word)


def state_2(word):
    if word == "":
        print("Word is not plural")
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter in kalin_unlu:
        state_3(word_to_next_state)
    elif current_letter in ince_unlu:
        state_4(word_to_next_state)
    else:
        state_2(word_to_next_state)



def state_3(word):
    if word == "":
        print("Word is not plural")
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter in ince_unlu:
        state_4(word_to_next_state)
    elif current_letter == "l":
        state_5(word_to_next_state)
    else:
        state_3(word_to_next_state)



def state_4(word):
    if word == "":
        print("Word is not plural")
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter in kalin_unlu:
        state_3(word_to_next_state)
    elif current_letter == "l":
        state_8(word_to_next_state)
    else:
        state_4(word_to_next_state)



def state_5(word):
    if word == "":
        print("Word is not plural")
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == "a":
        state_6(word_to_next_state)
    else:
        state_3(word_to_next_state)


def state_6(word):
    if word == "":
        print("Word is not plural")
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == "r":
        state_7(word_to_next_state)
    else:
        state_3(word_to_next_state)


def state_7(word):
    if word == "":
        state_11("ε");

    else:
        word_to_next_state = word[1:len(word)]
        state_3(word_to_next_state)


def state_8(word):
    if word == "":
        print("Word is not plural")
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == "e":
        state_9(word_to_next_state)
    else:
        state_4(word_to_next_state)




def state_9(word):
    if word == "":
        print("Word is not plural")
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == "r":
        state_10(word_to_next_state)
    else:
        state_4(word_to_next_state)



def state_10(word):
    if word == "":
        state_11("ε");
    else:
        word_to_next_state = word[1:len(word)]
        state_3(word_to_next_state)




def state_11(word):
    if word == "ε":
        print("Word is plural")
    else:
        print("Error")









print("Enter Words to check if they are plural,enter \"-1\" to stop entering word")



words = []

while True:
    word = input("Enter word : ")

    if word == "-1":
        break
    else:
        words.append(word)



for word in words:
    print(word + ": ",end=' ')
    str(state_1(word))