//修改后的解法
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define me(a,x) memset(a,x,sizeof(a))
const double pi = acos(1.0);
const double e = exp(-1.0);
const int MAXN = 200010;
const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;

bool vis[100][100];
char mp[100][100];

int ans;

//一个比较经典的写法

//vx和vy数组代表了四个方向
int vx[4] = {0,0,1,-1};
int vy[4] = {1,-1,0,0};



//模拟寻路，cnt代表走了多少个弯
void dfs(int x,int y,int xn,int yn,int cnt,int dir){
    if(x == xn && y == yn){
        ans = min(ans,cnt);
        return;
    }
    //如果当前的值已经不可能是最优的解了
    if(cnt >= ans)return;
    //#数量
    //int q = 0;
    //四个方向
    for(int i = 0;i < 4;i++){
        int nx = x + vx[i];
        int ny = y + vy[i];
        //如果这个点是_或者已经走过了，那么就不走了
        if(mp[nx][ny] == '_' || vis[nx][ny])continue;
        else{
            vis[nx][ny] = true;
            
            if(dir == i || dir == -1)dfs(nx,ny,xn,yn,cnt,i);
            else dfs(nx,ny,xn,yn,cnt+1,i);
            
            vis[nx][ny] = false;
        }
    }
};

int main(){
    int n,m;
    cin>> n >> m;
    int xn;
    int yn;
    int xc;
    int yc;
    cin>>xc>>yc>>xn>>yn;
    
    //初始化，将将矩阵外面一圈都变成_，防止越界等问题
    for(int i = 0;i <= n+1;i++){
        for(int j = 0;j <= m+1;j++){
            if(i == 0 || j == 0 || (i==n+1) || (j == m+1)){
                mp[i][j] = '_';
                continue;
            }
            cin>>mp[i][j];
        }
    }
    ans = INF;
    vis[xc][yc] = true;

    dfs(xc,yc,xn,yn,0,-1);
    if(ans == INF)ans = -1;
    cout<<ans<<"\n";
    return 0;
}