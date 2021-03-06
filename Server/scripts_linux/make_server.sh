#!/bin/bash

#project_name=(meplay superserver gatewayserver gameserver statisticserver)
project_name=(meplay superserver gatewayserver battleserver gameserver matchserver statisticserver)

if [ ! -n "$1" -o "$1" == "debug" ] ; then
    cd ../src
    for file in ${project_name[*]}
    do
        cd ./${file}
        cmake -DCMAKE_BUILD_TYPE=Debug ./
        make -j
        cd ..
    done
elif [ "$1" == "release" ] ; then
    cd ../src
    for file in ${project_name[*]}
    do
        cd ./${file}
        cmake -DCMAKE_BUILD_TYPE=Release ./
        make -j
        cd ..
    done
elif [ "$1" == "clean" ] ; then
    cd ../src
    for file in ${project_name[*]}
    do
        cd ./${file}
        make clean
        cd ..
    done
fi
