/**
 * @author Anthony DeDominic
 */
#include "grade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

enum TYPE 
{
	STUDENT_ID,
	QUIZ_1,
	QUIZ_2,
	MIDTERM,
	FINAL
};

char* open_file(const char *filename)
{
	FILE *student_file = fopen(filename, "r");

	if (student_file == NULL)
	{
		fprintf(stderr, "ERROR: CANNOT OPEN FILE");
		exit(EXIT_FAILURE);
	}

	if (fseek(student_file, 0, SEEK_END))
	{
		fprintf(stderr, "ERROR: CANNOT SEEK FILE");
		exit(EXIT_FAILURE);
	}

	size_t file_size = ftell(student_file);
	rewind(student_file);
	char *buffer = (char*) malloc(file_size);

	if(fread(buffer, 1, file_size, student_file) != file_size)
	{
		fprintf(stderr, "ERROR: CANNOT READ FILE");
		exit(EXIT_FAILURE);
	}
	
	fclose(student_file);
	return buffer;	
}

void save_to_file(const std::vector<Student> &students, const char *filename)
{
	FILE *outfile = fopen(filename, "w+");
	
	// if file could not be opened, error out and quit
	if (outfile == NULL)
	{
		fprintf(stderr, "ERROR: CANNOT OPEN FILE");
		exit(EXIT_FAILURE);
	}

	// top most row describing what the values mean
	if(fprintf(outfile, "StuID\tQuiz1\tQuiz2\tMidterm\tFinal\tAverage\tFinal Grade\n") < 0)
	{
		fprintf(stderr, "ERROR CANNOT WRITE TO FILE");
		exit(EXIT_FAILURE);
	}
	
	// NEED c++11 or gnu++11!!!
	// takes all students and writes a row of all it's data
	for (Student student : students)
	{	
		if(fprintf(outfile, "%s\t%d\t%d\t%d\t%d\t%lf\t%c\n",
				student.student_id,student.getQuiz1(),
				student.getQuiz2(),student.getMidterm(),
				student.getFinal_t(),student.getAverage(),
				student.getLetter_grade()) < 0)
		{
			fprintf(stderr, "ERROR CANNOT WRITE TO FILE");
			exit(EXIT_FAILURE);
		}
	}
	
	// ALWAYS CLOSE FILE WHEN DONE
	fclose(outfile);
}

void expected_output()
{
	printf("StuID\tQuiz1\tQuiz2\tMidterm\tFinal\tAverage\tFinal Grade\n");
	printf("0001\t8\t9\t100\t90\t91.250000\tA\n");
	printf("0002\t7\t9\t70\t90\t82.500000\tB\n");
	printf("0003\t7\t8\t75\t80\t77.500000\tC\n");
	printf("0004\t9\t9\t90\t85\t87.500000\tB\n");
	printf("0005\t6\t7\t70\t75\t71.250000\tC\n");
	printf("0006\t5\t5\t60\t60\t57.500000\tF\n");
	printf("0007\t8\t7\t100\t90\t88.750000\tB\n");
	printf("0008\t7\t7\t50\t60\t60.000000\tD\n");
	printf("0009\t9\t9\t85\t92\t89.750000\tB\n");
	printf("0010\t7\t6\t60\t70\t66.250000\tD\n");
}

int main(int argc, char **argv)
{
	// who needs static arrays?
	std::vector<Student> students;

	// since the instructions label the test data as "input.dat"
	char *file_data = open_file("input.dat");

	// get number of students, UNUSED
	char *readval = strtok(file_data, " \n");
	// discard the number at the top indicating how many students
	readval = strtok(NULL, " \n");

	int i = 0;
	// read while values are still being pulled out
	while (readval != NULL)
	{
		// See enum at top
		switch (i)
		{
			case STUDENT_ID:
				students.push_back(readval);
				break;
			case QUIZ_1:
				students.back().setQuiz1(atoi(readval));
				break;
			case QUIZ_2:
				students.back().setQuiz2(atoi(readval));
				break;
			case MIDTERM:
				students.back().setMidterm(atoi(readval));
				break;
			case FINAL:
				students.back().setFinal_t(atoi(readval));
		}
		// increment if value over FINAL, reset for next student
		if (++i > FINAL)
		{
			i = 0;
		}

		// read next space or newline seperated value
		readval = strtok(NULL, " \n");
	}

	// close out malloc'd data from mem
	free(file_data);
	// save file data to file
	save_to_file(students, "students.txt");
	// EXPECTED OUTPUT
	expected_output();
	return 0;
}


