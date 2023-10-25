#include <stdio.h>
int main(int argc, char *argv[])
{
FILE *fp;
int a, c;
scanf("%d", &a);
if (argc<2)
	fp = stdin;
	else{
if( a =0){
fp = fopen(argv[1],"wb+");
}
if(a=1){
	fp = fopen(argv[1],"ab+");
}}
c=getc(fp);
while (c != EOF) {
putc(c, stdout);
c = getc(fp);
}
fclose(fp);
return 0;
}
