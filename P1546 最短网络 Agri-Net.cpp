#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
struct node{
    int x,y,w;
}a[200002];
int f[200002];
bool cmp(node xx,node yy){
    return xx.w<yy.w;
}
int find(int x){
    if(x==f[x]) return x;
    f[x]=find(f[x]);
    return f[x];
}
int main(){
    int n,k,m=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        f[i]=i;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&k);
            if(j>i){
                m++;
                a[m].x=i;a[m].y=j;a[m].w=k; 
            }   
        }
    }
    sort(a+1,a+m+1,cmp);
    int ans=0,p=1;
    for(int i=1;i<=m;i++){
        if(find(a[i].x)!=find(a[i].y)){
            ans+=a[i].w;
            f[find(a[i].x)]=a[i].y;
            p++;
            if(p==n) 
				break; 
        }
    }
    cout<<ans;
    return 0;
} 
