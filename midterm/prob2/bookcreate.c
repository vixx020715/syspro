#include <stdio.h> 
#include <stdlib.h>
#include "book.h"
int main(int argc, char* argv[]) 
{ 
struct book rec;
FILE *fp;

if (argc != 2) {
fprintf(stderr, "How to use: %s FileName\n",argv[0]);
return 1; 
}
fp = fopen(argv[1], "wb");
printf("%-2s %-8s %-8s %-4s %-2s %-5s \n","ID", "BOOK NAME", "AUTHOR", "YEAR", "NUMOFBORROW", "BORROW" ); 
while (scanf("%d %s %s %d %d %s", &rec.id, rec.name, rec.writer, &rec.date, &rec.time, rec.tf) == 6)
fwrite(&rec, sizeof(rec), 1, fp);
fclose(fp);
return 0;
}
