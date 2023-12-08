#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fobj;
	fobj = fopen("object.txt","r");
	char prog_name[10],text_line[100],temp[50];
	int addr,i,j;
	printf("Enter the program name : ");
	scanf("%s",prog_name);
	fscanf(fobj,"%s",text_line);
	if(text_line[0]=='H') {
		j=0;
		i=2;
		while(text_line[i]!='^') {
			temp[j]=text_line[i];
			j++;
			i++;
		}
		temp[j]='\0';
	}
	if(strcmp(prog_name,temp)==0) {
		fscanf(fobj,"%s",text_line);
		while((!feof(fobj)) && (text_line[0]!='E')) {
			
			if(text_line[0]=='T') {
				j=0;
				i=2;
				while(text_line[i]!='^') {
					temp[j]=text_line[i];
					j++;
					i++;
				}
				temp[j]='\0';
			}
			i++;
			addr=atoi(temp);
			while(text_line[i]!='^')
				i++;
			while(text_line[i]!='\0') {
				if(text_line[i]=='^') 
					i++;
				else {
					printf("\n%d : %c%c",addr,text_line[i],text_line[i+1]);
					i+=2;
					addr++;
				}
			}
			fscanf(fobj,"%s",text_line);
		}
	}
	else
		printf("Program name does not match");
	printf("\n");
	fclose(fobj);
}
