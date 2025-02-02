#define INI_MAX_W 240 // 1920/8
#define INI_MAX_H 135 // 1080/8

#define ESC "\x1b"
#define MOVE_HOME_POS printf("%s[H",ESC)
#define ERASE_SCREEN printf("%s[2J",ESC)
#define RESET_COLOR printf("%s[0m",ESC)
#define SET_FG_COLOR(v) printf("%s[38;5;%dm",ESC,v);
#define SET_BG_COLOR(v) printf("%s[48;5;%dm",ESC,v);
#define SET_POS_X(v) printf("%s[%dC",ESC,v)
#define SET_POS_Y(v) printf("%s[%dB",ESC,v)

unsigned char vsram[ INI_MAX_W * INI_MAX_H ]; // Virtual Screen RAM  

typedef struct
{
  unsigned char w;
  unsigned char h;  
} vscreen;

vscreen vs;

typedef struct
{
  unsigned char x;
  unsigned char y; 
  unsigned char w; 
  unsigned char h; 
  unsigned char o; // Sprite Object data 
  unsigned char p; // Sprite Palette
} sprite;

void initScreen(void);
void drawScreen(void);
void setSprite(sprite sp);
