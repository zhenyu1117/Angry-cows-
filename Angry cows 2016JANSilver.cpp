#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int n,ans;
int a[110];
bool bo[110];

void f(int w,int t)
{
 int p,q;
 
 p=1;
 while( a[w] - a[w-p] <= t && a[w] - a[w-p] >=0 && w-p>0 &&bo[w-p])    
 {
  
  ans++; 
  bo[w-p]=0; 
  p++;
 }
 
 q=p-1;
 
 p=1;
 while( a[w+p] - a[w] <= t && a[w+p] - a[w] >=0 && w+p<=n &&bo[w+p])  
 {
  
  ans++; //草堆个数加 1  
  bo[w+p]=0; //被引爆 
  p++;
 }
 p--;
 
 
 if(w-q>0&&q>0) 
  f(w-q,t+1);
 if(w+p<=n&&p>0) 
  f(w+p,t+1);
 
}

int main()
{
 int maxx=-0x0fffffff;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  scanf("%d",&a[i]);
  
 sort(a+1,a+n+1);
 
 for(int i=1;i<=n;i++)
 {
    
  memset(bo,1,sizeof(bo));
  ans=1;
  
  bo[i]=0;
  f(i,1);
  
  maxx=max(maxx,ans);
 }
 
 printf("%d",maxx);
 return 0;
 } 
