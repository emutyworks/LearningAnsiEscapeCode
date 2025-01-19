void drawObj(int px, int py, int sx, int sy, unsigned int* col,
  unsigned int* pal)
{
  int x,y;
  int color;
  
  setPosY(py);
  for(y=0; y<sy; y++){
    setPosX(px);
    for(x=0; x<sx; x++){
      color = pal[ col[y*sx+x] ];
      setBGColor(color);
      printf(" ");
    }
    printf("\n");
  }  
}

void setPosX(int x)
{
  printf("%s[%dC",ESC,x);
}

void setPosY(int y)
{
  printf("%s[%dB",ESC,y);
}

void initScreen(int w, int h, int c)
{
  int x,y;
  
  printf("%s[H",ESC);   //moves cursor to home position (0, 0)
  printf("%s[2J",ESC);  //erase entire screen

  setBGColor(c);
  for(y=0; y<h; y++){
    for(x=0; x<w; x++){
      printf(" ");
    }
    printf("\n");
  }
  printf("%s[H",ESC);   //moves cursor to home position (0, 0)
}

void setFGColor(int c)
{
  printf("%s[38;5;%dm",ESC,c);
}

void setBGColor(int c)
{
  printf("%s[48;5;%dm",ESC,c);
}

void resetColor(void)
{
  printf("%s[0m",ESC);
}
