#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int len=0,start_address=0,flag=0;
FILE *finput,*foptab,*fintermediate,*fsymtab;
finput = fopen("input.dat","r");
foptab = fopen("optab.dat","r");
fintermediate = fopen("intermediate.dat","w");
fsymtab = fopen("symtab.dat","w");
char label[20],opcode[20],operand[20],optabval[20],optabhexcode[20];
int locctr=0;
fscanf(finput,"%s %s %s",label,opcode,operand);
start_address=atoi(operand);
if(strcmp(opcode,"START")==0) {
locctr=atoi(operand);
fprintf(fintermediate,"\t%s\t%s\t%s\n%d",label,opcode,operand,locctr);
}
else
locctr=0;
fscanf(finput,"%s %s %s",label,opcode,operand);
while(strcmp(opcode,"END")!=0) {
flag=0;
if(strcmp(label,"**")!=0) {
fprintf(fsymtab,"%s\t%d\n",label,locctr);
}
else {
while(!feof(foptab)) {
fscanf(foptab,"%s%s",optabval,optabhexcode);
if(strcmp(opcode,optabval)==0) {
locctr+=3;
flag=1;
break;
}
}
if(flag==0)
{
printf("\nError!! Opcode not found!!\n");
exit(0);
}
}
if(strcmp(opcode,"WORD")==0)
locctr+=3;
else if(strcmp(opcode,"RESW")==0)
locctr+=3*atoi(operand);
else if(strcmp(opcode,"RESB")==0)
locctr+=atoi(operand);
fprintf(fintermediate,"\t%s\t%s\t%s\n%d",label,opcode,operand,locctr);
fscanf(finput,"%s %s %s",label,opcode,operand);
}
fprintf(fintermediate,"\t%s\t%s\t%d",label,opcode,start_address);
printf("Pass 1 is Successfull\n");
printf("Program length : %d\n",locctr-start_address);
fclose(finput);
fclose(foptab);
fclose(fintermediate);
fclose(fsymtab);
}
