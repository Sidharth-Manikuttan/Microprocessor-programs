#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int len=0,flag=0;
char start_address[20];
char length[20]="000018";
FILE *foptab,*fintermediate,*fsymtab,*fassembly,*fobject,*flength;
foptab = fopen("optab.dat","r");
fintermediate = fopen("intermediate.dat","r");
fsymtab = fopen("symtab.dat","r");
fassembly = fopen("assembly.dat","w");
fobject = fopen("objectcode.dat","w");
char label[20],opcode[20],operand[20],optabval[20],optabhexcode[20],address[20];
char symtablabel[20],symtablabeladdress[20];
fscanf(fintermediate,"%s %s %s %s",address,label,opcode,operand);
strcpy(start_address,operand);
fprintf(fassembly,"**\t%s\t%s\t%s\t**\n",label,opcode,operand);
fprintf(fobject,"H^%s^00%s^%s\n",label,operand,length);
fscanf(fintermediate,"%s %s %s %s",address,label,opcode,operand);
while(strcmp(opcode,"END")!=0) {
if(strcmp(label,"**")!=0) {
if(strcmp(opcode,"WORD")==0) {
 fprintf(fassembly,"%s\t%s\t%s\t%s\t00000%s\n",address,label,opcode,operand,operand);
 fprintf(fobject,"T^00%s^03^00000%s\n",address,operand);
 }
 else if(strcmp(opcode,"RESW")==0) {
 fprintf(fassembly,"%s\t%s\t%s\t%s\t**\n",address,label,opcode,operand);
 }
 }
else {
 while(!feof(foptab)) {
 fscanf(foptab,"%s%s",optabval,optabhexcode);
 if(strcmp(opcode,optabval)==0) {
 while(!feof(fsymtab)) {
 fscanf(fsymtab,"%s %s",symtablabel,symtablabeladdress);
 if(strcmp(operand,symtablabel)==0) {
 strcat(optabhexcode,symtablabeladdress);
fprintf(fassembly,"%s\t%s\t%s\t%s\t%s\n",address,label,opcode,operand,optabhexcode);
 fprintf(fobject,"T^00%s^03^%s\n",address,optabhexcode);
 flag=1;
 break;
 }
 }
 }
 if(flag==1)
 break;
 }
}
fscanf(fintermediate,"%s %s %s %s",address,label,opcode,operand);
}
fprintf(fassembly,"%s\t%s\t%s\t%s\t00%s\n",address,label,opcode,operand,operand);
fprintf(fobject,"E^00%s",start_address);
fclose(foptab);
fclose(fintermediate);
fclose(fsymtab);
fclose(fassembly);
fclose(fobject);
}
