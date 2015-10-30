#ifndef REC_H
#define REC_H

#include "Key.h" 
class Record {
   Key key;
public:
   Record(int x);
   Record();

   // cast to Key  to conduct and size comparisons and assignments. 
   // do not override comparisons and assignments operators
   operator Key() const;  
   
};

#endif
