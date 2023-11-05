# Optimizing Adaptive Seed Search in a Suffix Array
## Test information
- Data:
   -Nebulin gene. About 500,000 bases. Y-chromosome genomes of chimpanzees. About 200,000,00 bases.
* Algorithms:
  -a. Build the suffix array of this gene and then test search algorithms on the suffix array. 
  -b. Test two rounds of binary search. 
  -c. Test two rounds of adapted ternary search. 
  -d. Test one round of exponential search to find the upper bound, and one round of binary search to find the lower bound, because exponential search is not good for finding the lower bound. 
+ Time catch:
   -Run 10,000 loops and take the average of the algorithm for a simple test.
## Simple result
- The test platform is an Intel i5-13600KF@3.50 GHz with 32GB DDR4 3200mhz RAM, running on Windows 10 (x64). Only single-core computing is used due to the simple model.
+ The data in the bracket indicate that the result is at the start of the array.

| Algorithm | Binary search | Ternary search | Exponential search | Interpolation search | Interpolation optimized |
| :----: | :----: || :----: || :----: || :----: || :----: |
| Time(μs)| 0.107 (0.104) | 0.108 (0.091) | 0.162 (0.062) | 0.197 (0.141) | 0.136 (0.179) |
