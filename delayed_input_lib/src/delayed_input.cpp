#include "delayed_input.h"

DelayedInput :: ~DelayedInput() { }

void
DelayedInput :: initialize()
{
  
  d_fileName = "../share/delayed_input.xml";

}

void
DelayedInput :: print()
{
  
  printf("*************** Delayed Input ***************\n\n");

  printf("  Number of delayed inputs: %d\n\n", (int) d_inputs.size());

  for(int i = 0; i < d_delays.size(); i++) {
    printf("  Delayed at : %7.2f\n", d_delays.at(i));
    printf("\n");
    d_inputs.at(i)->print();
  }

}

void
DelayedInput :: loadFromXML(std::string in_fileName) {

  XMLConfig config(in_fileName,"DelayedInput");

  std::string _inputFileName;
  assert(config.getString("InputXMLFile", _inputFileName));

  double _resMult;
  assert(config.getDouble("ResolutionMultiplier", _resMult));

  std::vector<double> _delays;
  assert(config.getVectorOfDouble("Delays", _delays));
      
  for(int i = 0; i < _delays.size(); i++) {

      Input* _input = new Input(d_fileContext,_inputFileName);
      _input->scaleAllResolutions(_resMult);

      d_inputs.push_back(_input);
      d_delays.push_back(_delays.at(i));

      _resMult = _resMult * _resMult;

  }

}

Input*
DelayedInput :: getInput(int in_index) {

  // TODO: CHECK IF INDEX WITHIN RANGE

  return d_inputs.at(in_index);

}

double
DelayedInput :: getDelay(int in_index) {

  // TODO: CHECK IF INDEX WITHIN RANGE

  return d_delays.at(in_index);

}

void
DelayedInput :: setDelay(int in_index, double in_delay) {

  // TODO: CHECK IF INDEX WITHIN RANGE

  d_delays.at(in_index) = in_delay;

}

int
DelayedInput :: getNumDelays() {

  return d_inputs.size();

}


