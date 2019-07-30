//
//  Graphics.h
//  Codes
//
//  Created by An Zhang on 2019-07-29.
//  Copyright © 2019 An Zhang. All rights reserved.
//

#ifndef SORCERY_GRAPHICS_H
#define SORCERY_GRAPHICS_H
#include "window.h"
#include "Observer.h"
#include "State.h"
#include <vector>
#include <iostream>

class GraphicsDisplay: public Observer<std::shared_ptr<Card>, Effect> {
    Xwindow display;
public:
    GraphicsDisplay (Game g);
    
    void notify(Subject<std::shared_ptr<Card>, Effect> &whoNotified) override; // Notified if the grid is changed
    
    friend std::ostream &operator<<(std::ostream &out, const GraphicsDisplay &gd); // print grid
};

#endif /* Graphics_h */
