#define ESC "\x1b"
#define INI_MAX_W 240 // 1920/8
#define INI_MAX_H 135 // 1080/8

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
void resetColor(void);
void setPosX(unsigned char x);
void setPosY(unsigned char y);
void setFGColor(unsigned char c);
void setBGColor(unsigned char c);
