void setPosX(unsigned char x)
{
  printf("%s[%dC",ESC,x);
}

void setPosY(unsigned char y)
{
  printf("%s[%dB",ESC,y);
}

void initScreen(void)
{
  printf("%s[H",ESC);   // Moves cursor to home position (0, 0)
  printf("%s[2J",ESC);  // Erase entire screen

  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);

  vs.w=w.ws_col;
  vs.h=w.ws_row;

  unsigned char x,y;
  unsigned int dy;
  for(y=0; y<vs.h; y++){
    dy=y*vs.w;
    for(x=0; x<vs.w; x++){
      vsram[ dy+x ]=sp_pal[0][0];
    }
  } 
}

void drawScreen(void){
  printf("%s[H",ESC);   // Moves cursor to home position (0, 0)

  unsigned char x,y;
  unsigned int py;

  for(y=0; y<vs.h; y++){
    py=y*vs.w;
    for(x=0; x<vs.w; x++){
      setBGColor( vsram[ py+x ] );
      printf(" ");
    }
  }
}

void setSprite(sprite sp)
{
  unsigned char x,y,d;
  unsigned int oy,dy;

  for(y=0; y<sp.h; y++){
    oy=y*sp.w;
    dy=(y+sp.y)*vs.w+sp.x;
    for(x=0; x<sp.w; x++){
      d = sp_obj[ sp.o ][ oy+x ];
      if(d!=0){
        vsram[ dy+x ]=sp_pal[ sp.p ][ d ];
      }
    }
  }
}

void setFGColor(unsigned char c)
{
  printf("%s[38;5;%dm",ESC,c);
}

void setBGColor(unsigned char c)
{
  printf("%s[48;5;%dm",ESC,c);
}

void resetColor(void)
{
  printf("%s[0m",ESC);
}
