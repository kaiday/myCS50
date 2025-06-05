import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) < 3:
        print("Usage: python dna.py data.csv sequence.txt")

        sys.exit(1)

    # TODO: Read database file into a variable
    list = []  # list of STR and person that asscoicate with it

    list_of_STR = []  # list of just STR
    try:
        with open(sys.argv[1], "r") as DB_file:
            reader = csv.DictReader(DB_file)

            for line in reader:
                record_of_STR = dict()
                tmp_STR = dict()

                for field_names in reader.fieldnames:
                    record_of_STR[field_names] = line[field_names]
                    if field_names != "name":
                        tmp_STR[field_names] = line[field_names]
                        # this line is here because i want to create a list with just STR without the name so i can check more easily

                list.append(record_of_STR)
                list_of_STR.append(tmp_STR)
    except:
        print("Could not open '" + sys.argv[1] + "'")
        sys.exit(1)

    # TODO: Read DNA sequence file into a variable
    try:
        with open(sys.argv[2], "r") as DNA_file:
            DNA_sequence = DNA_file.readline()
    except:
        print("Could not open '" + sys.argv[2] + "'")
        sys.exit(1)

    # TODO: Find longest match of each STR in DNA sequence
    del record_of_STR["name"]  # delete an element

    record_of_STR = dict.fromkeys(record_of_STR, 0)
    # dict.fromkeys(dict, value) will create a new dictionary base on the key on the given dict
    # and set all value of the key to the given value

    for STR in record_of_STR.keys():  # STR is a short sequence of DNA
        record_of_STR[STR] = str(longest_match(DNA_sequence, STR))

    # TODO: Check database for matching profiles
    if record_of_STR in list_of_STR:
        print(list[list_of_STR.index(record_of_STR)]["name"])
        # go to the index of that value in the list and print the name in dictionary
    else:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
