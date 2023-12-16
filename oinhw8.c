#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define mapx 10

#define mapy 10

int map[mapx][mapy] = {  
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
  { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

int stack[1000][2] = {};
int top = -1;

int footage[1000][2] = {};
int ftop = -1;

int out = 0;

int fake[mapx][mapy];
int step[mapx][mapy];

int ansx;
int ansy;

void find()
{   

    int x = 0 ;
    int y = 0 ;

    if(x == ansx && y == ansy)out = 1;



    x = stack[top][0];
    y = stack[top][1];
    top--;

    if((x-1) >= 0) 
    {
        if(fake[x-1][y] == 0)
        {
            fake[x-1][y] = 2;
            stack[top][0] = x-1 ;
            stack[top][1] = y ;
            top++;
        }
    }
    if((x+1) < mapx) 
    {
        if(fake[x+1][y] == 0)
        {
            fake[x+1][y] = 4;
            stack[top][0] = x+1 ;
            stack[top][1] = y ;
            top++;
        }
    }
    if((y+1) < mapy) 
    {
        if(fake[x][y+1] == 0)
        {
            fake[x][y+1] = 1;
            stack[top][0] = x ;
            stack[top][1] = y-1 ;
            top++;
        }
    }
    if((y-1) >= 0) 
    {
        if(fake[x][y-1] == 0)
        {
            fake[x][y-1] = 3;
            stack[top][0] = x ;
            stack[top][1] = y+1 ;
            top++;
        }
    }

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
    }
}

void printstep(int ansx , int ansy,int qx , int qy)
{
    int gx = ansx;
    int gy = ansy;

    while((gx!=qx)&&(gy!=qy))
    {
        step[gx][gy] = 2;
        if(fake[gx][gy] == 1)
        {
            gx = gx;
            gy = gy-1;
        }
        else if(fake[gx][gy] == 2)
        {
            gx = gx+1;
            gy = gy;
        }
        else if(fake[gx][gy] == 3)
        {
            gx = gx;
            gy = gy+1;
        }
        else if(fake[gx][gy] == 4)
        {
            gx = gx-1;
            gy = gy;
        }

    }
    step[gx][gy] = 2;

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
    
    ansx = 6;
    ansy = 9;

    int qx = 1;
    int qy = 0;

    check(qx, qy);
    if(out == 1)
    {
        printstep(ansx , ansy,qx,qy);
        printf("yes");
    }
    if(out != 1)
    {
        printf("no");
    }

    return 0;
}




