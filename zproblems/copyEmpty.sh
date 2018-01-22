#!/bin/sh
## Example of a broken script.
for f in $(seq 1 50);
do cp empty.cpp "empty$f.cpp";
done
