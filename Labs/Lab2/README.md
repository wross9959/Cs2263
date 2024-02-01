exercise 2
gcc -g -Wall -Wshadow p1.c -o p1
gcc -g -Wall -Wshadow calcTrib.c -o calcTrib
ddd ./p1

ddd ./calcTrib

(gdb) b g1
(gdb) b g2



(gdb) run



(gdb) continue


(gdb) bt


(gdb) info frame




or


gdb ./p1
(gdb) break g1
(gdb) break g2
(gdb) run
(gdb) continue
(gdb) bt
(gdb) info frame





gcc -g -Wall -Wshadow p1.c -o p1
 ./p1
gdb ./p1

(gdb) b g1
(gdb) b g2
(gdb) run
(gdb) continue
(gdb) bt
(gdb) bt
(gdb) f 1


output
PS C:\Users\willr\Documents\GitHub\Cs2263\Labs\Lab2> gdb ./p1
GNU gdb (GDB) 14.1
Copyright (C) 2023 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-w64-mingw32".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./p1...
(gdb) (gdb) b g1
Undefined command: "".  Try "help".
(gdb) b g1
Breakpoint 1 at 0x1400014b2: file p1.c, line 6.
(gdb) b g2
Breakpoint 2 at 0x14000151b: file p1.c, line 14.
(gdb) run
Starting program: C:\Users\willr\Documents\GitHub\Cs2263\Labs\Lab2\p1.exe
[New Thread 30484.0x15dc]

Thread 1 hit Breakpoint 2, g2 (a=4, b=34) at p1.c:14
14          int c = g1(a + 3, b - 11);
(gdb) continue
Continuing.

Thread 1 hit Breakpoint 1, g1 (a=7, b=23) at p1.c:6
6           int c = (a + b) * b;
(gdb) bt
#0  g1 (a=7, b=23) at p1.c:6
#1  0x00007ff7827f152e in g2 (a=4, b=34) at p1.c:14
#2  0x00007ff7827f15b7 in main (argc=1, argv=0x6c4750) at p1.c:24

(gdb) info frame 1 
Stack frame at 0x5ffe70:
 rip = 0x7ff7827f152e in g2 (p1.c:14); saved rip = 0x7ff7827f15b7
 called by frame at 0x5ffeb0, caller of frame at 0x5ffe30
 source language c.
 Arglist at 0x5ffe60, args: a=4, b=34
 Locals at 0x5ffe60, Previous frame's sp is 0x5ffe70
 Saved registers:
  rbp at 0x5ffe60, rip at 0x5ffe68, xmm15 at 0x5ffe68
(gdb) info frame 2
Stack frame at 0x5ffeb0:
 rip = 0x7ff7827f15b7 in main (p1.c:24); saved rip = 0x7ff7827f12ee
 caller of frame at 0x5ffe70
 source language c.
 Arglist at 0x5ffea0, args: argc=1, argv=0x6c4750
 Locals at 0x5ffea0, Previous frame's sp is 0x5ffeb0
 Saved registers:
  rbp at 0x5ffea0, rip at 0x5ffea8, xmm15 at 0x5ffea8
(gdb)

(gdb) info frame
Stack level 0, frame at 0x5ffe30:
 rip = 0x7ff7827f14b2 in g1 (p1.c:6); saved rip = 0x7ff7827f152e
 called by frame at 0x5ffe70
 source language c.
 Arglist at 0x5ffe20, args: a=7, b=23
 Locals at 0x5ffe20, Previous frame's sp is 0x5ffe30
 Saved registers:
  rbp at 0x5ffe20, rip at 0x5ffe28, xmm15 at 0x5ffe28
(gdb)


[q3d5k@gc112m37 Lab2]$ cd "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/" && gcc p1.c -o p1 && "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/"p1
g1:   a = 7, b = 23, c = 690
g1: address of a = 0x7ffe5ea7361c
address of b = 0x7ffe5ea73618
 address of c = 0x7ffe5ea7362c
g2:   a = 4, b = 34, c = 690
g2: address of a = 0x7ffe5ea7364c, address of b = 0x7ffe5ea73648, address of c = 0x7ffe5ea7365c
main: a = 5, b = 17, c = 656
main: address of a = 0x7ffe5ea7368c, address of b = 0x7ffe5ea73688, address of c = 0x7ffe5ea73684
[q3d5k@gc112m37 Lab2]$ cd "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/" && gcc p1.c -o p1 && "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/"p1
g1: a = 7
b = 23
c = 690
g1: address of a = 0x7ffe68e3674c
 address of b = 0x7ffe68e36748
 address of c = 0x7ffe68e3675c
