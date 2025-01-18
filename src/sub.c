void set_pos_x(int x)
{
  printf("%s[%dC",ESC,x);
}

void set_pos_y(int y)
{
  printf("%s[%dB",ESC,y);
}

void init_screen(int w, int h, int c)
{
  int x,y;
  
  printf("%s[H",ESC);   //moves cursor to home position (0, 0)
  printf("%s[2J",ESC);  //erase entire screen

  set_bgcolor(c);
  for(y=0; y<h; y++){
    for(x=0; x<w; x++){
      printf(" ");
    }
    printf("\n");
  }
  printf("%s[H",ESC);   //moves cursor to home position (0, 0)
}

void set_fgcolor(int c)
{
  printf("%s[38;5;%dm",ESC,c);
}

void set_bgcolor(int c)
{
  printf("%s[48;5;%dm",ESC,c);
}

void reset_color(void)
{
  printf("%s[0m",ESC);
}
