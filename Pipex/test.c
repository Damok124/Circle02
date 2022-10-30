#include <unistd.h>
#include <stdio.h>

//tester le retour d'erreur d'execve avec une cmd inexistante

int main(int ac, char **argv, char **env)
{
	//execve(validpath, cmd, env);
	execve("/usr/bin/cat", argv + 1, env);
	printf("watch out\n");
	(void)ac;
	(void)argv;
	return (0);
}
