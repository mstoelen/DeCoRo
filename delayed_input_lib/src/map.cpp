#include "map.h"

Map :: ~Map() { }

void
Map :: initialize()
{

  d_tag = "not_defined";
  
}

void
Map :: print()
{

  printf("***** Map %s *****\n", d_tag.c_str());
  printf("  First tag: %s\n", d_tagFirst.c_str()); 
  printf("  First index: %d\n", d_indexFirst); 
  printf("  Second tag: %s\n", d_tagSecond.c_str()); 
  printf("  Second index: %d\n", d_indexSecond); 
  printf("  Is 1-dimensional: %d\n", d_is1D); 
  printf("\n");

}

int
Map :: getFirstIndex()
{
  return d_indexFirst;
}

bool
Map :: getIs1D()
{
  return d_is1D;
}

void
Map :: setFirstIndex(int in_first)
{
  d_indexFirst = in_first;
}

void
Map :: setSecondIndex(int in_second)
{
  d_indexSecond = in_second;
}

int
Map :: getSecondIndex()
{
  return d_indexSecond;
}

double
Map :: getSecondStdDev()
{
  return d_stdDevSecond;
}

std::string
Map :: getFirstTag()
{
  return d_tagFirst;
}

void
Map :: setFirstTag(std::string in_first)
{
  d_tagFirst = in_first;
}

void
Map :: setSecondTag(std::string in_second)
{
  d_tagSecond = in_second;
}

std::string
Map :: getSecondTag()
{
  return d_tagSecond;
}

std::string
Map :: getTag()
{
  return d_tag;
}

