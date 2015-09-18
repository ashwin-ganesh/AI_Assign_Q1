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

#define SIZE 100



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

P G[SIZE][SIZE];
int cost[SIZE][SIZE];
int h[SIZE][SIZE];
int f[SIZE][SIZE];

bool visited[SIZE][SIZE];
S parent[SIZE][SIZE];

int nodes_traversed = 0;
int n;

int maxb = 3;

bool is_valid(int i , int j)
{
	if(i>=0 && i<=n-1 && j>=0 && j<=n-1)
		return true;

	return false;
}

int best_poss(int i, int j)
{
	 int ans = 0;

   ans = ceil((n-1-i)/maxb) + ceil((n-1-j)/maxb);    // max b value in this case is 2
	 return ans;

}

int C_heuristic(int i , int j)
{

  int a = G[i][j].a;
  int b = G[i][j].b;

  if(a == 0 || a==1)
    return best_poss(i,j);

  int ans = INT_MAX;

  if(is_valid(i-b,j))
    ans = best_poss(i-b,j);
  if(is_valid(i,j-b))
    ans = min(ans, best_poss(i,j-b));


	return ans;
}


void initialize()
{
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      visited[i][j]  = false;

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      {
        h[i][j] = C_heuristic(i,j);
      }

  
}



S mindistance()
{
	int i,min1=INT_MAX,j;
	S index;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		if(visited[i][j]==false && f[i][j] < min1)
		{
			min1 = f[i][j];
			index.x = i;
			index.y = j;
		}
	}

	return index;
}

void Astar()
{
	int i,j;

	S start,end1;
    start.x = 0; start.y = 0;  end1.x=n-1; end1.y = n-1;



    for(i=0;i<n;i++)
    	for(j=0;j<n;j++)
    		f[i][j] = INT_MAX;

    cost[0][0] = 0;
    h[0][0] = C_heuristic(0,0);
    f[0][0] = cost[0][0] + h[0][0];


    while(1)
    {
    	S top = mindistance();          // For now , brute force it

    	int x = top.x;
        int y = top.y;
        nodes_traversed++;

        visited[x][y] = true;

        if(x == end1.x && y == end1.y)
      {
      	cout<<"Cost of path "<<cost[n-1][n-1]+1<<endl;
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
      				if(is_valid(x,y+i)  && visited[x][y+i] == false )
      				{
      					if(1+ cost[x][y] + h[x][y+i] < f[x][y+i] )
      					{
      						f[x][y+i] = 1+ cost[x][y] + h[x][y+i];
      						cost[x][y+i] = 1+ cost[x][y];
                  //S p; p.x = x; p.y = y;
                  //parent[x][y+i] = p;
      					}
      				}
      				if(is_valid(x,y-i)  && visited[x][y-i] == false)
      				{
      					if(1+ cost[x][y] + h[x][y] < f[x][y-i] )
      					{
      						f[x][y-i] = 1+ cost[x][y] + h[x][y-i];
      						cost[x][y-i] = 1+ cost[x][y];
      					}
      				}
      				if(is_valid(x+i,y)  && visited[x+i][y] == false )
      				{
      					if(1+ cost[x][y] + h[x][y] < f[x+i][y] )
      					{
      						f[x+i][y] = 1+ cost[x][y] + h[x+i][y];
      						cost[x+i][y] = 1+ cost[x][y];
      					}
      				}
      				if(is_valid(x-i,y)  && visited[x-i][y] == false )
      				{
      					if(1+ cost[x][y] + h[x][y] < f[x-i][y] )
      					{
      						f[x-i][y] = 1+ cost[x][y] + h[x-i][y];
      						cost[x-i][y] = 1+ cost[x][y];
      					}
      				}
      			}
      	break;
      	case 1:
      			if(is_valid(x,y+b)  && visited[x][y+b] == false )
      				{
      					if(1+ cost[x][y] + h[x][y+b] < f[x][y+b] )
      					{
      						f[x][y+b] = 1+ cost[x][y] + h[x][y+b];
      						cost[x][y+b] = 1+ cost[x][y];
      					}
      				}
      			if(is_valid(x+b,y)  && visited[x+b][y] == false )
      				{
      					if(1+ cost[x][y] + h[x][y] < f[x+b][y] )
      					{
      						f[x+b][y] = 1+ cost[x][y] + h[x+b][y];
      						cost[x+b][y] = 1+ cost[x][y];
      					}
      				}
      	break;
      	case -1:
      			if(is_valid(x,y-b)  && visited[x][y-b] == false)
      				{
      					if(1+ cost[x][y] + h[x][y] < f[x][y-b] )
      					{
      						f[x][y-b] = 1+ cost[x][y] + h[x][y-b];
      						cost[x][y-b] = 1+ cost[x][y];
      					}
      				}
      			if(is_valid(x-b,y)  && visited[x-b][y] == false )
      				{
      					if(1+ cost[x][y] + h[x][y] < f[x-b][y] )
      					{
      						f[x-b][y] = 1+ cost[x][y] + h[x-b][y];
      						cost[x-b][y] = 1+ cost[x][y];
      					}
      				}
        break;

    }

  }

 }



int main()
{
   freopen("Q1_input2.txt", "r", stdin);
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
   cout<<"hi\n";
   initialize();
   Astar();

   return 0;
}

