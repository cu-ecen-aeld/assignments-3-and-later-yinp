#!/bin/bash
# Bash script:		finder.sh
# First argument:	path to a directory on the file system
# Second argument:	text string which will be searched within theses files
# Exit (1) + Error:	If any of the arguments is not specified
# Exit (1) + Error:	If first argument is not a directory
# Otherwise:		Print message				  	 

# Check number of input arguments
if [ "$#" -ne 2 ]
then
	echo 'There should be two input arguments.' 
	exit 1
fi

# Assign input arguments to variables
filesdir=$1
searchstr=$2

# Check input argument
if [ ! -d "$filesdir" ]
then
	echo "The $filesdir does not exist."
	exit 1 
fi

numFiles=$( find $filesdir -type f | wc -l )

numLines=$(grep -r -c "$searchstr" $filesdir | awk -F: '{sum += $2} END {print sum}') 
echo "The number of files are $numFiles and the number of matching lines are $numLines"
