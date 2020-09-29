#!/bin/bash

# For every element x in an array, start a new program that:
# Sleeps for x seconds.
# Prints out x.
# The clock starts on all the elements at the same time. It works for any array that has non-negative integers.

function f() {
	sleep "$1"
	echo "$1"
}
while [ -n "$1" ]
do
	f "$1" &
	shift
done
wait