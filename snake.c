
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int width=20,height=20,gameOver;
int x,y,fruitX,fruitY,score,flag;
int tailX[100], tailY[100];  // array for tails of snake after eating food
int CountTail=0;
void setup()
{
    gameOver=0;    //make this one when game get over
    x=width/2;     //initially x cordinate of snake
    y=height/2;     //initially y cord  of snake
    
    label1:
    fruitX=rand()%20;  //x codinate of fruit will be less then 20 (in the square)
    if(fruitX==0)      //if fruit is on boundry
       goto label1;
       
     
    label2:
    fruitY=rand()%20;  //y codinate of fruit will be less then 20 (in the square)
    if(fruitY==0)          //if fruit is on boundry
       goto label2;
       
       score=0;
    
}
void draw()
{
    int i,j,k;
    system("cls");
    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
            if(i==0||i==height-1||j==0||j==width-1)
            {
                printf("*");
            }
            else{
                if(i==x && j==y)             //x and y are coordinates of snake
                printf("O");
                else if(i==fruitX&&j==fruitY)  //fX and fY are coordinates of fruit
                printf("F");
                else
                {
                    int d=0;
                    for(k=0;k<CountTail;k++)  //Printing increasing snake 
                    {
                        if(i==tailX[k] && j==tailY[k]) //i and j ki uss value pe print krao jaha  array k element ki value match kre 
                        {
                                    printf("o");
                                    d=1;
                        }
                    }
                    if(d==0)
               printf(" "); 
                }
               
            }
        }
        printf("\n");
    }

    printf("SCORE=%d",score);
}// end of draw function


void input()
{
    if(kbhit())
    {
        switch(getch())  // our ch input pressed is catched
        {
            case 'a':          //aswz
                 flag=1;
                 break;
            case  'd':
                  flag=2;
                  break;
             case  'w':
                  flag=3;
                  break;
              case  's':
                  flag=4;
                  break;
             case 'x':
                   gameOver=1;
                   break;
           
        }
    }
}

void MakeLogic()
{
    // https://youtu.be/ON5ODiA-AQE
      // SHIFTING FOOD AS A BODY SIZE OF (O) LEFT TO RIGHT SO THAT SIZE INCREASE

     int prevX=tailX[0]; //initialy we stored index of 0 position of  'O(snake)'  is stored   beacause we want shifting      
     int prevY=tailY[0];   
     int prev2X;
     int prev2Y;
     tailX[0]=x;  //at this position we are adding x y coordinates of new snake because each tim x and y coordinates is increasing 
     tailY[0]=y;
    
     int i;
     for(i=1;i<CountTail;i++) // till counttails(tails now we have) you are shifting snake part to next 
   {
       // while shifting  we have also store second position body because when we shift x1y1 body to x2y2 ,x2y2 will overright so store it
       prev2X=tailX[i]; //so i is 1 means second one is stored so that we can store x1y1 to x2y2 part
       prev2Y=tailY[i];
       tailX[i]=prevX; // adding previous value to currunt index (shifting)
       tailY[i]=prevY;

       prevX=prev2X;  //abhi wali value add ki prevx mai so that neext time we get latest for shifting
       prevY=prev2Y;
   }

   // NOW GO TO DRAW FUNCTION FOR PRINTING IN ELSE PART OF FREE SPACE

  //NOTE X AND Y ARE HEAD QUARDINATES OF SNAKE

    switch(flag)
  {
      case 1:
           y--;    // user wants to go left side
           break;
      case 2:
           y++;    // user wants to go left side
           break;
      case 3:
           x--;      //up
           break;
      case 4:
           x++;      //down
           break;
      default:
           break;
      
  }
  if(x<0||x>width||y<0||y>height) // NEW FOOD GENERATED EACH TIME AND PREV WILL HIDE DUE TO CLS
  {
      gameOver=1;    //when snake head strikes boundries then gameover=1 means !1 = 0 ,,while(0) loop stops 
      
  }
   for(i=0;i<CountTail;i++)
   {
       if(x==tailX[i]&& y==tailY[i])
       {
           gameOver=1;
       }
   }

     if(x==fruitX && y==fruitY)
     {
         label3:
    fruitX=rand()%20;  //x codinate of fruit will be less then 20 (in the square)
    if(fruitX==0)      //if fruit is on boundry
       goto label3;
       
     
    label4:
    fruitY=rand()%20;  //y codinate of fruit will be less then 20 (in the square)
    if(fruitY==0)         //if fruit is on boundry
       goto label4;  
     
      
     score+=10;  //eating each time score is increasing
    CountTail++;    //it counts how many times eat food and size
     }
  
}
int main()
{
    char c;
    label5:

   setup();   // values setup
   
   
   while(!gameOver)   //infinite loop because after input screen closed we want that forever
   {      // initially gameover is 0 so negation of 0 is 1 no prob but if (gameover =1) negation of which is 0 then loop stops
    draw();   // layout
    input();   //keboard hit
    MakeLogic(); //what to heappen
    int i;
    int j;

   for(i=0;i<1000;i++)  //empty for loop it takes time to execute and make our steps slow
   {
       for(j=0;j<10000;j++)
       {

       }
   }

  for(i=0;i<100;i++)  //empty for loop it takes time to execute and make our steps slow
   {
       for(j=0;j<1000;j++)
       {

       }
   }

   }
   
   printf("\nPress Y to continue again:");
   scanf("%c",&c);
   if(c=='y'||c=='Y')
   {
       goto label5;
   }

   
   
    return 0;
}
