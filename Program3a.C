#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
  int files[50], i, j, start, len, more, k;
  printf("Sequential File Allocation Simulation.\n\n");
  for(i = 0; i < 50; i++)
  { files[i] = 0;  }
  printf("Files allocated are: \n");
  X:

  printf("Enter starting block and length of file: ");
  scanf("%d %d", &start, &len);

  for(j = start; j < (start + len); j++)
  { if(files[j] == 0)
    {
      files[j] = 1;
      printf("%d\t%d\n", j, files[j]);
    }
    else
    {
      printf("Block already allocated.\n");
      break; 
    }
  }

  if(j == (start + len))
  {  printf("The file is allocated to disk.\n");  }
  printf("Enter 1 if more files needed, 0 if not: ");
  scanf("%d", &more);
  if(more == 1)
    goto X;
  else
    exit(0);

  getch();
  return 0;

}
