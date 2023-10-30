
#include <stdio.h>
#include <string.h>

#define SIZE 8




void checkNewStep(int chess[SIZE][SIZE], int txen[SIZE][SIZE], int i, int j, int color)
{
  int color2 = 0;

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
      for (int r = 0; r < 8 && ok != 1 ; r++)
      { 
        //next*way 是步數*方向的意思 
        /*
        判斷的方法:看下兩個地方是不是兩個異色或先異色再同色
        兩個異色:繼續往下找 直到找到空白 或是找到異色再同色
        先異色在同色:恭喜 找到了 可以下
        */
        for (int next = 1; i+(way[r][0]*(next+1)) < 8 && i+(way[r][0]*(next+1)) >= 0 && 
          j+(way[r][1]*(next+1)) < 8  && j+(way[r][1]*(next+1)) >= 0 ; next++)
        {
          if (chess[i+(way[r][0]*next)][j+(way[r][1]*next)] == 0)
          {

            ok = 0;
            break;
          }

          if (chess[i+(way[r][0]*next)][j+(way[r][1]*next)] == color2 &&
         chess[i+(way[r][0]*(next+1))][j+(way[r][1]*(next+1))] == color)  
          {
            txen[i][j] = 1;
            
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
  }
  if (ok==1)
  {
    txen[i][j] = 1;
  }

}




void checkNewStepByColor(int chess[SIZE][SIZE], int txen[SIZE][SIZE], int color)
{
    for (int i = 0; i < 8; i++)
      {
        for (int j = 0; j < 8; j++)
        {
          checkNewStep(chess , txen , i , j , color);
        }
      }

  if(color == 1)
  { 
    printf("白色可以下在");
    for (int XD = 0; XD < 8; XD++)
    {
      for (int DX = 0; DX < 8; DX++)
      {
        if(txen[XD][DX]==1)
        {
          printf("(%d,%d)",XD ,DX);
        }
      }
       printf("\n");
    }
  }
  if(color == 2)
  { 
    printf("黑色可以下在");
    for (int XD = 0; XD < 8; XD++)
    {
      for (int DX = 0; DX < 8; DX++)
      {
        if(txen[XD][DX]==1)
        {
          printf("(%d,%d)",XD ,DX);
        }
      }
       printf("\n");
    }
  }

  printf("1 是你可以下的地方\n");
  for (int XD = 0; XD < 8; XD++)
  {
    for (int DX = 0; DX < 8; DX++)
    {
      printf("%d ",txen[XD][DX]);

    }
     printf("\n");
  }
  printf("\n");
    
}
  
int main(void)
{
  int chess[SIZE][SIZE] = 
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
  int color = 2;
  int txen[SIZE][SIZE] = {0};

  checkNewStepByColor(chess, txen, color);
  memset(txen, 0,sizeof(txen));
  checkNewStepByColor(chess, txen, 3-color);

  return 0;
}