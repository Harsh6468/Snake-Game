#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>

void line_hor(int column1, int column2, int row, char c);
void line_ver(int row1, int row2, int column, char c);
void box(int column1, int row1, int column2, int row2, char c);
void game();
void food();
void snake();
void welcomescr();
void menu();
void setup();
void level();
void HighScore();
void option(int y, char str[]);
void toggle(int y, int y1, char str[], char str1[]);
void end(int y);

char *str[4]={"NEW GAME","LEVEL","HIGH SCORE","QUIT"};
int foodx,foody;
int x,y,boxWidth = 80,boxLength = 22;
int mx=0,my=0,pause;
int score,length,speed=300;
int tailx[100],taily[100];

void main()
{
  textbackground(0);
  clrscr();
  welcomescr();
  menu();
}
void setup()
{
  x=20;
  y=10;
  mx=0;
  my=0;
  score=0;
  length=0;
}
void line_hor(int column1, int column2, int row, char c)
{
  for(column1;column1<=column2;column1++)
  {
    gotoxy(column1,row) ;
    cprintf("%c",c);
  }
}
void line_ver(int row1, int row2, int column, char c)
{
  for ( row1; row1<=row2; row1++ )
  {
    gotoxy(column,row1) ;
    cprintf("%c",c);
  }
}
void box(int column1, int row1, int column2, int row2, char c)
{
  char ch=218 ;
  char c1, c2, c3, c4 ;
  char l1=196, l2=179 ;
  if (c == ch)
  {
    c1 = 218;
    c2 = 191;
    c3 = 192;
    c4 = 217;
  }
  else
  {
    c1=c;
    c2=c;
    c3=c;
    c4=c;
    l1=c;
    l2=c;
  }
  gotoxy(column1,row1) ;
  cprintf("%c",c1);
  gotoxy(column2,row1) ;
  cprintf("%c",c2);
  gotoxy(column1,row2) ;
  cprintf("%c",c3);
  gotoxy(column2,row2) ;
  cprintf("%c",c4);
  column1++ ;
  column2-- ;
  line_hor(column1,column2,row1,l1) ;
  line_hor(column1,column2,row2,l1) ;
  column1-- ;
  column2++ ;
  row1++ ;
  row2-- ;
  line_ver(row1,row2,column1,l2) ;
  line_ver(row1,row2,column2,l2) ;
}
void level()
{
   int gd=DETECT,gm=DETECT,i,a,opt=1;
   initgraph(&gd,&gm,"..\\bgi");
   char *str1[4]={"EASY","NORMAL","HARD","VER HARD"},ch;
   setfillstyle(1,9);
   floodfill(1,1,9);
   setcolor(15);
   settextstyle(8,0,6);
   outtextxy(239,20,"LEVEL");
   rectangle(0,25,640,24);
   rectangle(680,100,0,101);
   settextstyle(8,1,6);
   outtextxy(40,160,"LEVEL");
   outtextxy(500,160,"LEVEL");
   option(130,str1[0]);
   option(210,str1[1]);
   option(290,str1[2]);
   option(370,str1[3]);
    setcolor(7);
    rectangle(220,50+(opt*80),420,100+(opt*80));
    setfillstyle(1,7);
    floodfill(225,(opt*80)+55,7);
    setcolor(15);
    outtextxy(255,(opt*80)+58,str1[opt-1]);
  while(1)
  {
    if(kbhit)
    {
       ch = getch();
       switch(ch)
       {
	  case 72:
	  case 75: a = -1;
	  break;
	  case 'w':
	  case 'W':
	  case 'A':
	  case 'a': a = -1;
	  break;
	  case 77:
	  case 80: a = 1;
	  break;
	  case 's':
	  case 'S':
	  case 'd':
	  case 'D': a = 1;
	  break;
	  case 13: a = 13;
	  break;
       }        //end switch   statement
       if(opt == 1 && a == -1)
       {
	  toggle(130,370,str1[0],str1[3]);
	  opt = 4;
       }
       else if(opt == 4 && a == 1)
       {
	  toggle(370,130,str1[3],str1[0]);
	  opt = 1;
       }
       else if(a == -1)
       {
	  toggle(50+(80*opt),(80*opt)-30,str1[opt-1],str1[opt-2]);
	  opt--;
       }
       else if(a == 1)
       {
	  toggle(50+(80*opt),130+(80*opt),str1[opt-1],str1[opt]);
	  opt++;
       }
       else if(a == 13)
       {
	  switch(opt)
	  {
	   case 1: speed = 400;
	   break;
	   case 2: speed = 300;
	   break;
	   case 3: speed = 200;
	   break;
	   case 4: speed = 100;
	  }
	  break;
       } a=0;
    }
  }
}
void welcomescr()
{
    int gd=DETECT,gm=DETECT,i,a;
    initgraph(&gd,&gm,"..\\bgi");
    settextstyle(3,0,5);
    outtextxy(190,100,"Snake Game");
    rectangle(140,400,500,420);
    setcolor(2);
    setfillstyle(SOLID_FILL,2);
    line(141,400,141,420);
    ellipse(140,410,-90,90,9,9);
    floodfill(142,410,2);
    gotoxy(33,24);
    printf("Loading... %d%",0);
    delay(1000);
    for(i=0;i<351;i++)
    {
      gotoxy(43,24);
      printf(" %3.0f%",i/3.5);
      setcolor(2);
      circle(142+i,407,1);
      setcolor(15);
      circle(143+i,407,1);
      setcolor(2);
      circle(142+i,413,1);
      setcolor(15);
      circle(143+i,413,1);
      setcolor(2);
      ellipse(140+i,410,-90,90,9,9);
      delay(20);
    }
    settextstyle(0,0,1);
    a=0;
    gotoxy(33,24);
    printf("   Completed        ");
    while(1)
    {
      delay(400);
      if(a == 0)
	 a=11;
      else
	a=0;
      setcolor(a);
      settextstyle(8,0,3);
      outtextxy(150,300,"Press Any key to continue...");
      if(kbhit())
	break;
    }
    getch();
    closegraph();
}
void menu()
{
    int gd=DETECT,gm=DETECT,i,a;
    initgraph(&gd,&gm,"..\\bgi");
    FILE *f;
    int sco,opt=1;
    setfillstyle(1,9);
    floodfill(1,1,9);
    for(i = 1; i<=540; i++)
    {
	setcolor(9);
	settextstyle(8,0,6);
	outtextxy(-401+i,20,"SNAKE GAME");
	setcolor(15);
	settextstyle(8,0,6);
	outtextxy(-400+i,20,"SNAKE GAME");
	rectangle(0,25,(i * 1.2),24);
	rectangle(680,100,620 - (i*1.2),101);
	if(i<278)
	  sound(2*i);
	else
	  sound(2*(566-i));
	delay(3);
    }
    nosound();
    while(1)
    {
       setfillstyle(1,9);
       floodfill(1,1,9);
       setcolor(9);
       settextstyle(8,0,6);
       outtextxy(138,20,"SNAKE GAME");
       setcolor(15);
	settextstyle(8,0,6);
       outtextxy(139,20,"SNAKE GAME");
       rectangle(0,25,640,24);
       rectangle(680,100,0,101);
       settextstyle(8,1,6);
       outtextxy(40,160,"OPTIONS");
       outtextxy(500,160,"OPTIONS");
       option(130,str[0]);
       option(210,str[1]);
       option(290,str[2]);
       option(370,str[3]);
       if(opt == 1 || opt == 3 || opt == 2)
       {
	 setcolor(7);
	 rectangle(220,50+(opt*80),420,100+(opt*80));
	 setfillstyle(1,7);
	 floodfill(225,(opt*80)+55,7);
	 setcolor(15);
	 outtextxy(255,(opt*80)+58,str[opt-1]);
       }
    if(kbhit)
       {
	   switch(getch())
	   {
	      case 72:
	      case 75: a = -1;
	      break;
	      case 'w':
	      case 'W':
	      case 'A':
	      case 'a': a = -1;
	      break;
	      case 77:
	      case 80: a = 1;
	      break;
	      case 's':
	      case 'S':
	      case 'd':
	      case 'D': a = 1;
	      break;
	      case 13: a = 13;
	      break;
	   }        //end switch   statement
	   if(opt == 1 && a == -1)
	   {
	      toggle(130,370,str[0],str[3]);
	      opt = 4;
	   }
	   else if(opt == 4 && a == 1)
	   {
	      toggle(370,130,str[3],str[0]);
	      opt = 1;
	   }
	   else if(a == -1)
	   {
	      toggle(50+(80*opt),(80*opt)-30,str[opt-1],str[opt-2]);
	      opt--;
	   }
	   else if(a == 1)
	   {
	      toggle(50+(80*opt),130+(80*opt),str[opt-1],str[opt]);
	      opt++;
	   }
	   else if(a == 13)
	   {
	      switch(opt)
	      {
		   case 1: closegraph();
			   game();
			   initgraph(&gd,&gm,"..\\bgi");
		   break;
		   case 2: level();cleardevice();
		   break;
		   case 3:HighScore();cleardevice();
		   break;
		   case 4: end(50+(80*opt)); exit(0);
	      }
	   } a=0;
       }
    f=fopen("HIGHSCORE.DAT","r");
    sco=getw(f);
    fclose(f);
    if(sco<score)
    {
      f=fopen("HIGHSCORE.DAT","w");
      putw(score,f);
      fclose(f);
    }//if close
  }//infinte while close
}
void game()
{
  int i,sx = 0,sy = 0,Gover=0,flag;
  char ch;
  setup();
  label1:
  time_t t;
  srand((unsigned)time(&t));
  foodx = rand() % (boxWidth - 1);
  if(foodx==0 || foodx==1)
    goto label1;
  label2:
  foody = rand() % (boxLength - 2);
  if(foody==0 || foody==1)
    goto label2;
  box(1,1,boxWidth,boxLength,218);
  char temp;
  while(1)
  {
    if(kbhit())
    {
      temp = getch();
      if(temp == 0)
	 ch = getch();
      if(ch == 72 || temp == 'w' || temp == 'W')
	  ch = 'w';
      else if(ch == 75 || temp == 'a' || temp == 'A')
	  ch = 'a';
      else if(ch == 77 || temp == 'd' || temp == 'D')
	  ch = 'd';
      else if(ch == 80 || temp == 's' || temp == 'S')
	  ch = 's';
      else if(temp == 27)
	  ch = 27;

      switch(ch)
      {
	case 'a':
	case 'A': sx = mx = -1; sy = my = 0; pause=0;
	break;
	case 's':
	case 'S': sy = my = 1; sx = mx = 0; pause=0;
	break;
	case 'd':
	case 'D': sx = mx = 1; sy = my = 0; pause=0;
	break;
	case 'w':
	case 'W': sy = my = -1; sx = mx = 0; pause=0;
	break;
	case 'p':
	case ' ': mx = 0; my = 0;
		  if(pause == 1)
		  {
		     pause = 0;
		     mx = sx;
		     my = sy;
		  }
		  else
		     pause = 1;
	break;
	case 27:
	case 'q':
	case 'Q': flag = 1;
      }
    }
    ch = '\0';
    snake();
    food();
    textcolor(11);
    box(10,23,75,25,218);
    gotoxy(15,24);
    textcolor(7);
    cprintf("Score = %d",score);
    gotoxy(51,24);
    cprintf("Status = ");
    delay(speed);
    if(x==1 || x==boxWidth || y==1 || y==boxLength)
    {
      gotoxy(60,24);
      cprintf("Game Over.");
      getch();
      break;
    }
    for(i=1;i<=length;i++)
    {
      if(x==tailx[i]&&y==taily[i])
      {
	Gover=1;
	break;
      }
    }
    if(Gover==1 || flag == 1)
    {
      if(Gover == 1)
      {
	 gotoxy(60,24);
	 cprintf("Game Over.");
	 getch();
      }
      break;
    }
  }
}
void snake()
{
  int i,prevx,prev1x,prevy,prev1y;
  x += mx;
  y += my;
  gotoxy(x,y);
  printf("%c",4);
  prevx=tailx[0];
  prevy=taily[0];
  tailx[0]=x;
  taily[0]=y;
  for(i=1;i<=length+1;i++)
  {
    if(pause==0)
    {
      prev1x=tailx[i];
      prev1y=taily[i];
      tailx[i]=prevx;
      taily[i]=prevy;
      prevx=prev1x;
      prevy=prev1y;
      gotoxy(60,24);
      printf("Playing ");
    }
    else
    {
      gotoxy(60,24);
      textcolor(14);
      cprintf("Pause      ");
    }
    if(i == (length+1))
    {
       gotoxy(tailx[i],taily[i]);
       printf("%c",32);
    }
    else
    {
       gotoxy(tailx[i],taily[i]);
       printf("%c",4);
    }
  }
}
void food()
{
  int i;
  if(x==foodx && y==foody)
  {
    for(i=650;i>120;i-=10)
    {
      sound(i);delay(1);
    }
    nosound();
    label1:
    time_t t;
    srand((unsigned)time(&t));
    foodx = rand() % 40;
    if(foodx==0 || foodx==1)
      goto label1;
    label2:
    foody = rand() % 20;
    if(foody==0 || foody==1)
      goto label2;
    for(i=0;i<=length;i++)
    {
      if(foodx==tailx[i]&&foody==taily[i])
	goto label1;
    }
    length++;
    score++;
  }
  gotoxy(foodx,foody);
  textcolor(2);
  cprintf("%c",3);textcolor(7);
}
void HighScore()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"..\\bgi");
  FILE *f;
  int sco;
  char sc[50];
  cleardevice();
  setcolor(9);
  setfillstyle(1,9);
  floodfill(1,1,9);
  f=fopen("HIGHSCORE.DAT","r");
  sco = getw(f);
  sprintf(sc,"HIGHEST SCORE IS %d",sco);
  setcolor(0);
  rectangle(118,128,119,182);
  rectangle(120,128,520,129);
  setcolor(15);
  rectangle(521,128,522,182);
  rectangle(120,181,520,182);
  settextstyle(8,0,3);
  outtextxy(180,138,sc);
  fclose(f);
  getch();
}

