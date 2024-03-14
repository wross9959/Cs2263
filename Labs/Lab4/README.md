
# CS2263

## Lab 4
**Date:** March 14th, 2024  
---
**Student:**  
Name: Will Ross  
Number: #3734692  
Email: [will.ross@unb.ca](mailto:will.ross@unb.ca)

**Due Date:** March 18th, 2024

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

<div style="page-break-after: always;"></div>

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

![Backtrace](Exercise1Photos\ex1A2.png)

From the photo we see that we have two frames frame 1 and frame o on the memory stack.

#### B. The screenshot showing the output info frame 0. What are the frame boundaries of the main function? (Hint: compare the values under “Stack frame at” and “Called by frame at”).
![InfoFrame0](Exercise1Photos\ex1B.png)

Stack Frame at: 0x5ffe60
Called by Frame at: 0x5ffeb0

So the frame bountrys are 0x5ffeb0 -> 0x5ffe60

#### C. Are the addresses of array elements falling within the range of the main function frame?

![MainFrame](Exercise1Photos\mainframe.png)

The addresses 0x5ffeb0 -> 0x5ffe60 are within the main functions stack as we can see from the screenshot above.

<div style="page-break-after: always;"></div>

### 1.2  Modify the program ex1.c so that the array a[] is allocated on the heap (use malloc()). Set up the breakpoint at the function dummy_frame(). Run the program until the breakpoint.
---

#### A. The source code of the modified program

```c
#include <stdio.h>
#include <stdlib.h>
 
void dummy_frame()
{
  return;
}

int main(int argc, char * * argv)
{

  int i;
  int size = 5;

  int *a = (int*)malloc(size);

  //fill array with 1 to 5
  for(i = 0; i <= size; i++)
  {
    a[i] = i + 1;
  }

  dummy_frame();

  for (i=0; i< size; i++){
    printf("a[%d] = %d at address: %p \n", i, a[i], &a[i]);
  }
  

  free(a);
  return EXIT_SUCCESS;
}

```
#### B. The screenshot showing the output form the backtrace bt. How many frames are there on the memory stack?

![Backtrace](Exercise1Photos\ex1.2A.png)

From the photo we see that we have two frames frame 1 and frame 0 on the memory stack.

#### C. The screenshot showing the output info frame 0. What are the frame boundaries of the main function? (Hint: compare the values under “Stack frame at” and “Called by frame at”).

![InfoFrame](Exercise1Photos\ex1.2C.png)

Stack Frame at: 0x5ffe70
Called by Frame at: 0x5ffeb0

So the frame bountrys are 0x5ffeb0 -> 0x5ffe70

#### D. Are the addresses of array elements falling within the range of the main function frame? Explain why.
![MainFrame](Exercise1Photos\ex1.2D2.png)

No, becuase of how malloc reserves memory. It reseveres a user-defined chuick of memory and the address of the users defined memory is higher then the addresses of the stack frame.

<div style="page-break-after: always;"></div>

## Exercise 2
---
### The source code of the modified program
```c
#include <stdio.h>
#include <stdlib.h>


void dummy_frame()
{
    return;
}

int main(int argc, char * * argv)
{

    int i;
    int size = 5;
    int addedSize = 9;
    int *a;

    //call malloc
    a = (int *) malloc(size);
    printf("\nMalloc Values:\n\n");
    //fill array with 1 to 5
    for(i = 0; i <= size; i++)
    {
        a[i] = i + 1;
    }

    //print the original array
    for (i=0; i< size; i++)
    {
        printf("a[%d] = %d at address: %p \n", i, a[i], &a[i]);
    }

    printf("\nRealloc Values:\n\n");
    //called realloc getting the orignal values + our new size
    a = (int *) realloc(a, addedSize);

    //add more values to the array
    for(i = size; i < addedSize; i++){
        a[i] = i + 1;
    }

    //print all values
    for (i=0; i< addedSize; i++)
    {
        printf("a[%d] = %d at address: %p \n", i, a[i], &a[i]);
    }

    free(a);
    return EXIT_SUCCESS;
}

```

### The screenshot showing the output. Are you getting the same addresses for the new extended array? Explain why.
![Exercise2Output](Exercise2Photos\Output.png)

Due to us using the realloc function for our array it tells our system to keep the same addresses when using the function to resurve memory space. So when we call realoc to add more elements onto our array it will find our array and build off of it. In our case and it being an integer array the memory pointer increments in 4.

<div style="page-break-after: always;"></div>

## Exercise 3
---
### Remove any calls to free() function (if you had any) form the program form Exercise 2 and then run it again under valgrind. to Show the complete output (program output, plus the valgrind messages).  For example:
`valgrind ./a.out`


### Modify the program from Exercise 3.1 to eliminate the memory leak. Run the program again under valgrind. Show the modified program source code and the complete output (program output, plus the valgrind messages, if any).  

