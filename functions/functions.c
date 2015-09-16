#include <stdio.h>


int mult(int a, int b);
void display(int c);
int greater_than(int d, int e);

int main()

{
	int x, y, z;
	printf("please input the first number to be multiplied: ");
	scanf("%d", &x);
	printf("please input the second number to be multiplied: ");
	scanf("%d", &y);
	z = mult(x, y);
	display(z);

	int f, g, h;
	printf("please input an integer: ");
	scanf("%d", &f);
	printf("please input another integer greater than the first: ");
	scanf("%d", &g);
	h = greater_than(f, g);
	if(h)
	{
		printf("%d is greater than %d\n", g, f);	
	}
	else
	{
		printf("%d is less than %d\n", g, f);
	}	

	return 0;
}

int mult(int a, int b)
{
	int t;
	t = a * b;
	return t;
}

void display(int c)
{
	printf("The product of your two numbers is %d\n", c);

}

int greater_than(int d, int e)
{
	if(d < e)
	{
		return 1;
	}	
	else
	{
		return 0;
	}

}





