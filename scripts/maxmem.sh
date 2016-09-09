#!/bin/bash
# GET PEAK MEMORY OF RUNNING PROGRAMS
# . maxmem.sh prog args
# . maxmem.sh "./GeCo" " -v -l 1 -r REF TAR "
function ProgMemoryStart {
  echo "0" > mem_ps_234552;
  while true
    do
    ps aux | grep $1 | head -n 1 | awk '{ print $6; }' >> mem_ps_234552;
    sleep 1;
    done
  }
function ProgMemoryStop {
  kill $1 >/dev/null 2>&1
  cat mem_ps_234552 | sort -V | tail -n 1;
  }
ProgMemoryStart "$1" &
MEMPID=$!
$1 $2
printf "Maximum memory (bytes): "
ProgMemoryStop $MEMPID;
rm -f mem_ps_234552;
