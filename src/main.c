/*
 *
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

#include "define.h"
#include "sub.c"
#include "data.c"

int main(void)
{
  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);

  initScreen(w.ws_col, w.ws_row, 15);

  drawObj(5, 3, 16, 8, ball_col, ball_pal);

  resetColor();
	return 0;
}
