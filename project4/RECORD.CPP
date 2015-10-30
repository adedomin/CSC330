#include "RECORD.H" 
Record::Record()
{
   key = 0;
}
 
Record::Record(int x)
{
   key = x;
}
 
Record::operator Key() const
{
   return key;
}
