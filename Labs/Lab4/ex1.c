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

  for (i=0; i< size; i++)
  {
    printf("a[%d] = %d at address: %p \n", i, a[i], &a[i]);
  }


  free(a);
  return EXIT_SUCCESS;
}