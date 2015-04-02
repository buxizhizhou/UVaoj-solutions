//邻接表方法，TLE 
#include<stdio.h>
#include<string.h>

void dfs(int cur, int fr, int max);

int adj[25][25];
int vis[25];
int path[25];
int cnt;
int num;//路径数 

int main()
{
  freopen("208.in","r",stdin);
  freopen("208.out","w",stdout);
    
  int fire;
  int a,b;
  int t=0;
  while(scanf("%d",&fire)==1)
  {
    //初始化
    memset(adj,0,sizeof(adj));
    memset(vis,0,sizeof(vis));
    memset(path,0,sizeof(path));
    cnt=1;
    num=0; 
    printf("CASE %d:\n",++t);
    int max=0;
    path[0]=1;
    vis[1]=1;
    while(scanf("%d%d",&a,&b)==2 && a &&b)
    {
      int k=adj[a][0];
      adj[a][++k]=b;
      adj[a][0]=k;
      
      k=adj[b][0];
      adj[b][++k]=a;
      adj[b][0]=k;                         
    }
    dfs(1,fire,max);
    printf("There are %d routes from the firestation to streetcorner %d.\n",num,fire);
  }
  return 0;
}

void dfs(int cur, int fr, int max)
{
  if(cur==fr)
  {
    num++;
    for(int i=0;i<cnt;++i)
      printf("%d ",path[i]);
    printf("\n");
    return ;           
  }
  int k=adj[cur][0];
  if(k)
  for(int i=1;i<=k;++i)//i是从1开始，不是从0开始 
  {
      int temp=adj[cur][i];
      if(!vis[temp])
      {
        vis[temp]=1;
        path[cnt++]=adj[cur][i];
        dfs(adj[cur][i],fr,max);
        //恢复
        cnt--;
        vis[temp]=0;
      }
  }
}
