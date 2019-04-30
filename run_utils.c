# include	<sys/types.h>
# include	<sys/wait.h>
# include	<stdio.h>
# include	<stdarg.h>
# include	<unistd.h>

//
// fork/exec and wait for command 
//
int	run (char* cmd, ...) {
	va_list	ap;
	char*	argv [256];
	int	argc	= 0;
	char*	argp	= 0;
	pid_t	pid	= 0;

	va_start (ap, cmd);
	do	{
		argp	= va_arg (ap, char*);
		argv [argc++]	= argp;
	} while (argp);
	va_end (ap);
	pid	= fork ();
	if (pid == 0) {
		execv (cmd, argv);
	}
	else if (pid > 0) {
		waitpid (pid, 0, 0);
	}
	else	{
		perror ("fork: ");
	}
}
