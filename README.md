# FPGA baremetal examples

INFORMATION

author: Jay Convertino  

date: 2024.10.02

license: MIT

## Release Versions
### Current
  - v0.0.0

### Past
  - none

## License
  All files

## Info
  
## Requirements (Ubuntu 20.04)

## Recommended
  
## Building
  1. mkdir build
  2. cd build
  3. cmake ../
  4. make

## Cmake options

The Following options are off by default. ALSA will not build if it is not found.
  * EXAMPLE APPLICATIONS:
    - BUILD_EXAMPLES_ALL : Build all examples.
    - BUILD_ALSA_EXAMPLES : Only build ALSA only examples.
    - BUILD_CODEC2_EXAMPLES : Only build CODEC2 only examples.
    - BUILD_UHD_EXAMPLES : Only build UHD only examples
    - BUILD_SOXR_EXAMPLES : Only build SOXR only examples.
    - BUILD_VOSK_EXAMPLES : Only build VOSK only examples.
    - BUILD_EXAMPLES : Only build file to file examples.
    - BUILD_NCURSES_VERSIONS : Build any of the above, but as a version with ncurses gui.
    - CREATE_DOXYGEN : Generate doxygen documents for DSP Node.
  * LIBRARIES (will automagically build for applications above)
    - BUILD_LIB_ALL : Build all dsp_node libraries
    - BUILD_LIB_SOXR : resample functions
    - BUILD_LIB_FILE : file functions
    - BUILD_LIB_UHD  : ettus radio
    - BUILD_LIB_ALSA : linux audio
    - BUILD_LIB_CODEC2 : data mod/demod
    - BUILD_LIB_TCP : TCP server or client
    - BUILD_LIB_VOSK : VOSK speech to txt processor.

To turn on codec2 for example:
  - cmake ../ -DBUILD_CODEC2_EXAMPLES=ON
