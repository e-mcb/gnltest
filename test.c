#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h" 

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  /*count = 0;
  fd = open("1char.txt", O_RDONLY);
  while (1)
  {
    next_line = get_next_line(fd);
    if (next_line == NULL)
	{
		printf("[%d]:%s\n", count, next_line);
		break ;
	}
    count++;
    printf("[%d]:%s\n", count, next_line);
	free(next_line);
    next_line = NULL;
  }
  close(fd);*/ //file with only 1 character

   /* count = 0;
  fd = open("empty.txt", O_RDONLY);
  while (1)
  {
    next_line = get_next_line(fd);
    if (next_line == NULL)
  {
    printf("[%d]:%s\n", count, next_line);
    break ;
  }
    count++;
    printf("[%d]:%s\n", count, next_line);
  free(next_line);
    next_line = NULL;
  }
  close(fd);*/ //empty file

  //   count = 0;
  // fd = open("longline.txt", O_RDONLY);
  // while (1)
  // {
  //   next_line = get_next_line(fd);
  //   if (next_line == NULL)
  // {
  //   printf("%s\n", next_line);
  //   break ;
  // }
  //   count++;
  //   printf("[%d]:%s\n", count, next_line);
  // free(next_line);
  //   next_line = NULL;
  // }
  // close(fd); // a ton of character with no newline

  count = 0;
  fd = open("random.txt", O_RDONLY);
  while (777)
  {
    next_line = get_next_line(fd);
    if (next_line == NULL)
  {
    printf("%s\n", next_line);
    break ;
  }
    count++;
    printf("[%d]:%s\n", count, next_line);
  free(next_line);
    next_line = NULL;
  }
  close(fd); //lorem ipsum generator

  /*  count = 0;
  fd = open("newlines.txt", O_RDONLY);
  while (1)
  {
    next_line = get_next_line(fd);
    if (next_line == NULL)
  {
    printf("[%d]:%s\n", count, next_line);
    break ;
  }
    count++;
    printf("[%d]:%s\n", count, next_line);
  free(next_line);
    next_line = NULL;
  }
  close(fd);*/ //just a bunch of newlines

  return (0);
}
