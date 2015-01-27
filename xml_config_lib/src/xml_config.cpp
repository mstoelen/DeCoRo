#include "xml_config.h"

XMLConfig :: ~XMLConfig() { }

void
XMLConfig :: print()
{

  printf("********** XMLConfig **********\n");
  // TODO

}

bool
XMLConfig :: loadFile(std::string in_fileName) 
{

  FILE *fp;
  bool returnValue = true;

  fp = fopen(in_fileName.c_str(), "r");

  if(fp != NULL) {
    d_tree = mxmlLoadFile(NULL, fp, MXML_OPAQUE_CALLBACK);
    fclose(fp);
  }
  else {
    returnValue = false;
  }

  return returnValue;
}

bool
XMLConfig :: openContextNode(std::string in_name) {

  mxml_node_t *node = mxmlFindElement(d_tree,d_tree,in_name.c_str(),NULL,NULL,MXML_DESCEND);
  
  if(node == NULL) {
    return false;
  }
  else {
    d_contextNode = node;
    d_localNode = d_contextNode;
    return true;
  }
}

bool
XMLConfig :: getInt(std::string in_name, int& out_value) {

  mxml_node_t *node = mxmlFindElement(d_localNode,d_localNode,in_name.c_str(),NULL,NULL,MXML_DESCEND);

  if(node == NULL) {
    return false;
  }
  else {
    std::string string = mxmlGetOpaque(node);
    out_value = stringToInt(string);
    return true;
  }
}

bool
XMLConfig :: getDouble(std::string in_name, double& out_value) {

  mxml_node_t *node = mxmlFindElement(d_localNode,d_localNode,in_name.c_str(),NULL,NULL,MXML_DESCEND);

  if(node == NULL) {
    return false;
  }
  else {
    std::string string = mxmlGetOpaque(node);
    out_value = stringToDouble(string);
    return true;
  }
}

bool
XMLConfig :: getBool(std::string in_name, bool& out_value) {

  mxml_node_t *node = mxmlFindElement(d_localNode,d_localNode,in_name.c_str(),NULL,NULL,MXML_DESCEND);

  if(node == NULL) {
    return false;
  }
  else {
    std::string string = mxmlGetOpaque(node);
    out_value = stringToBool(string);
    return true;
  }
}

bool
XMLConfig :: getString(std::string in_name, std::string& out_string) {

  mxml_node_t *node = mxmlFindElement(d_localNode,d_localNode,in_name.c_str(),NULL,NULL,MXML_DESCEND);

  if(node == NULL) {
    return false;
  }
  else {
    out_string = mxmlGetOpaque(node);
    return true;
  }
}

bool
XMLConfig :: getStringAttribute(std::string in_name, std::string& out_string) {

  out_string = mxmlElementGetAttr(d_localNode,in_name.c_str());

  if(out_string.length() == 0) {
    return false;
  }
  else {
    return true;
  }
}

double
XMLConfig :: stringToDouble(const std::string& s) {

  std::istringstream iss(s);
  double t;
  iss >> std::dec >> t;

  return t;
}

int
XMLConfig :: stringToInt(const std::string& s) {

  std::istringstream iss(s);
  int t;
  iss >> t;

  return t;
}

bool
XMLConfig :: stringToBool(std::string const& s)
{
  return s != "0";
}


