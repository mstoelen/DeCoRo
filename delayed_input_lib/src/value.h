#ifndef __VALUE_H
#define __VALUE_H

#include <assert.h>
#include "stdio.h"
#include <vector>
#include <string>
    
class Value {
  
 public:
  
  /**
     @brief default constructor
  **/
  Value() {

    initialize();

  }

  /**
     @brief non-default constructor
  **/
  Value(std::string in_tag, int in_resolution, double in_min, double in_max, double in_stdDev, bool in_activationFlag, bool in_hypothesisFlag) {

    d_tag = in_tag;
    d_resolution = in_resolution;
    d_min = in_min;
    d_max = in_max;
    d_stdDev = in_stdDev;
    d_activationFlag = in_activationFlag;
    d_hypothesisFlag = in_hypothesisFlag;

  }
  
  /**
     @brief default destructor
  **/
  virtual 
    ~Value();
  
  /**
     @brief prints the object to cout
  **/
  virtual void
    print(); 

  /**
     @brief get min value
  **/
  virtual double
    getMin(); 

  /**
     @brief get max value
  **/
  virtual double
    getMax(); 

  /**
     @brief get resolution
  **/
  virtual int
    getRes(); 

  /**
     @brief get standard deviation used when activating with value
  **/
  virtual double
    getStdDev(); 

  /**
     @brief get tag of value
  **/
  virtual std::string
    getTag(); 

  /**
     @brief get activation flag
  **/
  virtual bool
    getActivationFlag(); 

  /**
     @brief get hypothesis flag
  **/
  virtual bool
    getHypothesisFlag();

 /**
     @brief get current value
  **/
  virtual double
    getCurrent();

 /**
     @brief get current value
  **/
  virtual void
    setCurrent(double in_currentValue);

 /**
     @brief set min value
  **/
  virtual void
    setMin(double in_min); 

  /**
     @brief set max value
  **/
  virtual void
    setMax(double in_max); 

  /**
     @brief set resolution
  **/
  virtual void
    setRes(int in_resolution); 

  /**
     @brief set standard deviation used when activating with value
  **/
  virtual void
    setStdDev(double in_stdDev); 

  /**
     @brief set tag of value
  **/
  virtual void
    setTag(std::string in_tag); 

  /**
     @brief set activation flag
  **/
  virtual void
    setActivationFlag(bool in_activityFlag); 

  /**
     @brief set hypothesis flag
  **/
  virtual void
    setHypothesisFlag(bool in_hypothesisFlag);

 protected:

  /**
     @brief initialize
  **/
  void
    initialize();

 protected:

  std::string d_tag;
  int d_resolution;
  double d_min;
  double d_max;
  double d_stdDev;
  bool d_activationFlag;
  bool d_hypothesisFlag;

  double d_currentValue;

};

#endif
