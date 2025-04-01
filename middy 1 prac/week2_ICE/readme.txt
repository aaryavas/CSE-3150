In this practice, you will write a simple code that takes an integer from standard input and outputs its square and the two-times of this integer. 

The purpose of this practice is getting started on C++ header/source file structure, compiling and linking and standard I/O.


PA1: std::cout << XXXX <<std::endl <iostream>

* Input (cin): cin is an instance of the istream class and is used to read input from the standard input device, usually the keyboard. You can use the extraction operator (>>) to read input into variables.
* Output (cout): cout is an instance of the ostream class and is used to write output to the standard output device, usually the console. You can use the insertion operator (<<) to write values to the console.
* Error Output (cerr): cerr is used to output error messages to the standard error device, which is also usually the console. It is used in a similar way to cout.
* Log Output (clog): clog is used for logging messages, and it is also used in a similar way to cout and cerr.

File: <fstream>

* ifstream: This class is used to read data from files. It stands for input file stream.
* ofstream: This class is used to write data to files. It stands for output file stream.
* fstream: This class can perform both read and write operations on files. It stands for file stream.


Check the provided started code for function signatures.

0. The very first practice is practicing how to debug a C program. 

Open the file called ECBug.cpp. It does something very simple: it has a single function: int ECSillyCalc(int a); This function returns 1 if a is non-negative. Although it looks simple, it has some bugs that you need to fix. Have you found the bug(s)? If you haven't, how to find the bugs?

1. The first part is implementing two functions as specified in ECNumbers.h. Note: you need to declare the functions properly according to the description. Note: you need to properly write up the header file!

2. Once you complete the code in ECNumbers.h, create a namespace called ECNumbers and place the two functions you just implemented inside this namespace.

3. Now implement the (simple) function in ECCalculator.cpp

4. Now test the functions you just coded in TestNumbers.cpp. Here you would practice how to invoke functions when there is namespace

5. Now experiment to work with files in separate folders. Copy the header files you just created into the inc folder under SeparateFolder, and the source files under src folder. Now try to compile the code.


*********************************************************
Programming practice: implement function
void ECRemoveSpace(int nums[], int let, int val) 
(from Leetcode)

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.





Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