g2:     a = 4
b = 34
c = 690
g2:     address of a = 0x7ffe68e3677c, address of b = 0x7ffe68e36778, address of c = 0x7ffe68e3678c
main: a = 5, b = 17, c = 656
main: address of a = 0x7ffe68e367bc, address of b = 0x7ffe68e367b8, address of c = 0x7ffe68e367b4
[q3d5k@gc112m37 Lab2]$ cd "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/" && gcc p1.c -o p1 && "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/"p1
g1:
a = 7
b = 23
c = 690
g1:
address of a = 0x7fffea2d715c
 address of b = 0x7fffea2d7158
 address of c = 0x7fffea2d716c
g2:     a = 4
b = 34
c = 690
g2:     address of a = 0x7fffea2d718c, address of b = 0x7fffea2d7188, address of c = 0x7fffea2d719c
main: a = 5, b = 17, c = 656
main: address of a = 0x7fffea2d71cc, address of b = 0x7fffea2d71c8, address of c = 0x7fffea2d71c4
[q3d5k@gc112m37 Lab2]$ cd "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/" && gcc p1.c -o p1 && "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/"p1
g1:
a = 7
b = 23
c = 690
g1:
address of a = 0x7ffd0659d2cc
 address of b = 0x7ffd0659d2c8
 address of c = 0x7ffd0659d2dc
g2:
a = 4
b = 34
c = 690
g2:
address of a = 0x7ffd0659d2fc
address of b = 0x7ffd0659d2f8
address of c = 0x7ffd0659d30c
main: a = 5, b = 17, c = 656
main: address of a = 0x7ffd0659d33c, address of b = 0x7ffd0659d338, address of c = 0x7ffd0659d334
[q3d5k@gc112m37 Lab2]$ cd "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/" && gcc p1.c -o p1 && "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/"p1
g1:
a = 7
b = 23
c = 690
g1:
address of a = 0x7fff05ada89c
address of b = 0x7fff05ada898
address of c = 0x7fff05ada8ac
g2:
a = 4
b = 34
c = 690
g2:
address of a = 0x7fff05ada8cc
address of b = 0x7fff05ada8c8
address of c = 0x7fff05ada8dc
main:
a = 5
b = 17
c = 656
main:
address of a = 0x7fff05ada90c
address of b = 0x7fff05ada908
address of c = 0x7fff05ada904
[q3d5k@gc112m37 Lab2]$ gcc -g -Wall -Wshadow p1.c -o p1
[q3d5k@gc112m37 Lab2]$ ./p1
g1:
a = 7
b = 23
c = 690
g1:
address of a = 0x7fff3d5a0c1c
address of b = 0x7fff3d5a0c18
address of c = 0x7fff3d5a0c2c
g2:
a = 4
b = 34
c = 690
g2:
address of a = 0x7fff3d5a0c4c
address of b = 0x7fff3d5a0c48
address of c = 0x7fff3d5a0c5c
main:
a = 5
b = 17
c = 656
main:
address of a = 0x7fff3d5a0c8c
address of b = 0x7fff3d5a0c88
address of c = 0x7fff3d5a0c84
[q3d5k@gc112m37 Lab2]$ gdb ./p1
GNU gdb (GDB) Rocky Linux 10.2-10.el9.0.1
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
--Type <RET> for more, q to quit, c to continue without paging--b g1
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./p1...
(gdb) b g2
Breakpoint 1 at 0x401190: file p1.c, line 14.
(gdb) exit
Undefined command: "exit".  Try "help".
(gdb) quit
[q3d5k@gc112m37 Lab2]$ gcc -g -Wall -Wshadow p1.c -o p1                      
[q3d5k@gc112m37 Lab2]$ gdb ./p1
GNU gdb (GDB) Rocky Linux 10.2-10.el9.0.1
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./p1...
(gdb) b g1
Breakpoint 1 at 0x401134: file p1.c, line 6.
(gdb) b g2
Breakpoint 2 at 0x401190: file p1.c, line 14.
(gdb) run
Starting program: /home1/ugrads/q3d5k/Cs2263/Labs/Lab2/p1 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib64/libthread_db.so.1".

