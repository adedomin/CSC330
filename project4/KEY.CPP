#include "KEY.H"
int Key::comparisons = 0;
int Key::assignments = 0;
 
void Key::initialize()
{
   comparisons = 0;
}
 
int Key::sizeer()
{
   return comparisons;
}
 
Key::Key (int x)
{
   key = x;
}
 
Key &Key::operator =(const Key &x)
{
   Key::assignments++;
   key = x.key;
   return *this;
}
 
bool operator ==(const Key &x, const Key &y)
{
   Key::comparisons++;
   return x.the_key() == y.the_key();
}
 
bool operator !=(const Key &x, const Key &y)
{
   Key::comparisons++;
   return x.the_key() != y.the_key();
}
 
bool operator >=(const Key &x, const Key &y)
{
   Key::comparisons++;
   return x.the_key() >= y.the_key();
}
 
bool operator <=(const Key &x, const Key &y)
{
   Key::comparisons++;
   return x.the_key() <= y.the_key();
}
 
bool operator >(const Key &x, const Key &y)
{
   Key::comparisons++;
   return x.the_key() > y.the_key();
}
 
bool operator <(const Key &x, const Key &y)
{
   Key::comparisons++;
   return x.the_key() < y.the_key();
}
 
int Key::the_key() const
{
   return key;
}
