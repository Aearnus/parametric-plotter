Parametric Plotter
===
This isn't a serious project, just something high quality enough that I feel could be published and at least looked at by someone else. The parametric equation is defined in `userfunctions.c`, with two arguments each:
* t - the parametric step
* c - the frame number constant

The options for the renderer such as the window size and parametric step are defined in `userfunctions.h`. Simply recompile using `make` every time you make a change to the function.

Requires:
* ncurses
* gcc
