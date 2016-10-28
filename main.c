#include <stdio.h>
#include <ncurses.h>
#include <math.h>
#include <unistd.h>

#include "userfunctions.h"

int main() {
    //init ncurses
    initscr();
    long double t = 0.0L;
    long double x = 0.0L;
    long double y = 0.0L;
    long double c = 1.0L;
    int x_dim = 0;
    int y_dim = 0;
    //main animation loop
    for (;;) {
        clear();
        //update the window size
        getmaxyx(stdscr, y_dim, x_dim);
        //enter main graphing loop
        for (t = MIN_T; t <= MAX_T; t += T_STEP) {
            //calculate parametric point
            x = f(t, c); y = g(t, c);
            //display frame constant
            mvprintw(0,0,"Frame: %Lf", c);
            //shift it to be the scale of the terminal window
            x = (x - MIN_X) * ((long double)x_dim / (MAX_X - MIN_X));
            y = (y - MIN_Y) * ((long double)y_dim / (MAX_Y - MIN_Y));
            //flip y because curses is weird
            y = (long double)y_dim - y;
            mvaddch(floor(y), floor(x), '#');
        }
        //update ncurses screen
        refresh();
        //update frame constant
        c++;
        //sleep before we go to the next loop
        usleep(1000);
    }
    //wait for input then close ncurses
    getch();
    endwin();
    return 0;
}
