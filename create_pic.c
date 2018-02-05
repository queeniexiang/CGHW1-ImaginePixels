#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>



int main() {
  //Creating header for PPM file
  char header [128] = "P3\n500 500\n255\n";

  //Opening file
  int fd = open("picture.ppm", O_CREAT | O_TRUNC | O_RDWR);
  printf("fd: %d\n", fd);

  //Writing header to file
  write(fd, header, sizeof(header));

  //Seeding time to rand() 
  srand(time(NULL));

  //Creating buffer that will store each rgb value 
  char buffer[16];
  
  for (int count1 = 0; count1 < 500; count1++) {
    for (int count2 = 0; count2 < 500; count2++) {

      int red;
      int green;
      int blue;

      if (count1 == count2) {
	red = 255;
	green = 192;
	blue = 203;
      }

      else { 
	red = 255 - (count2%65); //(count1 + count2) % 256 + 100; //255;
	green = count2 % 256 + (rand()%15); //200 + count2%56;
	blue = 255 - (rand()%256);
      }
      
      //Printing rand_num to buffer and converts it to a string
      sprintf(buffer, "%d %d %d ", red, green, blue);

      //Write buffer to the file 
      write(fd, buffer, sizeof(buffer));
    }

    //Writes a newline to the file
    write(fd, "\n", sizeof("\n"));
   }

  //Closes file
  close(fd);
  return 0;  
}
