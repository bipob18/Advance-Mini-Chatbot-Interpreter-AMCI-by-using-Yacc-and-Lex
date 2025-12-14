#!/bin/bash

echo "=========================================="
echo "AMCI - Demo Test Script"
echo "=========================================="
echo ""

if [ ! -f "./amci" ]; then
    echo "Error: amci executable not found!"
    echo "Please run ./build.sh first"
    exit 1
fi

echo "Test 1: Running demo.edu (Original patterns)"
echo "----------------------------------------"
./amci demo.edu
echo ""
echo "=========================================="
echo ""

echo "Test 2: Running demo2.edu (Flexible patterns)"
echo "----------------------------------------"
./amci demo2.edu
echo ""
echo "=========================================="
echo ""

echo "All tests completed!"
