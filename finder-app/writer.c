/*** File name:				writer.c												***/
/*** First argumement:		full path to a file										***/
/*** Second argument:		text string which will be written with this file		***/
/*** Exit(1) + Error:		If any of the argument is not specified					***/
/*** Exit(1) + Error:		If file deosn not exist and not able to create			***/
/*** Otherwise:				Create a new file with the name and path and content	***/
/***						, overwriting any existing file, assuming the folder	***/
/***						exists													***/  

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc != 3)
	{
		syslog(LOG_ERR, "There should be two input arguments.");
		return 1;
	}

	fp = fopen(argv[1], "w");

	if (fp == NULL)
	{
		syslog(LOG_ERR, "The file %s can't be opened.", argv[1]);
		return 1;
	}

	syslog(LOG_DEBUG, "The file %s is opened.", argv[1]);

	fprintf(fp, "%s", argv[2]);

	syslog(LOG_DEBUG, "The string %s is written to the file %s", argv[2], argv[1]);

	fclose(fp);

	syslog(LOG_DEBUG, "The file %s is closed.", argv[1]);

	
	return 0;
}
