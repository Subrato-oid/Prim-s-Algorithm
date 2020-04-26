#include<iostream>
#include<climits>
#define I INT_MAX

using namespace std;

 int cost[8][8]={{I,I,I,I,I,I,I,I},
               {I,I,25,I,I,I,5,I},
               {I,25,I,12,I,I,I,10},
               {I,I,12,I,8,I,I,I},
               {I,I,I,8,I,16,I,14},
               {I,I,I,I,16,I,20,18},
               {I,5,I,I,I,20,I,I},
               {I,I,10,I,14,18,I,I}};

int near[8]={I,I,I,I,I,I,I,I};

int t[2][6];
int main(){

    int i,j,k,u,v,n=7,min=I;

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(cost[i][j]<min){
                min=cost[i][j];
                u=i;
                v=j;
            }
        }
    }
    t[0][0]=u;
    t[1][0]=v;
    near[u]=near[v]=0;

    for(int j=1;j<=n;j++){
        if(near[j]!=0){
            if(cost[j][u]<cost[j][v])
                near[j]=u;
            else
                near[j]=v;
        }
    }
    for(int j=1;j<n-1;j++){
        min=I;
        for(i=1;i<n;i++){
          if(near[i]!=0 && cost[i][near[i]] < min){
              k=j;
              min=cost[i][near[i]];
          }
        }

        t[0][j]=k;
        t[1][j]=near[k];
        near[k]=0;

        for(int i=1;i<=n;i++){
            if(near[i]!=0 && cost[i][k] < cost[i][near[i]]){
                near[i]=k;
            }
        }
    }
    for(i=0;i<n-1;i++){
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    }
    return 0;
}

