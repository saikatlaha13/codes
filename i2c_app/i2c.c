#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#include <linux/i2c-dev.h>
// Terrible portability hack between arm-linux-gnueabihf-gcc on Mac OS X and native gcc on raspbian.
#ifndef I2C_M_RD
#include <linux/i2c.h>
#endif

int i2c_init() {
	if ((i2c_fd = open(i2c_fname, O_RDWR)) < 0) {
		char err[200];
		sprintf(err, "open('%s') in i2c_init", i2c_fname);
		perror(err);
		return -1;
	}
}

void i2c_close() {
	close(i2c_fd);
}

// Write to an I2C slave device's register:
int i2c_write(char slave_addr, char *data) {

	int i=0;
	int wr_cnt=0;
	int addr=0x50;
	char buf[4]={0};
	buf[0]=0x00;
	buf[1]=0x00;
	
	if(ioctl(i2c_fd,I2C_SLAVE,addr)<0){
		printf("failed to acquire bus access\n");
	}
	else{
		if((wr_cnt=write(i2c_fd,buf,2))!=2){
			printf("write failed\n");
		}
		else{
                        //for(i=0 ; i<4 ; i++){
			//printf("read success %x\n",buf[i]);
			//}
		}
	}
}

