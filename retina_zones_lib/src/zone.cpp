#include "zone.h"

Zone :: ~Zone() { }

void
Zone :: initialize()
{

  d_tag = "not_defined";
  d_minX = 1;
  d_maxX = 320;
  d_minY = 1;
  d_maxY = 240;
  d_currentValue = 0.0;
  
}

void
Zone :: print()
{

  printf("***** Zone %s *****\n", d_tag.c_str());
  printf("  Min x, max x: %d, %d\n", d_minX,d_maxX);
  printf("  Min y, max y: %d, %d\n", d_minY,d_maxY);
  printf("  Current value: %7.2f\n", d_currentValue);
  printf("\n");   

}

int
Zone :: getMinX() {

  return d_minX;

}

int
Zone :: getMaxX() {

  return d_maxX;

}

int
Zone :: getMinY() {

  return d_minY;

}

int
Zone :: getMaxY() {

  return d_maxY;

}

std::string
Zone :: getTag() {

  return d_tag;

}

double
Zone :: getCurrent() {

  return d_currentValue;

}

void
Zone :: setMinX(int in_minX) {

  d_minX = in_minX;

}

void
Zone :: setMaxX(int in_maxX) {

  d_maxX = in_maxX;

}

void
Zone :: setMinY(int in_minY) {

  d_minY = in_minY;

}

void
Zone :: setMaxY(int in_maxY) {

  d_maxY = in_maxY;

}

void
Zone :: setTag(std::string in_tag) {

  d_tag = in_tag;

}

void
Zone :: setCurrent(double in_currentValue) {

  d_currentValue = in_currentValue;

}


