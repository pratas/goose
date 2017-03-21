#!/bin/bash
# 1. install mapDamage
git clone https://github.com/ginolhac/mapDamage.gi
cd mapDamage
sudo python setup.py install
# 2. install pysam
# 2.1 cynthon
mkdir cynthon
cd cynthon
wget wget https://pypi.python.org/packages/cb/0c/9d64e6ed68e76eb7d8a1ca8ec0d42ba0cac31dae10c6fbe6b3a5385b83a7/Cython-0.25.2-cp26-cp26mu-manylinux1_x86_64.whl#md5=81f24ce7637de392299d7cb9b12ec8cd
pip install Cython --install-option="--no-cython-compile"
cd ..
# 2.2 pysam
rm -f pysam-0.7.5.tar.gz
wget https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/pysam/pysam-0.7.5.tar.gz
tar -vxf pysam-0.7.5.tar.gz
pysam-0.7.5/
python setup.py build
sudo python setup.py install
cd ..
# 3. Install R
# https://cloud.r-project.org/
# 4. Install the R packages:
R 
install.packages("inline") #select 39
install.packages("gam")
install.packages("Rcpp")
install.packages("ggplot2")
quit("yes")
# 5.
sudo apt-get install libgsl0-dev
# 6.
R
install.packages("RcppGSL") #select 39
quit("yes")