Breakpoint 2, g2 (a=4, b=34) at p1.c:14
14          int c = g1(a + 3, b - 11);
Missing separate debuginfos, use: dnf debuginfo-install glibc-2.34-60.el9_2.7.x86_64
(gdb) bt
#0  g2 (a=4, b=34) at p1.c:14
#1  0x000000000040121c in main (argc=1, argv=0x7fffffffdd48) at p1.c:24
(gdb) b g1
Note: breakpoint 1 also set at pc 0x401134.
Breakpoint 3 at 0x401134: file p1.c, line 6.
(gdb) cont
Continuing.

Breakpoint 1, g1 (a=7, b=23) at p1.c:6
6           int c = (a + b) * b;
(gdb) bt
#0  g1 (a=7, b=23) at p1.c:6
#1  0x00000000004011a5 in g2 (a=4, b=34) at p1.c:14
#2  0x000000000040121c in main (argc=1, argv=0x7fffffffdd48) at p1.c:24
(gdb) info frame g1
No frame at level g1.
(gdb) info frame g2
No frame at level g2.
(gdb) info frame 1
Stack frame at 0x7fffffffdc10:
 rip = 0x4011a5 in g2 (p1.c:14); saved rip = 0x40121c
 called by frame at 0x7fffffffdc40, caller of frame at 0x7fffffffdbe0
 source language c.
 Arglist at 0x7fffffffdc00, args: a=4, b=34
 Locals at 0x7fffffffdc00, Previous frame's sp is 0x7fffffffdc10
 Saved registers:
  rbp at 0x7fffffffdc00, rip at 0x7fffffffdc08
(gdb) info frame 0
Stack frame at 0x7fffffffdbe0:
 rip = 0x401134 in g1 (p1.c:6); saved rip = 0x4011a5
 called by frame at 0x7fffffffdc10
 source language c.
 Arglist at 0x7fffffffdbd0, args: a=7, b=23
 Locals at 0x7fffffffdbd0, Previous frame's sp is 0x7fffffffdbe0
 Saved registers:
  rbp at 0x7fffffffdbd0, rip at 0x7fffffffdbd8
(gdb) info frame 1
Stack frame at 0x7fffffffdc10:
 rip = 0x4011a5 in g2 (p1.c:14); saved rip = 0x40121c
 called by frame at 0x7fffffffdc40, caller of frame at 0x7fffffffdbe0
 source language c.
 Arglist at 0x7fffffffdc00, args: a=4, b=34
 Locals at 0x7fffffffdc00, Previous frame's sp is 0x7fffffffdc10
 Saved registers:
  rbp at 0x7fffffffdc00, rip at 0x7fffffffdc08
(gdb) info frame 2
Stack frame at 0x7fffffffdc40:
 rip = 0x40121c in main (p1.c:24); saved rip = 0x7ffff7c3feb0
 caller of frame at 0x7fffffffdc10
 source language c.
 Arglist at 0x7fffffffdc30, args: argc=1, argv=0x7fffffffdd48
 Locals at 0x7fffffffdc30, Previous frame's sp is 0x7fffffffdc40
 Saved registers:
  rbp at 0x7fffffffdc30, rip at 0x7fffffffdc38
(gdb) clear
Deleted breakpoints 1 3 
(gdb) clear
No breakpoint at this line.
(gdb) clear
No breakpoint at this line.
(gdb) clear
No breakpoint at this line.
(gdb) clear
No breakpoint at this line.
(gdb) clear
No breakpoint at this line.
(gdb) 
No breakpoint at this line.
(gdb) quit
A debugging session is active.

        Inferior 1 [process 445696] will be killed.

Quit anyway? (y or n) y
[q3d5k@gc112m37 Lab2]$ gcc -g -Wall -Wshadow p1.c -o p1
[q3d5k@gc112m37 Lab2]$ gcc -g -Wall -Wshadow p1.c -o p1
[q3d5k@gc112m37 Lab2]$ gdb ./p1
GNU gdb (GDB) Rocky Linux 10.2-10.el9.0.1
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./p1...
(gdb) b g1
Breakpoint 1 at 0x401134: file p1.c, line 6.
(gdb) b g2
Breakpoint 2 at 0x401190: file p1.c, line 14.
(gdb) cont
The program is not being run.
(gdb) run
Starting program: /home1/ugrads/q3d5k/Cs2263/Labs/Lab2/p1 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib64/libthread_db.so.1".

