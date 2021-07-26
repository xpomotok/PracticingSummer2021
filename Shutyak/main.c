#include <stdio.h>
#include <stdlib.h>
#include <Z:\Practika\3\dm5.h>
#include <string.h>
#include <dirent.h>


char file_names[50][50] ;

void prochest (const char *holder_name)
{
    int i = 0;
DIR *dir;
struct dirent *ent;
if ((dir = opendir (holder_name)) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
    printf ("%s\n", ent->d_name);
    strcpy(file_names[i], ent->d_name);
    i++;
  }
  closedir (dir);

} else {
  /* could not open directory */
  perror ("");
  return 0;
}

}


int main()
{
    int a, i, j, f;
    char str1 [50];
   char str2 [33];
   char str3 [50];
   char str4 [33];
   char str5 [50];
   char files_hash1[50][33];
   char files_hash2[50][33];

   i = 2;

printf("Chto sravnivaen?\n");
printf ("1 - compare individual files\n");
printf ("2 - compare lines\n");
printf ("3 - comparison of two directories\n");
scanf ("%d",&a);


       switch( a )
        {
    case 1 :
        {
        printf ("Enter name of the original file:");
        scanf ("%s", str1);
        strcpy(str2, digestFile(str1));
        printf("%s\n", str2);
        printf ("Enter name of the verifiable file:");
        scanf ("%s", str3);
        strcpy(str4, digestFile(str3));
        printf("%s\n", str4);
        if (strcmp(str2, str4) == 0)
            printf("Files match!\n");
        else printf("Files do not match!\n");
        }
        break;
    case 2 :
        {
        printf ("Enter the line:");
        scanf ("%s", str1);
        strcpy(str2, digestString(str1));
        printf("%s\n", str2);
        printf ("Enter the line to compare to:");
        scanf ("%s", str3);
        strcpy(str4, digestString(str3));
        printf("%s\n", str4);
        if (strcmp(str2, str4) == 0)
            printf("Lines match!\n");
        else printf("Lines do not match!\n");
        }
        break;
    case 3 :
        {
        printf("Enter path to the holder:");
        scanf("%s", str1);
        prochest(str1);
        i=2;
        strcpy(str5, str1);
        while (strlen(file_names[i]) != 0)
        {
           strcat(str1, file_names[i]);
           strcpy(files_hash1[i-2], digestFile(str1));
           i++;
           strcpy(str1, str5);
        }
        printf("Enter path to the holder to compare to:");
        scanf("%s", str3);
        prochest(str3);
        i = 2;
        strcpy(str5, str3);
        while (strlen(file_names[i]) != 0)
        {
           strcat(str3, file_names[i]);
           strcpy(files_hash2[i-2], digestFile(str3));
           i++;
           strcpy(str3, str5);
        }
        i=0;
        j=0;
        f=0;
        while (strlen(files_hash1[i]) != 0)
        {
            while (strlen(files_hash2[j]) != 0)
            {
              if (strcmp(files_hash1[i], files_hash2[j]) == 0) f=1;
              j++;
            }
       if (f == 1) {i++; j=0; f=0;}
       else {printf("Holder do not match!"); f=1; break;}

        }
        if (f == 0) printf("Holder match!");
        }
        break;
    default :
        printf ("Error:Incorrect value!\n");
        }

//Z:\Practika\BPO1\1.txt
//Z:\Practika\BPO2\1.txt
//Z:\Practika\BPO3\
    return 0;
}

