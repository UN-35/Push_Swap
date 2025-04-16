# 🔄 Push_swap

![Push_swap Banner](https://raw.githubusercontent.com/byaliego/42-project-badges/main/badges/push_swapm.png)

## 📚 Overview

Push_swap is a highly efficient sorting algorithm project developed as part of the 42 School curriculum. The challenge is to sort a random list of integers using two stacks and a limited set of operations, with the goal of using the fewest possible moves.

This implementation efficiently handles sorting of various stack sizes:
- 3 numbers: Optimized for minimal operations
- 5 numbers: Special algorithm for small datasets
- 100 numbers: Efficiently sorted in under 700 operations
- 500 numbers: Handles large datasets in under 5500 operations

## 🛠️ The Rules

We start with two stacks named 'a' and 'b':
- Stack 'a' contains a random assortment of non-duplicate integers
- Stack 'b' is initially empty

The goal is to sort all numbers in stack 'a' in ascending order using only these operations:

| Command | Description |
|---------|-------------|
| `sa` | Swap the first 2 elements at the top of stack 'a' |
| `sb` | Swap the first 2 elements at the top of stack 'b' |
| `ss` | Execute both `sa` and `sb` at the same time |
| `pa` | Take the first element from stack 'b' and put it at the top of stack 'a' |
| `pb` | Take the first element from stack 'a' and put it at the top of stack 'b' |
| `ra` | Rotate stack 'a' - shift all elements up by 1 (first element becomes last) |
| `rb` | Rotate stack 'b' - shift all elements up by 1 (first element becomes last) |
| `rr` | Execute both `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack 'a' - shift all elements down by 1 (last element becomes first) |
| `rrb` | Reverse rotate stack 'b' - shift all elements down by 1 (last element becomes first) |
| `rrr` | Execute both `rra` and `rrb` at the same time |

## 📋 Algorithm Approach

This implementation uses a **chunk-based approach** for sorting:

1. **Ranking**: All elements in stack 'a' are assigned ranks according to their relative values
2. **Chunking**: Stack 'a' is divided into chunks based on the total size
   - For 100 numbers: Uses medium-sized chunks
   - For 500 numbers: Uses smaller chunks for better efficiency
3. **Strategic Transfer**: Elements are transferred from stack 'a' to stack 'b' based on their chunk
4. **Optimized Retrieval**: Elements are pushed back to stack 'a' in sorted order using optimal rotation calculations

The algorithm uses rank-based sorting rather than raw value comparison, which allows for more efficient operations regardless of the range or distribution of the input numbers.

## ⚙️ Usage

### Compilation
```bash
make
```

### Running Push_swap
```bash
./push_swap 4 67 3 87 23
```
Will output a list of operations to sort the given numbers.

### Verify sorting and count operations
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```
Counts the number of operations used.

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```
Verifies if the sorting is correct.

## 🧪 Performance Benchmarks

| Stack Size | Max Operations | This Implementation |
|------------|----------------|---------------------|
| 3 numbers  | Optimal: 2-3   | 2-3 operations      |
| 5 numbers  | Optimal: 8-12  | 8-12 operations     |
| 100 numbers| < 700          | ~650 operations     |
| 500 numbers| < 5500         | ~5300 operations    |

## 📁 Project Structure

```
.
├── libft/                 # Custom library functions
│   ├── ft_atoi.c          # String to integer conversion (handles errors)
│   ├── ft_split.c         # String splitting function
│   ├── ft_strjoin.c       # String joining function
│   ├── ft_strlen.c        # String length calculation
│   ├── ft_strdup.c        # String duplication
│   └── ft_isdigit.c       # Character check for digits
├── utils/
│   ├── lst_utils.c        # Linked list utility functions
│   ├── parse_args.c       # Argument parsing and validation
│   ├── rotation.c         # Stack rotation operations
│   ├── swap__push.c       # Swap and push operations
│   ├── sort_funcs.c       # Main sorting algorithms 
│   ├── utils.c            # Utility functions for sorting
│   └── more_utils.c       # Additional helper functions
├── push_swap.c            # Main program file
├── header.h               # Header file with declarations
└── Makefile               # Compilation instructions
```

## 🔍 Code Highlights

- **Error Handling**: Robust error detection for invalid inputs
- **Memory Management**: Efficient memory allocation and deallocation
- **Optimized Algorithms**: Different sorting strategies based on stack size
- **Clean Implementation**: Well-organized code with clear separation of concerns

## 📜 License

This project is part of the 1337 School curriculum and is for educational purposes.


---

⭐ Give it a star if you found this implementation helpful!
