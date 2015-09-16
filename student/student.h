#ifndef _STUDENT_H
#define _STUDENT_H

#define MAX_GPA 4.0
#define STU_ID_SIZE 9
//name, gpa, stuid, major, num_hours
typedef struct {
	char* name;
	float gpa;
	char* stuid;
	char* major;
	int num_hours;
	
}student;

//student a;


//preconditions:
//stu_name != NULL
//0 < stu_gpa <= MAX_GPA
//stud_id != NULL
//stu_major != NULL
//stu_num_hours >= 0
student* create_student(char* stu_name, float stu_gpa, char* stu_stuid,
			char* stu_major, int stu_num_hours);

int is_on_probation(student* s);
void display_student(student* s);
void delete_student(student* s);


#endif
