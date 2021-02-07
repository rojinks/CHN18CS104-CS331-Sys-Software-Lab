#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int files[50],i,k,j,ind[50],num,more,indb;
int main()
{
  printf("Indexed File Allocation Simulation.\n\n");
  for(i = 0; i < 50; i++)
    files[i] = 0;
  X:
  printf("Enter index block: ");
  scanf("%d",&indb);
  if(files[indb] == 0)
  {
    files[indb] = 1;
    printf("Enter number of files on index: ");
    scanf("%d",&num);
  }
  else
  {
    printf("Block already allocated.\n");
    goto X;
  }

  printf("Enter index numbers: ");
  for(i = 0; i < num; i++)
    scanf("%d", &ind[i]);
  for(i = 0; i < num; i++)
    if(files[ind[i]]==1)
    {
      printf("Block already allocated.\n");
      goto X; 
    }

  for(j = 0;  j < num;  j++)
  files[ind[j]] = 1;
  printf("Allocated.\n");
  printf("File indexed.\n");
  for(k = 0;  k <  num; k++)
    printf("%d -> %d : %d\n", indb, ind[k], files[ind[k]]);

  printf("Enter 1 to enter more files and 0 to exit: ");
  scanf("%d",&more);
  if(more == 1)
    goto X;
  else
    exit(0);

  getch();
  return 0;
}
