#!/bin/bash
size=`cat $1 | head -n 6 | tail -n 1 | awk '{print $12;}'`;
cat $1 | sed '1,5d' | awk '{print $1","$2","$10;}' > XTMP-GLOBAL;
value=0;
while IFS="," read col1 col2 col3
  do
  value=`echo "($value+(($col2-$col1)*$col3))" | bc -l`;
  done < "XTMP-GLOBAL";
echo "`echo "scale=8;($value / $size)" | bc -l;`";
