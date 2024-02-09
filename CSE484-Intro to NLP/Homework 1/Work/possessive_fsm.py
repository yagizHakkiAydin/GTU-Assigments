# -*- coding: utf-8 -*-


kalin_unlu = ["a","ı","o","u"]
ince_unlu = ["e","i","ö","ü"]
unsuz = ["b", "c", "ç", "d", "f", "g", "ğ", "h", "j", "k", "l", "m", "n", "p", "r", "s", "ş", "t", "v", "y", "z"]



def start_state(word):
	state_0(word)


def state_0(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]



    if current_letter in unsuz:
    	state_0(word_to_next_state)

    elif (current_letter == 'a') or (current_letter == 'ı'):
    	state_1(word_to_next_state)
    elif (current_letter == 'e') or (current_letter == 'i'):
    	state_2(word_to_next_state)
    elif (current_letter == 'o') or (current_letter == 'u'):
    	state_3(word_to_next_state)
    elif (current_letter == 'ö') or (current_letter == 'ü'):
    	state_4(word_to_next_state)



def state_1(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    
    
    if current_letter == 'm':
    	state_5(word_to_next_state)
    elif current_letter == 'n':
    	state_6(word_to_next_state)
    elif (current_letter == 'e') or (current_letter == 'i'):
    	state_2(word_to_next_state)
    elif (current_letter == 'o') or (current_letter == 'u'):
    	state_3(word_to_next_state)
    elif (current_letter == 'ö') or (current_letter == 'ü'):
    	state_4(word_to_next_state)
    else:
    	state_1(word_to_next_state)




def state_2(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    
    
    if current_letter == 'm':
    	state_7(word_to_next_state)
    elif current_letter == 'n':
    	state_8(word_to_next_state)
    elif (current_letter == 'a') or (current_letter == 'ı'):
    	state_1(word_to_next_state)
    elif (current_letter == 'o') or (current_letter == 'u'):
    	state_3(word_to_next_state)
    elif (current_letter == 'ö') or (current_letter == 'ü'):
    	state_4(word_to_next_state)
    else:
    	state_2(word_to_next_state)






def state_3(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    
    
    if current_letter == 'm':
    	state_9(word_to_next_state)
    elif current_letter == 'n':
    	state_10(word_to_next_state)
    elif (current_letter == 'a') or (current_letter == 'ı'):
    	state_1(word_to_next_state)
    elif (current_letter == 'e') or (current_letter == 'i'):
    	state_2(word_to_next_state)
    elif (current_letter == 'ö') or (current_letter == 'ü'):
    	state_4(word_to_next_state)
    else:
    	state_3(word_to_next_state)





def state_4(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    
    
    if current_letter == 'm':
    	state_11(word_to_next_state)
    elif current_letter == 'n':
    	state_12(word_to_next_state)
    elif (current_letter == 'a') or (current_letter == 'ı'):
    	state_1(word_to_next_state)
    elif (current_letter == 'e') or (current_letter == 'i'):
    	state_2(word_to_next_state)
    elif (current_letter == 'o') or (current_letter == 'u'):
    	state_3(word_to_next_state)
    else:
    	state_4(word_to_next_state)





def state_5(word):
    if word == "":
        print("Benim ", end=' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]


    if current_letter == 'ı':
    	state_13(word_to_next_state)
    else:
    	state_1(word_to_next_state)








def state_6(word):
    if word == "":
        print("Senin ", end=' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'ı':
    	state_15(word_to_next_state)
    else:
    	state_1(word_to_next_state)





def state_7(word):
    if word == "":
        print("Benim " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]
    if current_letter == 'i':
    	state_17(word_to_next_state)
    else:
    	state_2(word_to_next_state)





def state_8(word):
    if word == "":
        print("Senin " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'i':
    	state_19(word_to_next_state)
    else:
    	state_2(word_to_next_state)




def state_9(word):
    if word == "":
        print("Benim " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'u':
    	state_21(word_to_next_state)
    else:
    	state_3(word_to_next_state)






def state_10(word):
    if word == "":
        print("Senin " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'u':
    	state_23(word_to_next_state)
    else:
    	state_3(word_to_next_state)





def state_11(word):
    if word == "":
        print("Benim " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'ü':
    	state_25(word_to_next_state)
    else:
    	state_4(word_to_next_state)





def state_12(word):
    if word == "":
        print("Senin " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'ü':
    	state_27(word_to_next_state)
    else:
    	state_4(word_to_next_state)











def state_13(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'z':
    	state_14(word_to_next_state)
    else:
    	state_1(word_to_next_state)












def state_14(word):
    if word == "":
        print("Bizim ", end=' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    state_1(word_to_next_state)










def state_15(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]


    if current_letter == 'z':
    	state_16(word_to_next_state)
    else:
    	state_1(word_to_next_state)










def state_16(word):
    if word == "":
        print("Sizin ",end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    state_6(word_to_next_state)











def state_17(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'z':
    	state_18(word_to_next_state)
    else:
    	state_2(word_to_next_state)










def state_18(word):
    if word == "":
        print("Bizim ",end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    state_2(word_to_next_state)











def state_19(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'z':
    	state_20(word_to_next_state)
    else:
    	state_2(word_to_next_state)











def state_20(word):
    if word == "":
        print("Sizin ",end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    state_2(word_to_next_state)











def state_21(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'z':
    	state_22(word_to_next_state)
    else:
    	state_3(word_to_next_state)











def state_22(word):
    if word == "":
        print("Bizim " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    state_3(word_to_next_state)











def state_23(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'z':
    	state_24(word_to_next_state)
    else:
    	state_3(word_to_next_state)











def state_24(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    state_3(word_to_next_state)











def state_25(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'z':
    	state_26(word_to_next_state)
    else:
    	state_4(word_to_next_state)











def state_26(word):
    if word == "":
        print("Bizim " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    state_4(word_to_next_state)










def state_27(word):
    if word == "":
        print("Word is not possesive " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    if current_letter == 'z':
    	state_28(word_to_next_state)
    else:
    	state_4(word_to_next_state)












def state_28(word):
    if word == "":
        print("Sizin " , end = ' ')
        return

    current_letter = word[0]
    word_to_next_state = word[1:len(word)]

    state_4(word_to_next_state)












print("Enter Words to check if they are plural,enter \"-1\" to stop entering word")



words = []

while True:
    word = input("Enter word : ")

    if word == "-1":
        break
    else:
        words.append(word)



for word in words:
    start_state(word)
    print("'" + word + "'") 
    



