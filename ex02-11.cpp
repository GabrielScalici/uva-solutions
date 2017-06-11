#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define inf 2000000000
struct tree
{
    int from,to,cap,flow;
    tree(){}
    tree(int ff,int tt,int cc,int ww)
    {
        from=ff;to=tt;cap=cc;flow=ww;
    }
};
int source,sink,n,m;
vector<tree>G;
vector<int>v[2000];
int vis[2000];
int cur[2000];//标记遍历时是否遍历，加快遍历速度
int d[2000];//层数
void addtree(int from,int to,int cap)
{
    G.push_back(tree(from,to,cap,0));
    G.push_back(tree(to,from,cap,0));
    int m=G.size();
    v[from].push_back(m-2);
    v[to].push_back(m-1);
}
bool bfs()
{
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(source);
    d[source]=0;
    vis[source]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x==sink) return true;
        for(int i=0;i<v[x].size();i++)
        {
            tree &e=G[v[x][i]];
            if(!vis[e.to]&&e.cap>e.flow)
            {
                vis[e.to]=1;
                d[e.to]=d[x]+1;
                q.push(e.to);
            }
        }
    }
    return false;
}
int dfs(int x,int a)
{
    if(x==sink||a==0)
    return a;
    int flow=0,f;
    for(int &i=cur[x];i<v[x].size();i++)
    {
        tree &e=G[v[x][i]];
        if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0)
        {
            e.flow+=f;
            G[v[x][i]^1].flow-=f;
            flow+=f;
            a-=f;
            if(a==0)
            break;
        }
    }
    return flow;
}
int maxflow()
{
    int flow=0;
    while(bfs())
    {
        memset(cur,0,sizeof(cur));
        flow+=dfs(source,inf);
    }
    return flow;
}
int viscut[2000];
int que[20000];
void docut()      //此处为割边
{
    memset(viscut,0,sizeof(viscut));
    memset(cur,0,sizeof(cur));
    int front=0,end=0;
    que[end++]=source;
    viscut[source]=1;
    while(front<end)
    {
        int u=que[front++];
        for(int &i=cur[u];i<v[u].size();i++)
        {
            tree &e=G[v[u][i]];
            if(e.flow<e.cap&&!viscut[e.to])
            {
                viscut[e.to]=1;
                que[end++]=e.to;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(viscut[i])
        {
            //printf("!! %d\n",i);
            for(int j=0;j<v[i].size();j++)
            {
                tree &e=G[v[i][j]];
                if(e.flow==e.cap&&e.cap>0&&!viscut[e.to])
                {
                    printf("%d %d\n",e.from,e.to);
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)==2,n+m)
    {
        source=1;sink=2;
        for(int i=0;i<=2000;i++)
        v[i].clear();
        G.clear();
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addtree(a,b,c);
        }
        maxflow();
        docut();
        printf("\n");
    }
} 
