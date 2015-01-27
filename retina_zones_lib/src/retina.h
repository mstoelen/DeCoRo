#ifndef __RETINA_H
#define __RETINA_H

#include "zone.h"
#include "xml_config/xml_config_deep.h"

#include "mxml.h"

#include <assert.h>
#include "stdio.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
    
class Retina {
  
 public:
  
  /**
     @brief default constructor
  **/
  Retina() {

    initialize();

  }

  /**
     @brief non-default constructor
  **/
  Retina(std::string in_fileContext, std::string in_fileName) {

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
    ~Retina();
  
  /**
     @brief prints the object to cout
  **/
  virtual void
    print(); 

  /**
     @brief get the zone at a given index
  **/
  virtual Zone*
    getZone(int in_index);

 /**
     @brief get the number of zones stored
  **/
  virtual int
    getNumZones();

 /**
     @brief get max x value for all zones
  **/
  virtual int
    getMaxX();

 /**
     @brief get max y value for all zones
  **/
  virtual int
    getMaxY();

  /**
     @brief load content from XML file
  **/
  virtual void
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
  std::vector<Zone*> d_zones;

};

#endif
