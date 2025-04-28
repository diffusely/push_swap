# 🌀 push_swap

## 📚 Project Description

`push_swap` is a project from 42 School that involves sorting a stack of integers using only a limited set of stack operations and an auxiliary stack. The main goal is to sort the numbers with the fewest possible moves.

This implementation is written in **C** and uses a **Chunk Sort** strategy for efficient sorting.

---

## 🚀 Features

- Efficient sorting using **chunking**
- Handles duplicates, negatives, and edge cases
- Clean and modular C code
- Low move count performance for 100 and 500 elements

---

## 📊 Performance

| Stack Size | Operations |
|------------|------------|
| 100        | ~550       |
| 500        | ~4900–5200 |

Performance varies depending on chunk size and input sequence.

---

## ⚙️ How to Run

### 1. Compile

```bash

make
./push_swap 3 2 1 6 5 8 4

make bonus
./push_swap 3 2 1 6 5 8 4 | ./checker 3 2 1 6 5 8 4

The checker will print:

OK if the stack is correctly sorted.

KO if the stack is not correctly sorted.
