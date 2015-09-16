#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_all_digits(char* id)
{
	int result = 0;
	if(id != NULL)
	{
		int i = 0;
		while (i < strlen(id) && isdigit(id[i]))
			i++;
		result = i == strlen(id);
	}
	return result;
}

char* create_copy(char* s)
{
	char* cpy = NULL;
	if(s != NULL)
	{
		cpy = malloc((strlen(s) +1) * sizeof(char));
		strcpy(cpy, s);
		cpy[strlen(s)] = 0;
	}
	return cpy;
}

student* create_student(char* stu_name, float stu_gpa, 
		        char* stu_stuid, char* stu_major, 
		        int stu_num_hours)
{
	student* s = NULL;
	if(stu_name != NULL && strlen(stu_name) > 0)
		if(0 <= stu_gpa && stu_gpa <= MAX_GPA)
			if(stu_stuid != NULL && strlen(stu_stuid) == STU_ID_SIZE
					&& is_all_digits(stu_stuid))
				if(stu_major != NULL && strlen(stu_major) > 0)
					if(stu_num_hours >= 0)
					{
						s = malloc(sizeof(student));
						s->name = create_copy(stu_name);
						s->stuid = create_copy(stu_stuid);
						s->major = create_copy(stu_major);
						s->gpa = stu_gpa;
						s->num_hours = stu_num_hours;
					}

	return s;
}

void delete_student(student* s)
{
	if(s != NULL)
	{
		free(s->name);
		free(s->major);
		free(s->stuid);
		free(s);
	}
}
