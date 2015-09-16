/**
 * @author Anthony DeDominic
 */
#ifndef GRADES_HEAD_DEF
#define GRADES_HEAD_DEF
class Student
{
	int midterm;
	int final_t;
	int quiz1;
	int quiz2;
	// total grade value
	double average;
	char letter_grade;

	// run every time a setter is called
	// total quizes are 25% of grade
	// midterm is 25% of grade
	// final is 50% of grade
	bool calculateAverage();
	// run everytime average succeeds
	bool calculateLetter_grade();

	public:
	
	// not safe, but easier for this assignment
	char student_id[5];
	Student(const char*);

	int getMidterm();
	// false if midterm does not meet requirements, NOT SET
	// midterm must be greater than 0 and less than 101
	bool setMidterm(int);

	int getFinal_t();
	// false if final does not meet requirements, NOT SET
	// final must be greater than 0 and less than 101
	bool setFinal_t(int);
	
	int getQuiz1();
	// false if quiz does not meet requirements, NOT SET
	// quiz 1 must be greater than 0 and less than 11
	bool setQuiz1(int);
	int getQuiz2();
	// false if quiz does not meet requirements, NOT SET
	// quiz 2 must be greater than 0 and less than 11
	bool setQuiz2(int);
	
	// note no setter, if value -1, it's NOT SET
	double getAverage();
	// note no setter, if value 'e', it's NOT SET
	char getLetter_grade();
};
#endif

