#include<stdio.h>
#include<curses.h>

int main()
{
	initscr();
	clear();

	int i;
	for(i=0; i<LINES/2; i++)
	{
		move(i, i+1);
		if(i%2==1)
		{
			standout();
		}
		addstr("Hello, Curses!");
		if(i%2==1)
		{
			standend();
		}
	}
	
	refresh();
	getch();
	endwin();
	return 0;
}
