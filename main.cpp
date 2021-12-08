#include <iostream>
#include "Display.h"
#include "FileLuar.h"

using namespace std;

int main() { 
    FileLuar fl;
    Display screen;
    fl.readFile();
    screen.menuMain();
  
  return 0;
}
