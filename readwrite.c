#include <stdio.h>

int main()
{

	FILE *fp;
	int i = 0;

	fp = fopen("testfile.txt", "w");
	fprintf(fp, "%d", i);
	fclose(fp);

	while(i < 100){
	
		//read
		fp = fopen("testfile.txt", "r");
		fscanf(fp, "%d", &i);
		fclose(fp);

		//wait 1 second
		sleep(1);

		//write
		fp = fopen("testfile.txt", "w");
		i++;
		fprintf(fp, "%d", i);
		fclose(fp);

	}

	return 0;
}
