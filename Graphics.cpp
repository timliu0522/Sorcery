//
//  Graphics.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-29.
//  Copyright © 2019 An Zhang. All rights reserved.
//

#include "Graphics.h"

GraphicsDisplay::GraphicsDisplay (int size) : size(size) {
    display.fillRectangle(0, 0, 1000, 1000, Xwindow::Black);
}

// Notified if the grid is changed
void GraphicsDisplay::notify(Subject<std::shared_ptr<Card>, Effect> &whoNotified) {
    
}

std::ostream &operator<<(std::ostream &out, const GraphicsDisplay &gd) {}

