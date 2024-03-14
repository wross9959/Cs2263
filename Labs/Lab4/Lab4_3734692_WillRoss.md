
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
- [Lab 4](#lab-4)
      - [Name](#name)
      - [Studnet ID](#studnet-id)- [CS2263](#cs2263)
  - [Contents](#contents)
  - [Exercise 1](#exercise-1)
    - [1.1  Run the program ex1.c in the gdb debugger (see Laboratory #2 instructions). Set up the breakpoint at the function dummy\_frame(). Run the program until the breakpoint.](#11--run-the-program-ex1c-in-the-gdb-debugger-see-laboratory-2-instructions-set-up-the-breakpoint-at-the-function-dummy_frame-run-the-program-until-the-breakpoint)
      - [A. The screenshot showing the output form the backtrace bt. How many frames are there on the memory stack?](#a-the-screenshot-showing-the-output-form-the-backtrace-bt-how-many-frames-are-there-on-the-memory-stack)
      - [B. The screenshot showing the output info frame 0. What are the frame boundaries of the main function? (Hint: compare the values under “Stack frame at” and “Called by frame at”).](#b-the-screenshot-showing-the-output-info-frame-0-what-are-the-frame-boundaries-of-the-main-function-hint-compare-the-values-under-stack-frame-at-and-called-by-frame-at)
      - [C. Are the addresses of array elements falling within the range of the main function frame?](#c-are-the-addresses-of-array-elements-falling-within-the-range-of-the-main-function-frame)
    - [1.2  Modify the program ex1.c so that the array a\[\] is allocated on the heap (use malloc()). Set up the breakpoint at the function dummy\_frame(). Run the program until the breakpoint.](#12--modify-the-program-ex1c-so-that-the-array-a-is-allocated-on-the-heap-use-malloc-set-up-the-breakpoint-at-the-function-dummy_frame-run-the-program-until-the-breakpoint)
      - [A. The source code of the modified program](#a-the-source-code-of-the-modified-program)
      - [B. The screenshot showing the output form the backtrace bt. How many frames are there on the memory stack?](#b-the-screenshot-showing-the-output-form-the-backtrace-bt-how-many-frames-are-there-on-the-memory-stack)
      - [C. The screenshot showing the output info frame 0. What are the frame boundaries of the main function? (Hint: compare the values under “Stack frame at” and “Called by frame at”).](#c-the-screenshot-showing-the-output-info-frame-0-what-are-the-frame-boundaries-of-the-main-function-hint-compare-the-values-under-stack-frame-at-and-called-by-frame-at)
      - [D. Are the addresses of array elements falling within the range of the main function frame? Explain why.](#d-are-the-addresses-of-array-elements-falling-within-the-range-of-the-main-function-frame-explain-why)
  - [Exercise 2](#exercise-2)
    - [The source code of the modified program](#the-source-code-of-the-modified-program)
    - [The screenshot showing the output. Are you getting the same addresses for the new extended array? Explain why.](#the-screenshot-showing-the-output-are-you-getting-the-same-addresses-for-the-new-extended-array-explain-why)
  - [Exercise 3](#exercise-3)
    - [Remove any calls to free() function (if you had any) form the program form Exercise 2 and then run it again under valgrind. to Show the complete output (program output, plus the valgrind messages).  For example:](#remove-any-calls-to-free-function-if-you-had-any-form-the-program-form-exercise-2-and-then-run-it-again-under-valgrind-to-show-the-complete-output-program-output-plus-the-valgrind-messages--for-example)
    - [Modify the program from Exercise 3.1 to eliminate the memory leak. Run the program again under valgrind. Show the modified program source code and the complete output (program output, plus the valgrind messages, if any).](#modify-the-program-from-exercise-31-to-eliminate-the-memory-leak-run-the-program-again-under-valgrind-show-the-modified-program-source-code-and-the-complete-output-program-output-plus-the-valgrind-messages-if-any)

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

![Backtrace1](Exercise1Photos\ex1A2.png)

From the photo we see that we have two frames frame 1 and frame o on the memory stack.

#### B. The screenshot showing the output info frame 0. What are the frame boundaries of the main function? (Hint: compare the values under “Stack frame at” and “Called by frame at”).

![InfoFrame0.1](Exercise1Photos\ex1B.png)

Stack Frame at: 0x5ffe60
Called by Frame at: 0x5ffeb0

So the frame bountries are 0x5ffeb0 -> 0x5ffe60

#### C. Are the addresses of array elements falling within the range of the main function frame?

![MainFrame1](Exercise1Photos\mainframe.png)

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

![Backtrace2](Exercise1Photos\ex1.2A.png)

From the photo we see that we have two frames frame 1 and frame 0 on the memory stack.

#### C. The screenshot showing the output info frame 0. What are the frame boundaries of the main function? (Hint: compare the values under “Stack frame at” and “Called by frame at”).

![InfoFrame2](Exercise1Photos\ex1.2C.png)

Stack Frame at: 0x5ffe70
Called by Frame at: 0x5ffeb0

So the frame bountrys are 0x5ffeb0 -> 0x5ffe70

#### D. Are the addresses of array elements falling within the range of the main function frame? Explain why.

![MainFrame2](Exercise1Photos\ex1.2D2.png)

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

Source Code:

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

    return EXIT_SUCCESS;
}
```

The output from running valgrind ./ex3

```txt
==6479== Memcheck, a memory error detector
==6479== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==6479== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==6479== Command: ./ex3
==6479== 

Malloc Values:

==6479== Invalid write of size 4
==6479==    at 0x109218: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479==  Address 0x4a7c044 is 4 bytes inside a block of size 5 alloc'd
==6479==    at 0x4845828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==6479==    by 0x1091E1: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479== 
a[0] = 1 at address: 0x4a7c040 
==6479== Conditional jump or move depends on uninitialised value(s)
==6479==    at 0x48D2B59: __printf_buffer (vfprintf-process-arg.c:58)
==6479==    by 0x48D36E0: __vfprintf_internal (vfprintf-internal.c:1523)
==6479==    by 0x48C886E: printf (printf.c:33)
==6479==    by 0x109272: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479== 
==6479== Use of uninitialised value of size 8
==6479==    at 0x48C777B: _itoa_word (_itoa.c:178)
==6479==    by 0x48D19A3: __printf_buffer (vfprintf-process-arg.c:155)
==6479==    by 0x48D36E0: __vfprintf_internal (vfprintf-internal.c:1523)
==6479==    by 0x48C886E: printf (printf.c:33)
==6479==    by 0x109272: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479== 
==6479== Conditional jump or move depends on uninitialised value(s)
==6479==    at 0x48C778C: _itoa_word (_itoa.c:178)
==6479==    by 0x48D19A3: __printf_buffer (vfprintf-process-arg.c:155)
==6479==    by 0x48D36E0: __vfprintf_internal (vfprintf-internal.c:1523)
==6479==    by 0x48C886E: printf (printf.c:33)
==6479==    by 0x109272: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479== 
a[1] = 2 at address: 0x4a7c044 
==6479== Invalid read of size 4
==6479==    at 0x109258: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479==  Address 0x4a7c048 is 3 bytes after a block of size 5 alloc'd
==6479==    at 0x4845828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==6479==    by 0x1091E1: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479== 
a[2] = 3 at address: 0x4a7c048 
a[3] = 4 at address: 0x4a7c04c 
a[4] = 5 at address: 0x4a7c050 

Realloc Values:

==6479== Invalid write of size 4
==6479==    at 0x1092C9: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479==  Address 0x4a7c4e4 is 11 bytes after a block of size 9 alloc'd
==6479==    at 0x484ABC0: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==6479==    by 0x1092A2: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479== 
a[0] = 1 at address: 0x4a7c4d0 
==6479== Conditional jump or move depends on uninitialised value(s)
==6479==    at 0x48D2B59: __printf_buffer (vfprintf-process-arg.c:58)
==6479==    by 0x48D36E0: __vfprintf_internal (vfprintf-internal.c:1523)
==6479==    by 0x48C886E: printf (printf.c:33)
==6479==    by 0x109323: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479== 
a[1] = 2 at address: 0x4a7c4d4 
==6479== Conditional jump or move depends on uninitialised value(s)
==6479==    at 0x48D1A54: __printf_buffer (vfprintf-process-arg.c:186)
==6479==    by 0x48D36E0: __vfprintf_internal (vfprintf-internal.c:1523)
==6479==    by 0x48C886E: printf (printf.c:33)
==6479==    by 0x109323: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479== 
a[2] = 0 at address: 0x4a7c4d8 
==6479== Invalid read of size 4
==6479==    at 0x109309: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479==  Address 0x4a7c4dc is 3 bytes after a block of size 9 alloc'd
==6479==    at 0x484ABC0: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==6479==    by 0x1092A2: main (in /home/will/Git/Cs2263/Labs/Lab4/ex3)
==6479== 
a[3] = 0 at address: 0x4a7c4dc 
a[4] = 0 at address: 0x4a7c4e0 
a[5] = 6 at address: 0x4a7c4e4 
a[6] = 7 at address: 0x4a7c4e8 
a[7] = 8 at address: 0x4a7c4ec 
a[8] = 9 at address: 0x4a7c4f0 
==6479== 
==6479== HEAP SUMMARY:
==6479==     in use at exit: 9 bytes in 1 blocks
==6479==   total heap usage: 3 allocs, 2 frees, 1,038 bytes allocated
==6479== 
==6479== LEAK SUMMARY:
==6479==    definitely lost: 9 bytes in 1 blocks
==6479==    indirectly lost: 0 bytes in 0 blocks
==6479==      possibly lost: 0 bytes in 0 blocks
==6479==    still reachable: 0 bytes in 0 blocks
==6479==         suppressed: 0 bytes in 0 blocks
==6479== Rerun with --leak-check=full to see details of leaked memory
==6479== 
==6479== Use --track-origins=yes to see where uninitialised values come from
==6479== For lists of detected and suppressed errors, rerun with: -s
==6479== ERROR SUMMARY: 28 errors from 9 contexts (suppressed: 0 from 0)
will@will-System-Product-Name:~/Git/Cs2263/Labs/Lab4$ 
```
