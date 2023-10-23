#include <stdio.h>
int main(int argc, char *argv[])
{
   FILE *fp1, *fp2, *fp3;
   int c;
   if (argc < 4){ 
      fp1 = stdin;
      fp2 = stdin;
      fp3 = stdin;
   } 
   else{  fp1 = fopen(argv[1],"r");
	 fp2 = fopen(argv[2],"r");
	 fp3 = fopen(argv[3],"r");
   }
   c = getc(fp1); 	
   while (c != EOF) { 	
      putc(c, stdout); 	 
      c = getc(fp1); 
   }
   c= getc(fp2);
   while (c != EOF){
	   putc(c, stdout);
	   c= getc(fp2);
   }
   c= getc(fp3);
   while(c!= EOF){
	   putc(c, stdout);
	   c= getc(fp3);
   }
   fclose(fp1);
   fclose(fp2);
   fclose(fp3); 
   return 0;
}
