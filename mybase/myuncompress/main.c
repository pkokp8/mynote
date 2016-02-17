#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern int decompress(unsigned char *buf, int in_len, unsigned char *output);

#define LEN (1024*1024)
int main()
{
	char *buff = (char*)malloc(LEN);
	char *outbuff = (char*)malloc(LEN);
	memset(buff,0,LEN);
	memset(outbuff,0,LEN);
	int fdin = 0;
	int fdout = 0;
	fdin = open("image_data.lzma",O_RDONLY);
	fdout = open("myimage_data",O_WRONLY|O_CREAT);
	int filelen = read(fdin,buff,LEN);
	decompress(buff,filelen,outbuff);
	write(fdout,outbuff,150488);
	close(fdin);
	close(fdout);
	
	
	free(buff);
	free(outbuff);
}