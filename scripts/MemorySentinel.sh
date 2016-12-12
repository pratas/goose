#!/bin/bash
BSIZE=536870912; # 512 GB
MAIL="pratas@ua.pt";
PERIOD=30; # seconds
for((;;));
  do
  AB=`df -la | grep /home | awk '{ print $3; }'`;
  if [[ $AB -lt $BSIZE ]]; 
    then
    echo "WARNING: STORAGE SIZE EXCEEDED (LESS THAN 512 GB)" | mail -s "STORAGE SIZE EXCEEDED!" "$MAIL"
    fi
  sleep $PERIOD;
  done
