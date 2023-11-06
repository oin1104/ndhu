
#include <stdio.h>
#include <string.h>

#define SIZE 8




void checkNewStep(int chess[SIZE][SIZE], int txen[SIZE][SIZE], int i, int j, int color)
{
  int color2 = 3-color;
  int ok = 3;
  int _flip = 0;
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

  if (!(i >= 0 && i < 8 && j >= 0 && j < 8))
  { 
      return;
  }

    if (chess[i][j] != 0){
        return;
    }
  for (int r = 0; r < 8 ; r++)
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
        break;
      }

      if (chess[i+(way[r][0]*next)][j+(way[r][1]*next)] == color2 &&
     chess[i+(way[r][0]*(next+1))][j+(way[r][1]*(next+1))] == color)  
      {
        
        txen[i][j] = txen[i][j] + next;
        break;
      }  
      if (chess[i+(way[r][0]*next)][j+(way[r][1]*next)] == color2 &&
         chess[i+(way[r][0]*(next+1))][j+(way[r][1]*(next+1))] == color2)
      {         
      }
      else
      {
        break;
      }
    }   
  }
      
  
}




//這裡因為方便就直接複製貼上改一點點了
void flip(int chess[SIZE][SIZE], int i, int j, int color)
{
  int color2 = 3-color;
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
        for (int r = 0; r < 8 ; r++)
        { 
            int nextok =0;
            for (int next = 1; i+(way[r][0]*(next+1)) < 8 && i+(way[r][0]*(next+1)) >= 0 && 
              j+(way[r][1]*(next+1)) < 8  && j+(way[r][1]*(next+1)) >= 0 ; next++)
            {
                if (chess[i+(way[r][0]*next)][j+(way[r][1]*next)] == 0)
                {      

                    break;
                }
                  if (chess[i+(way[r][0]*next)][j+(way[r][1]*next)] == color2 &&
                 chess[i+(way[r][0]*(next+1))][j+(way[r][1]*(next+1))] == color)  
                {
                    for (int next_ok = next+1; next_ok >=0 ; next_ok--)
                    {
                        chess[i+(way[r][0]*next_ok)][j+(way[r][1]*next_ok)] = color;  
                    }


                }  
                if (chess[i+(way[r][0]*next)][j+(way[r][1]*next)] == color2 &&
                     chess[i+(way[r][0]*(next+1))][j+(way[r][1]*(next+1))] == color2)
                {         
                }
                else
                {

                    break;
                }
            }    
        }
    }
  }
}


void computer(int chess[SIZE][SIZE], int txen[SIZE][SIZE], int color)
{
    for (int i = 0; i < 8; i++)
      {
        for (int j = 0; j < 8; j++)
        {
          checkNewStep(chess , txen , i , j , color);
        }
      }

    if(color == 2)
    { 
        printf("電腦(黑色)說他下在");
        for(int cf = 18 ; cf >0 ; cf--)
        {
            for (int XD = 0; XD < 8; XD++)
            {
              for (int DX = 0; DX < 8; DX++)
              {
                if(txen[XD][DX] == cf)
                {
                    printf("(%d,%d)\n",XD , DX);
                    flip(chess , XD, DX, color);
                    return ;
                }
              }
            }
        }
    }
    if(color == 1)
    { 
        printf("電腦(白)說他下在");
        for(int cf = 18 ; cf >0 ; cf--)
        {
            for (int XD = 0; XD < 8; XD++)
            {
              for (int DX = 0; DX < 8; DX++)
              {
                if(txen[XD][DX] == cf)
                {
                    printf("(%d,%d)\n",XD , DX);
                    flip(chess , XD, DX, color);
                    return ;
                }
              }
               printf("\n");
            }
        }
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
    printf("白色可以下在\n");
    for (int XD = 0; XD < 8; XD++)
    {
      for (int DX = 0; DX < 8; DX++)
      {
        if(txen[XD][DX]>=1)
        {
          printf("(%d,%d)",XD ,DX);
          printf("\n");
        }
      }
    }
    printf("\n");
  }
  if(color == 2)
  { 
    printf("黑色可以下在\n");
    for (int XD = 0; XD < 8; XD++)
    {
      for (int DX = 0; DX < 8; DX++)
      {
        if(txen[XD][DX]>=1)
        {
          printf("(%d,%d)",XD ,DX);
          printf("\n");
        }
      }
    }
    printf("\n");
  }

  printf("有數字的地方是你可以下的地方跟翻轉的數目\n");
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

void checkNewStepByColor_noprint(int chess[SIZE][SIZE], int txen[SIZE][SIZE], int color)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
          checkNewStep(chess , txen , i , j , color);
        }
    }
}


