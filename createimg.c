#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
  int r, g , b , i , j ;
  char rgb [100];
  r = 1;
  g = 2;
  b = 3;
  
  int fd = open("image.ppm", O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0644);
  write(fd, "P3\n700 700 256\n" , 40);

  for (i = 0 ; i < 700 ; i++){
    for (j = 0; j < 700 ; j++){
      r = (r + 1) % 256;
      g = (g + 2) % 256;
      b = (3 + b) % 256;
    
    snprintf(rgb, sizeof(rgb), "%d %d %d\n", r , g , b);
    write (fd, rgb, sizeof(rgb));
	}
  }
    return 0;
}