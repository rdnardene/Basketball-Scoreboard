#include<reg51.h>
#include<stdio.h>
#define msec 1

sbit s1=P3^2;
sbit s2=P3^3;
sbit s3=P3^4;
sbit s4=P3^5;


sbit TF=P3^0;
sbit TIMEOUT=P3^1;



unsigned int v1,v2,v3;

unsigned int VALUE[10]={0x40,0xF9,0x24,0x30,0x19,0X88,0x88};




void delay(unsigned int count)
{
unsigned int j,k;
for (j=0;j<=count;j++);
for (k=0;k<=50;k++);
}




void main()
{
P1 =0x40;
v1 = v2 = v3= 0;
s1 = s2 = s3=1;
while(1)
{
if (s1==0)
{
while (s1 == 0);
{
v1 = v1 + 1;
if(v1==6)
v1=0;
}
TF = 1;
TIMEOUT =  0;
P1 = VALUE[v1];
}


delay(msec);
if (s2==0)
{
while (s2 == 0);
{v2 = v2 + 5;
if(v2==5)
P1 = VALUE[v2];
v2=0;
TIMEOUT = 1;
TF = 0;



delay(msec);

}

} 
if (s3==0)
{
while (s3 == 0);
{v3 = v3 + 6;
if(v3==6)
P1 = VALUE[v3];
v3=0;
TIMEOUT = 1;
TF = 0;



delay(msec);

}

}

if (s4==0)
{
while (s4 == 0);
{
TIMEOUT = 0;
TF = 1;




delay(msec);

}

}
}
}