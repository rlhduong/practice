import random
import sys

n = int(sys.argv[1])
def write_numbers_to_file(n, filename="in"):
    with open(filename, "w") as file:
        file.write(f"{n} {n} {n}\n")
        for j in range(0, n + 1):
            file.write(" ".join(str(i) for i in range(1, n + 1)))
            file.write(f"\n")

write_numbers_to_file(n)



