finger-switch
========

This code is to help with calculating an arbitrary path length from angle
measurements taken with an arduino. The idea is to take the angle measurements
between the points of a path, calculating relative edge sizes. These can then be
scaled accordingly with various edge measurements.

Included is also an arduino repository, which is basically a simple ardunio
program to read a magnetometer and acceleromter to get angles relative to north.
It is designed to output a csv to be parsed by the other program (written in
C++).

