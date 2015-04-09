#include "input.h"

Input :: ~Input() { }

void
Input :: initialize()
{
  
  d_fileName = "../share/input.xml";

}

void
Input :: print()
{

  printf("********** Input **********\n");

  for(int i = 0; i < d_values.size(); i++) {
    d_values.at(i)->print();
  }

}

void
Input :: loadFromXML(std::string in_fileName) {

  XMLConfigDeep config(in_fileName,"Input");

  while( config.openNextLocalNode("Value") ) {

    Value* value = new Value();

    std::string tag;
    assert(config.getStringAttribute("tag", tag));
    value->setTag(tag);

    double min, max, stdDev;
    assert(config.getDouble("Min", min));
    value->setMin(min);
    assert(config.getDouble("Max", max));
    value->setMax(max);
    assert(config.getDouble("StdDev", stdDev));
    value->setStdDev(stdDev);

    int resolution;
    assert(config.getInt("Resolution", resolution));
    value->setRes(resolution);

    // push back value
    d_values.push_back(value);

  }

}

Value*
Input :: getValue(int in_index) {

  // TODO: CHECK IF INDEX WITHIN RANGE

  return d_values.at(in_index);

}

void
Input :: scaleAllResolutions(double in_multiplier) {

  for(int i = 0; i < d_values.size(); i++) {
    Value* value = d_values.at(i);
    int res = value->getRes();
    res = ceil(res * in_multiplier);
    d_values.at(i)->setRes(res);
  }

}

bool
Input :: findValueIndex(std::string in_tag, int& out_index) {

  for(int i = 0; i < d_values.size(); i++) {
    Value* value = getValue(i);
    std::string tag = value->getTag();
    int res = in_tag.compare(tag);
    if(res == 0) {
      out_index = i;
      return true;
    }
  }

  return false;

}

int
Input :: getNumValues() {

  return d_values.size();

}


