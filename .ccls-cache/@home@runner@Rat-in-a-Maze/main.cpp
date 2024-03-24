#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int i, int j,int &row,int &col,vector<vector<int>>&arr, vector<vector<bool>>&visit)
{
  if((i >=0 && i < row) && (j >=0 && j < col) && (arr[i][j] == 1) && (visit[i][j] == false))
  {
     return true;
  }
  else
  {
    return false;
  }
}
void EscapeWay(vector<vector<int>>arr,int row,int col,int ratx,int raty, vector<vector<bool>>&visit ,vector <string>& path,string direction)
{
  //Base Case
  if(ratx==row-1 && raty==col-1)
  {
    path.push_back(direction );
    return;
  }

  //Step 1
  //Down => ratx+1,raty
  if(isSafe(ratx+1 ,raty ,row ,col ,arr ,visit ))
  {
    visit[ratx+1][raty]=true;
    EscapeWay(arr ,row ,col ,ratx+1 ,raty ,visit ,path ,direction + "D");
    visit[ratx+1][raty]=false;
  }

  //Step 2
  //Left => ratx,raty-1
  if(isSafe(ratx ,raty-1 ,row ,col ,arr ,visit ))
  {
    visit[ratx][raty-1]=true;
    EscapeWay(arr ,row ,col ,ratx ,raty-1 ,visit ,path ,direction + "L");
    visit[ratx][raty-1]=false;
  }

  //Step 3
  //Right => ratx,raty+1
  if(isSafe(ratx ,raty+1 ,row ,col ,arr ,visit ))
  {
    visit[ratx][raty+1]=true;
    EscapeWay(arr ,row ,col ,ratx ,raty+1 ,visit ,path ,direction + "R");
    visit[ratx][raty+1]=false;
  }

  //Step 4
  //Up => ratx-1,raty
  if(isSafe(ratx-1 , raty,row,col,arr,visit))
  {
    visit[ratx-1][raty]=true;
    EscapeWay(arr ,row ,col ,ratx-1 ,raty ,visit ,path ,direction + "U");
    visit[ratx-1][raty]=false;
  }
}
int main() {

  vector<vector<int>>maze{
                    {1,0,0,0},
                    {1,1,0,1},
                    {1,1,0,0},
                    {0,1,1,1}
                             };
  if(maze[0][0] == 0)
  {
    cout<<"No Path Exist"<<endl;
    return 0;
  }
  int row = 4;
  int col = 4;
  vector<vector<bool>>visit(row,vector<bool>(col,false));
  visit[0][0] = true;
  vector<string> path;
  string direction = "";

  EscapeWay(maze,row,col,0,0,visit,path,direction);

  for(int i = 0;i<path.size();i++)
    {
      cout << path[i] << " ";
    }
  cout << endl;

  if(path.size() == 0)
  {
    cout << "No Path Exist" << endl;
  }
}