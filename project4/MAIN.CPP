#include "RANDOM.H"
#include "TIMER.H"

#include "SORTLIST.H"   // SORTABLE LIST SPECIFICATION
#include <iostream>
using namespace std;

//Main.cpp is the test driver to test the Sortlist class. 
//It contains user interface, filling the list with random integers, 
//calling Sortlist sorting functions and calculate the CPU time, 
//the number of comparison of keys, and the number of assignments of 
//list entries during the sorting list.

void write_entry(Record &c)
{
   cout << ((Key) c).the_key() << " ";
}
 
void help()
{
   cout << "User options are:\n"
        << "[H]elp  [Q]uit  (re)[F]ill list \n"
        << "write [D]ata  write sorted [O]utput \n"

        << "[0] insertion sort \n"
        << "[1] selection sort \n"
        << "[2] shell sort     \n"
        << "[3] quick sort\n"
        << "[4] heap sort\n"
        << "[5] bubble sort \n"
		<< "[6] merge sort \n"
        << endl;
}

void intro()
{
   cout << "Testing program for sorting methods for a contiguous list."
        << endl;
   help ();
}

int main()
{
   List<Record> s; List<Record> t = s;  //  help out a poor old compiler
   intro();

   int n;
   Random dice;
   bool report;
   Record target;
   Sortable_list<Record> the_list;
   Sortable_list<Record> copy_list;
   char command = ' ';

   while (command != 'q' && command != 'Q') {
      cout << "Enter a command of H, Q, F, O, D, " 
           << "0, 1, 2, 3, 4, 5, 6: " 
           << flush;
      cin  >> command;
      switch (command) {
         case 'h': case 'H':
           help();
         break;

         case 'd': case 'D':
            cout << "\nUnsorted list \n";
            the_list.traverse(write_entry);
            cout << endl;
         break;

         case 'o': case 'O':
            cout << "\nLast sorted list \n";
            copy_list.traverse(write_entry);
            cout << endl;
         break;

         case '0': case '1': case '2': case '3': case '4': case '5': case '6': 
         {
           copy_list = the_list;
           Key::comparisons = 0;
           Key::assignments = 0;
           Timer clock;
           switch (command) {
              case '0': 
              cout << "Insertion Sort ";
              copy_list.insertion_sort();
            break;
              case '1': 
              cout << "Selection Sort ";
              copy_list.selection_sort();
            break;
              case '2': 
              cout << "    Shell Sort ";
              copy_list.shell_sort();
            break;
              case '3': 
              cout << "    Quick Sort ";
              copy_list.quick_sort();
            break;
              case '4': 
              cout << "     Heap Sort ";
              copy_list.heap_sort();
            break;
              case '5': 
              cout << "     Bubble Sort ";
              copy_list.bubble_sort();
            break;
			  case '6': 
              cout << "     Merge Sort ";
              copy_list.merge_sort();
            break;
           }
           cout << "Time: " << clock.elapsed_time() << " seconds.\n"
                << "Comparisons: " << Key::comparisons << "\n"
                << "Assignments: " << Key::assignments
                << endl <<endl;
         }
         break;
         case 'f': case 'F':
           the_list.clear();
           cout << "How many list entries would you like? "
                << flush;
           cin  >> n;
           for (int i = 0; i < n; i++) {
              target = dice.random_integer(0, 10 * n);
              the_list.insert(i, target, report);
              if (report == false) {
                 cout << "Available list space filled up at " << i 
                      << " entries." << endl;
                 break;
              }
              if (report != true) i--;
           }
         break;
      }  // end of outer switch statement
   }     // end of outer while statement
}

