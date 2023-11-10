#include<stdio.h>
#include<stdlib.h>
void main(){
int n,r,i,j,count=0,k=0,flag,exec;
printf("Enter the number of processes : ");
scanf("%d",&n);
int vis[n];
int a[n];
printf("Enter the number of resources : ");
scanf("%d",&r);
int alloc[n][r],max[n][r],avail[r],need[n][r];
printf("Enter the availability of the resources : ");
for(i=0;i<r;i++){
scanf("%d",&avail[i]);
}
for(i=0;i<n;i++)
{
printf("Enter the allocation value of the process P%d : ",i);
for(j=0;j<r;j++)
{
scanf("%d",&alloc[i][j]);
}
vis[i]=0;
printf("Enter the max value of the process P%d : ",i);
for(j=0;j<r;j++)
{
scanf("%d",&max[i][j]);
}
for(j=0;j<r;j++)
{
need[i][j]=max[i][j]-alloc[i][j];
}
}
printf("The Need Matrix is : \n");
printf("Allocation Max Need\n");
for(i=0;i<n;i++)
{
for(j=0;j<r;j++)
{
printf("%d ",alloc[i][j]);
}
printf(" ");
for(j=0;j<r;j++)
{
printf("%d ",max[i][j]);
}
printf(" ");
for(j=0;j<r;j++)
{
printf("%d ",need[i][j]);
}
printf("\n");
}
while(count<n)
{
flag=0;
for(i=0;i<n;i++)
{
exec=0;
for(j=0;j<r;j++)
{
if(need[i][j]<=avail[j])
exec++;
}
if(exec==r&&vis[i]==0)
{
for(j=0;j<r;j++)
{
avail[j]+=alloc[i][j];
}
flag=1;
vis[i]=1;
count++;
a[k++]=i;
}
}
if(flag==0)
{
printf("No safe sequence!!!");
exit(0);
}
}
printf("\nThe Safe Sequence is : \n");
printf("\n<");
for(i=0;i<n;i++)
{
printf("P%d ",a[i]);
}
printf(">\n");
}
