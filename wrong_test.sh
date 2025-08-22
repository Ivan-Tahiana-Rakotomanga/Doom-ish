#!/bin/bash

for file in map/error/*; do
    echo $file
    valgrind --track-fds=yes ./cub3D $file
    echo
done
