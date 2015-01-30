#ifndef __XML_CONFIG_H
#define __XML_CONFIG_H

#include "mxml.h"

#include <assert.h>
#include "stdio.h"
#include <string>
#include <vector>
#include <sstream>
    
class XMLConfig {
  
 public:
  
  /**
     @brief default constructor
  **/
  XMLConfig() {

  }

  /**
     @brief non-default constructor
  **/
  XMLConfig(std::string in_fileName, std::string in_contextName) {

    assert(loadFile(in_fileName));
    assert(openContextNode(in_contextName));

  }
  
  /**
     @brief default destructor
  **/
  virtual 
    ~XMLConfig();
  
  /**
     @brief prints the object to cout
  **/
  virtual void
    print(); 

  /**
     @brief load content from XML file
  **/
  virtual bool
    loadFile(std::string in_fileName);

  /**
     @brief open the top level element of the XML file structure
  **/
  virtual bool
    openContextNode(std::string in_name);

  /**
     @brief get an int value with a given name from local node
  **/
  virtual bool
    getInt(std::string in_name, int& out_value);

  /**
     @brief get a double value with a given name from local node
  **/
  virtual bool
    getDouble(std::string in_name, double& out_value);

  /**
     @brief get an bool value with a given name from local node
  **/
  virtual bool
    getBool(std::string in_name, bool& out_value);

  /**
     @brief get a string with a given name from local node
  **/
  virtual bool
    getString(std::string in_name, std::string& out_string);

  /**
     @brief get string attribute of local node
  **/
  virtual bool
    getStringAttribute(std::string in_name, std::string& out_string);

  /**
     @brief get a vector of strings with a given name from local node
  **/
  virtual bool
    getVectorOfInt(std::string in_name, std::vector<int>& out_vector);

 protected:

  /**
     @brief conversion from string to double
  **/
  virtual double
    stringToDouble(const std::string& s);

 /**
     @brief conversion from string to int
  **/
  virtual int
    stringToInt(const std::string& s);

  /**
     @brief conversion from string to bool
  **/
  virtual bool
    stringToBool(std::string const& s);

 protected:

  mxml_node_t *d_tree;
  mxml_node_t *d_contextNode;
  mxml_node_t *d_localNode;

};

#endif
