#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct{
 	char dname[10], fname[10][10];
 	int fcnt;
}dir;

int main() {

	 int i, choice;
	 char files[30];
	 dir.fcnt = 0;
   printf("Single Level Directory File Organization.\n\n")
	 printf("Enter name of directory: ");
	 scanf("%s", dir.dname);
	 while (1) {
		 printf("\n1. Create File\t2. Delete File\t3. Search File \t4. Display Files\n5. Exit\n\nEnter your choice: ");
		 scanf("%d", &choice);
		 switch (choice) {
			 case 1:
				 printf("\nEnter the name of the file: ");
				 scanf("%s", dir.fname[dir.fcnt]);
				 dir.fcnt++;
				 break;
			 case 2:
				 printf("\nEnter the name of the file: ");
				 scanf("%s", files);
				 for (i = 0; i < dir.fcnt; i++) {
				 	if (strcmp(files, dir.fname[i]) == 0) { 
				 		printf("File %s is deleted\n", files);
				 		strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
				 		break;
				 	}
				 }
				 if (i == dir.fcnt)
					printf("File %s not found\n", files);
				else
				 	dir.fcnt--;
				 break;
			case 3:
				 printf("\nEnter the name of the file: ");
				 scanf("%s", files);
				 for (i = 0; i < dir.fcnt;i++)
				 {
				  	if (strcmp(files, dir.fname[i]) == 0)
				  	{
						printf("File %s is found\n", files);
						break;
				   	}
				 }
				 if (i == dir.fcnt)
				 	printf("File %s not found\n", files);
				break;

			 case 4:
				 if (dir.fcnt == 0)
				 	printf("\nDirectory Empty");

				 else {
				 	printf("\nThe Files are:");
				 	for (i=0; i < dir.fcnt; i++)
						printf("\t%s", dir.fname[i]);
					printf("\n");
				 }
				 break;

			 default:
			 	exit(0);
		 }
	 }
   return 0;
}
