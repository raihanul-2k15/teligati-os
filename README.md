# CSE3202-OS-Assignment

This is a simple OS assignment for my university OS course.
I have followed a few videos from IKnow's youtube series: https://www.youtube.com/watch?v=rr-9w2gITDM&list=PLBK_0GOKgqn3hjBdrf5zQ0g7UkQP_KLC3

But I've fixed critical flaws and bugs in this version.

# Just a demo

This is not intended to be any useful OS. It is just a demo for students.

# How to run on Linux

1. Install packages: nasm, gcc, qemu
  sudo apt-get install nasm
  sudo apt-get install gcc
  sudo apt-get install qemu
2. Apply execute permission on build_linux.sh
3. Run build_linux.sh
  ./build.sh
  
# How to run on Windows

1. Download preconfigured cygwin from http://www.mediafire.com/file/hakdoz32a7kspv6/IknowPackageOS_EP4_cross_tools.7z
It has the necessary packages install and configured to run the OS in qemu
Alternatively, download cygwin from the official website and install qemu, nasm and gcc add add them to path variable yourself

2. Open cygwin.bat
3. Navigate to the OS folder
4. RUn ./build_cygwin.sh
