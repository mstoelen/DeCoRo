#ifndef __INPUT_H
#define __INPUT_H

#include "value.h"
#include "xml_config/xml_config_deep.h"

#include <assert.h>
#include <math.h>
#include "stdio.h"
#include <vector>
#include <string>
    
class Input {
  
 public:
  
  /**
     @brief default constructor
  **/
  Input() {

    initialize();

  }

  /**
     @brief non-default constructor
  **/
  Input(std::string in_fileContext, std::string in_fileName) {

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
    ~Input();
  
  /**
     @brief prints the object to cout
  **/
  virtual void
    print(); 

  /**
     @brief get the value at a given index
  **/
  virtual Value*
    getValue(int in_index);

 /**
     @brief get the number of values stored
  **/
  virtual int
    getNumValues();

  /**
     @brief load content from XML file
  **/
  virtual void
    loadFromXML(std::string in_fileName);

  /**
     @brief find a value with a given tag
  **/
  virtual bool
    findValueIndex(std::string in_tag, int& out_index);

  /**
     @brief scale the resolution of all values by multiplier (rounding up)
  **/
  virtual void
    scaleAllResolutions(double in_multiplier);

 protected:

  /**
     @brief initialize
  **/
  void
    initialize();

 protected:

  std::string d_fileContext;
  std::string d_fileName;
  std::vector<Value*> d_values;

};

#endif
