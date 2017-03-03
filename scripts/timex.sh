#!/bin/bash
START=$(date +%s.%N)
$1
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo "total_time:" $DIFF

