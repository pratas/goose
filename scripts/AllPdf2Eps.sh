#!/bin/bash
# It converts all pdfs in the current folder to eps files
# It needs inkscape.
# sudo apt-get update 
# sudo apt-get install build-essential libxslt1-dev libgsl0-dev libgtkmm-utils-dev libpangomm-1.4-dev libboost-dev libpopt-dev
# sudo apt-get install inkscape
echo "Running AllPdf2Eps ... ";
ls *.pdf | tr '.' '\t' | awk '{ print $1;}' > xpdf2eps-tmp;
while read p; 
 do
 echo "Converting $p.pdf to $p.eps ..."
 inkscape $p.pdf --export-eps=$p.eps
 done < xpdf2eps-tmp
echo "Done all!
