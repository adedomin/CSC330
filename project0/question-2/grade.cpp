/**
 * @author Anthony DeDominic
 */
#include "grade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Student::Student(const char *student_id)
{
	strncpy(this->student_id, student_id, 5);
	this->midterm = -1;
	this->final_t = -1;
	this->average = -1;
	this->letter_grade = 'e';
	this->quiz1 = -1;
	this->quiz2 = -1;
}

bool Student::calculateAverage()
{
	if (quiz1 == -1 || quiz2 == -1 || midterm == -1 || final_t == -1)
	{
		return false;
	}

	double quiz_average = (double)(quiz1+quiz2)/2.0 * 10;
	
	average = (quiz_average*.25)+(midterm*.25)+(final_t*.50); 
	calculateLetter_grade();
	return true;
}

bool Student::calculateLetter_grade()
{	
	if (average == -1)
	{
		letter_grade = 'e';
		return false;
	}
	if ((int)average > 89)
	{
		letter_grade = 'A';
	}
	else if ((int)average > 79)
	{
		letter_grade = 'B';
	}
	else if ((int)average > 69)
	{
		letter_grade = 'C';
	}
	else if ((int)average > 59)
	{
		letter_grade = 'D';
	}
	else
	{
		letter_grade = 'F';
	}

	return true;
}

int Student::getMidterm()
{
	return midterm;
}

// 
bool Student::setMidterm(int midterm)
{
	if (midterm < 0 || midterm > 100)
	{
		return false;
	}
	this->midterm = midterm;
	calculateAverage();
	return true;
}
	
int Student::getFinal_t()
{
	return final_t;
}

bool Student::setFinal_t(int final_t)
{
	if (final_t < 0 || final_t > 100)
	{
		return false;
	}
	this->final_t = final_t;
	calculateAverage();
	return true;
}

int Student::getQuiz1()
{
	return quiz1;
}

int Student::getQuiz2()
{
	return quiz2;
}

bool Student::setQuiz1(int quiz1)
{
	if (quiz1 < 0 || quiz1 > 10)
	{
		return false;
	}

	this->quiz1 = quiz1;
	calculateAverage();
	return true;
}

bool Student::setQuiz2(int quiz2)
{
	if (quiz2 < 0 || quiz2 > 10)
	{
		return false;
	}

	this->quiz2 = quiz2;
	calculateAverage();
	return true;
}

double Student::getAverage()
{
	return average;
}

char Student::getLetter_grade()
{
	return letter_grade;
}
