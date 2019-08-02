#pragma once

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ioctl.h>
#include<linux/i2c-dev.h>
#include<unistd.h>
#include<stdio_ext.h>

#define E_SUCCESS 1
#define E_FAIL    0

int i2c_fd=-1;
const char *i2c_fname="/dev/i2c-1";

int i2c_write(int , int[]);

