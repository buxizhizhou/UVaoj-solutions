//AC  用并查集修改后AC 
#include<stdio.h>
#include<string.h>

void dfs(int cur, int fr, int max);
int find(int x);
void unn(int x, int y);

int p[25];
int g[25][25];
int vis[25];//不用0号结点，编号是从1到n 
int path[25];
int cnt;
int num;//路径数 

int main()
{
  //freopen("208.in","r",stdin);
  //freopen("208.out","w",stdout);
    
  int fire;
  int a,b;
  int t=0;
  while(scanf("%d",&fire)==1)
  {
    //初始化
    memset(g,0,sizeof(g));
    memset(vis,0,sizeof(vis));
    memset(path,0,sizeof(path));
    for(int i=1;i<25;++i) p[i]=i;
    cnt=1;
    num=0; 
    printf("CASE %d:\n",++t);
    int max=0;
    path[0]=1;
    vis[1]=1;//vis[1]不是vis[0] 
    while(scanf("%d%d",&a,&b)==2 && a &&b)
    {
      max=a>max?a:max;
      max=b>max?b:max;
      g[a][b]=1;
      g[b][a]=1;        
      unn(a,b);                 
    }
    dfs(1,fire,max);
    printf("There are %d routes from the firestation to streetcorner %d.\n",num,fire);
  }
  return 0;
}

void unn(int x, int y)
{
  int xrt=find(x);
  int yrt=find(y);
  if(xrt!=yrt)
  {
    p[xrt]=yrt; 
  }
}

int find(int x)
{
  return x==p[x]?x:p[x]=find(p[x]);    
}

void dfs(int cur, int fr, int max)
{
  if(cur==fr)
  {
    num++;
    for(int i=0;i<cnt-1;++i)
      printf("%d ",path[i]);
    printf("%d\n",path[cnt-1]);
    return ;           
  }
  for(int i=2;i<=max;++i)
  {
    int ffr=find(fr);
    if(g[cur][i] && !vis[i] && find(i)==ffr)
    {
      vis[i]=1;
      path[cnt++]=i;
      dfs(i,fr,max);
      //恢复
      cnt--;
      vis[i]=0; 
    }
  }
}
