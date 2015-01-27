#include "retina.h"

Retina :: ~Retina() { }

void
Retina :: initialize()
{
  
  d_fileName = "../share/retina.xml";

}

void
Retina :: print()
{

  printf("********** Retina **********\n");

  for(int i = 0; i < d_zones.size(); i++) {
    d_zones.at(i)->print();
  }

}

void
Retina :: loadFromXML(std::string in_fileName) 
{

  XMLConfigDeep config(in_fileName,"Retina");

  while( config.openNextLocalNode("Zone") ) {

    Zone* zone = new Zone();

    std::string tag;
    assert(config.getStringAttribute("tag", tag));
    zone->setTag(tag);

    int minX, maxX, minY, maxY;
    assert(config.getInt("MinX", minX));
    zone->setMinX(minX);
    assert(config.getInt("MaxX", maxX));
    zone->setMaxX(maxX);
    assert(config.getInt("MinY", minY));
    zone->setMinY(minY);
    assert(config.getInt("MaxY", maxY));
    zone->setMaxY(maxY);

    d_zones.push_back(zone);

  }

}

Zone*
Retina :: getZone(int in_index) {

  // TODO: CHECK IF INDEX WITHIN RANGE

  return d_zones.at(in_index);

}

int
Retina :: getNumZones() {

  return d_zones.size();

}

int
Retina :: getMaxX() {

  int max = 0;
  for(int i = 0; i < d_zones.size(); i++) {
    int current = d_zones.at(i)->getMaxX();
    if(current > max) {
      max = current;
    }
  }

  return max;
}

int
Retina :: getMaxY() {

  int max = 0;
  for(int i = 0; i < d_zones.size(); i++) {
    int current = d_zones.at(i)->getMaxY();
    if(current > max) {
      max = current;
    }
  }

  return max;
}


