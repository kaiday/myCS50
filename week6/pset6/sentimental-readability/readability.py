def main():
    text = input("Text: ")
    numberOfWord = len(text.split())

    L = average_number_of_letters(text,numberOfWord) # per 100 words
    S = average_number_of_sentences(text,numberOfWord) # per 100 words

    index = round(0.0588*L - 0.296*S - 15.8) # Coleman-Liau index

    if index <= 0:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Grade " + str(index))

def average_number_of_letters(text,numberOfWord):
    count = 0
    for i in range(len(text)):
        if text[i].isalpha():
            count +=1
    return count/numberOfWord * 100 # calculate how many letters per 100 words

def average_number_of_sentences(text,numberOfWord):
    count = 0
    for i in range(len(text)):
        if text[i] == "." or text[i] == "!" or text[i] == "?":
            count +=1

    return count/numberOfWord * 100 # calculate how many sentences per 100 words

main()