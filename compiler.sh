#!/bin/bash
echo "Criando Build..."
g++ -std=c++0x main.cpp src/Classes/* src/Headers/* Startup.cpp Startup.h -o run

echo "--- Run Build ---"
./run

echo "--- End Build ---"
rm -rf .vscode
