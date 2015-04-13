#include "mapped_input.h"

MappedInput :: ~MappedInput() { }

void
MappedInput :: initialize()
{
  
  d_fileName = "../share/mapped_input.xml";

}

void
MappedInput :: print()
{
  
  printf("*************** Mapped Input ***************\n\n");

  printf("  Number of mapped inputs: %d\n\n", (int) d_maps.size());

  for(int i = 0; i < d_maps.size(); i++) {
    d_maps.at(i)->print();
  }

}

void
MappedInput :: loadFromXML(std::string in_fileName) {

  XMLConfigDeep config(in_fileName,"MappedInput");

  while( config.openNextLocalNode("Map") ) {

    std::string tag;
    assert(config.getStringAttribute("tag", tag));
    std::string tagFirst;
    assert(config.getString("tagFirstInput", tagFirst));
    std::string tagSecond;
    assert(config.getString("tagSecondInput", tagSecond));
    double stdDevSecond;
    assert(config.getDouble("stdDevSecondInput", stdDevSecond));
    
    bool is1D = false;
    if(tagSecond.compare("none") == 0) {
      is1D = true;
    }

    Map* map = new Map(tag, tagFirst, tagSecond, stdDevSecond, is1D);
    d_maps.push_back(map);

  }

}

void
MappedInput :: findIndices() {

  int size = d_maps.size();
  for(int i = 0; i < size; i++) {

    std::string tag = d_maps.at(i)->getTag();
    std::string tagFirst = d_maps.at(i)->getFirstTag();
    std::string tagSecond = d_maps.at(i)->getSecondTag();

    int indexFirst, indexSecond;

    assert(d_firstInputs->findValueIndex(tagFirst,indexFirst));
    d_maps.at(i)->setFirstIndex(indexFirst);

    if(d_maps.at(i)->getIs1D()) {
      d_maps.at(i)->setSecondIndex(-1);
    }
    else {
      assert(d_secondInputs->findValueIndex(tagSecond,indexSecond));
      d_maps.at(i)->setSecondIndex(indexSecond);
    }

  }

}

Map*
MappedInput :: getMap(int in_index) {

  // TODO: CHECK IF INDEX WITHIN RANGE

  return d_maps.at(in_index);

}


int
MappedInput :: getNumMaps() {

  return d_maps.size();

}


