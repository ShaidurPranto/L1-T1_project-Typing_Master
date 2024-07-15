//Project Typing Master\\

//phase 1 menu
//phase 2 before playing
//phase 3 main
//phase 4 end/result
//phase 5 hof/records

#include "iGraphics.h"
#include<string.h>
#include<stdio.h>

//GENERAL PARAMETERS
//screen parameters
//int screenwidth = 400, screenheight = 265;
int screenwidth = 1350, screenheight = 700;
//function prototypes
void convert(int score , char sscore[]);
void mainphase();
void resultphase();
void timecount();
void phase1();
void phase2();
void phase5();
void record();
//parameter for switching phase
int phase = 1;


//PARAMETERS FOR PHASE 3
//time for typing
int timeup=60;
//parameter for yellow box
int ymx = 250,ymy = 550;
int ybr=250,ybg=250,ybb=0;
//parameters for text on screen
int cpx[15];
int cpy[10];
char c[150][10];
//string checking
char check[150][10];
int checki = 0;
int ci = 0;
int charlength[150];
//checked box
int checkedx[150],checkedy[150];
int okay[150];
int checkedboxr[150],checkedboxg[150],checkedboxb[150];
//user text on yellow box
char yt[10];
//score board
int score = 0;
char sscore[10] = "0";
//time count
int sec = 0;
char csec[2];
int minute = 0;
char cminute[5];


//PARAMETERS FOR PHASE 4-result
//time count for showing final result
double finalminute = 0;
int intfinalscore;
char charfinalscore[30];
int wrong = 0;
int resultphasesec = 0;


//PARAMETERS FOR PHASE 2-before playing
int p2time = 0;
char playername[20];
int p2i = 0;

//PARAMETERS FOR PHASE 5-records
int p5score[7];
char p5name[7][30];
int p5hofy = 300;
int resultmenux = 1000,resultmenuy = 600,resultmenua=150,resultmenub=50;


//parameters for phase 1/menu
int menuplayx = 300,menuplayy = 400,menuplaya = 150,menuplayb = 70;
int differx=30,differy=20;
int menuhofx = menuplayx,menuhofy = menuplayy - 100;
int menuhofa = menuplaya,menuhofb=menuplayb;


int main() {
	//place your own initialization codes here.

	record();
	iSetTimer(1000,timecount);
	iInitialize(screenwidth,screenheight,"Typing Master");

    return 0;
}


void iDraw() {

	iClear();

	//apatoto




	if(phase == 1)
    {
        phase1();
    }
    if(phase == 2)
    {
        phase2();
    }
	if(phase == 3)
    {
        mainphase();
    }
    if(phase == 4)
    {
        resultphase();
    }
    if(phase == 5)
    {
        phase5();
    }
}


/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
int p1startx1 = 150,p1startx2 = p1startx1+40;
int p1starty1 = 150,p1starty2 = p1starty1+15;

int p1hofx1 = 100,p1hofx2 = p1hofx1+40;
int p1hofy1 = 70,p1hofy2 = p1hofy1+15;


void iMouse(int button, int state, int mx, int my) {

    //printf(" value of phase %d\n", phase);

    if(phase == 1)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
           if(mx>=menuplayx&&mx<=menuplayx+menuplaya&&my>=menuplayy&&my<=menuplayy+menuplayb)
           {
              phase = 2;
           }
           else if(mx>=menuhofx&&mx<=menuhofx+menuhofa&&my>=menuhofy&&my<=menuhofy+menuhofb)
            {
                phase = 5;
            }
        }

    }
    else if(phase == 5)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=resultmenux&&mx<=resultmenux+resultmenua&&my>=resultmenuy&&my<=resultmenuy+resultmenub)
           {
              phase = 1;
           }

        }
    }
    else if(phase == 4)
    {
        /*if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>=resultmenux&&mx<=resultmenux+resultmenua&&my>=resultmenuy&&my<=resultmenuy+resultmenub)
           {
              phase = 1;
           }

        }*/
    }
}


/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	//printf("Mouse x = %d, Mouse y= %d\n",mx,my);

}

