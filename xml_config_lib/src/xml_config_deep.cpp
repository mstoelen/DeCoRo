#include "xml_config_deep.h"

XMLConfigDeep :: ~XMLConfigDeep() { }

void
XMLConfigDeep :: print()
{

  printf("********** XMLConfigDeep **********\n");
  // TODO

}

bool
XMLConfigDeep :: openNextLocalNode(std::string in_name) {

  d_localNode = mxmlFindElement(d_localNode,d_tree,in_name.c_str(),NULL,NULL,MXML_DESCEND);
  
  if(d_localNode == NULL) {
    d_localNode = d_contextNode;
    return false;
  }
  else {
    return true;
  }
  
}


