#!/bin/sh

# Author : Joey
# Script follows here:

myvar=hello
mycount=1

echo $myvar
expr $mycount + 2

myvar2="$myvar there!"
echo $myvar2

myvar3='$myvar there!'
echo $myvar3
