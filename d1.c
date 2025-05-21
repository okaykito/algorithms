#include<stdio.h>
int main ()
{
int n,a[20][20],i,j,min,u,v,s[10],d[10],k;
printf ("Enter the number of vertices\n");
scanf("%d",&n);
printf ("Enter adjacency matrix\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("Enter source vertex\n");
scanf("%d",&v);
for(i=1;i<=n;i++)
{
s[i]=0;
d[i]=a[v][i];
}
d[v]=0;
s[v]=1;
for(k=2;k<=n;k++)
{
min=999;
for(i=1;i<=n;i++)
{
if(d[i]<min && s[i]==0)
{
min=d[i];
u=i;
}
}
s[u]=1;
for(i=1;i<=n;i++)
{
if(s[i]==0)
{
if(d[i]>d[u]+a[u][i])
{
d[i]=d[u]+a[u][i];
}
}
}
}
for(i=1;i<=n;i++)
{
printf("%d---->%d=%d\n",v,i,d[i]);
}
}
