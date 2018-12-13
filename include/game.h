#ifndef GAME_H
#define GAME_H

struct player {
	uint8 x;
	uint8 y;
	char c;
};
struct player a = {4, 4, 'A'};
struct player b = {20, 20, 'B'};

uint8 boundX(uint8 x) {
	if (x < 1) return 1;
	if (x >= sw-1) return sw-2;
	return x;
}
uint8 boundY(uint8 y) {
	if (y < 1) return 1;
	if (y >= sh-1) return sh-2;
	return y;
}

void game_putchar(char c, uint8 x, uint8 y) {
	string vidmem = (string) 0xb8000;
	vidmem[(y*sw+x)*sd]=c;
    vidmem[(y*sw+x)*sd+1] = 0x0F;
}
void game_printborder(char c) {
	uint16 i,j;
	for (i=0, j=0; i<sw; i++) game_putchar(c, i, j);
	for (i=0, j=0; j<sh; j++) game_putchar(c, i, j);
	for (i=0, j=sh-1; i<sw; i++) game_putchar(c, i, j);
	for (i=sw-1, j=0; j<sh; j++) game_putchar(c, i, j);
}

void game() {
	b.x = sw - 6;
	b.y = sw - 6;
	
	game_printborder((char)219);
	
	game_putchar(a.c, a.x, a.y);
	game_putchar(b.c, b.x, b.y);
	
	while (1) {
		if(inportb(0x64) & 0x1)                 
        {
			uint8 quit = 0;
            switch(inportb(0x60))
            {
				case 17:
				game_putchar(' ', a.x, a.y);
				a.x = boundX(a.x); a.y = boundY(a.y-1);
				game_putchar(a.c, a.x, a.y);
				break;
				
				case 30:
				game_putchar(' ', a.x, a.y);
				a.x = boundX(a.x-1); a.y = boundY(a.y);
				game_putchar(a.c, a.x, a.y);
				break;
				
				case 31:
				game_putchar(' ', a.x, a.y);
				a.x = boundX(a.x); a.y = boundY(a.y+1);
				game_putchar(a.c, a.x, a.y);
				break;
				
				case 32:
				game_putchar(' ', a.x, a.y);
				a.x = boundX(a.x+1); a.y = boundY(a.y);
				game_putchar(a.c, a.x, a.y);
				break;
				
				
				
				case 0x48:
				game_putchar(' ', b.x, b.y);
				b.x = boundX(b.x); b.y = boundY(b.y-1);
				game_putchar(b.c, b.x, b.y);
				break;
				
				case 0x4b:
				game_putchar(' ', b.x, b.y);
				b.x = boundX(b.x-1); b.y = boundY(b.y);
				game_putchar(b.c, b.x, b.y);
				break;
				
				case 0x50:
				game_putchar(' ', b.x, b.y);
				b.x = boundX(b.x); b.y = boundY(b.y+1);
				game_putchar(b.c, b.x, b.y);
				break;
				
				case 0x4d:
				game_putchar(' ', b.x, b.y);
				b.x = boundX(b.x+1); b.y = boundY(b.y);
				game_putchar(b.c, b.x, b.y);
				break;
				
				
				case 45:
				quit = 1;
				break;
			}
			if (quit) break;
			if (a.x == b.x && a.y == b.y) {
				game_putchar('W', b.x, b.y);
				break;
			}
		}
	}
	while(1)
		if(inportb(0x64) & 0x1 && inportb(0x60) == 45)
			return;
	
}

#endif
