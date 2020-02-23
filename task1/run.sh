#!/bin/bash
path=$1
extension=$2
directory=$3
archive=$4
cd ${path}
mkdir -p ./${directory}
filepath=$(find . -type f -name "*.$extension")
for file in $filepath; do
    folder=${file:1}
    mkdir -p ./${directory}${folder%/*}
    cp ${file} ./${directory}${file:1}
done
tar -cf ${archive} ./${directory}
echo "done"
