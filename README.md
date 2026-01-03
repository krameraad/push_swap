*This project has been created as part of the 42 curriculum by ekramer*

# push_swap
Sort an array of integers organized in a pair of structures called *stack a* and *stack b*. Stack a starts with all integers, b starts empty. Only certain operations are allowed on these stacks:

- **Swap**: swap the top two elements of a stack.
- **Push**: push the top element to the other stack.
- **Rotate**: move all elements up one position (first element becomes last).
- **Reverse rotate**: move all elements down one position (last element becomes first).

Implement a sorting algorithm that can use these operations to sort any given list of integers in ascending order, printing the required operations to the terminal. Of course, the number of operations performed is limited; the algorithm should be efficient and able to handle small and large lists.

## Instructions
Tests are dependent on `arg_gen` from this repo: `git@github.com:krameraad/arg_gen.git`. It's a program to generate random arrays of integers, ordered, shuffled, and with varying distances between each element.

Clone `arg_gen` and place its source file in the push_swap directory.
Then, run `make -i test` in the root directory to compile the program and run all tests with `arg_gen`. **The `-i` is important**: some tests cause the program to exit with a non-zero exit code, which normally stops Make from progressing. Some of the tests use a random seed, which must be manually changed if you want to see more permutations (there are three default seeds per category).

## Resources
I evaluated someone on push_swap before making this project, which gave me a good idea on how to make the project. He was also the reason I used radix sort. Apart from that, I used help from other students and AI.
- Bitwise operators: https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/
- Radix sort visualization: https://www.youtube.com/watch?v=mVRHvZF8xtg
