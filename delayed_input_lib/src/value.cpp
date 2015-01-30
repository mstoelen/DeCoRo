#include "value.h"

Value :: ~Value() { }

void
Value :: initialize()
{

  d_tag = "not_defined";
  d_resolution = 999;
  d_min = -999.99;
  d_max = 999.99;
  d_stdDev = 999.99;
  d_activationFlag = false;
  d_hypothesisFlag = false;
  d_currentValue = 0.0;
  
}

void
Value :: print()
{

  printf("***** Value %s *****\n", d_tag.c_str());
  printf("  Current: %7.2f\n", d_currentValue);
  printf("  Resolution: %d\n", d_resolution);
  printf("  Min: %7.2f\n", d_min);
  printf("  Max: %7.2f\n", d_max);
  printf("  Std. dev. for input activation: %7.2f\n", d_stdDev);
  printf("  Activation flag: %d\n", d_activationFlag); 
  printf("  Hypothesis: %d\n", d_hypothesisFlag);
  printf("\n");   

}

double
Value :: getMin() {

  return d_min;

}

double
Value :: getMax() {

  return d_max;

}

int
Value :: getRes() {

  return d_resolution;

}

double
Value :: getStdDev() {

  return d_stdDev;

}

std::string
Value :: getTag() {

  return d_tag;

}

bool
Value :: getActivationFlag() {

  return d_activationFlag;

}

bool
Value :: getHypothesisFlag() {

  return d_hypothesisFlag;

}

double
Value :: getCurrent() {

  return d_currentValue;

}

void
Value :: setCurrent(double in_currentValue) {

  d_currentValue = in_currentValue;

}

void
Value :: setMin(double in_min) {

  d_min = in_min;

}

void
Value :: setMax(double in_max) {

  d_max = in_max;

}

void
Value :: setRes(int in_resolution) {

  d_resolution = in_resolution;

}

void
Value :: setStdDev(double in_stdDev) {

  d_stdDev = in_stdDev;

}

void
Value :: setTag(std::string in_tag) {

  d_tag = in_tag;

}

void
Value :: setActivationFlag(bool in_activationFlag) {

  d_activationFlag = in_activationFlag;

}

void
Value :: setHypothesisFlag(bool in_hypothesisFlag) {

  d_hypothesisFlag = in_hypothesisFlag;

}


