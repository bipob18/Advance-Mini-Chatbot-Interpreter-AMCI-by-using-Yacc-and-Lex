# Installation Guide

## Quick Installation

### For WSL/Ubuntu/Debian:

```bash
sudo apt-get update
sudo apt-get install -y flex bison gcc build-essential
```

### For Windows:

1. Install WSL (Windows Subsystem for Linux) or MSYS2
2. In WSL/MSYS2 terminal:
   ```bash
   pacman -S flex bison gcc
   ```

### For macOS:

```bash
brew install flex bison gcc
```

## Automated Installation

Use the provided script:

```bash
chmod +x install_dependencies.sh
./install_dependencies.sh
```

## Verify Installation

After installation, verify tools are available:

```bash
flex --version
bison --version
gcc --version
```

All should show version information if installed correctly.

## Building the Project

Once dependencies are installed:

```bash
chmod +x build.sh
./build.sh
```

## Troubleshooting

**"flex: command not found"**
- Install flex: `sudo apt-get install flex`

**"bison: command not found"**
- Install bison: `sudo apt-get install bison`

**"gcc: command not found"**
- Install gcc: `sudo apt-get install gcc build-essential`

**Build errors:**
- Make sure all dependencies are installed
- Check file permissions: `chmod +x build.sh`
- Clean and rebuild: `rm -f *.c *.h amci && ./build.sh`
