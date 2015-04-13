#ifndef __MAP_H
#define __MAP_H

#include "value.h"

#include <assert.h>
#include "stdio.h"
#include <vector>
#include <string>
    
class Map {
  
 public:
  
  /**
     @brief default constructor
  **/
  Map(std::string in_tag, std::string in_tagFirstInput, std::string in_tagSecondInput, double in_stdDevSecondInput, bool in_is1D) {
    
    d_tag = in_tag;
    d_tagFirst = in_tagFirstInput;
    d_tagSecond = in_tagSecondInput;
    d_stdDevSecond = in_stdDevSecondInput;
    d_is1D = in_is1D;
  }
  
  /**
     @brief default destructor
  **/
  virtual 
    ~Map();
  
  /**
     @brief prints the object to cout
  **/
  virtual void
    print();  

  /**
     @brief get first index
  **/
  virtual int
    getFirstIndex(); 

  /**
     @brief set first index
  **/
  virtual void
    setFirstIndex(int in_first); 

  /**
     @brief get second index
  **/
  virtual int
    getSecondIndex(); 

  /**
     @brief get std. dev. of second
  **/
  virtual double
    getSecondStdDev(); 

  /**
     @brief set second index
  **/
  virtual void
    setSecondIndex(int in_second);

  /**
     @brief get first index
  **/
  virtual std::string
    getFirstTag(); 

  /**
     @brief set first index
  **/
  virtual void
    setFirstTag(std::string in_first); 

  /**
     @brief get second index
  **/
  virtual std::string
    getSecondTag(); 

  /**
     @brief set second index
  **/
  virtual void
    setSecondTag(std::string in_second);  

  /**
     @brief get map tag
  **/
  virtual std::string
    getTag(); 

  /**
     @brief get if is 1D or not
  **/
  virtual bool
    getIs1D();

 protected:

  /**
     @brief initialize
  **/
  void
    initialize();

 protected:
  
  std::string d_tag;
  std::string d_tagFirst;
  std::string d_tagSecond;
  int d_indexFirst;
  int d_indexSecond;
  double d_stdDevSecond;
  bool d_is1D;

};

#endif
