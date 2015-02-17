#ifndef __MAPPED_INPUT_H
#define __MAPPED_INPUT_H

#include "input.h"
#include "map.h"
#include <xml_config/xml_config.h>

#include <assert.h>
#include "stdio.h"
#include <vector>
#include <string>
    
class MappedInput {
  
 public:
  
  /**
     @brief default constructor
  **/
  MappedInput() {

    initialize();

  }

  /**
     @brief non-default constructor
  **/
  MappedInput(std::string in_fileContext, std::string in_fileName, Input* in_firstInputs, Input* in_secondInputs) {

    d_fileContext = in_fileContext;
    d_fileName = in_fileName;

    d_firstInputs = in_firstInputs;
    d_secondInputs = in_secondInputs;

    std::string _completeFileName;
    _completeFileName.append(in_fileContext);
    _completeFileName.append(in_fileName);

    loadFromXML(_completeFileName);

    findIndices();

  }
  
  /**
     @brief default destructor
  **/
  virtual 
    ~MappedInput();
  
  /**
     @brief prints the object to cout
  **/
  virtual void
    print();

  /**
     @brief get the mapped input at a given index
  **/
  virtual Map*
    getMap(int in_index);

 /**
     @brief get the number of mapped inputs stored
  **/
  virtual int
    getNumMaps();

  /**
     @brief load content from XML file
  **/
  void
  loadFromXML(std::string in_fileName);

 protected:

  /**
     @brief after loading from XML, find indices for input values used in map
  **/
  void
    findIndices();

  /**
     @brief initialize
  **/
  void
    initialize();

 protected:

  std::string d_fileContext;
  std::string d_fileName;
  std::vector<Map*> d_maps;

  Input* d_firstInputs;
  Input* d_secondInputs;

};

#endif
