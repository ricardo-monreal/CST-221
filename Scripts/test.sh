#!/bin/bash
# My first script

echo "Hello,what is your name?"
read  name

#show todays date

echo "Hello $name, Today's date is" 
date
#Show kernel  info
echo "$name is using the following kernel;"
uname -a 
#show disk usage
echo "The disk usage in $name's computer is;"
df
#show memory usage
echo "And memory usage in $name's computer is; "
free
#show current active processes
echo "The current active processes in $name's computer are;"
ps