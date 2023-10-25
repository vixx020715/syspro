#include <stdio.h>
  #include <stdlib.h>
#include "book.h"

 int main(int argc, char* argv[]){
     struct book rec;
 FILE *fp;

  if (argc != 2) {
  fprintf(stderr, "How to use: %s FileName\n", argv[0]);
  return 1;
  }
  if ((fp=fopen(argv[1],"rb"))==NULL) {
          fprintf(stderr,"Error Open File\n");
         return 2;
         }
 fp = fopen(argv[1], "r");
 printf("%-2s %-7s %-7s %-4s %-4s %-4s \n","ID", "BOOKNAME", "AUTHOR", "YEAR", "NUMOFBORROW", "BORROW");
 printf("%3d %8s %8s %5d %5d %5s\n", rec.id, rec.name, rec.writer, rec.date, rec.time, rec.tf);
fclose(fp);
 return 0;
  }
