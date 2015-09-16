#include "apue.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static volatile sig_atomic_t sigflag;
static sigset_t newmask, oldmask, zeromask;
static void readwrite(int i);

static void
sig_usr(int signo)
{
  if (signo == SIGUSR1)
    printf("received SIGUSR1\n");
  else if (signo == SIGUSR2)
    printf("received SIGUSR2\n");
  else
    printf("received signal %d\n", signo);

}


int main()
{
	// CREATE FILE TO BE MODIFIED
        int i = 0;


        while(i < 100)
	{
	// FORK PIDs
	pid_t pid;
	
	if((pid = fork()) < 0)
		printf("Fork error");
		else
		{
		
		TELL_WAIT();
		
			if(i%2==0)
				{
				sig_usr(SIGUSR1);
				WAIT_PARENT();
				readwrite(i);
				TELL_CHILD(0);
				}
			else
				{
        			sig_usr(SIGUSR2);
				WAIT_CHILD();
				readwrite(i);
				TELL_PARENT(getppid());
				}
		}

	}	

return 0;
}

static void readwrite(int i)
{
		FILE *fp;
		fp = fopen("testfile.txt", "w");
        	fprintf(fp, "%d", i);
        	fclose(fp);

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


void
TELL_WAIT(void)
{
	if(signal(SIGUSR1, sig_usr) == SIG_ERR)
	{
		printf("signal(SIGUSR1) error");
		exit(1);
	}
	if(signal(SIGUSR2, sig_usr) == SIG_ERR)
	{
		printf("signal(SIGUSR2) error");
		exit(1);
	}
	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGUSR2);
	sigaddset(&newmask, SIGUSR1);
	
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		{
			printf("SIG_BLOCK error");
			exit(1);
		}

}

void
TELL_PARENT(pid_t pid)
{
	kill(pid, SIGUSR2);
}

void
WAIT_PARENT(void)
{
	while (sigflag == 0)
		sigsuspend(&zeromask);
	sigflag = 0;

	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		{
			printf("SIG_SETMASK error");
			exit(1);
		}

}

void
TELL_CHILD(pid_t pid)
{
	kill(pid, SIGUSR1);
}

void
WAIT_CHILD(void)
{
	while (sigflag == 0)
		sigsuspend(&zeromask);
	sigflag = 0;

	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		{
			printf("SIG_SETMASK error");
			exit(1);
		}
}
	
