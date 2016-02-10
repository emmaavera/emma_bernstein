#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {

  int fileID = 0;
  int xres = 500; int yres = 500;
  int r = 3; int b = 9; int g = 27;

  fileID = open("myimage.ppm", O_CREAT|O_WRONLY, 0644);

  //Write the header
  char* header = "P3 500 500 255 ";
  write(fileID, header, 15);
 

  for (int i = 0; i < xres; i++) {
    for (int j = 0; j < yres; j++) {

      r = i*i + j*j;
      r %= 225;
      g = 255; 
      b = i * j;
      b %= 25;
      b += 200;
      dprintf(fileID, "%d %d %d ", r, b, g);
    }
  }

  close(fileID);
  return 1;

}
