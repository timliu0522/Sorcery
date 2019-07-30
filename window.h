#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>
#include "Observer.h"
#include "State.h"
#include "game.h"
#include <X11/Xutil.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

class Xwindow {
    Display *d;
    Window w;
    int s;
    GC gc;
    unsigned long colours[10];
    
public:
    Xwindow(int width=1005, int height=900);  // Constructor; displays the window.
    ~Xwindow();                              // Destructor; destroys the window.
    Xwindow(const Xwindow&) = delete;
    Xwindow &operator=(const Xwindow&) = delete;
    
    enum {White=0, Black, Red, Green, Blue}; // Available colours.
    
    // Draws a rectangle
    void fillRectangle(int x, int y, int width, int height, int colour=Black);
    
    void drawRectangle(int x, int y, int width, int height, int colour=Black);
    
    void fillCircle(int x, int y, int width, int height, int colour);
    
    // Draws a string
    void drawString(int x, int y, std::string msg);
    
    void drawBoard();
    
    void drawPlayer(Player p);
    
};

 Xwindow::Xwindow(int width, int height) {
    d = XOpenDisplay(NULL);
    if (d == NULL) {
        cerr << "Cannot open display" << endl;
        exit(1);
    }

    s = DefaultScreen(d);
    w = XCreateSimpleWindow(
            d, RootWindow(d, s), 10, 10, width, height,
            1, BlackPixel(d, s), WhitePixel(d, s)
    );

    XSelectInput(d, w, ExposureMask | KeyPressMask);

    Pixmap pix = XCreatePixmap(
            d, w, width, height,
            DefaultDepth(d, DefaultScreen(d))
    );

    gc = XCreateGC(d, pix, 0, 0);

    // Set up colours.
    XColor xcolour;
    Colormap cmap;

    const size_t numColours = 5;
    char color_vals[numColours][10] = {
            "white", "black", "red",
            "green", "blue"
    };

    cmap = DefaultColormap(d, DefaultScreen(d));

    for(unsigned int i = 0; i < numColours; ++i) {
        XParseColor(d, cmap, color_vals[i], &xcolour);
        XAllocColor(d, cmap, &xcolour);
        colours[i] = xcolour.pixel;
    }

    XSetForeground(d, gc, colours[Black]);

    // Make window non-resizeable.
    XSizeHints hints;
    hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
    hints.height = hints.base_height = hints.min_height = hints.max_height = height;
    hints.width = hints.base_width = hints.min_width = hints.max_width = width;
    XSetNormalHints(d, w, &hints);

    // map window and flush
    XMapRaised(d, w);
    XFlush(d);

    // wait 1 second for setup
    sleep(1);
}

Xwindow::~Xwindow() {
    XFreeGC(d, gc);
    XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XFillRectangle(d, w, gc, x, y, width, height);
    XFlush(d);
}

void Xwindow::drawRectangle(int x, int y, int width, int height, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XDrawRectangle(d, w, gc, x, y, width, height);
    XFlush(d);
}

void Xwindow::fillCircle(int x, int y, int width, int height, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XDrawArc(d, w, gc, x, y, width, height, 0, 360*64);
    XFlush(d);
}

void Xwindow::drawString(int x, int y, string msg) {
    XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
    XFlush(d);
}


#endif
