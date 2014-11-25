#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (int argc, char *argv[])
{

	FILE	*IN = NULL, *OUT = NULL;
	int 	n;
	unsigned long long conter = 0;
	unsigned long long start_position = 0;
	unsigned long long end_position;
	char 	c;

	if(argc < 9)
	{
		fprintf(stderr,"\nUSAGE:\nDNAExt -i IN_FILE -o OUT_FILE -pS FIRST_POSITION_NUMBER -pL LAST_POSITION_NUMBER\n\nCOMMON USAGE:\nDNAExt -i input -o output -pS 1000 -pL 1000000\n\n");
		return 1;
	}

	fprintf(stderr,"\n[STATUS] Starting DNAExt...");

        for(n = 1 ; n < argc ; n++)
                if(strcmp("-i", argv[n]) == 0)
		{
                        if(!(IN = fopen(argv[n+1], "r")))
                        {
                                fprintf(stderr, "[ERROR] Can't open read file 1\n");
                                return 1;
                        }
                        break;
                }

	for(n = 1 ; n < argc ; n++)
                if(strcmp("-o", argv[n]) == 0)
                {
                        if(!(OUT = fopen(argv[n+1], "w")))
                        {
                                fprintf(stderr, "[ERROR] Can't open write file\n");
                                return 1;
                        }
                        break;
                }

    	for(n = 1; n < argc; n++)
      		if(strcmp("-pS",argv[n]) == 0)
		{	
			start_position = atol(argv[n+1]);
		        break;
		}

	for(n = 1; n < argc; n++)
                if(strcmp("-pL",argv[n]) == 0)
                {      
                        end_position = atol(argv[n+1]);
                        break;
                }

	/*-----------------------------------------------------------*/

	do
	{
		c = fgetc(IN);
		if(start_position <= conter && end_position > conter)
		{
			fprintf(OUT, "%c", c);		
		}
		
		if(conter >= end_position)
			break;

		conter++;

	}while(c != EOF);

	/*-----------------------------------------------------------*/

	printf("\n[STATUS] Done! \n\n");

	fclose(IN);
	fclose(OUT);

	return 0;
}
