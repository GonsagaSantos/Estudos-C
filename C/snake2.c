#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
	WINDOW* win = initscr();
	keypad(win, true);
	nodelay(win, true);
	noecho();
	curs_set(0);

	int posX = 0, posY = 0;
	int dirX = 1, dirY = 0;
    //char cobra = "*";

	srand(time(NULL));
	int foodX = LINES % 20, foodY = COLS % 20;

	while(true) {

		int pressed = wgetch(win);

		posX += dirX;
		posY += dirY;

        if(posX == foodX && posY == foodY) {
            foodX = rand() % 20;
            foodY = rand() & 20;
            //cobra = cobra + "*";
            mvaddstr(posY, posX, "**");
            refresh();
        }

		if(pressed == 'q') {
			break;
		}

		if(pressed == KEY_LEFT) {
			dirX = -1;
			dirY = 0;
		}

		if(pressed == KEY_RIGHT) {
			dirX = 1;
			dirY = 0;
		}

		if(pressed == KEY_UP) {
			dirX = 0;
			dirY = -1;
		}
		
		if(pressed == KEY_DOWN) {
			dirX = 0;
			dirY = 1;
		}

        if(posX >= LINES || posY >= COLS)

		erase();
		mvaddstr(posY, posX, "*");
		mvaddstr(foodY, foodX, "&");

		refresh();
		usleep(100000);
	}

	endwin();
	return 0;
}
