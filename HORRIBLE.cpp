#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
long long int A[MAX+1];
long long int SegTree[4*MAX+1];
long long int LazyUp[4*MAX+1];
void BuildSegTree(int left,int right,int vertex)
{
    if(left==right)
        SegTree[vertex] = A[left];
    else
    {
        int mid = left+(right-left)/2;
        BuildSegTree(left,mid,2*vertex);
        BuildSegTree(mid+1,right,2*vertex+1);
        SegTree[vertex] = SegTree[2*vertex]+SegTree[2*vertex+1];
    }
}
long long int Query(int ia, int ib, int vertex, int a, int b)
{
    ia = max(ia,a);
    ib = min(ib,b);
    if(ia>=ib)return 0;
    if(ia==a && ib==b)
        return LazyUp[vertex]*(b-a)+SegTree[vertex];
    SegTree[vertex]+=(b-a)*LazyUp[vertex];
    LazyUp[2*vertex]+=LazyUp[vertex];
    LazyUp[2*vertex+1]+=LazyUp[vertex];
    LazyUp[vertex] = 0;
    return Query(ia,ib,2*vertex,a,(a+b)/2) + Query(ia,ib,2*vertex+1,(a+b)/2,b);
}
void Update(long long int incr, int ia, int ib, int vertex, int a, int b)//a = 0 and b = N
{
    ia = max(ia,a);ib = min(ib,b);
    if(ia>=ib)return;
    if(ia==a && ib==b)
    {
        LazyUp[vertex]+=incr;
        return;
    }
    SegTree[vertex]+=incr*(ib-ia);
    Update(incr,ia,ib,2*vertex,a,(a+b)/2);  // And push the increment to its children
    Update(incr,ia,ib,2*vertex+1,(a+b)/2, b);
}
void setZero(int N)
{
    for(int i = 0;i<N;i++)
        A[i] = 0;
    for(int i = 1;i<=4*N;i++)
    {
        SegTree[i] = 0;
        LazyUp[i] = 0;
    }
}
int main()
{
    int T, N, C;
    long long int opcode, start, end, val;
    cin>>T;
    while(T--)
    {
        cin>>N>>C;
        setZero(N);
        while(C--)
        {
            cin>>opcode;
            if(opcode==0)
            {
                cin>>start>>end>>val;
                Update(val,start-1,end,1,0,N);
                for(int i = 1;i<16;i++)
                    cout<<SegTree[i]<<" ";
                cout<<endl;
                for(int i = 1;i<16;i++)
                    cout<<LazyUp[i]<<" ";
            }
            else
            {
                cin>>start>>end;
                cout<<Query(start-1,end,1,0,N)<<"\n";
            }
        }
    }
    return 0;
}
