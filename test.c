#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h" 

int main(void)
{
  int    fd[1024];
  char  *next_line;
  static int i = 0;
  static int j = 0;

  // fd[i] = open("1char.txt", O_RDONLY); //file with only 1 character
  // i++;
  // fd[i] = open("empty.txt", O_RDONLY); // empty file
  fd[i] = open("longline.txt", O_RDONLY); //a single line
  printf("%d\n", fd[i]);
  i++;
  fd[i] = open("random.txt", O_RDONLY); //lorem ipsum
  printf("%d\n", fd[i]);
  // fd = open("newlines.txt", O_RDONLY); //bunch of newlines
  // fd = open("noperms.txt", O_RDONLY); // no reading perms
  //fd = 0; //stdin

  
//   while (1)
//   {
//     next_line = get_next_line(fd[j]);
//     if (next_line == NULL)
// 	{
// 		printf("%s", next_line);
// 		break ;
// 	}
//     printf("%s", next_line);
// 	free(next_line);
//     next_line = NULL;
//     j++;
//     if (i == j)
//     	j = 0;
//   }
//   j = 0;
//   while (i != j)
//   {
//   	close(fd[j]);
//   	j++;
//   } 
//   return (0);
// }

	next_line = (get_next_line(fd[j]));
	printf("%s", next_line);
	j++;
  while (next_line)
	{
		next_line = (get_next_line(fd[j]));
		printf("%s", next_line);
	free(next_line);
    next_line = NULL;
    j++;
    if (i == j)
    	j = 0;
	}
  j = 0;
  while (i != j)
  {
  	close(fd[j]);
  	j++;
  } 
  return (0);
}