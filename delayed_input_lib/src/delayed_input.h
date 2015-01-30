#ifndef __DELAYED_INPUT_H
#define __DELAYED_INPUT_H

#include "input.h"
#include <xml_config/xml_config.h>

#include <assert.h>
#include "stdio.h"
#include <vector>
#include <string>
    
class DelayedInput {
  
 public:
  
  /**
     @brief default constructor
  **/
  DelayedInput() {

    initialize();

  }

  /**
     @brief non-default constructor
  **/
  DelayedInput(std::string in_fileContext, std::string in_fileName) {

    d_fileContext = in_fileContext;
    d_fileName = in_fileName;

    std::string _completeFileName;
    _completeFileName.append(in_fileContext);
    _completeFileName.append(in_fileName);

    loadFromXML(_completeFileName);

  }
  
  /**
     @brief default destructor
  **/
  virtual 
    ~DelayedInput();
  
  /**
     @brief prints the object to cout
  **/
  virtual void
    print();

  /**
     @brief get the delayed input at a given index
  **/
  virtual Input*
    getInput(int in_index);

  /**
     @brief get the delay at a given index
  **/
  virtual double
    getDelay(int in_index);

  /**
     @brief set the delay at a given index
  **/
  virtual void
    setDelay(int in_index, double in_delay);

 /**
     @brief get the number of delayed inputs stored
  **/
  virtual int
    getNumDelays();

  /**
     @brief load content from XML file
  **/
  void
    loadFromXML(std::string in_fileName);

 protected:

  /**
     @brief initialize
  **/
  void
    initialize();

 protected:

  std::string d_fileContext;
  std::string d_fileName;
  std::vector<Input*> d_inputs;
  std::vector<double> d_delays;

};

#endif
