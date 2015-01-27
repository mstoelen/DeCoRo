#ifndef __XML_CONFIG_DEEP_H
#define __XML_CONFIG_DEEP_H

#include "xml_config.h"

#include "mxml.h"

#include <assert.h>
#include "stdio.h"
#include <string>
#include <sstream>
    
class XMLConfigDeep : public XMLConfig {
  
 public:
  
  /**
     @brief default constructor
  **/
  XMLConfigDeep() {

  }

  /**
     @brief non-default constructor
  **/
  XMLConfigDeep(std::string in_fileName, std::string in_contextName) {

    assert(loadFile(in_fileName));
    assert(openContextNode(in_contextName));

  }
  
  /**
     @brief default destructor
  **/
  virtual 
    ~XMLConfigDeep();
  
  /**
     @brief prints the object to cout
  **/
  virtual void
    print(); 

  /**
     @brief opens the next local node with given name, inside the current context node
  **/
  virtual bool
    openNextLocalNode(std::string in_name); 

};

#endif
