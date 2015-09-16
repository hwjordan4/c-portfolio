/* 
 	Harrison
 	cs3540/01
 	9/10/14
 	Assignment 3
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

int* get_data(int num_grades);
float cal_average(int num_grades, int* grades);
void display_average(float ave);
float cal_std_deviation(int* grades, int num_grades, float ave);
void display_std_deviation(float std);
float cal_median(int* grades, int num_grades);
int* sort_array(int* grades, int num_grades);
void display_median(float m);
const int MAX_GRADE = 100;

int main()

{	

	int num_grades = 0;
	int* grades;
	float ave;
	float std;
	float m;
	printf("Enter the number of grades: ");
	scanf("%d", &num_grades);
	
	grades = get_data(num_grades);
	ave = cal_average(num_grades, grades);
	display_average(ave);
	std = cal_std_deviation(grades, num_grades, ave);
	display_std_deviation(std);
	m = cal_median(grades, num_grades);	
	display_median(m);
	
	return 0;

}


int* get_data(int num_grades)
{
	int *a = malloc(num_grades * sizeof(int));
	int i;
	for(i=0; i<num_grades; i++)
	{
		printf("Enter a grade: ");
		int grade;
		scanf("%d", &grade);
		while(grade < 0 || grade > MAX_GRADE)
		{
			printf("Grades need to be >= 0 and <= 100\n");
			printf("Enter a grade: ");
			scanf("%d", &grade);
		}
		a[i] = grade;
	}
	return a;

}

float cal_average(int num_grades, int* grades)

{
	float ave;
	float sum=0;
	int i;
	for(i=0; i<num_grades; i++)
	{
		sum += grades[i];
	}
	ave = (float)(sum/num_grades);
	return ave;
}

void display_average(float a)
{
	printf("Average: %2f\n", a);
}


float cal_std_deviation(int* grades, int num_grades, float ave)
{
	int i;
	float squared;
	float diff_from_average;
	float sum=0;
	float std_deviation;
	for(i=0; i < num_grades; i++)
	{
		diff_from_average = grades[i] - ave;
		squared = diff_from_average * diff_from_average;	
		sum += squared; 
	}		
	std_deviation = (float)sqrt(sum/num_grades);

	return std_deviation;
}

void display_std_deviation(float std)
{
	printf("Standard Deviation: %2f\n", std);
}

int* sort_array(int* grades, int num_grades)
{
	int i, k, swap;

  	for (i = 0 ; i < num_grades - 1; i++)
  	{
    		for (k = 0 ; k < num_grades - i - 1; k++)
    		{
      			if (grades[k] > grades[k+1])
      			{
        			swap = grades[k];
        			grades[k] = grades[k+1];
        			grades[k+1] = swap;
      			}
    		}
  	}
	return grades;
}

float cal_median(int* grades, int num_grades)
{
	int  a, half;
	float b, median, half_odd;
	grades = sort_array(grades, num_grades);
	if(num_grades % 2 == 0)
	{
		half = num_grades / 2;
		a = grades[half];
		b = grades[half-1];
		median = (float)((a+b)/2);
	}
	else
	{
		half_odd = num_grades / 2;
		half_odd += 0.5;
		a = (int)half_odd;
		median = grades[a];
	}
	return median;
}

void display_median(float m)
{
	printf("Median: %2f\n", m);
}



