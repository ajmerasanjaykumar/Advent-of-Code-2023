#include <bits/stdc++.h>
using namespace std;

int inside(int a,int b,int c){
    if(a>=b && a<=c) return 1;
    return 0;
}

int tell(int j,int st,int en){
    if(inside(j-1,st,en) || inside(j,st,en) || inside(j+1,st,en)) return 1;
    return 0;
}

void solve(int i,int j,int m,vector<int> &num,vector<string>& v){

    string s;
    for(int j1=0;j1<m;j1++)
        {
            if(v[i][j1]>='0' && v[i][j1]<='9') s.push_back(v[i][j1]);
            else
            {
                int t=s.size();
                if(t>0 && tell(j,j1-t,j1-1)) num.push_back(stoi(s));
                s.clear();
            }
        }
    int t=s.size();
    if(t>0 && tell(j,m-1-t,m-1)) num.push_back(stoi(s));
    return ;
}

int main() {

    vector<string> v;
    while (true) {
        string s;
        getline(cin, s);
        if (s.empty()) break;
        v.push_back(s);
    }
    int n=v.size();
    int m=v[0].size();
    string s;
    int ans=0;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                {
                    if(v[i][j]=='*')
                    {
                        int a[3][3]={{0,0,0},{0,0,0},{0,0,0}};
                        for(int i1=i-1;i1<=i+1;i1++)
                            {
                                for(int j1=j-1;j1<=j+1;j1++)
                                    {
                                        if(i1>=0 && i1<=n-1 && j1>=0 && j1<=m-1 &&
                                            v[i1][j1]>='0' && v[i1][j1]<='9') a[i1-(i-1)][j1-(j-1)]=1;
                                        else a[i1-(i-1)][j1-(j-1)]=0;
                                    }
                            }
                        int c=0;
                        for(int i1=0;i1<3;i1++)
                            {
                                for(int j1=0;j1<3;j1++) c=c+a[i1][j1];
                            }

                        if(a[0][0]==1 && a[0][1]==1 && a[0][2]==1) c=c-2;
                        if(a[2][0]==1 && a[2][1]==1 && a[2][2]==1) c=c-2;
                        if(a[0][0]==1 && a[0][1]==1 && a[0][2]==0) c--;
                        if(a[0][0]==0 && a[0][1]==1 && a[0][2]==1) c--;
                        if(a[2][0]==1 && a[2][1]==1 && a[2][2]==0) c--;
                        if(a[2][0]==0 && a[2][1]==1 && a[2][2]==1) c--;

                        if(c==2)
                        {
                            vector<int> num;
                            if(i>0) solve(i-1,j,m,num,v);
                            solve(i,j,m,num,v);
                            if(i<n-1) solve(i+1,j,m,num,v);
                            ans=ans+num[0]*num[1];
                        }
                    }
                }
        }

    cout<<ans;
    return 0;
}