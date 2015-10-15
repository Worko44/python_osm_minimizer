
#ifndef _MACRO_H_
#define _MACRO_H_

typedef enum	type_osm 
{
  NO_TYPE = 0,
  TYPE_XML = 1,
  TYPE_OSM = 2,
  TYPE_BOUNDS = 3,
  TYPE_NODE = 4,
  TYPE_TAG = 5,
  TYPE_WAY = 6,
  TYPE_ND = 7,
  TYPE_RELATION = 8,
  TYPE_MEMBER = 9,
  END_TYPE = 10,
  END_XML = 11,
  END_OSM = 12,
  END_BOUNDS = 13,
  END_NODE = 14,
  END_TAG = 15,
  END_WAY = 16,
  END_ND = 17,
  END_RELATION = 18,
  END_MEMBER = 19,

}		type_osm;


#define END_TYPE_LINE 0
#define NO_END_TYPE_LINE  1


#endif
