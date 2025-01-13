#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

enum {START, END};
enum {HEIGHT, WIDTH};

int h, w;
int count;

int randomPosition[3];

void set_disp(int code)
{
	switch(code) {
		case START:
			initscr();
			cbreak();
			noecho();
			curs_set(0);
			timeout(0);
			start_color();
			break;
		case END:
			endwin();
			break;
		default:
			break;
	}
}

void mapping(void)
{
	randomPosition[HEIGHT] = rand() % h;
	randomPosition[WIDTH] = rand() % w;
	randomPosition[3] = 0;
	mvwprintw(stdscr, 0, 0, "%d", count);
	mvwaddch(stdscr, randomPosition[HEIGHT], randomPosition[WIDTH], '*');
	count++;
	refresh();
	sleep(1);
}

int main(void)
{
	set_disp(START);
	getmaxyx(stdscr, h, w);
	char k;
	while(1) {
		mapping();
		k = getch();
		if(k == 'q' || k == 'Q') {
			break;	
		}
	}
	set_disp(END);
	return 0;
}
