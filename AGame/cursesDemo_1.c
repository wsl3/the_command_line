#include<stdio.h>
#include<curses.h>

int main(int ac, char* av[])
{
	initscr();
	clear();

	move(10, 20);
	addstr("Hello, Curses!");

	move(LINES-1, 0);
	refresh();
	getch();

	endwin();
	return 0;
}
