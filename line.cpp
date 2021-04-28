#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

/* Defining structure for end point of line */
typedef struct coordinate
{
int x,y;
char code[4];
}pt;
void drawwindow();
void drawline(pt p1,pt p2,int c1);
pt setcode(pt p);
int visibility(pt p1,pt p2);
pt resetendpt(pt p1,pt p2);

main()
{
int gd=DETECT,gm,v;
pt p1,p2,ptemp;
initgraph(&gd,&gm,"");
cleardevice();
printf("\n\n\tEnter End point 1 (x,y): ");
scanf("%d %d",&p1.x,&p1.y);
printf("\n\n\tEnter End point 2 (x,y):");
scanf("%d %d",&p2.x,&p2.y);
cleardevice();
drawwindow();
getch();
drawline(p1,p2,15);
getch();
p1=setcode(p1);
p2=setcode(p2);
v=visibility(p1,p2);
switch(v)
{
 case 0:cleardevice();
            drawwindow();
            drawline(p1,p2,15);
            break;
 case 1: cleardevice();
             drawwindow();
             break;
 case 2: cleardevice();
             p1=resetendpt(p1,p2);
             p2=resetendpt(p2,p1);
             drawwindow();
             drawline(p1,p2,15);
             break;
}
getch();
closegraph();
return(0);
}

/* function to draw window*/
void drawwindow()
{
 setcolor(RED);
 line(150,100,450,100);
 line(450,100,450,350);
 line(450,350,150,350);
 line(150,350,150,100);
 }

 /*function to draw line between two points*/
 void drawline(pt p1,pt p2,int c1)
 {
 setcolor(c1);
 line(p1.x,p1.y,p2.x,p2.y);
 }

 /*function to set code of the coordinate*/
 pt setcode(pt p)
 {
 pt ptemp;

 if(p.y<100)
 ptemp.code[0]='1'; //top
 else
  ptemp.code[0]='0';
 if(p.y>350)

 ptemp.code[1]='1'; //bottom
 else
  ptemp.code[1]='0';

  if(p.x>450)
 ptemp.code[2]='1'; //right
 else
  ptemp.code[2]='0';

  if(p.x<150)
 ptemp.code[3]='1'; //left
 else
  ptemp.code[3]='0';

   ptemp.x = p.x;
   ptemp.y=p.y;
   return(ptemp);
   }

   /*function to determine visibillity of line*/
   int visibility(pt p1,pt p2)
   {
   int i,flag=0;
   for(i=0;i<4;i++)
   {
   if((p1.code[i]!='0')||(p2.code[i]!='0'))
   flag=1;
   }
   if(flag==0)
   return(0);
   for(i=0;i<4;i++)
   {
   if((p1.code[i]==p2.code[i])&&(p1.code[i]=='1'))
   flag=0;
   }

   if(flag==0)
   return(1);
   return(2);
   }

   /*function to find new end points*/
pt resetendpt(pt p1,pt p2)
   {
   pt temp;
   int x,y,i;
   float m,k;
   if(p1.code[3]=='1')
   x=150;
   if(p1.code[2]=='1')
   x=450;
   if((p1.code[3]=='1')||(p1.code[2]=='1'))
   {
   m=(float)((p2.y-p1.y)/(p2.x-p1.x));
   k=(p1.y+(m*(x-p1.x)));
   temp.y=k;
   temp.x=x;
   for(i=0;i<4;i++)
   temp.code[i]=p1.code[i];
   if(temp.y<=350 && temp.y >=100)
   return(temp);
   }
  if(p1.code[0]=='1')  /*cutting top edge*/
   y=100;
   if(p1.code[1]=='1')  /*cutting bottom edge*/
   y=350;
    if((p1.code[0]=='1')||(p1.code[1]=='1'))
   {
     m=(float)(p2.y-p1.y)/(p2.x-p1.x);
     k=(float)p1.x+(float)(y-p1.y)/m;
     temp.x=k;
     temp.y=y;
     for(i=0;i<4;i++)
     temp.code[i]=p1.code[i];
     return(temp);
     }
     else
     return(p1);
     }

