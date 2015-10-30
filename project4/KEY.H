#ifndef KEY_H
#define KEY_H

class Key {
   int key;
public:
   static int comparisons;  // # of Key comparisons
   static int assignments;	// # of Key Assignment
   static void initialize();
   static int sizeer();
   Key ( int x = 0 );
   int the_key() const;
   Key &operator =(const Key &y);
};

bool operator ==(const Key &y,const Key &x);
bool operator !=(const Key &y,const Key &x);
bool operator >=(const Key &y,const Key &x);
bool operator <=(const Key &y,const Key &x);
bool operator >(const Key &y,const Key &x);
bool operator <(const Key &y,const Key &x);


#endif