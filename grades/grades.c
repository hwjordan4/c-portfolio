/*
 * Harrison
 * cs3540/01
 * 8/25/14
 * Assignment2
*/
#include <stdio.h>


int main(int argc, char* argv[])

{
	

	int sum = 0;
	int num_grades;
	int done = 0; //this is my loop flag
	
	const int MAX_SIZE = 40;
	int grades[MAX_SIZE];
	const int MAX_GRADE = 100;
	
	
	//printf("Enter the number of grades");
	//scanf("%d", &num_grades);
	//	while(num_grades < 1 || num_grades > 40)
	//		{
	//			printf("Must be between 1 and 40");
	//			scanf("%d", &num_grades); 
	//		}
			
	while(!done)
	{	
		printf("Enter a grade: ");
		int grade; 
		scanf("%d", &grade);
		if(grade < 0) 
		{
			done = 1;
		}
		else if (grade <= MAX_GRADE) 
		{
			//accumulator
			grades[num_grades] = grade;
			num_grades++;
			if(num_grades == MAX_SIZE)
			{
				done = 1;
			}
			 
		}
		else
		{
			printf("Enter a grade between 0 and 100\n");
		}
			
	}
	if(num_grades == 0)
	{
		printf("No grades to average");
	}
	else
	{
		int i;	
		for(i = 0; i < num_grades; i++)
		{
			sum += grades[i];
		}

		float ave = (float)sum/num_grades;
		printf("Average: %f\n ", ave);
	}
	return 0;
}

