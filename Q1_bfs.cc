#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <map>
#include <climits>
#include <set>
using namespace std;


# define ll long long
# define pll pair < ll, ll >
# define fs first
# define se second
# define mp make_pair
# define pb push_back

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define llmax 	1LL<<60
#define SIZE 300005

struct S
{
	int x;
	int y;
};


struct P
{
	int a;
	int b;
};

P G[100][100];
int hash1[100][100];
queue < pair<S,int> > Q;

int nodes_traversed = 0;
int n;


bool is_valid(int i , int j)
{
	if(i>=0 && i<=n-1 && j>=0 && j<=n-1)
		return true;

	return false;
}




void bfs()
{
   int i ,j,m;
   S start,end;
   start.x = 0; start.y = 0;  end.x=n-1; end.y = n-1;

   Q.push(mp(start,0));

   hash1[0][0] = 1;

   while(! Q.empty())
   {
   	  pair<S,int> top = Q.front();
   	  Q.pop();



      int x = top.fs.x;
      int y = top.fs.y;
      nodes_traversed++;

      if(x == end.x && y == end.y)
      {
      	cout<<"Cost of path "<<top.se+1<<endl;
      	cout<<"Nodes traversed "<<nodes_traversed<<endl;
      	break;
      }

      int a = G[x][y].a;
      int b = G[x][y].b;

      switch(a)
      {
      	case 0:
      			for(i=1;i<=b;i++)
      			{
      				if(is_valid(x,y+i)  && hash1[x][y+i] ==0 )
      				{
      					hash1[x][y+i] = 1;
      					S node; node.x = x; node.y = y+i;
      					Q.push(mp(node,top.se+1));
      				}
      				if(is_valid(x,y-i)  && hash1[x][y-i] ==0 )
      				{
      					hash1[x][y-i] = 1;
      					S node; node.x = x; node.y = y-i;
      					Q.push(mp(node,top.se+1));
      				}
      				if(is_valid(x+i,y)  && hash1[x+i][y] ==0 )
      				{
      					hash1[x+i][y] = 1;
      					S node; node.x = x+i; node.y = y;
      					Q.push(mp(node,top.se+1));
      				}
      				if(is_valid(x-i,y)  && hash1[x-i][y] ==0 )
      				{
      					hash1[x-i][y] = 1;
      					S node; node.x = x-i; node.y = y;
      					Q.push(mp(node,top.se+1));
      				}
      			}
      	break;
      	case 1:
      			if(is_valid(x,y+b)  && hash1[x][y+b] ==0 )
      				{
      					hash1[x][y+b] = 1;
      					S node; node.x = x; node.y = y+b;
      					Q.push(mp(node,top.se+1));
      				}
      				if(is_valid(x+b,y)  && hash1[x+b][y] ==0 )
      				{
      					hash1[x+b][y] = 1;
      					S node; node.x = x+b; node.y = y;
      					Q.push(mp(node,top.se+1));
      				}

      	break;

      	case -1:
      			if(is_valid(x,y-b)  && hash1[x][y-b] ==0 )
      				{
      					hash1[x][y-b] = 1;
      					S node; node.x = x; node.y = y-b;
      					Q.push(mp(node,top.se+1));
      				}

      			if(is_valid(x-b,y)  && hash1[x-b][y] ==0 )
      				{
      					hash1[x-b][y] = 1;
      					S node; node.x = x-b; node.y = y;
      					Q.push(mp(node,top.se+1));
      				}

        break;

      }


   }



}



int main()
{
   freopen("Q1_input.txt", "r", stdin);
   int i,j,a1,b1;

   cin>>n;

   for(i=0;i<n;i++)
   	for(j=0;j<n;j++)
   {
   	 cin>>a1;
   	 cin>>b1;

     G[i][j].a = a1;
     G[i][j].b = b1;
   }

    for(i=0;i<n;i++)
   	for(j=0;j<n;j++)
        cout<<G[i][j].a<<G[i][j].b<<" ";

    cout<<endl;

    bfs();

   return 0;
}
