#include <dirent.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <errno.h>

#define MAX_LINE_LENGTH 80

int main(void) {
  DIR *d;
  FILE *f;
  struct dirent *dir;
  char buf;
  int c;
  char *buffer;
  long length;
  char line[MAX_LINE_LENGTH] = {0};
  unsigned int line_count = 0;
  char cwd[255];
  char a=10;
  int i;
  char nev[255];
  int del;

  f=fopen("/storage/emulated/0/Documents/dir.txt","rb");
  if (f)
  {
  fseek (f, 0, SEEK_SET);
  while (fgets(line, MAX_LINE_LENGTH, f))
    {
        /* Print each line */
        printf("%s", line);
        for(i=0;line[i]!='\0';i++)
         {
//         printf("%i %c\n",line[i],line[i]);
         if(line[i]==10)
          {
          line[i] = 0;
         }
         if(line[i]==13)
          {
          line[i] = 0;
         }
        }
        chdir(line);
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
        } else {
         perror("getcwd() error");
         return 1;
        }
        printf("%s", line);
        d = opendir(line);
        if (d) {
        while ((dir = readdir(d)) != NULL) {
          strcpy(nev,dir->d_name);
          printf("%s\n", nev);
          int del = remove(nev);
         if (!del)
          printf("The file is Deleted successfully");
         else
          printf("the file is not Deleted");
        }
        closedir(d);
        }
        else
        {
         printf("Error failed to open input directory -%s\n",strerror(errno) );
        }
       
   }
 
  fclose (f);
  }
  return(0);
}

