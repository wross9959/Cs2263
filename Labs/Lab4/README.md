
# CS2263

## Lab 3
**Date:** February 8th, 2024  
---
**Student:**  
Name: Will Ross  
Number: #3734692  
Email: [will.ross@unb.ca](mailto:will.ross@unb.ca)

**Due Date:** February 12th, 2024
---
## Contents
- [Lab 3](#lab-3)
      - [Name](#name)
      - [Studnet ID](#studnet-id)
      - [Course](#course)
      - [Date](#date)
  - [Contents](#contents)
  - [Pre Lab](#pre-lab)
    - [Answer](#answer)
  - [Exercise 1](#exercise-1)
    - [Source code](#Source-code)
    - [Output Screenshot](#output-screenshot)
    - [Are the pointer variables incremented between successive print operations?](#are-the-pointer-variables-incremented-between-successive-print-operations)
    - [Use the memory addresses printed by your program to calculate the increments used for each pointer variable.](#use-the-memory-addresses-printed-by-your-program-to-calculate-the-increments-used-for-each-pointer-variable)
      - [tptr (int pointer)](#tptr-int-pointer)
      - [cptr (char pointer)](#cptr-char-pointer)
      - [dptr (double pointer)](#dptr-double-pointer)
    - [Are the increments for different pointers the same? Explain why.](#are-the-increments-for-different-pointers-the-same-explain-why)
  - [Exercise 2](#exercise-2)
    - [Source code](#Source-code-1)
    - [Output Screenshot](#output-screenshot-1)
  - [Exercise 3](#exercise-3)
    - [Source code](#Source-code-2)
    - [Output Screenshot](#output-screenshot-2)
  - [Exercise 4](#exercise-4)
  - [Compiler command](#compiler-command)
    - [Source code](#Source-code-3)
    - [Output Screenshot](#output-screenshot-3)
    - [Diagram of memory locations](#diagram-of-memory-locations)
    - [Are the results (i.e. numerical values) printed from your program different from the results shown in the textbook? Explain why](#are-the-results-ie-numerical-values-printed-from-your-program-different-from-the-results-shown-in-the-textbook-explain-why)
      - [Memory addresses](#memory-addresses)
      - [Numeric Changes](#numeric-changes)
      - [TextBook Results](#textbook-results)
      - [My Results](#my-results)



## Lab 3


## Exercise 1

### 1.1  Run the program ex1.c in the gdb debugger (see Laboratory #2 instructions). Set up the breakpoint at the function dummy_frame(). Run the program until the breakpoint.
---
```bash
1. gdb ex1
2. break dummy_frame
3. run
4. backtrace
5. select-frame 0
6. info frame

```
#### A. The screenshot showing the output form the backtrace bt. How many frames are there on the memory stack?


#### B. The screenshot showing the output info frame 0. What are the frame boundaries of the main function? (Hint: compare the values under “Stack frame at” and “Called by frame at”).


#### C. Are the addresses of array elements falling within the range of the main function frame?

The addresses 0x5ffe80 to 0x5ffe90 are within the main functions stack as we can see from the screenshot below


### 1.2  Modify the program ex1.c so that the array a[] is allocated on the heap (use malloc()). Set up the breakpoint at the function dummy_frame(). Run the program until the breakpoint.
---

#### A. The source code of the modified program


#### B. The screenshot showing the output form the backtrace bt. How many frames are there on the memory stack?


#### C. The screenshot showing the output info frame 0. What are the frame boundaries of the main function? (Hint: compare the values under “Stack frame at” and “Called by frame at”).


#### D. Are the addresses of array elements falling within the range of the main function frame? Explain why.


## Exercise 2

### The source code of the modified program


### The screenshot showing the output. Are you getting the same addresses for the new extended array? Explain why.
![Screenshot](Ex2Output.png)


## Exercise 3

### Source code 

```c
#include <stdio.h>
#include <stdlib.h>


int arrindex(int a[], int * p){
    return p - a;
}


int main (int argc ,char * * argv)
{

    //for exercise 3
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i ++){
        printf ("%d\t%d\n", i, arrindex( arr, & arr[i]));
    }
    return EXIT_SUCCESS;
}
```

### Output Screenshot
![Screenshot](Ex3Output.png)

## Exercise 4

## Compiler command
`[q3d5k@gc112m38 Lab3]$ cd "/home1/ugrads/q3d5k/Cs2263/Labs/Lab3/" && gcc wrongindex.c -o wrongindex && "/home1/ugrads/q3d5k/Cs2263/Labs/Lab3/"wrongindex`

### Source code 

```c

/*
 * wrongindex.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
    int x = -2;
    int arr[] = {0, 1, 2, 3, 4};
    int y = 15;

    //memory address of x and y
    //printf("& x = %p, & y = %p\n", (void*)& x, (void*)& y);

    printf("& of x = %p,\n& of y = %p\n", & x, & y);


    //one invaild
    printf("& of arr[%d] %d\t%p\n", -1,arr[-1], &arr[-1]);

    //all valid
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]) + 1; i++){

        printf("& of arr[%d]\t%d\t%p\n", i,arr[i], &arr[i]);

    }

    printf("x = %d, y = %d\n", x, y);

    arr[-1] = 7;
    arr[5]  = -23;

    printf("x = %d, y = %d\n", x, y);


    arr[6]  = 108;

    printf("x = %d, y = %d\n", x, y);

    arr[7]  = -353;

    printf("x = %d, y = %d\n", x, y);

    return EXIT_SUCCESS;
}

```

### Output Screenshot
![Screenshot](Ex4Output.png)

### Diagram of memory locations
![Screenshot](Diagram.png)
### Are the results (i.e. numerical values) printed from your program different from the results shown in the textbook? Explain why

#### Memory addresses

My memory address will be completely diffrenet due to c being a hardware low level language so our memory addresses/pointers wil most likely always be different.

#### Numeric Changes
In the text they do the out of bounds call `arr[-1]` there x changes to 108 while my y changes to 7 when I call `arr[-1]` this means that it does not overlap with y in my program due to my personal memory layout. 

#### TextBook Results

```
& x = 0x7fffcabf4e68, & y = 0x7fffcabf4e6c
& arr[0] = 0x7fffcabf4e50, & arr[4] = 0x7fffcabf4e60
x = -2, y = 15
x = -2, y = 15
x = 108, y = 15
x = 108, y = -353

As we can see, x has changed because of this assignment:
    arr [6] = 108;
Similarly, y is changed because of this assignment:
    arr [7] = -353;

```

#### My Results

```
[q3d5k@gc112m38 ~]$ cd "/home1/ugrads/q3d5k/Cs2263/Labs/Lab3/" && gcc wrongindex.c -o wrongindex && "/home1/ugrads/q3d5k/Cs2263/Labs/Lab3/"wrongindex
& of x = 0x7ffd46b75ae8,
& of y = 0x7ffd46b75acc
& of arr[-1] 15 0x7ffd46b75acc
& of arr[0]     0       0x7ffd46b75ad0
& of arr[1]     1       0x7ffd46b75ad4
& of arr[2]     2       0x7ffd46b75ad8
& of arr[3]     3       0x7ffd46b75adc
& of arr[4]     4       0x7ffd46b75ae0
& of arr[5]     0       0x7ffd46b75ae4
& of arr[6]     -2      0x7ffd46b75ae8
& of arr[7]     7       0x7ffd46b75aec
x = -2, y = 15
x = -2, y = 7
x = 108, y = 7
x = 108, y = 7
[q3d5k@gc112m38 Lab3]$ 
```