int gamecheck(int txen[SIZE][SIZE])
{
    for (int XD = 0; XD < 8; XD++)
    {
      for (int DX = 0; DX < 8; DX++)
      {
        if(txen[XD][DX] > 0)
        {
            return 1;

        }
      }
    }
  return 0;
}


void printmap(int chess[SIZE][SIZE])
{
    printf("棋盤現在的樣子:\n");
    for (int pmy = 0; pmy < 8; pmy++)
    {
        for (int pmx = 0; pmx < 8; pmx++)
        {
          printf("%d ",chess[pmy][pmx]);

        }
        printf("\n");
    }
    printf("\n");
    return;
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

  int pi,pj = 0;
  int txen[SIZE][SIZE] = {0};

  int color = 0;
  printf("你是啥顏色 1=白 2=黑\n");
  scanf("%d",&color);


    while(1)  
    {
        memset(txen, 0,sizeof(txen));
        checkNewStepByColor_noprint(chess, txen, color);
        if(gamecheck(txen) == 1)
        {  
            memset(txen, 0,sizeof(txen));
            checkNewStepByColor(chess, txen, color);
            memset(txen, 0,sizeof(txen));
            printmap(chess);
            printf("你要下在哪裡\n");
            scanf("%d %d",&pi ,&pj);
            memset(txen, 0,sizeof(txen));
            flip(chess , pi, pj, color);
            memset(txen, 0,sizeof(txen));
        }
        else
        {
            printf("沒地方下 跳過\n");
        }
        
        color = 3 - color;
        
        memset(txen, 0,sizeof(txen));
        checkNewStepByColor_noprint(chess, txen, color);
        
        if(gamecheck(txen) == 1)
        {
            memset(txen, 0,sizeof(txen));
            computer(chess, txen, color);
            memset(txen, 0,sizeof(txen));
            printmap(chess);
            memset(txen, 0,sizeof(txen));
            
        }
        else
        {
            printf("沒地方下 跳過\n");
        }

        
        color = 3 - color;
        
        memset(txen, 0,sizeof(txen));
        checkNewStepByColor_noprint(chess, txen, color);

        if((gamecheck(txen) == 0))
        {
            color = 3 - color;
            memset(txen, 0,sizeof(txen));
            checkNewStepByColor_noprint(chess, txen, color);
            if((gamecheck(txen) == 0))
            break;
            color = 3 - color;
        }
        memset(txen, 0,sizeof(txen));
        checkNewStepByColor_noprint(chess, txen, color);
    }

//結算
    int score1 = 0;
    int score2 = 0;
    for(int finx = 0 ; finx < SIZE ; finx ++)
    {
        for(int finy = 0 ; finy < SIZE ; finy ++)
        {
            if(chess[finx][finy]==1)
            {
                score1 ++;
            }
            if(chess[finx][finy]==2)
            {
                score2 ++;
            }
        }
    }
    if(score1 > score2)
    {
      printf("白色贏了 %d : %d" , score1 , score2);
    }
    if(score1 < score2)
    {
      printf("黑色贏了 %d : %d" , score2 , score1);
    }
    if(score1 == score2)
    {
      printf("平手 %d : %d" , score1 , score2);
    }
    return 0;
}