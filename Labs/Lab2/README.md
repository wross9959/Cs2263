exercise 2
gcc -g -Wall -Wshadow p1.c -o p1

ddd ./p1



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