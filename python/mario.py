size = int(input("Height : "))

while size > 8 or size < 1:
    size = int(input("Please enter a number between 1 and 8 \n"))

# go trought row
for i in range(size, 0, -1):

    # print space
    for blank in range(i - 1, 0, -1):
        print(" ", end="")

    # Print left #
    for hash in range(size - i + 1, 0, -1):
        print('#', end="")

    # Print middle space
    print("  ", end="")

    # Print right #
    for hash in range(size - i + 1, 0, -1):
        print("#", end="")

    # newline
    print("")
