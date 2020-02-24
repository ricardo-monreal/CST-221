#!/bin/bash

#file to read and group name
userfile="input_users.txt"
group="CST221"

#check if group already exists
if grep -q $group /etc/group
then 
	echo "$group already exists."
#create a new group if it doesn't exists
else 
	groupadd $group
fi

#read the username and password from input_users.txt
userfile="input_users.txt"
while read -r username password
do 
	name="$username"
	pwd="$password"
	echo "Username: $name"
	echo "Password: $pwd"
#add users read to group
	if [ $(id -u) -eq 0 ]; then
		egrep "^$name" /etc/passwd >/dev/null
		if [ $? -eq 0 ]; then
		echo "$name already exists"
		exit 1
#in case it can't add user to group 
		else
		useradd -m -p $pwd $name
		[ $? -eq 0 ] && echo "User has been added to the $group group" || echo "Failed to add user"
		fi
	else
		echo "Need root access to add user"
		exit 2
	fi
	usermod -aG $group $name
done < "$userfile"

#delete user from group with -r
userfile="input_users.txt"
while read -r username password
do
	name="$username"
	pwd="$password"
	userdel -r $name
	echo "$name  deleted from $group group"
done < "$userfile"

if grep -q $group /etc/group
then 
	groupdel $group
else
	echo "Group does not exist"
fi