Breakpoint 2, g2 (a=4, b=34) at p1.c:14
14          int c = g1(a + 3, b - 11);
Missing separate debuginfos, use: dnf debuginfo-install glibc-2.34-60.el9_2.7.x86_64
(gdb) info frame
Stack level 0, frame at 0x7fffffffdc10:
 rip = 0x401190 in g2 (p1.c:14); saved rip = 0x40121c
 called by frame at 0x7fffffffdc40
 source language c.
 Arglist at 0x7fffffffdc00, args: a=4, b=34
 Locals at 0x7fffffffdc00, Previous frame's sp is 0x7fffffffdc10
 Saved registers:
  rbp at 0x7fffffffdc00, rip at 0x7fffffffdc08
(gdb) Quit
(gdb) quit
A debugging session is active.

        Inferior 1 [process 447563] will be killed.

Quit anyway? (y or n) y
[q3d5k@gc112m37 Lab2]$ gcc -g -Wall -Wshadow p1.c -o p1
[q3d5k@gc112m37 Lab2]$ gdb ./p1
GNU gdb (GDB) Rocky Linux 10.2-10.el9.0.1
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./p1...
(gdb) list
8           printf("g1:\naddress of a = %p\naddress of b = %p\naddress of c = %p\n", &a, &b, &c);
9           return c;
10      }
11
12      int g2(int a, int b)
13      {
14          int c = g1(a + 3, b - 11);
15          printf("g2:\na = %d\nb = %d\nc = %d\n", a, b, c);
16          printf("g2:\naddress of a = %p\naddress of b = %p\naddress of c = %p\n",&a,&b,&c);
17          return c - b;
(gdb) list
18      }
19
20      int main(int argc, char * * argv)
21      {
22          int a = 5;
23          int b = 17;
24          int c = g2(a - 1, b * 2);
25          printf("main:\na = %d\nb = %d\nc = %d\n", a, b, c);
26          printf("main:\naddress of a = %p\naddress of b = %p\naddress of c = %p\n", &a,&b,&c);
27          return EXIT_SUCCESS;
(gdb) b7
Undefined command: "b7".  Try "help".
(gdb) b 7
Breakpoint 1 at 0x401145: file p1.c, line 7.
(gdb) b 15
Breakpoint 2 at 0x4011a8: file p1.c, line 15.
(gdb) b 25
Breakpoint 3 at 0x40121f: file p1.c, line 25.
(gdb) run
Starting program: /home1/ugrads/q3d5k/Cs2263/Labs/Lab2/p1 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib64/libthread_db.so.1".

Breakpoint 1, g1 (a=7, b=23) at p1.c:7
7           printf("g1:\na = %d\nb = %d\nc = %d\n", a, b, c);
Missing separate debuginfos, use: dnf debuginfo-install glibc-2.34-60.el9_2.7.x86_64
(gdb) info args
a = 7
b = 23
(gdb) info locals
c = 690
(gdb) print (&a)
$1 = (int *) 0x7fffffffdbbc
(gdb) print (&b)
$2 = (int *) 0x7fffffffdbb8
(gdb) Quit
(gdb) print (&b)
$3 = (int *) 0x7fffffffdbb8
(gdb) print (&c)
$4 = (int *) 0x7fffffffdbcc
(gdb) cont
Continuing.
g1:
a = 7
b = 23
c = 690
g1:
address of a = 0x7fffffffdbbc
address of b = 0x7fffffffdbb8
address of c = 0x7fffffffdbcc

Breakpoint 2, g2 (a=4, b=34) at p1.c:15
15          printf("g2:\na = %d\nb = %d\nc = %d\n", a, b, c);
(gdb) cont
Continuing.
g2:
a = 4
b = 34
c = 690
g2:
address of a = 0x7fffffffdbec
address of b = 0x7fffffffdbe8
address of c = 0x7fffffffdbfc

Breakpoint 3, main (argc=1, argv=0x7fffffffdd48) at p1.c:25
25          printf("main:\na = %d\nb = %d\nc = %d\n", a, b, c);
(gdb) cont
Continuing.
main:
a = 5
b = 17
c = 656
main:
address of a = 0x7fffffffdc2c
address of b = 0x7fffffffdc28
address of c = 0x7fffffffdc24
[Inferior 1 (process 450299) exited normally]
(gdb) info frame 0
No registers.
(gdb) run
Starting program: /home1/ugrads/q3d5k/Cs2263/Labs/Lab2/p1 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib64/libthread_db.so.1".

Breakpoint 1, g1 (a=7, b=23) at p1.c:7
7           printf("g1:\na = %d\nb = %d\nc = %d\n", a, b, c);
(gdb) info frame 0
Stack frame at 0x7fffffffdbe0:
 rip = 0x401145 in g1 (p1.c:7); saved rip = 0x4011a5
 called by frame at 0x7fffffffdc10
 source language c.
 Arglist at 0x7fffffffdbd0, args: a=7, b=23
 Locals at 0x7fffffffdbd0, Previous frame's sp is 0x7fffffffdbe0
 Saved registers:
  rbp at 0x7fffffffdbd0, rip at 0x7fffffffdbd8
(gdb) info frame 1
Stack frame at 0x7fffffffdc10:
 rip = 0x4011a5 in g2 (p1.c:14); saved rip = 0x40121c
 called by frame at 0x7fffffffdc40, caller of frame at 0x7fffffffdbe0
 source language c.
 Arglist at 0x7fffffffdc00, args: a=4, b=34
 Locals at 0x7fffffffdc00, Previous frame's sp is 0x7fffffffdc10
 Saved registers:
  rbp at 0x7fffffffdc00, rip at 0x7fffffffdc08
(gdb) info frame 2
Stack frame at 0x7fffffffdc40:
 rip = 0x40121c in main (p1.c:24); saved rip = 0x7ffff7c3feb0
 caller of frame at 0x7fffffffdc10
 source language c.
 Arglist at 0x7fffffffdc30, args: argc=1, argv=0x7fffffffdd48
 Locals at 0x7fffffffdc30, Previous frame's sp is 0x7fffffffdc40
 Saved registers:
  rbp at 0x7fffffffdc30, rip at 0x7fffffffdc38
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home1/ugrads/q3d5k/Cs2263/Labs/Lab2/p1 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib64/libthread_db.so.1".

Breakpoint 1, g1 (a=7, b=23) at p1.c:7
7           printf("g1:\na = %d\nb = %d\nc = %d\n", a, b, c);
(gdb) bt
#0  g1 (a=7, b=23) at p1.c:7
#1  0x00000000004011a5 in g2 (a=4, b=34) at p1.c:14
#2  0x000000000040121c in main (argc=1, argv=0x7fffffffdd48) at p1.c:24
(gdb) select-frame 0
(gdb) info frame
Stack level 0, frame at 0x7fffffffdbe0:
 rip = 0x401145 in g1 (p1.c:7); saved rip = 0x4011a5
 called by frame at 0x7fffffffdc10
 source language c.
 Arglist at 0x7fffffffdbd0, args: a=7, b=23
 Locals at 0x7fffffffdbd0, Previous frame's sp is 0x7fffffffdbe0
 Saved registers:
  rbp at 0x7fffffffdbd0, rip at 0x7fffffffdbd8
(gdb) select-frame 1
(gdb) info frame
Stack level 1, frame at 0x7fffffffdc10:
 rip = 0x4011a5 in g2 (p1.c:14); saved rip = 0x40121c
 called by frame at 0x7fffffffdc40, caller of frame at 0x7fffffffdbe0
 source language c.
 Arglist at 0x7fffffffdc00, args: a=4, b=34
 Locals at 0x7fffffffdc00, Previous frame's sp is 0x7fffffffdc10
 Saved registers:
  rbp at 0x7fffffffdc00, rip at 0x7fffffffdc08
(gdb) select-frame 2
(gdb) info frame
Stack level 2, frame at 0x7fffffffdc40:
 rip = 0x40121c in main (p1.c:24); saved rip = 0x7ffff7c3feb0
 caller of frame at 0x7fffffffdc10
 source language c.
 Arglist at 0x7fffffffdc30, args: argc=1, argv=0x7fffffffdd48
 Locals at 0x7fffffffdc30, Previous frame's sp is 0x7fffffffdc40
 Saved registers:
  rbp at 0x7fffffffdc30, rip at 0x7fffffffdc38
(gdb) cd "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/" && gcc calcTrib.c -o calcTrib && "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/"calcTrib
"/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/" && gcc calcTrib.c -o calcTrib && "/home1/ugrads/q3d5k/Cs2263/Labs/Lab2/"calcTrib: No such file or directory.