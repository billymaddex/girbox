/* 
Girbox

Copyright (C) 2015 Billy Maddex

This file is part of Girbox.

Girbox is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Girbox is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Girbox.  If not, see <http://www.gnu.org/licenses/>.

Author: Billy Maddex 
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "ps3ir.h"

void delay(int milliseconds)
{
  long pause;
  clock_t now,then;

  pause = milliseconds*(CLOCKS_PER_SEC/1000);
  now = then = clock();
  while( (now-then) < pause )
    now = clock();

  return;
}

int ps3_open(char *device)
{
  int ps3_ir;
  
  /* Open the Device with blocking reads. */
  ps3_ir = open(device, O_RDWR);

  if (ps3_ir < 0) {
    perror("Unable to open device");
  }

  return ps3_ir;
}

void ps3_close(int ps3_ir)
{
  int res;
  char buf[16];

  memset(buf, 0x0, sizeof(buf));
  
  /* Send a Report to the Device */
  /* Initialize device */
  buf[0] = 0x00; /* Report Number */
  buf[1] = 0xAA;
  buf[2] = 0x00;
  buf[3] = 0x55;
  buf[4] = 0xA5;
  buf[5] = 0x5A;
  buf[6] = 0x66;
  buf[7] = 0x99;
  buf[8] = 0x69;
  res = write(ps3_ir, buf, 9);
  if (res < 0) {
    printf("Error: %d\n", errno);
    perror("write");
  } else {
    printf("write() wrote %d bytes\n", res);
  }
  
  close(ps3_ir);

  return;
}

/* 0x00 = Teach Remote, 0x01 = Virtual Remote */
void ps3_set_mode(int ps3_ir, char mode)
{
  int i, res;
  char buf[16];

  memset(buf, 0x0, sizeof(buf));

  /* Send a Report to the Device */
  /* Initialize device */
  buf[0] = 0x00; /* Report Number */
  buf[1] = 0xAA;
  buf[2] = 0x00;
  buf[3] = 0x55;
  buf[4] = 0xA5;
  buf[5] = 0x5A;
  buf[6] = 0x66;
  buf[7] = 0x99;
  buf[8] = 0x69;
  res = write(ps3_ir, buf, 9);
  if (res < 0) {
    printf("Error: %d\n", errno);
    perror("write");
  } else {
    printf("write() wrote %d bytes\n", res);
  }

  /* Send a Report to the Device */
  /* Set Mode */
  buf[0] = 0x00; /* Report Number */
  buf[1] = 0x00;
  buf[2] = 0xA6;
  buf[3] = 0x00;
  buf[4] = 0x00;
  buf[5] = 0x00;
  buf[6] = 0x00;
  buf[7] = 0x00;
  buf[8] = 0x00;
  res = write(ps3_ir, buf, 9);
  if (res < 0) {
    printf("Error: %d\n", errno);
    perror("write");
  } else {
    printf("write() wrote %d bytes\n", res);
  }

  /* Get a report from the device */
  res = read(ps3_ir, buf, 16);
  if (res < 0) {
    perror("read");
  } else {
    printf("read() read %d bytes:\n\t", res);
    for (i = 0; i < res; i++)
      printf("%hhx ", buf[i]);
    puts("\n");
  }

  /* Send a Report to the Device */
  /* set mode based on mode variable */
  buf[0] = 0x00; /* Report Number */
  buf[1] = 0x00;
  buf[2] = 0xA5;
  buf[3] = mode;
  buf[4] = 0x00;
  buf[5] = 0x00;
  buf[6] = 0x00;
  buf[7] = 0x00;
  buf[8] = 0x00;
  res = write(ps3_ir, buf, 9);
  if (res < 0) {
    printf("Error: %d\n", errno);
    perror("write");
  } else {
    printf("write() wrote %d bytes\n", res);
  }

  /* Get a report from the device */
  res = read(ps3_ir, buf, 16);
  if (res < 0) {
    perror("read");
  } else {
    printf("read() read %d bytes:\n\t", res);
    for (i = 0; i < res; i++)
      printf("%hhx ", buf[i]);
    puts("\n");
  }
	
  /* Send a Report to the Device */
  /* Initialize device */
  buf[0] = 0x00; /* Report Number */
  buf[1] = 0xAA;
  buf[2] = 0x00;
  buf[3] = 0x55;
  buf[4] = 0xA5;
  buf[5] = 0x5A;
  buf[6] = 0x66;
  buf[7] = 0x99;
  buf[8] = 0x69;
  res = write(ps3_ir, buf, 9);
  if (res < 0) {
    printf("Error: %d\n", errno);
    perror("write");
  } else {
    printf("write() wrote %d bytes\n", res);
  }

  return;
}

