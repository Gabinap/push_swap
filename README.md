_This project has been created as part of the 42 curriculum by cobussie, gagulhon._

# Push_swap
**Because Swap_push doesn’t feel as natural**

## Description
The **Push_swap** project is a very simple and highly straightforward algorithm project: data must be sorted. You have at your disposal a set of integer values, 2 stacks, and a set of operations to manipulate both stacks.

The goal is to write a C program called `push_swap` which calculates and displays on the standard output the smallest program, made of Push_swap language operations, that sorts the integers received as arguments.

This project allows you to discover algorithmic complexity in a very concrete way. Sorting numbers is easy; sorting them fast with only two stacks and a handful of allowed moves is another story.

## Instructions

### Compilation
To compile the project, run the following command in the root directory:
```bash
make
```
This will generate the `push_swap` executable.

### Usage
Run the program with a list of integers as arguments:
```bash
./push_swap 4 67 3 87 23
```

You can also use the optional strategy selector flags:
- `--simple`: Forces the use of the $O(n^2)$ algorithm.
- `--medium`: Forces the use of the $O(n\sqrt{n})$ algorithm.
- `--complex`: Forces the use of the $O(n \log n)$ algorithm.
- `--adaptive`: Forces the use of the adaptive algorithm based on disorder (default).
- `--bench`: Displays benchmark metrics after sorting (disorder, strategy used, operation counts).

Example with benchmark:
```bash
./push_swap --bench 4 67 3 87 23
```

### Bonus (Checker)
To compile the bonus checker:
```bash
make bonus
```
Usage:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Algorithms

### Simple Algorithm ($O(n^2)$)
**Implementation**: `chunk_sort`
This algorithm uses a simplified chunk-based approach. It divides the stack into rough ranges and pushes them to stack B. When pushing back to A, it performs a linear scan to find the maximum element in B and rotates it to the top before pushing. This linear scan for every element results in quadratic complexity.
- We chose this algorithm because it is more efficient than most others $O(n^2)$ algorithms, also it was really easy to implement because it is a simplification of our $O(n\sqrt{n})$ algorithm.

### Medium Algorithm ($O(n\sqrt{n})$)
**Implementation**: `medium_sort`
This strategy is an optimized chunk sort. It calculates the optimal number of chunks based on the square root of the input size ($\sqrt{n}$). Elements are pushed to B in these chunks. The "smart" aspect comes from how it manages the elements in B, keeping them relatively ordered to minimize rotations when pushing back to A.
- We chose this algorithm because it is easy to understand and relatively fast to implement.

### Complex Algorithm ($O(n \log n)$)
**Implementation**: `radix_sort`
We use a **Bitwise Radix Sort**. The numbers are first simplified to their relative ranks (0 to N-1). Then, we process the numbers bit by bit. For each bit position, we push numbers with a '0' at that bit to stack B and keep '1's in stack A. This process repeats, effectively sorting the numbers in base-2. Since the number of bits required to represent $N$ distinct values is $\lceil \log_2 N \rceil$, and we perform roughly $N$ operations per bit, the total complexity in terms of operations is $O(n \log n)$.
- We chose this algorithm because it is quite easy to implement for this complexity.
### Adaptive Strategy
The program calculates a **disorder metric** (0.0 to 1.0) to determine how "messy" the stack is before starting.
- **Disorder < 0.2**: Uses `chunk_sort` (Simple) - effective for nearly sorted lists.
- **0.2 <= Disorder < 0.5**: Uses `medium_sort`.
- **Disorder >= 0.5**: Uses `radix_sort` (Complex) - best for random/messy data.

## Resources & AI Usage

### Resources
- [Radix Sort Explanation](https://en.wikipedia.org/wiki/Radix_sort)
- [manuals]

### AI Usage
AI tools were used in this project for the following tasks, as permitted by the subject:
- **Debugging**: Helping to identify the cause of segmentation faults and logic errors in edge cases.
- **Testing**: Generating shell commands to run random number tests and check for memory leaks.
- **Verification**: Reviewing code snippets to ensure they meet the 42 Norm and logic requirements before submission.

- **Edge Cases**: Suggesting test inputs (duplicates, max/min integers) that might have been overlooked.

## Contribution

### cobussie :

- **$O(n \log n)$ algorithm** implementation 
- **$O(n^2)$ algorithm** implementation
- **parsing** of **all** arguments
- **bench mode** implementation
- **rotate** operations

### gagulhon :

- **$O(n\sqrt{n})$ algorithm** implementation 
- **push and swap** operations
- ****Bonus :**** **Checker program** implementation
