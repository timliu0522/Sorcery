//
//  Graphics.cpp
//  Sorcery
//
//  Created by An Zhang on 2019-07-29.
//  Copyright © 2019 An Zhang. All rights reserved.
//

#include "Graphics.h"

GraphicsDisplay::GraphicsDisplay (Game g) {
    // Background
    display.fillRectangle(0, 0, 1005, 900);
    
    // Player 2 stuff
    display.drawRectangle(5, 5, 200, 190, Xwindow::White);
    display.drawString(110, 100, "Ritual");
    
    display.drawRectangle(400, 5, 200, 190, Xwindow::White);
    display.drawString(480, 45, g.getPlayer2()->getName());
    display.fillCircle(410, 160, 20, 20, Xwindow::Red);
    display.drawString(420, 170, g.getPlayer2()->getHealth());
    display.fillCircle(570, 160, 20, 20, Xwindow::Blue);
    display.drawString(580, 170, g.getPlayer2()->getMagic());
    
    display.drawRectangle(805, 5, 200, 190, Xwindow::White);
    display.drawString(910, 100, "Grave");

    // Board stuff
    display.fillRectangle(5, 300, 995, 600, Xwindow::Green);
    display.fillRectangle(5, 595, 995, 10, Xwindow::Black);
    
    // Player 1 stuff
    display.drawRectangle(5, 710, 200, 190, Xwindow::White);
    display.drawString(110, 100, "Ritual");
    
    display.drawRectangle(400, 710, 200, 190, Xwindow::White);
    display.drawString(480, 750, g.getPlayer1()->getName());
    display.fillCircle(410, 865, 20, 20, Xwindow::Red);
    display.drawString(420, 875, g.getPlayer1()->getHealth());
    display.fillCircle(570, 865, 20, 20, Xwindow::Blue);
    display.drawString(580, 875, g.getPlayer1()->getMagic());
    
    display.drawRectangle(805, 710, 200, 190, Xwindow::White);
    display.drawString(910, 805, "Grave");
}

// Notified if the grid is changed
void GraphicsDisplay::notify(Subject<std::shared_ptr<Card>, Effect> &whoNotified) {
    if (whoNotified.getState() == EffectType::MEC)
    
}

std::ostream &operator<<(std::ostream &out, const GraphicsDisplay &gd) {}

