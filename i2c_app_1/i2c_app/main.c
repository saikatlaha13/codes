#include"header.h"
#include"i2c.c"

int main()
{
    int address_slave;
    int buf[2];

    printf("enter the slave address\n");
    scanf("%x",&address_slave);
    printf("enter the register to write to\n");
    __fpurge(stdin);
    scanf("%x",&buf[0]);
    printf("enter the data\n");
    __fpurge(stdin);
    scanf("%x",&buf[1]);
   
    i2c_init();
    i2c_write(address_slave,buf);
    i2c_close();

}