//int menuplayx = 300,menuplayy = 400,menuplaya = 150,menuplayb = 70;
//int differx=30,differy=20;
//int menuhofx = menuplayx,menuhofy = menuplayy - 100;
//int menuhofa = menuplaya,menuhofb=menuplayb;



void phase1()
{
    iSetColor(66,141,245);
    iFilledRectangle(0,0,screenwidth,screenheight);
    //create start button
    iSetColor(0,0,0);
    iFilledRectangle(menuplayx,menuplayy,menuplaya,menuplayb);
    iSetColor(255,255,255);
    iText(menuplayx+differx,menuplayy+differy,"Play",GLUT_BITMAP_TIMES_ROMAN_24);
    //create hall of fame
    iSetColor(0,0,0);
    iFilledRectangle(menuhofx,menuhofy,menuhofa,menuhofb);
    iSetColor(255,255,255);
    iText(menuhofx+differx,menuhofy+differy," H O F ",GLUT_BITMAP_TIMES_ROMAN_24);
    //create quit

    //
    //char playername[30];
}

int beforex = 100,beforey = 600;
int beforenamex = 400,beforenamey = 400,beforenamea = 300,beforenameb = 150;
//int beforedifferx = 50,beforediffery = 50;
void phase2()
{
    //FILE *f = fopen("2.txt","w");

    iSetColor(108,245,66);
    iFilledRectangle(0,0,screenwidth,screenheight);
    iSetColor(255,0,0);
    iText(beforex,beforey,"The Game is about to start",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(beforex,beforey-30,"HIT THE SPACE BUTTON TO START",GLUT_BITMAP_TIMES_ROMAN_24);
    //iText(beforex,beforey-60,"Hit the space button",GLUT_BITMAP_TIMES_ROMAN_24);


    //name input
    iSetColor(255,255,255);
    iFilledRectangle(beforenamex,beforenamey,beforenamea,beforenameb);
    iSetColor(0,0,0);
    iText(beforenamex+10,beforenamey+100,"INPUT YOUR NAME",GLUT_BITMAP_TIMES_ROMAN_24);
    //show user text
    iText(beforenamex+20,beforenamey+50,playername,GLUT_BITMAP_TIMES_ROMAN_24);

    if(p2time >= 60)
    {
        phase = 3;
    }

}




void phase5()
{





    iSetColor(255,0,0);
    iFilledRectangle(0,0,screenwidth,screenheight);



    FILE *a = fopen("3.txt","r");
    FILE *b = fopen("4.txt","r");
    for(int i=0;i<7;i++)
    {
        fscanf(a,"%s ",p5name[i]);
    }
    for(int i=0;i<7;i++)
    {
        fscanf(b,"%i ", &p5score[i]);
    }

    iSetColor(0,0,0);
    iText(300,600,"SCORER NAME",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(600,600,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
    p5hofy = 500;
    for(int i=0;i<7;i++)
    {
        printf("%s %i\n",p5name[i],p5score[i]);
        iSetColor(0,0,0);
        iText(300,p5hofy,p5name[i],GLUT_BITMAP_TIMES_ROMAN_24);
        char p5temp[20];
        if(p5score[i]>0)
        {
           convert(p5score[i],p5temp);
        }

        iText(600,p5hofy,p5temp,GLUT_BITMAP_TIMES_ROMAN_24);
        p5hofy = p5hofy-50;

    }
    fclose(a);
    fclose(b);


    //creating menu button



    iSetColor(0,0,0);
    iFilledRectangle(resultmenux,resultmenuy,resultmenua,resultmenub);
    iSetColor(255,255,255);
    iText(resultmenux+20,resultmenuy+10,"Main Menu",GLUT_BITMAP_TIMES_ROMAN_24);

}

void resultphase()
{
        iSetColor(3,255,255);
        iFilledRectangle(0,0,screenwidth,screenheight);
        iSetColor(128,128,128);
        //printf("minute is %d\n", finalminute);
        intfinalscore = score/finalminute;

        convert(intfinalscore,charfinalscore);
        int accuracy = ((score*100)/ci);
        char caccuracy[10];
        convert(accuracy,caccuracy);
        //printf("%d\n%s\n", intfinalscore,charfinalscore);
        //printf("accuracy is %d\n%s\n", accuracy,caccuracy);

        iSetColor(0,0,0);
        iText(100,500,"YOUR ACCURACY IS: ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(350,500,caccuracy,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(385,500,"%",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(100,400,"YOUR SPEED IS:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(327,400,sscore,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(415,400,"WORDS PER MINUTE",GLUT_BITMAP_TIMES_ROMAN_24);

       /* char swrong[10];
        convert(wrong,swrong);
        iText(90,150,"WRONG WORDS: ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(150,150,swrong,GLUT_BITMAP_TIMES_ROMAN_24);*/

    FILE *f1 = fopen("3.txt","r");
    FILE *f2 = fopen("4.txt","r");
    char c[10][30];
    int a[10];
    for(int i=0;i<10;i++)
    {
        fscanf(f1,"%s ",c[i]);
        fscanf(f2,"%i ",&a[i]);
    }
    int n=score;
    //printf("n is %d\n", n);
    //int n=23;
    //char playername[30]="king";
    char ct[30];
    strcpy(ct,playername);
    //printf("player name is %s\n", ct);
    if(a[9]<n)
    {
        a[9] = n;
        strcpy(c[9],ct);
    }
    fclose(f1);
    fclose(f2);




    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(a[j]>a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;

                //

                char ccc[30];
                strcpy(ccc,c[j]);
                strcpy(c[j],c[i]);
                strcpy(c[i],ccc);
            }
        }
    }

    FILE *ff1 = fopen("3.txt","w");
    FILE *ff2 = fopen("4.txt","w");
    for(int i=0;i<10;i++)
    {

        fprintf(ff1,"%s ", c[i]);
        fprintf(ff2,"%i ", a[i]);
        //printf("%s\n",c[i]);
        //printf("%i\n",a[i]);
    }


    fclose(ff1);
    fclose(ff2);


        if(resultphasesec>=60)
        {
            //phase = 1;
            //resultphasesec = 0;
        }



    //menu button
    //iSetColor(0,0,0);
    //iFilledRectangle(resultmenux,resultmenuy,resultmenua,resultmenub);
    //iSetColor(255,255,255);
    //iText(resultmenux+20,resultmenuy+10,"Main Menu",GLUT_BITMAP_TIMES_ROMAN_24);

    //printf("ALLAH is almighty\n");

}

void iKeyboard(unsigned char key) {

    if(phase == 3)
    {
        if(key == ' ')
        {

           int temp;
           temp = strcmp(c[ci], check[ci]);

           if(temp == 0)
           {
               checkedboxr[ci] = 0;
               checkedboxg[ci] = 255;
               checkedboxb[ci] = 0;
               score++;

               int xscore = score;

               //printf("score is %i\n", score);
               //printf("sscore is %s\n", sscore);

               //convert(score,sscore);

               int i = 0;
               while(xscore)
               {
                   sscore[i] = xscore%10 + '0';
                   xscore = xscore/10;
                   i++;
               }
                sscore[i] = '\0';
                i--;
               int j=0;
               while(j<i)
               {
                   char c = sscore[j];
                   sscore[j] = sscore[i];
                   sscore[i] = c;
                   ++j;
                   --i;
               }



               //printf("score is %i\n", score);
               //printf("sscore is %s\n", sscore);





              // sprintf(sscore , "%i", score);
              /*int temp2 = 0;
              while(score>0)
              {
                 temp2 = temp2 + score/10 + score%10;

              }*/


        }
        else if(temp < 0 || temp > 0)
        {
            wrong++;
            checkedboxr[ci] = 255;
            checkedboxg[ci] = 0;
            checkedboxb[ci] = 0;
        }

        for(int i=0;i<checki;i++)
        {
            yt[i] = ' ';
        }


        //okay[ci] = 0;

        /*for(int j=0;j<charlength[ci];j++)
        {
            if(c[ci][j] == check[j])
            {
                okay[ci]++;
            }

        }*/




        /*if(okay[ci] != 3)
        {
            ybr = 255;
            ybg = 0;
            ybb = 0;

        }
        else if(okay[ci] == 3)
        {
            ybr = 0;
            ybg = 255;
            ybb = 0;
        }*/


        checkedx[ci] = ymx;
        checkedy[ci] = ymy;
        ci++;
        checki = 0;

        if(ymx<1200)
        {
            ymx = ymx + 70;
        }
        else if(ymy>100)
        {
            ymy = ymy - 50;
            ymx = 250;
        }
        else
        {
            ymx = 250;
            ymy = 1300;
        }

    }
        else if((key>='a' && key<='z') || (key>='A' && key<='Z'))
       {
            check[ci][checki] = key ;
            yt[checki] = key ;
            checki++;
       }
    }



    //for any other phase if this function is needed continue below

    if(phase == 2)
    {
        if((key>='a' && key <= 'z')||(key>='A' && key <= 'Z'))
        {
            playername[p2i] = key;
            p2i++;
        }
        else if(key == ' ')
        {
            phase = 3;
            //p2i=0;
        }

    }


}

void convert(int score , char sscore[])
{
    int i = 0;
    while(score)
    {
        sscore[i] = score%10 + '0';
        score = score/10;
        i++;
    }
    sscore[i] = '\0';
    i--;
    int j=0;
    while(j<i)
    {
        char c = sscore[j];
        sscore[j] = sscore[i];
        sscore[i] = c;
        ++j;
        --i;
    }
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}

	/*if(phase == 3)
    {
        if(key == GLUT_KEY_DOWN)
        {
           if(ymy>50)
           {
              ymy = ymy - 20;
           }
        }
        else if(key == GLUT_KEY_UP)
        {
	       if(ymy<230)
           {
              ymy = ymy + 20;
           }

	    }
	    else if(key == GLUT_KEY_RIGHT)
        {
           if(ymx<330)
           {
              ymx = ymx + 20;
           }

       }
       else if(key == GLUT_KEY_LEFT)
       {
          if(ymx>50)
          {
              ymx = ymx - 20;
          }

       }*/

}


void mainphase()
{

    //background
    //iShowBMP(0,0,"5.bmp");

    iSetColor(67,132,145);
    iFilledRectangle(0,0,screenwidth,screenheight);



	//rectangle white box
	iSetColor(255,255,255);
	//50,50,300,300
	iFilledRectangle(250,100,1050,500);

	//line daw
	iSetColor(10,10,10);

	//vertical line draw
	for(int ly1=150;ly1<600;ly1=ly1+50)
    {

        iLine(250,ly1,1300,ly1);
    }
    //horizontal line draw
    for(int i=320;i<1300;i=i+70)
    {
        iLine(i,100,i,600);
    }


    //yellow box
    iSetColor(ybr,ybg,ybb);
    iFilledRectangle(ymx,ymy,68,48);



    //text on screen
    iSetColor(0,0,0);
    int tdx=0,tdy=0;

    for(int i=0;i<15;i++)
    {
    cpx[i]=250 + tdx+5;
    tdx = tdx + 70;
    }

    for(int i=0;i<10;i++)
    {
    cpy[i] = 550 - tdy + 7;
    tdy = tdy + 50;
    }

    iSetColor(0,0,0);

    FILE *mf = fopen("1.txt", "r");
    //taking string from file to c
    for(int i=0;i<150;i++)
    {
        fscanf(mf,"%s " ,c[i]);
    }
    //length of each string
    for(int i=0;i<150;i++)
    {
        charlength[ci] = strlen(c[ci]);
    }
    //showing text
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<15;j++)
        {
            iText(cpx[j],cpy[i],c[i*15+j],GLUT_BITMAP_HELVETICA_18);
        }
    }


    //permanent colour
    /*for(int i=0;i<= ci;i++)
    {
        if(okay[ci] != charlength[ci])
        {
            iSetColor(255,0,0);
            iFilledRectangle(checkedx[i],checkedy[i],19,19);
        }
        else if(okay[ci] == charlength[ci])
        {
            iSetColor(0,255,0);
            iFilledRectangle(checkedx[i],checkedy[i],19,19);

        }
    }*/
    //permanent colour
    for(int i=0;i<ci;i++)
    {
        iSetColor(checkedboxr[i],checkedboxg[i],checkedboxb[i]);
        iFilledRectangle(checkedx[i],checkedy[i],68,49);
    }


    //user text on screen
    iSetColor(3,161,252);
    for(int i=0;i<checki;i++)
    {
        iText(ymx+5,ymy+30,yt,GLUT_BITMAP_HELVETICA_18);
    }

    //score on screen
    iSetColor(252,136,3);
    iFilledEllipse(120,550,70,30);
    iSetColor(0,0,0);
    //printf("score is %s\n", sscore);
    iText(90,545,"score: ",GLUT_BITMAP_HELVETICA_18);
    iText(145,545,sscore,GLUT_BITMAP_HELVETICA_18);



    //showing text
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<15;j++)
        {
            iText(cpx[j],cpy[i],c[i*15+j],GLUT_BITMAP_HELVETICA_18);
        }
    }

    //showing time

    iSetColor(0,0,0);
    iText(70,493,"Time Passed",GLUT_BITMAP_HELVETICA_18);

    iSetColor(252,136,3);
    iFilledEllipse(120,450,70,30);
    iSetColor(0,0,0);

    iText(90,450,cminute,GLUT_BITMAP_HELVETICA_18);
    iText(100,450,":",GLUT_BITMAP_HELVETICA_18);
    iText(110,450,csec,GLUT_BITMAP_HELVETICA_18);


    //phase switching
    if(ci>=150 || (minute*60+sec)>=timeup)
    {
        phase = 4;
    }


}

