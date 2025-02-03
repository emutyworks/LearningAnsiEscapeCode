void initScreen(void)
{
  MOVE_HOME_POS;
  ERASE_SCREEN;

  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);

  vs.w=(w.ws_col<INI_MAX_W?w.ws_col:INI_MAX_W);
  vs.h=(w.ws_row<INI_MAX_H?w.ws_row:INI_MAX_H);

  unsigned char x,y;
  unsigned int vy;
  for(y=0; y<vs.h; y++){
    vy=y*vs.w;
    for(x=0; x<vs.w; x++){
      vsram[ vy+x ]=sp_pal[0][0];
    }
  } 
}

void drawScreen(void){
  MOVE_HOME_POS;

  unsigned char x,y;
  unsigned int vy;

  for(y=0; y<vs.h; y++){
    vy=y*vs.w;
    for(x=0; x<vs.w; x++){
      SET_BG_COLOR( vsram[ vy+x ] );
      printf(" ");
    }
  }
}

void setSprite(sprite sp)
{
  unsigned char x,y,d;
  unsigned int oy,vy;

  for(y=0; y<sp.h; y++){
    oy=y*sp.w;
    vy=(y+sp.y)*vs.w+sp.x;
    for(x=0; x<sp.w; x++){
      d = sp_obj[ sp.o ][ oy+x ];
      if(d!=0){
        vsram[ vy+x ]=sp_pal[ sp.p ][ d ];
      }
    }
  }
}
