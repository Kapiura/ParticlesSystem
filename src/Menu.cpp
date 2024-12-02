#include "ofMain.h"
#include "Menu.hpp"
#include "ofxGui.h"


Menu::Menu()
{
  gui.setup();

  gui.add(radius.setup("Radius min", 1, 1, 400));
}

void Menu::draw()
{
  gui.draw();
}