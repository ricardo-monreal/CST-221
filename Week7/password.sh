#!/bin/bash
# r will check for all 3 requirements, 
r=0

echo 'Type a password: '
# read the password typed
read password;

#set password lenght variable
lenght=${#password}

#checks for password lenght
if (("$lenght" < 8)); then
	echo 'Password lenght needs to be more than 8 characters'
#add to requirements variable if password has more than 8 characters
else 
	let "r++"
fi

#use regex operator to check for number characters
if [[ $password =~ [0-9] ]]; then 
#add to requirements variable if password has numbers
	let "r++"

else 
	echo 'Password typed does not have any number characters'
fi

#check for special characters
if [[ $password == *[@#$%'&'*+-=]* ]]; then
#add to requirements variable
	let "r++"
else 
	echo 'Password typed does not have any special characters'

fi

#check to see if requirements are met
if [ "$r" == 3 ]; then
	echo 'Password meets all requirements'
fi
