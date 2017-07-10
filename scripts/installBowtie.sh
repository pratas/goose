#!/bin/bash
sudo apt-get install libtbb-dev
git clone https://github.com/BenLangmead/bowtie.git
cd bowtie/
make
