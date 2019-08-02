#include"header.h"
#include"i2c.c"

int main()
{
    char result;
    char address_slave;
    char buf[2];
    char register_to_write;
/*
    printf("enter the slave address\n");
    scanf("%c",&address_slave);
    printf("enter the register to write to\n");
    __fpurge(stdin);
    scanf("%c",&buf[0]);
    printf("enter the data\n");
    __fpurge(stdin);
    scanf("%c",&buf[1]);*/
   
    i2c_init();
    i2c_write(address_slave,buf);
    i2c_close();

}

