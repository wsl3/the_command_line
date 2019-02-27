#include<stdio.h>
#include<unistd.h>
#include<curses.h>

#define TOP 0
#define BOTTOM (LINES-1)
#define LEFT 0
#define RIGHT (COLS-1)
#define MSG "o"
#define BLOCK " "

int main()
{
	initscr();
	clear();
	int x = LEFT;
	int y = TOP;
	int pos_x = 2;
	int pos_y = 2;

	while(1)
	{
		move(y, x);
		addstr(MSG);
		
		move(BOTTOM, LEFT);
//		sleep(1);
		refresh();

		move(y, x);
		addstr(BLOCK);
		
		x += pos_x;
		y += pos_y;

		if(x <= LEFT){ x += 1; pos_x = -pos_x;}
		if(x >= RIGHT){ x-=1; pos_x = -pos_x;}

		if(y <= TOP){ y+=1; pos_y = -pos_y;}
		if(y >= BOTTOM){y-=1; pos_y = -pos_y;}
	}
	
	endwin();
	return 0;
}
