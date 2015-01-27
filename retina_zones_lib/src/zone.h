#ifndef __ZONE_H
#define __ZONE_H

#include <assert.h>
#include "stdio.h"
#include <vector>
#include <string>
    
class Zone {
  
 public:
  
  /**
     @brief default constructor
  **/
  Zone() {

    initialize();

  }

  /**
     @brief non-default constructor
  **/
  Zone(std::string in_tag, int in_minX, int in_maxX, int in_minY, int in_maxY) {

    d_tag = in_tag;
    d_minX = in_minX;
    d_maxX = in_maxX;
    d_minY = in_minY;
    d_maxY = in_maxY;

  }
  
  /**
     @brief default destructor
  **/
  virtual 
    ~Zone();
  
  /**
     @brief prints the object to cout
  **/
  virtual void
    print(); 

  /**
     @brief get min x of zone
  **/
  virtual int
    getMinX(); 

  /**
     @brief get max x of zone
  **/
  virtual int
    getMaxX(); 

  /**
     @brief get min y of zone
  **/
  virtual int
    getMinY(); 

  /**
     @brief get max y of zone
  **/
  virtual int
    getMaxY(); 

  /**
     @brief get tag of of zone
  **/
  virtual std::string
    getTag(); 

  /**
     @brief get current value
  **/
  virtual double
    getCurrent();

 /**
     @brief set min x of zone
  **/
  virtual void
    setMinX(int in_minX); 

  /**
     @brief set max x of zone
  **/
  virtual void
    setMaxX(int in_maxX); 

 /**
     @brief set min y of zone
  **/
  virtual void
    setMinY(int in_minY); 

  /**
     @brief set max y of zone
  **/
  virtual void
    setMaxY(int in_maxY); 

  /**
     @brief set tag of zone
  **/
  virtual void
    setTag(std::string in_tag); 

  /**
     @brief set current value
  **/
  virtual void
    setCurrent(double in_currentValue);

 protected:

  /**
     @brief initialize
  **/
  void
    initialize();

 protected:

  std::string d_tag;

  int d_minX;
  int d_maxX;
  int d_minY;
  int d_maxY;

  double d_currentValue;

};

#endif
