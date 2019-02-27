#include<stdio.h>
#include<curses.h>
#include<unistd.h>

int main()
{
	int i;

	initscr();
	clear();

	for(i=0; i<LINES; i++)
	{
		move(i, i+1);
		if(i%2 == 0)
		{
			standout();
		}
		addstr("O");
		if(i%2 == 0)
		{
			standend();
		}

		sleep(1);
		refresh();

		move(i, i+1);
		addstr(" ");
	}

	endwin();
	return 0;
}
