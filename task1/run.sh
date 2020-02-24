#!/bin/bash
path=$1
extension=$2
directory=$3
archive=$4
mkdir -p ./${directory}
filepath=$(find ${path} -type f -name "*.${extension}")
for file in $filepath; do
    folder=${file}
    folder=${folder%/*}/
    mkdir -p ./${directory}/${folder#${path}}
    cp ${file} ./${directory}/${file#${path}}
done
tar -cf ${archive} ./${directory}
echo "done"
