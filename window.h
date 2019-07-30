#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>
#include "Observer.h"
#include "State.h"
#include "game.h"

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
    void drawCard (int x, int y, std::shared_ptr<Card>);
    
};

#endif