/* key codes in PS3_Keys.h */
void ps3_keydown(int ps3_ir, char command)
{
  int i, res;
  char buf[16];

  memset(buf, 0x0, sizeof(buf));

  /* Send a Report to the Device */
  /* Initialize device */
  buf[0] = 0x00; /* Report Number */
  buf[1] = 0xAA;
  buf[2] = 0x00;
  buf[3] = 0x55;
  buf[4] = 0xA5;
  buf[5] = 0x5A;
  buf[6] = 0x66;
  buf[7] = 0x99;
  buf[8] = 0x69;
  res = write(ps3_ir, buf, 9);
  if (res < 0) {
    printf("Error: %d\n", errno);
    perror("write");
  } else {
    printf("write() wrote %d bytes\n", res);
  }
	
  /* Send a Report to the Device */
  /* Key_Down */
  buf[0] = 0x00; /* Report Number */
  buf[1] = 0x00;
  buf[2] = 0xA2;
  buf[3] = command;
  buf[4] = 0x00;
  buf[5] = 0x00;
  buf[6] = 0x00;
  buf[7] = 0x00;
  buf[8] = 0x00;
  res = write(ps3_ir, buf, 9);
  if (res < 0) {
    printf("Error: %d\n", errno);
    perror("write");
  } else {
    printf("write() wrote %d bytes\n", res);
  }

  /* Get a report from the device */
  res = read(ps3_ir, buf, 16);
  if (res < 0) {
    perror("read");
  } else {
    printf("read() read %d bytes:\n\t", res);
    for (i = 0; i < res; i++)
      printf("%hhx ", buf[i]);
    puts("\n");
  }

  return;
}

/* key codes in PS3_Keys.h */
void ps3_keyup(int ps3_ir)
{
  int i, res;
  char buf[16];

  memset(buf, 0x0, sizeof(buf));

  /* Send a Report to the Device */
  /* Key_Up */
  buf[0] = 0x00; /* Report Number */
  buf[1] = 0x00;
  buf[2] = 0xA3;
  buf[3] = 0x00;
  buf[4] = 0x00;
  buf[5] = 0x00;
  buf[6] = 0x00;
  buf[7] = 0x00;
  buf[8] = 0x00;
  res = write(ps3_ir, buf, 9);
  if (res < 0) {
    printf("Error: %d\n", errno);
    perror("write");
  } else {
    printf("write() wrote %d bytes\n", res);
  }

  /* Get a report from the device */
  res = read(ps3_ir, buf, 16);
  if (res < 0) {
    perror("read");
  } else {
    printf("read() read %d bytes:\n\t", res);
    for (i = 0; i < res; i++)
      printf("%hhx ", buf[i]);
    puts("\n");
  }

  /* Send a Report to the Device */
  /* Initialize device */
  buf[0] = 0x00; /* Report Number */
  buf[1] = 0xAA;
  buf[2] = 0x00;
  buf[3] = 0x55;
  buf[4] = 0xA5;
  buf[5] = 0x5A;
  buf[6] = 0x66;
  buf[7] = 0x99;
  buf[8] = 0x69;
  res = write(ps3_ir, buf, 9);
  if (res < 0) {
    printf("Error: %d\n", errno);
    perror("write");
  } else {
    printf("write() wrote %d bytes\n", res);
  }

  return;
}

/* execute factory reset */
void ps3_factory_reset(int ps3_ir)
{
  puts("Begin Factory Reset\n");

  puts("End Factory Reset\n");

  return;
}
