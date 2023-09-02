# Digit Recognition

---

## Requirements:

- cmake (Version >= 3.25)

---

## How to build the project locally:

Run the following commands consecutively from within the root of this repo:
1. `cmake -S ./ -B build/`
2. `cd build && make`
3. `./Digit_Recognition`

It is not necessary to rebuild the project every time one tries to run it,
simply `make` in build dir to update executable

---

MNIST Dataset reader: [https://github.com/wichtounet/mnist](https://github.com/wichtounet/mnist)
