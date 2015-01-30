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

    bool activationFlag, hypothesisFlag;
    assert(config.getBool("ActivationFlag", activationFlag));
    value->setActivationFlag(activationFlag);
    assert(config.getBool("HypothesisFlag", hypothesisFlag));
    value->setHypothesisFlag(hypothesisFlag);

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

int
Input :: getNumValues() {

  return d_values.size();

}


