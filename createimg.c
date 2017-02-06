#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
  int r, g , b , i , j ;
  char rgb [100];

  int fd = open("image.ppm", O_WRONLY | O_CREAT | O_EXCL, 0666);
  write(fd, "P3 \n 700 700 256" , 40);

  for (i = 0 ; i < 700 ; i++){
    for (j = 0; j < 700 ; j++){
      r = (r + 1) % 255;
      g = (g + r) % 255;
      b = (g + b) % 255;
    }
    snprintf(rgb, sizeof(rgb), "%d %d %d \n", r , g , b);
    write (fd, rgb, sizeof(rgb));
  }
    return 0;
}
