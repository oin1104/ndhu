#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define mapx 10

#define mapy 10


//ㄚㄚㄚㄚ阿 ㄚㄚㄚㄚㄚㄚㄚㄚ ㄚㄚㄚ哀哀阿˙˙ 啊 啊 阿

int map[mapx][mapy] = {  
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
  { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 1, 0, 1, 0, 0, 1 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

int stack[1000][2] = {};
int top = -1;

int out = 0;

int fake[mapx][mapy];
int step[mapx][mapy];

int ansi=-1;
int ansj=-1;

void find()
{   

    int x = 0 ;
    int y = 0 ;

    x = stack[top][0];
    y = stack[top][1];
    
    if(x == ansi && y == ansj)out = 1;
    
    top--;

    if((x-1) >= 0) 
    {
        if(fake[x-1][y] == 0)
        {
            fake[x-1][y] = 8;
            top++;
            stack[top][0] = x-1 ;
            stack[top][1] = y ;
        }
    }
    if((x+1) < mapx) 
    {
        if(fake[x+1][y] == 0)
        {
            fake[x+1][y] = 2;
            top++;
            stack[top][0] = x+1 ;
            stack[top][1] = y ;

        }
    }
    if((y+1) < mapy) 
    {
        if(fake[x][y+1] == 0)
        {
            fake[x][y+1] = 6;
            top++;
            stack[top][0] = x ;
            stack[top][1] = y+1 ;

        }
    }
    if((y-1) >= 0) 
    {
        if(fake[x][y-1] == 0)
        {
            fake[x][y-1] = 4;
            top++;
            stack[top][0] = x ;
            stack[top][1] = y-1 ;

        }
    }
    return;
}

void check(int i , int j)
{

    if(fake[i][j] == 1)return;
    else if(fake[i][j] == 0)
    {
        top ++;
        stack[top][0] = i ;
        stack[top][1] = j ;
        fake[i][j] = -1;
        while(top != -1)
        {
            find(); 
        }
        return;
    }
}

void printstep(int ansx , int ansy,int qx , int qy)
{
    int gx = ansx;
    int gy = ansy;
    step[gx][gy] = 2;

    while( (gx!=qx) || (gy!=qy ) )
    {
        
        if(fake[gx][gy] == 6)
        {
            gx = gx;
            gy = gy-1;
            step[gx][gy] = 2;
        }
        else if(fake[gx][gy] == 8)
        {
            gx = gx+1;
            gy = gy;
            step[gx][gy] = 2;
        }
        else if(fake[gx][gy] == 4)
        {
            gx = gx;
            gy = gy+1;
            step[gx][gy] = 2;
        }
        else if(fake[gx][gy] == 2)
        {
            gx = gx-1;
            gy = gy;
            step[gx][gy] = 2;
        }

    }
    
    step[qx][qy] = 2;

    for(int i = 0 ; i < mapx ; i++)
    {
        for(int j = 0 ; j <mapy ; j++)
        {
            printf("%d ",step[i][j]);
        }
        printf("\n");
    } 

}




int main(void) 
{

    memcpy(fake,map,sizeof(map));
    memcpy(step,map,sizeof(map));
    
    ansi = 6;
    ansj = 9;

    int qi = 1;
    int qj = 0;

    check(qi, qj);
    
    if(out == 1)
    {
        printstep(ansi , ansj,qi,qj);
        printf("yes\n");
    }
    else if(out != 1)
    {
        printf("no\n");
    }
    for(int i = 0 ; i < mapx ; i++)
    {
        for(int j = 0 ; j <mapy ; j++)
        {
            printf("%d ",fake[i][j]);
        }
        printf("\n");
    } 

    return 0;
}


