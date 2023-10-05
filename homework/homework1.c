
#include <stdio.h>

int main()
{

int X = 1;
int D = 1;
int XD = 1;

for(int i = 1; i < 10; i ++)
{
    D = 1;
    X = i;
 
    XD = X*D;
    printf("%d * %d = %d\n",X ,D ,XD);
    D++;
    XD = X*D;
    printf("%d * %d = %d\n",X ,D ,XD);   
    D++;
    XD = X*D;
    printf("%d * %d = %d\n",X ,D ,XD);
    D++;
    XD = X*D;
    printf("%d * %d = %d\n",X ,D ,XD);  
    D++;
    XD = X*D;
    printf("%d * %d = %d\n",X ,D ,XD);   
    D++;
    XD = X*D;
    printf("%d * %d = %d\n",X ,D ,XD);
    D++;
    XD = X*D;
    printf("%d * %d = %d\n",X ,D ,XD);
    D++;
    XD = X*D;
    printf("%d * %d = %d\n",X ,D ,XD);
    D++;
    XD = X*D;
    printf("%d * %d = %d\n",X ,D ,XD);

}
return 0;
}
