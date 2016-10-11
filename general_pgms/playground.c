#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    float k = 0.1;
	int p=100;
	char *hc = NULL;
	char c;
	char tp[100];
	extern char *optarg;
    //extern int getopt;
	while ( (c = getopt(argc, argv, "s:") ) != -1) 
	{
		switch (c) 
		{
			case 's':
				hc = optarg;
				break;
			case '?':
				fprintf(stderr, "Unrecognized option!\n");
				break;
		}
	}
	sprintf(tp,"%d_%s.pgm",p,hc);
	printf("%s",tp);
    printf("\n");
    return(0);
}
