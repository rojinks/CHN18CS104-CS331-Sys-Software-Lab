#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
  int files[50], prealloc, i, j, k, allocated, start, len, n, more;
  printf("Linked File Allocation Simulation.\n\n");
  for(i=0;i<50;i++)
    files[i]=0;
  printf("Enter how many blocks that are already allocated: ");
  scanf("%d",&prealloc);
  printf("Enter the blocks numbers that are already allocated: ");
  for(i = 0; i < prealloc; i++)
  {
    scanf("%d", &allocated);
    files[allocated] = 1;
  }

  X:
  printf("Enter the starting index block and length: ");
  scanf("%d %d", &start, &len);
  k = len;

  for(j = start; j < (k + start); j++)
  {
    if(files[j] == 0)
    {
      files[j] = 1;
      printf("%d -> %d\n", j, files[j]);
    }
    else
    {
      printf(" %d -> File is already allocated.\n", j);
      k++;
    }
  }

  printf("Enter 1 if more files needed, 0 if not: ");
  scanf("%d", &more);
  if(more == 1)
    goto X;
  else
    exit(0);

  getch();
  return 0;

}
