#!/bin/bash
cd ..
g++-7 -std=c++17 -o AgarOSS -I ./ *.cpp Connection/*.cpp Entities/*.cpp Game/*.cpp Modules/*.cpp Player/*.cpp Protocol/*.cpp -luWS -lz -lssl -pthread