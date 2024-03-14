#include <stdio.h>

#include <stdlib.h>

 
void dummy_frame()
{
  return;
}

int main(int argc, char * * argv)
{

  int i;
  int a[] = {1,2,3,4,5};
  for (i=0; i<5; i++){
    printf("main: a = %d %p \n", a[i], &a[i]);
  }
  dummy_frame();
  return EXIT_SUCCESS;
}