void timecount()
{
    if(phase == 3)
    {
        sec = sec + 1;
        finalminute = finalminute + 1/60;
        if(sec == 60)
        {
           sec = 1;
           minute = minute + 1;
        }

        //converting int sec into char sec

        int temp = sec;
        int ij = 0;
        while(temp)
        {
           csec[ij] = temp%10 + '0';
           temp = temp/10;
           ij++;
        }
        csec[ij] = '\0';
        ij--;
        int ji=0;
        while(ji<ij)
        {
           char c = csec[ji];
           csec[ji] = csec[ij];
           csec[ij] = c;
           ++ji;
           --ij;
        }

        //converting int minute into char minute

        temp = minute;
        ij = 0;
        while(temp)
        {
           cminute[ij] = temp%10 + '0';
           temp = temp/10;
           ij++;
        }
        //cminute[ij] = '\0';
        //ij--;
        ji=0;
        while(ji<ij)
        {
           char c = cminute[ji];
           cminute[ji] = cminute[ij];
           cminute[ij] = c;
           ++ji;
           --ij;
        }
    }
    else if(phase == 2)
    {
        p2time ++;
    }

    else if(phase == 4)
    {
        resultphasesec++;
    }
}



void record()
{
    //rearranging records

    /*FILE *f = fopen("2.txt","r");
    char p5name[30][30];
    int p5int[30];
    for(int i=0;i<30;i++)
    {
        fscanf(f,"%s %i " , p5name[i], &p5int);
    }
    fclose(f);
    char looptemp[30];
    int recordindex[30];
    for(int i=0;i<30;i++)
    {
        recordindex[i] = i;
    }
    /*for(int i=0;i<30;i++)
    {
        for(int j=i+1;i<30;j++)
        {
            if(p5int[j]>p5int[i])
            {
                int temp = p5int[j];
                p5int[j] = p5int[i];
                p5int[i] = temp;


                //name switching

                //printf("DEBUG: I am here\n");
                //strcpy(looptemp,p5name[j]);
                //strcpy(p5name[j],p5name[i]);
                //strcpy(p5name[i],looptemp);
            }
        }
    }*/
    /*printf("DEBUG: I am here finallyyyyy \n");

    FILE *ff = fopen("2.txt","w");
    for(int i=0;i<30;i++)
    {
        fprintf(ff,"%s %i\n", p5name[i],p5int);
    }
    fclose(ff);*/



}
