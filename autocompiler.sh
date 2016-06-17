#!/bin/bash
while true; do
find `pwd` |
  grep -E ".(cpp|hpp)" |
  grep -v "/.git/" |
  entr -d sh -c "tput reset; make exec;echo;date"
done
