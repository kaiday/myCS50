texts = "In the great green room"

words = texts.split()

print("Round 1")
for word in words:
    print(word)
print()

print("Round 2")
for word in words:
    for c in word:
        print(c)
print()

print("Round 3")
for word in words:
    if "g" in word:
        print(word)
print()

print("Round 4")
for word in words[2:]:
    print(word)
print()

print("Round 5")
for word in words:
    print("Good night Moon")
print()