
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
//client server prog
/*
using fifos simple client server commmunication protocol can be implemented
*/
int main(void){
printf("server - listening\n");

//create fifo
int code=mkfifo("cli_ser_fifo",0764);
if(code==-1){
perror("mkfifo returned an error - file may already exitst");
}

//open read end
int fd=open("cli_ser_fifo", O_RDONLY);
if(fd==-1){
perror("cannot open fifo for read");
return 0;
}
printf("FIFO OPEN\n");

//read string (upto 100 charachters)
char serverrcv[100];
memset(serverrcv,0,100); //string buffer set with 0s
int res;
char len;
while(1){
res=read(fd,&len,1);
if(res==0){
break;
}
read(fd,serverrcv,len);//read string char
//serverrcv[(int)len]=0; //0 terminator
printf("server recieved:%s\n",serverrcv);
}
printf("EOF reached");
close(fd);
printf("fifo closed");
return 0;
}


 


