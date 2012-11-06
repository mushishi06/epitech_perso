/*
** main.c for tes in /home/belia-_r/afs/C/strace/ex2
**
** Made by belia-_r
** Login   <belia-_r@epitech.net>
**
** Started on  Thu Apr 26 13:43:47 2012 belia-_r
** Last update Thu Apr 26 18:41:16 2012 belia-_r
*/
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<sys/ptrace.h>
#include	<sys/types.h>
#include	<sys/time.h>
#include	<sys/resource.h>
#include	<sys/wait.h>

int		run_child(char *path, char** env)
{
  ptrace(PTRACE_TRACEME, 0, NULL, NULL);
  return (execvp(path, env));
}

void		run_dad(pid_t pid)
{
  int		status;
  struct rusage	rusage;

  wait4(0, &status, 0, &rusage);
  ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
}

void	run(char *path, char **env)
{
  pid_t		pid;
  pid = fork();
  if (pid == -1)
    perror("fork in run");
  if (pid == 0)
    run_child(path, env);
  else
    run_dad(pid);
  printf("The child tracing is now done.\n");
}

int	main(int ac, char **av, char **env)
{
  if (ac >= 2)
    run(av[1], env);
  return (EXIT_SUCCESS);
}
