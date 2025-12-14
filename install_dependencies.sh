#!/bin/bash

echo "Installing required dependencies for AMCI..."

# Check if running on Ubuntu/Debian
if command -v apt-get &> /dev/null; then
    echo "Detected Ubuntu/Debian system. Installing packages..."
    sudo apt-get update
    sudo apt-get install -y flex bison gcc build-essential
elif command -v yum &> /dev/null; then
    echo "Detected RedHat/CentOS system. Installing packages..."
    sudo yum install -y flex bison gcc
elif command -v pacman &> /dev/null; then
    echo "Detected Arch Linux system. Installing packages..."
    sudo pacman -S --noconfirm flex bison gcc
else
    echo "Unknown package manager. Please install flex, bison, and gcc manually."
    exit 1
fi

echo ""
echo "Verifying installation..."
if command -v flex &> /dev/null && command -v bison &> /dev/null && command -v gcc &> /dev/null; then
    echo "✓ flex: $(flex --version | head -n1)"
    echo "✓ bison: $(bison --version | head -n1)"
    echo "✓ gcc: $(gcc --version | head -n1)"
    echo ""
    echo "All dependencies installed successfully!"
else
    echo "Error: Some dependencies are still missing."
    exit 1
fi

