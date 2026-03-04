#!/bin/bash
# Computes a hash value over the test function.

path="."

tstart='\%^void test(%'
tend='\%^}%'

for file in $1
do
    file="$path/$file.c"
    t=$( sed -n "$tstart,$tend{p; $tend{q;};}" "$file" )
    t=$( echo "$t" | tr -d " \t\n\r" )
    m=$( md5 -qs "$t" )
    c=$( echo "$t" | shasum )
    printf "%30s: %s %s\n" "$(basename $file)" "$c" "$m"
done
