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

#include <sys/ioctl.h>
#include <stdio.h>
#include "define.h"
#include "data.c"
#include "sub.c"

int main(void)
{
  initScreen();

  sprite sp;
  sp.x=5;
  sp.y=3;
  sp.w=16;
  sp.h=8;
  sp.o=0;
  sp.p=0;
  setSprite(sp);

  sp.x=13;
  sp.y=7;
  sp.w=16;
  sp.h=8;
  sp.o=0;
  sp.p=1;
  setSprite(sp);

  drawScreen();

	return 0;
}
