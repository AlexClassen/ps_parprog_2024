# Exercise 2

**fast.c:**
- Uses a parallel region with private localSum variables for each thread.
- The loop is parallelized using #pragma omp for.
- Each thread increments its own localSum.
- After the parallel region, a critical section (#pragma omp critical) is used to safely accumulate the individual thread sums into the global sum.

**medium.c:**
- Uses a parallel for loop (#pragma omp parallel for).
- The loop is parallelized directly, and each thread increments the shared sum using #pragma omp atomic to ensure atomicity of the increment operation.
- This eliminates the need for a separate critical section.

**slow.c:**
- Similar to medium.c but uses a critical section (#pragma omp critical) inside the loop instead of an atomic operation.
- This makes the increment operation for the shared sum variable atomic within the critical section.

This part was generated with ChatGPT to get a low level of understanding about the code:

"Whats the diffrence between the three diffrent code snippets: < Entering the code snippets >" prompt. ChatGPT, 3.5, OpenAI, 11 Mar. 2024. 

### Compile the three given source codes slow.c, medium.c, and fast.c with the compiler flag -fopenmp to enable OpenMP parallelism.

```
EXEC_FILES := fast medium slow

all: $(EXEC_FILES)

%: %.c
	clang -Xclang -fopenmp -L/opt/homebrew/opt/libomp/lib -I/opt/homebrew/opt/libomp/include -lomp $< -o $@ 

.PHONY: clean
clean:
	rm -f $(EXEC_FILES)

```

### Vary the number of cores by setting the environment variable OMP_NUM_THREADS before running the program, e.g. OMP_NUM_THREADS=1 ./slow. Measure the execution times of all three programs for all numbers of cores your personal computing system (e.g. PC or laptop) offers.

### See if you can reduce the execution times even further by trying out different compiler flags (optimization flags).

O2 (Optimization Level 2):
This level enables a set of optimizations that improve the performance of the compiled code without sacrificing too much in terms of compilation time. It includes common optimizations like loop unrolling, function inlining, and basic instruction scheduling.

```
clang -Xclang -fopenmp -L/opt/homebrew/opt/libomp/lib -I/opt/homebrew/opt/libomp/include -lomp -O2 fast.c -o faster
```

Using the -O2 flag the time got reduced to **0,0003 seconds** on average (10 tries).

O3 (Optimization Level 3):
This level includes more aggressive optimizations compared to -O2. It might perform more extensive loop transformations, vectorization, and other advanced optimizations that could result in better runtime performance. However, the trade-off is that compilation time might be longer.

```
clang -Xclang -fopenmp -L/opt/homebrew/opt/libomp/lib -I/opt/homebrew/opt/libomp/include -lomp -=3 fast.c -o faster
```

Using the -O3 flag the time got reduced to **0,00023 seconds** on average (10 tries).

### Create a table and figures that illustrate the measured data and study them. What effects can you observe?

| OMP_NUM_THREADS | Slow    | Medium | Fast   | Faster   |
|-----------------|---------|--------|--------|----------|
| 1    	   		  | 32.1363 | 0.2258 | 0.1395 |	< 0.0001 |
| 2    	   		  | 10.5227 | 0.8323 | 0.0715 | 0.0001   |
| 3    	   		  | 10.9548 | 1.085  | 0.0485 |	0.0001   |
| 4    	   		  | 10.7014 | 1.2650 | 0.0377 | 0.0001   |
| 5    	   		  | 23.0380 | 1.6720 | 0.0342 | 0.0002   |
| 6    	   		  | 26.337  | 2.4420 | 0.0316 | 0.0002   |
| 7    	   		  | 27.6001 | 2.5450 | 0.0274 | 0.0002   |
| 8    	   		  | 29.8158 | 3.2392 | 0.0250 | 0.0002   |

*Faster meaning fast + optimization flags.*

### How stable are the measurements when running the experiments multiple times?

Pretty stable during testing of diffrent flags and different cores.

### Enter the shortest execution times for 1 and 12 threads measured on the LCC3 cluster for each code to the performance comparison sheet linked on Discord.

**Slow:**

sum: 67108864, time: 0.0001 seconds

real	0m0.003s
user	0m0.001s
sys	0m0.000s
sum: 67108864, time: 0.0000 seconds

real	0m0.002s
user	0m0.000s
sys	0m0.002s

**Medium:**

sum: 67108864, time: 0.4252 seconds

real	0m0.428s
user	0m0.740s
sys	0m0.001s
sum: 67108864, time: 0.4321 seconds

real	0m0.434s
user	0m0.857s
sys	0m0.001s

**Fast:**

sum: 67108864, time: 0.0004 seconds

real	0m0.009s
user	0m0.006s
sys	0m0.000s
