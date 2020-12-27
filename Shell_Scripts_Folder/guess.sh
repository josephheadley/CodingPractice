#!/bin/bash

number=$(( $RANDOM % 50 + 1 ))

echo "I'm thinking of a number... Can you guess what it is?"

guess=0
count=0

while [ $guess -ne $number ] ; do
	read guess
	[ $guess -lt $number ] && echo "Your guess is too low. Go higher!" && ((count+=1))
	[ $guess -gt $number ] && echo "Your guess is too high. Go lower!" && ((count+=1))
done

echo "You guessed it! My number was $number and it only took you $count tries!"
exit 0
