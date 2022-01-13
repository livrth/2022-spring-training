#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=0x7fffffff;
const int maxn=1e5+5;
int a[maxn],head[maxn],size1[maxn],top[maxn],fa[maxn],son[maxn],dep[maxn];
int nid[maxn],oid[maxn];
int n,m;
int cou,cou1;
int f1,t1,sign;
int v1;
ll val[maxn<<2];
struct G
{
    int to,next;
}g[maxn<<1];
ll querys(int L,int R,int l,int r,int rt)
{
    if(L>r||R<l) return 0;
    if(L<=l&&r<=R) return val[rt];
    int mid=(l+r)>>1;
    return querys(L,R,l,mid,rt<<1)+querys(L,R,mid+1,r,rt<<1|1);
}
ll lcas(int x,int y)
{
    ll ans=0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=ans+querys(nid[top[x]],nid[x],1,n,1);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans=ans+querys(nid[x],nid[y],1,n,1);
    return ans;
}
void pushup(int rt) {
    val[rt] = val[rt << 1] + val[rt << 1 | 1];
}
void update(int x,ll w,int l,int r,int rt)
{
    if(x<l||x>r) return;
    if(x==l&&x==r)
    {
        val[rt]=w;
        return;
    }
    int mid=(l+r)>>1;
    update(x,w,l,mid,rt<<1);
    update(x,w,mid+1,r,rt<<1|1);
    pushup(rt);
}
void build(int l,int r,int rt)
{
    val[rt]=0;
    if(l==r)
    {
        val[rt]=a[oid[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
void add_edge(int x,int y)
{
    g[++cou].to=y;
    g[cou].next=head[x];
    head[x]=cou;
}
void dfs1(int x,int fathx)
{
    fa[x]=fathx;
    son[x]=0;
    size1[x]=1;
    dep[x]=dep[fathx]+1;
    for(int i=head[x];i!=-1;i=g[i].next)
    {
        int k=g[i].to;
        if(k==fathx) continue;
        dfs1(k,x);
        size1[x]+=size1[k];
        if(size1[k]>size1[son[x]]) son[x]=k;
    }
}
void dfs2(int x,int topx)
{
    top[x]=topx;
    nid[x]=++cou1;
    oid[cou1]=x;
    if(son[x]) dfs2(son[x],topx);
    for(int i=head[x];i!=-1;i=g[i].next)
    {
        int k=g[i].to;
        if(k==son[x]||k==fa[x]) continue;
        dfs2(k,k);
    }
}
void solve()
{
    cin>>n>>m;
    cou=0,cou1=0;
    for(int i=1;i<=n;i++)
    {
        head[i]=-1;
        cin>>a[i];
        a[i]=abs(a[i]);
    }
    for(int i=1;i<n;i++)
    {
        cin>>f1>>t1;
        add_edge(f1,t1);
        add_edge(t1,f1);
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,n,1);
    while(m--)
    {
        cin>>sign;
        if(sign==2)
        {
            cin>>f1>>t1;
            if(f1==t1)
            {
                cout<<0<<endl;
                continue;
            }
            cout<<(lcas(f1,t1)*2-querys(nid[f1],nid[f1],1,n,1)-querys(nid[t1],nid[t1],1,n,1)!=0?lcas(f1,t1)*2-querys(nid[f1],nid[f1],1,n,1)-querys(nid[t1],nid[t1],1,n,1):lcas(f1,t1))<<endl;
        }
        if(sign==1)
        {
            cin>>f1>>v1;
            update(nid[f1],abs(v1),1,n,1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}
