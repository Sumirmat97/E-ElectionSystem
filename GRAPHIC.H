void strtpg();

void strtpg()
{

  clrscr();


  int gd=DETECT,gm; // gd: used to automatically detect graphics driver & VDU
		    // gm: used to obtain screen mode eg: resolution,color,etc.

  initgraph(&gd,&gm,"C:\\turboc3\\bgi");
		    //The path refers to C++ graphics directory
		    //"C:\\TC\\BGI" also used on many computers

  cleardevice();     //erases graphics screen
  int mx,my,cx,cy,tlx,tly,brx,bry;
  //max. x,max. y,center x,center y,topleft x,topleft y,bottonright x, bottomright y resp.

  int height=150,length=250; //dimensions of rectangle

  mx=getmaxx();     //maximum x coordinate
  my=getmaxy();     //maximum y coordinate
  cx=mx/2;          // x of centre of screen
  cy=my/2;          // y of center of screen

  tlx=cx-length/2;  // tlx - top left x coord.
  tly=cy-height/2;  // tly - top left y coord.
  brx=cx+length/2;  // brx - botton right x coord.
  bry=cy+height/2;  // bry - bottom right y coord.

  setcolor(8);
  rectangle(tlx-6,tly-6,brx+14,bry+14);
  setfillstyle(SOLID_FILL,8);
  floodfill(cx,cy,8);   //fills area surrounding pt (cx,cy) with color

  setcolor(0);      //setcolor(0) means black color
  rectangle(tlx-8,tly-8,brx+12,bry+12);
  setfillstyle(SOLID_FILL,0);
  floodfill(cx,cy,0);

  setcolor(RED);
  rectangle(tlx-10,tly-10,brx+10,bry+10);
  setfillstyle(SOLID_FILL,RED);
  floodfill(cx,cy,RED);

  setcolor(BLUE);
  rectangle(tlx,tly,brx,bry);
  setfillstyle(SOLID_FILL,BLUE);
  floodfill(cx,cy,BLUE);

  setcolor(WHITE);
  settextstyle(1,0,2);
  delay(1000);      //delay of 1000 ms or 1 sec.
  outtextxy(cx-60,cy-55,"Welcome to");
  delay(1000);
  outtextxy(cx-110,cy-15,"Computerised Election");
  delay(1000);
  outtextxy(cx-40,cy+25,"System");
  delay(1000);

  line(tlx-10,bry+25,brx+10,bry+25);  //draws initial white line
  setcolor(GREEN);
  for(int i=tlx-10;i<=brx+10;i+=10)   //draws coloured line progressively to show loading
  {
    line(tlx-10,bry+25,i,bry+25);
    delay(50);
  }
  delay(500);

  setcolor(YELLOW);
  settextstyle(2,0,5);
  outtextxy(cx-90,bry+60,"Press any key to continue");

  getch();
  closegraph();   //ends graphics
}

