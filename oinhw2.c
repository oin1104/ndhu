
#include <stdio.h>
  
int chess[8][8] = 
{
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,2,1,0,0,0},
  {0,0,0,1,2,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

int main(void){
  int i = 0;
  int j = 0;
  int color = 0;
  int color2 = 0;

  scanf("%d%d%d",&i ,&j ,&color);
    
  if (color == 1)
  {
    color2 = 2;
  }
  else
  {
    color2 = 1;
  }
  
  int ok = 3;
    
  
  int way[8][2] = 
  {
    {-1,-1},
    {-1,0},
    {-1,1},
    {0,1},
    {1,1},
    {1,0},
    {1,-1},
    {0,-1}
  };

  if (i >= 0 && i < 8 && j >= 0 && j < 8)
  {
    while (chess[i][j] == 0)
    {
      printf("work\n");
      for (int r = 0; r < 8 && ok != 1 ; r++)
      { 
        printf("work0\n");
        for (int next = 1; i+(way[r][0]*(next+1)) < 8 && i+(way[r][0]*(next+1)) >= 0 && 
          j+(way[r][1]*(next+1)) < 8  && j+(way[r][1]*(next+1)) >= 0 ; next++)
        {
          printf("%d\n",chess[i+(way[r][0]*next)][j+(way[r][1]*next)]);
          if (chess[i+(way[r][0]*next)][j+(way[r][1]*next)] == 0)
          {
            printf("work1\n");
            
            ok = 0;
            break;
          }
    
          if (chess[i+(way[r][0]*next)][j+(way[r][1]*next)] == color2 &&
         chess[i+(way[r][0]*(next+1))][j+(way[r][1]*(next+1))] == color)  
          {
            printf("work2\n");
            ok = 1;
            break;
          }  
          if (chess[i+(way[r][0]*next)][j+(way[r][1]*next)] == color2 &&
             chess[i+(way[r][0]*(next+1))][j+(way[r][1]*(next+1))] == color2)
          {         
          }
          else
          {
            ok = 0;
            break;
          }
        }    
      } 
      if (ok==0||ok==1)
      {
      break;
      }
    }
    if (ok==1)
    {
      printf("ok\n");
    }
    else
    {
      printf("no\n");
    }
  
  }
  return 0;
}