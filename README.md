# skabuffersim

To build you need to have the syDEVS build tree in the directory one level below the directory that the skabuffersim files are in and will need to have built at least the static syDEVS library.

Currently this only has a simple Makefile in the src directory. Therefore, after buiding syDEVS run make in the src directory. This will create an skabuffer executable in the src directory.

Build instructions:
Go to base directory for the build.
git clone https://github.com/Autodesk/sydevs.git
cd sydevs
mkdir build
cd build
cmake ..
make

Go back to base directory for build. (cd ../..)
git clone https://github.com/Mus90/skabuffersim.git
cd skabuffersim/src
make

This should have built the skabuffer simulation executable.

