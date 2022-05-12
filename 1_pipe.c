



#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main() {
int p[2]; // P[O] P[1]indexes or subscripts of array P
pipe(p);//fdo --P[O]rd end and fd1---P[1] wt end
printf("Read end of pipe = %d It Write end of pipe = %d\n", p[0], p[1]);//
if(fork ) {// parent...chd pid fork //Parent..
char s[20];
printf("In Parent Enter Data... In");
scanf("%s", s);//wait user enter "15 +1"
write(p[1], s, strlen(s)+1); //Parent send data on pipe....write(fd, buf , 20);
}
else {
//Child--0
char buf[20];
printf("In child... \n");
read(p[0], buf, sizeof(buf)); //block. .... child collect data
printf("child pro printing..Data. of the parent process..%s\n", buf);
}
return 0;}