void option(int y, char str[])
{
    setcolor(0);
    rectangle(218,y-2,219,52+y);
    rectangle(220,y-2,420,y-1);
    setcolor(15);
    rectangle(421,y-2,422,y+52);
    rectangle(220,y+51,420,y+52);
    settextstyle(8,0,3);
    outtextxy(255,y+8,str);
}
void toggle(int y, int y1, char str[], char str1[])
{
    setcolor(9);
    rectangle(220,y,420,y+50);
    setfillstyle(1,9);
    floodfill(225,y+5,9);
    setcolor(15);
    outtextxy(255,y+8,str);
    setcolor(7);
    rectangle(220,y1,420,y1+50);
    setfillstyle(1,7);
    floodfill(225,y1+5,7);
    setcolor(15);
    outtextxy(255,y1+8,str1);
}
void end(int y)
{
    setcolor(15);
    rectangle(218,y-2,219,52+y);
    rectangle(220,y-2,420,y-1);
    setcolor(0);
    rectangle(421,y-2,422,y+52);
    rectangle(220,y+51,420,y+52);
    delay(300);
    setcolor(0);
    rectangle(218,y-2,219,52+y);
    rectangle(220,y-2,420,y-1);
    setcolor(15);
    rectangle(421,y-2,422,y+52);
    rectangle(220,y+51,420,y+52);
    delay(300);
    setcolor(1);
    for(int i=0; i<240; i++)
    {
       rectangle(i,i,640-i,480-i);
       delay(5);
       sound((240-i)*10);
    }
    nosound();
}