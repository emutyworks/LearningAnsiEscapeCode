/*
 * I used this Website/Document as a reference to create it.
 *
 * ANSI Escape Sequences
 * https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
 *
 * Build your own Command Line with ANSI escape codes
 * https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html
 * 
 * C Programming - using ANSI escape codes on Windows, macOS and Linux terminals
 * https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/
 *
 */

void set_pos_x(int x);
void set_pos_y(int y);
void init_screen(int w, int h, int c);
void set_fgcolor(int c);
void set_bgcolor(int c);
void reset_color(void);

#include <sys/ioctl.h>
#include <stdio.h>
#include "define.h"
#include "sub.c"

int main(void)
{
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);

  init_screen(w.ws_col, w.ws_row, 15);

  set_pos_y(3);
  
  set_bgcolor(196);
  int x1 = 5;
  set_pos_x(x1+4);
  printf("        \n");
  set_pos_x(x1+2);
  printf("            \n");
  set_pos_x(x1);
  printf("          ");
  set_bgcolor(15);
  printf("  ");
  set_bgcolor(196);
  printf("    \n");      
  set_pos_x(x1);
  printf("                \n");
  set_pos_x(x1);
  printf("                \n");
  set_pos_x(x1);
  printf("                \n");
  set_pos_x(x1+2);
  printf("            \n");
  set_pos_x(x1+4);
  printf("        \n");
  
  reset_color();
	return 0;
}
