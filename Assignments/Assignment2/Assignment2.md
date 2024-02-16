
# CS2263 Assignment 3

**Student:**  
Name: Will Ross  
Number: #3734692  
Email: [will.ross@unb.ca](mailto:will.ross@unb.ca)

**Date:** February 16th, 2024  
**Due Date:** February 21st, 2024

<div style="page-break-after: always;"></div>

## Contents

- [CS2263 Assignment 3](#cs2263-assignment-3)
  - [Contents](#contents)
  - [Question 1](#question-1)
    - [Answer Q1](#answer-q1)
  - [Question 2](#question-2)
    - [Source code Htag](#source-code-htag)
  - [Question 3](#question-3)
    - [Answer Q3](#answer-q3)
  - [Question 4](#question-4)
    - [Source code Htext1](#source-code-htext1)
  - [Question 5](#question-5)
    - [Input](#input)
    - [Htext1.c output](#htext1c-output)
    - [Htag1.c output](#htag1c-output)
  - [Question 6](#question-6)
    - [Htext1.c D2L output](#htext1c-d2l-output)
    - [Htags.c D2L Output](#htagsc-d2l-output)
  - [Question 7](#question-7)
    - [Htext1.c Output](#htext1c-output-1)
    - [Htag.c Output](#htagc-output)

<div style="page-break-after: always;"></div>

## Question 1

In a few sentences describe the design of the htags1 program. Focus on the description of the algorithm used and of any data structures needed to complete the task.

### Answer Q1

For my Htag program we will iterate threw the input given by a file, it will then check if the input is a `<` if its true it will then check for `!` if thats true that means we are in a a html comment.Doing this we get the current characters and then next char due to whitespace and invisble characters if its true we set inComment to `true`, if not we print a open tag `<` followed by the two chars we checked for. Once we enter the while loop for reading inside a tag we check if we are in a comment we don't use putchar(). After we leave the while loop we check if we in a comment if not we will print the closing tag `>` followed by a new line character `\n`.

<div style="page-break-after: always;"></div>

## Question 2

Show the complete source code for htags1.

### Source code Htag

```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void printArr(char a[], int n){

    for(int i = 0; i < (n-1); i++){

        putchar(a[i]);
    } 

    putchar('\n');
}
void readTags()
{

    int currChar;
    int first = '<';
    int second = '>';
    int newline = '\n';
    bool inComment = false;
    int check;

    while((currChar = getchar()) != EOF)
    {
        inComment = false;
        if(currChar == '<')
        {
            
            check = getchar();
            check = getchar();
            if(check == '!')
            {
                
                inComment = true;
            }
            else
            {
                putchar(first);
                putchar(check);
                
            }

            while((currChar = getchar()) != '>' && currChar != EOF){
                if(!inComment)
                {
                    putchar(currChar);
                    continue;
                }
            }
            if(!inComment)
            {
                putchar(second);
                putchar(newline);
            }
            
 
        }
    }

}
int main() 
{

    char start[] = "Start of output:";
    char end[] = "End of output:";

    printArr(start, strlen(start));
    readTags();
    printArr(end, strlen(end));
    
    return 0;
}


```

<div style="page-break-after: always;"></div>

## Question 3

In a few sentences describe the design of the htext1 program. Focus on the description of the algorithm used and of any data structures needed to complete the task.

### Answer Q3

For my Htext1 program we will iterate threw the input given by a file, it will then check if the input is a `>` if its true it will then we enter the while loop for plain text outside the html tags. We check if the currChar doesnt equal a starting tag `<`. After we leave the while loop we  will print a new space character `_`.

<div style="page-break-after: always;"></div>

## Question 4

Show the complete source code for htext1.

### Source code Htext1

```c
#include <stdio.h>
#include <string.h>

void printArr(char a[], int n)
{
    //just a for loop to go through char array
    for(int i = 0; i < (n-1); i++)
    {

        putchar(a[i]);
    } 

    //new line after complete
    putchar('\n');
}

void readText()
{
    int currChar;
    int index = 0;
    int space = ' ';

    while((currChar = getchar()) != EOF)
    {
        if(currChar == '>')
        {
            while((currChar = getchar()) != '<' && currChar != EOF)
            {
                putchar(currChar);
            }
            putchar(space);
        }
    }
}
int main() 
{
    char start[] = "Start of output:";
    char end[] = "End of output:";

    printArr(start, strlen(start));
    readText();
    printArr(end, strlen(end));

    return 0;
}

```

<div style="page-break-after: always;"></div>

## Question 5

Show the output from running htags1 and htext1 programs on the following input HTML code (store it in a file and use input redirection to read):

### Input

`<html> <b> TEST </b> </html>`

### Htext1.c output

```c
Start of output
 TEST 
```

### Htag1.c output

```html
Start of output:
<html>
<b>
</b>
</html>
End of output:

```

<div style="page-break-after: always;"></div>

## Question 6

Show the output from running htags1 and htext1 program on this HTML file, i.e. the very file describing this assignment: you need to download this file separately from D2L to your computer (do not download the entire D2L web page!). The file name is A2W2024.html.

### Htext1.c D2L output

```txt
Start of output


   CS 2263   

   Assignment 2   

   Due: Feb. 21, 2024 (before midnight)    

  _______________________________________________________  

   Assignments
are to be completed individually ( not  as a group work).   

  &nbsp;  

  Sample
reference:   https://www.educba.com/types-of-tags-in-html/  
  

  &nbsp;  

   Processing strings   

  Develop and test two
utility programs called  htags1  and  htext1  to process an HTML file. The   htags1   program should &nbsp;print all
HTML tags,  except  the HTML comment tags &lt;!-- --&gt;, one per line of
output. The   htext1   program should print
all plain text extracted from the source HTML file, i.e. just the text, no
tags. The utility programs should read form standard input and may use the  input redirection  to access
a file. (This means that your program code should read from standard input, and
NOT perform any file operations, like fopen() etc. You may capture the output
from your program using output redirection, or you may just output to the
terminal window and print the screen, your choice.)  

  Assume an
HTML tag is any text enclosed between &lt; and &gt;, including these delimiter
characters. The end tags, like &lt;/p&gt;, are valid tags. For example, in a
sample input HTML file containing:  

   
&lt;body lang=EN-CA link=blue vlink=&quot;#954F72&quot;&gt; 
&lt;div class=WordSection1&gt; 
&lt;p class=MsoNormal&gt;&lt;b&gt;&lt;span lang=EN-US
style='font-size:14.0pt;font-family: &quot;Times New Roman&quot;,serif'&gt;CS
2263&lt;/span&gt;&lt;/b&gt;&lt;/p&gt; 
&lt;p class=MsoNormal&gt;&lt;b&gt;&lt;span lang=EN-US
style='font-size:14.0pt;font-family: &quot;Times New
Roman&quot;,serif'&gt;Assignment 2&lt;/span&gt;&lt;/b&gt;&lt;/p&gt;  

   
we find the following tags:  
 
&lt;body lang=EN-CA link=blue vlink=&quot;#954F72&quot;&gt; 
&lt;div class=WordSection1&gt; 
&lt;p class=MsoNormal&gt; 
&lt;b&gt; 
&lt;span lang=EN-US style='font-size:14.0pt;font-family: &quot;Times New
Roman&quot;,serif'&gt;  
&lt;/span&gt; 
&lt;/b&gt; 
&lt;/p&gt; 
&lt;p class=MsoNormal&gt; 
&lt;b&gt; 
&lt;span lang=EN-US style='font-size:14.0pt;font-family: &quot;Times New
Roman&quot;,serif'&gt;  
&lt;/span&gt; 
&lt;/b&gt; 
&lt;/p&gt;  
 
and the plain text in this sample input is:  
 
CS 2263 Assignment 2  

   
When outputting the plain text you may keep new line characters present in the
input, or you may replace them with space characters.  
 
The data to your program should be read from standard input (use the input
redirection to read from the HTML file) using the    getchar()    function. The output should be
done using the    putchar()    function and/or using
the    printArr()    function from Assignment
1. You must use the   printArr()   function at least once in
each utility program developed for this assignment. The Assignment Report
should consist of the following parts/exercises:  

  1.  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  In a few
sentences describe the design of the htags1 program. Focus on the description of
the algorithm used and of any data structures needed to complete the task.  

  1.  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  Show the  complete 
source code for htags1.  

  1.  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  In a few
sentences describe the design of the htext1 program. Focus on the description of
the algorithm used and of any data structures needed to complete the task.   

  1.  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  Show the  complete 
source code for htext1.  

  1.  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  Show the output from
running htags1 and htext1 programs on the following input HTML code (store it
in a file and use input redirection to read):  
 
&lt;html&gt; &lt;b&gt; TEST &lt;/b&gt; &lt;/html&gt;  

  6.  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  Show the output from
running htags1 and htext1 program on this HTML file, i.e. the very file
describing this assignment: you need to download this file separately from D2L
to your computer  
(do not download the entire D2L web page!). The file name is A2W2024.html.&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;  

  7.  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  Show the output from
running htags1 and htext1 program on another HTML file, of your choice.  &nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;  

  &nbsp;  

  Submit a
SINGLE PDF FILE with your Assignment Report and it should include: a heading
for each exercise 1 to 7, including the source code of each completed program
and the screenshots of the terminal window (or the contents of the file with the
redirected program output) showing the test runs. In case of multiple
submission the most recent item in your Dropbox will be graded.  

  &nbsp;  

```

### Htags.c D2L Output

```txt
Start of output:
<html>
<head>
<meta http-equiv=Content-Type content="text/html; charset=unicode">
<meta name=Generator content="Microsoft Word 15 (filtered)">
<style>
</style>
</head>
<body lang=EN-CA link=blue vlink=purple style='word-wrap:break-word'>
<div class=WordSection1>
<p class=MsoNormal>
<b>
<span lang=EN-US style='font-size:14.0pt;font-family:
"Times New Roman",serif'>
</span>
</b>
</p>
<p class=MsoNormal>
<b>
<span lang=EN-US style='font-size:14.0pt;font-family:
"Times New Roman",serif'>
</span>
</b>
</p>
<p class=MsoNormal>
<b>
<span lang=EN-US style='font-size:14.0pt;font-family:
"Times New Roman",serif'>
</span>
</b>
</p>
<p class=MsoNormal style='text-align:justify'>
<span lang=EN-US
style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoNormal>
<u>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
<b>
</b>
</span>
</u>
</p>
<p class=MsoNormal>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoNormal>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
<a href="https://www.educba.com/types-of-tags-in-html/">
<span
style='text-decoration:none'>
</span>
</a>
</span>
</p>
<p class=MsoNormal>
<span style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:0cm;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<i>
<span
style='font-family:"Times New Roman",serif'>
</span>
</i>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
<span
lang=EN-US style='font-family:"Courier New"'>
</span>
<span lang=EN-US
style='font-family:"Times New Roman",serif'>
<b>
</b>
</span>
<span lang=EN-US style='font-family:"Courier New"'>
</span>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
<a
href="https://linuxcommand.org/lc3_lts0070.php">
</a>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:18.0pt;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:25.1pt;margin-bottom:.0001pt;text-indent:18.0pt;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
<br>
<br>
<br>
<br>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:25.1pt;margin-bottom:.0001pt;text-indent:18.0pt;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
<br>
<br>
<br>
</span>
<b>
<span lang=EN-US
style='font-family:"Courier New"'>
</span>
</b>
<span lang=EN-US
style='font-family:"Times New Roman",serif'>
</span>
<b>
<span lang=EN-US style='font-family:"Courier New"'>
</span>
</b>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
<b>
<span lang=EN-US style='font-family:"Courier New"'>
</span>
</b>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
<span lang=EN-US style='font-family:"Courier New"'>
</span>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
<span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
<span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<span style='font-family:"Times New Roman",serif'>
<u>
</u>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
<span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
<span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<span style='font-family:"Times New Roman",serif'>
<u>
</u>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
12.0pt;margin-left:43.1pt;text-indent:-18.0pt;line-height:12.0pt'>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
<span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<span style='font-family:"Times New Roman",serif'>
<br>
<br>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
<span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<span style='font-family:"Times New Roman",serif'>
</span>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
<span
lang=EN-US style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<span style='font-family:"Times New Roman",serif'>
</span>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;text-indent:0cm;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;text-indent:0cm;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoNormal>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
</div>
</body>
</html>
End of output:

```

<div style="page-break-after: always;"></div>

## Question 7

Show the output from running htags1 and htext1 program on another HTML file, of your choice.
For the last test I used this websites source code [Assignment 1 Report](https://lms.unb.ca/d2l/le/content/236332/viewContent/2705057/View)

### Htext1.c Output

```txt
Start of output
   CS 2263   

   Assignment 1   

   Due: January 29, 2024 (before midnight)    

  _______________________________________________________  

  &nbsp; Assignments are
to be completed individually ( not  as a group work).   

   
   getchar(),
putchar(), functions   

  On this assignment you are asked to
use the character input/output operations ( getchar(), putchar())  rather
than formatted input output (please do not use  scanf, printf ).  

  &nbsp;  

 1. &nbsp;&nbsp;&nbsp;&nbsp;
 Exercise 1 ( display a prompt using putchar() ) 
Write a function that accepts a character array of length n and prints all n
characters form this array one character at a time using putchar() to the
console. Then use this function in a program that prints the Hello World
message.  
 
 void printArr(char a[], int n)  

 2. &nbsp;&nbsp;&nbsp;&nbsp;
 Exercise 2 ( print an   int 
&nbsp; with all digits reversed   using putchar()  ) 
Write a function that accepts an unsigned integer and prints this value one
character at a time, and  in the reversed order , to the console. Then use
this function in a program to print an integer value 2263 in the reversed order
as 3622. 
 
 void printReversed(int n)   &nbsp;&nbsp;   

 &nbsp; 

 3. &nbsp;&nbsp;&nbsp;&nbsp;
 Exercise 3 ( convert char digits into int  ) 
Write a function that accepts a character array representing digits of an
unsigned integer with its digits stored in the reversed order and returns the
integer value represented by these characters. For example, the function  convertInt  when called on the array  char a[]={'3','2','1'}  would return
integer value   123  .
Parameter  n  holds the number of
digits stored in the array.  
 
 int convertInt(char a[], int n)   &nbsp;&nbsp;&nbsp;   

 &nbsp; 

 4. &nbsp;&nbsp;&nbsp;&nbsp;
 Exercise 4 ( add two numbers represented as reversed strings ) 
Write a function that accepts two character arrays representing digits of two unsigned
integer with their digits stored in the reversed order, and returns the integer
value representing the sum of these two integers. For example, the function  addReversedInt  when called on the
array  char a[]={'3','2','1'}   and   char b[]={'6','5','4'}  would return integer value   579  . Parameters  n  and  m 
hold the number of digits stored in arrays  a[] 
and  b[]  respectively. Use the
function form Exercise 3 to performs string to integer conversions. 
 
 int addReversedInt(char a[], int n,
char b[], int m)   &nbsp;&nbsp;&nbsp;
  

 &nbsp; 

 5. &nbsp;&nbsp;&nbsp;&nbsp;
 Exercise 5 ( simple calculator working on integer numbers entered with
digits reversed ) 
Write a program that prompts the user for two unsigned integer numbers and
prints the sum of these two numbers. The numbers are to be entered with their
digits reversed and the result should be printed with the digits reversed as
well. So, for example, if the user wanted to add   twenty five   to   one
hundred twenty three  , they would enter 321 for the first number, 52 for
the second and get the result 841 representing 123+25=148. Use the functions
developed for exercises 1, 2, 3 and 4. You program should: 

 a. &nbsp;&nbsp;&nbsp;&nbsp;
 Display a prompt (use the function from Exercise 1), 

 b. &nbsp;&nbsp;&nbsp;&nbsp;
 Read characters form the console (one at a time, using  getchar() )
representing the two integers to be added (assume maximum of 10 digits for each
number, no spaces, each number on the input is terminated by the  \n 
character), and store them in two arrays, 

 c. &nbsp;&nbsp;&nbsp;&nbsp;
 Add the two numbers using the function developed for Exercise 4, 

 d. &nbsp;&nbsp;&nbsp;&nbsp;
 Print the result of adding the two numbers entered by the user, with the
digits printed in the reversed order (use the function from Exercise 2 for
printing). 

  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;  

  Reminder:
use only the  getchar(), putchar()  functions for input/output. Include
minimal comments in your programs (use Section 11.4 and the programming
examples in the textbook as a guide).   

  Submit a
SINGLE PDF FILE with your Assignment Report and it should include:  cover
page , headings for each exercise, the source code of each completed program
and the screenshots showing    couple test runs for
each exercise   . When testing functions in exercises 1, 2, 3 and 4
you may need to write a driver program.   

  &nbsp;   

```

### Htag.c Output

```html
Start of output:
<html>
<head>
<meta http-equiv=Content-Type content="text/html; charset=unicode">
<meta name=Generator content="Microsoft Word 15 (filtered)">
<style>
</style>
</head>
<body lang=EN-CA style='word-wrap:break-word'>
<div class=WordSection1>
<p class=MsoNormal>
<b>
<span lang=EN-US style='font-size:14.0pt;font-family:
"Times New Roman",serif'>
</span>
</b>
</p>
<p class=MsoNormal>
<b>
<span lang=EN-US style='font-size:14.0pt;font-family:
"Times New Roman",serif'>
</span>
</b>
</p>
<p class=MsoNormal>
<b>
<span lang=EN-US style='font-size:14.0pt;font-family:
"Times New Roman",serif'>
</span>
</b>
</p>
<p class=MsoNormal style='text-align:justify'>
<span lang=EN-US
style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:0cm;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
<u>
<b>
</b>
</u>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
<br>
</span>
<i>
<span style='font-family:"Times New Roman",serif'>
</span>
</i>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<span
style='font-family:"Times New Roman",serif'>
<i>
</i>
<i>
</i>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:7.1pt;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<span
style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
12.0pt;margin-left:43.1pt;text-indent:-18.0pt;line-height:12.0pt'>
<span
style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<i>
</i>
<br>
<br>
<br>
<span style='font-family:"Courier New"'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<i>
</i>
<span style='font-family:"Courier New"'>
</span>
<i>
</i>
<i>
</i>
<br>
<u>
</u>
<br>
<br>
<span style='font-family:"Courier New"'>
</span>
<span
style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<i>
</i>
<br>
<span
style='font-family:"Courier New"'>
</span>
<span
style='font-family:"Courier New"'>
</span>
<strong>
<span style='font-family:Times'>
</span>
</strong>
<span style='font-family:"Courier New"'>
</span>
<br>
<br>
<span style='font-family:"Courier New"'>
</span>
<span
style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
12.0pt;margin-left:43.1pt;text-indent:-18.0pt;line-height:12.0pt'>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<i>
</i>
<br>
<span
style='font-family:"Courier New"'>
</span>
<span style='font-family:"Courier New"'>
</span>
<span
style='font-family:"Times New Roman",serif'>
</span>
<span style='font-family:
"Courier New"'>
</span>
<strong>
<span
style='font-family:Times'>
</span>
</strong>
<span
style='font-family:"Courier New"'>
</span>
<span style='font-family:"Courier New"'>
</span>
<span style='font-family:"Courier New"'>
</span>
<span style='font-family:"Courier New"'>
</span>
<br>
<br>
<span style='font-family:"Courier New"'>
</span>
<span style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
12.0pt;margin-left:43.1pt;text-indent:-18.0pt;line-height:12.0pt'>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:43.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<i>
</i>
<br>
<i>
<u>
</u>
</i>
<i>
<u>
</u>
</i>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:79.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:79.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
<i>
</i>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:79.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:79.1pt;margin-bottom:.0001pt;text-indent:-18.0pt;line-height:
12.0pt'>
<span style='font-size:7.0pt;font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;margin-right:0cm;margin-bottom:
0cm;margin-left:0cm;margin-bottom:.0001pt;text-indent:0cm;line-height:12.0pt'>
<span
lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;text-indent:0cm;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
<i>
</i>
</span>
</p>
<p class=MsoBodyTextIndent style='margin-top:6.0pt;text-indent:0cm;line-height:
12.0pt'>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
<b>
<u>
<span style='color:red'>
</span>
</u>
</b>
</span>
</p>
<p class=MsoNormal>
<span lang=EN-US style='font-family:"Times New Roman",serif'>
</span>
</p>
</div>
</body>
</html>
End of output:
```
