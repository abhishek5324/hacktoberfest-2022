class MaxAreaIsland
{
  static int m=0,n=0;
  static int dir[][]={{0,1},{1,0},{-1,0},{0,-1}};
  static int helpArea(int i,int j,int g[][])
      {
          int x=0,y=0;
       g[i][j]=0;int ans=0;
          for(int k=0;k<4;k++)
          {
              x=i+dir[k][0];y=j+dir[k][1];
              if(x>=0&&x<m&&y>=0&&y<n&&g[x][y]==1)
              {
                  
                  ans+=helpArea(x,y,g);}
          }
          return ans+1;
      }
  public static int maxAreaOfIsland(int[][] grid) 
  {
      m=grid.length;
      n=grid[0].length;
      int max=0;
     
      for(int i=0;i<m;i++)
      {
          for(int j=0;j<n;j++)
          {
              if(grid[i][j]==1)
              {
                  int k=helpArea(i,j,grid);
                  max=Math.max(max,k);}
          }
      }
      return max;
  }
  public static void main(String args[]) 
  {
    int grid[][]={{0,0,1,0,0,0,0,1,0,0,0,0,0},
                  {0,0,0,0,0,0,0,1,1,1,0,0,0},
                  {0,1,1,0,1,0,0,0,0,0,0,0,0},
                  {0,1,0,0,1,1,0,0,1,0,1,0,0},
                  {0,1,0,0,1,1,0,0,1,1,1,0,0},
                  {0,0,0,0,0,0,0,0,0,0,1,0,0},
                  {0,0,0,0,0,0,0,1,1,1,0,0,0},
                  {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    System.out.println("Max Area of an island : "+maxAreaOfIsland(grid));
  }
}