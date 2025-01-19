#include <sys/ioctl.h>
#include <stdio.h>

void setPosX(int x);
void setPosY(int y);
void initScreen(int w, int h, int c);
void setFGColor(int c);
void setBGColor(int c);
void resetColor(void);
void drawObj(int px, int py, int sx, int sy, unsigned int* col,
  unsigned int* pal);

#define ESC "\x1b"
