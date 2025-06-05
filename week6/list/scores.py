from cs50 import get_int

scores = [] # list in Python not an array, scores = list() will work the same

for i in range(3):
    score = get_int("Score: ")
    scores.append(score) # scores += [score] will have the same effect as concatenation
                         # here we concatenate a list74


average = sum(scores) / len(scores)
print(f"Average: {average}")