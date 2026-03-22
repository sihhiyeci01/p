# config
ROOT=C:/dev/p
SYSTEM_HEADERS="cstdint cstdlib cstdio cerrno memory iostream chrono format exception stdexcept system_error source_location string string_view utility ctime filesystem"
CXX=g++
FLAGS="-std=c++23 -fmodules-ts"
GCC_VER=$($CXX -dumpversion)

# paths
SRC=$ROOT/src
BUILD=$ROOT/build
OBJ=$BUILD/obj
BIN=$BUILD/bin
GCM=$BUILD/gcm.cache/C-/msys64/mingw64/include/c++/$GCC_VER

# prepare
mkdir -p $BUILD $OBJ/{application,exception,logging} $BIN
cd $BUILD
for header in $SYSTEM_HEADERS; do
    if [ ! -f $GCM/$header.gcm ]; then
        $CXX $FLAGS -x c++-system-header $header
    fi
done

# interface
$CXX $FLAGS -c $SRC/logging/logging.cppm         -o $OBJ/logging/logging.cppm.o
$CXX $FLAGS -c $SRC/exception/exception.cppm     -o $OBJ/exception/exception.cppm.o
$CXX $FLAGS -c $SRC/application/cli.cppm         -o $OBJ/application/cli.cppm.o
$CXX $FLAGS -c $SRC/application/application.cppm -o $OBJ/application/application.cppm.o

# implementation
$CXX $FLAGS -c $SRC/exception/exception.cpp      -o $OBJ/exception/exception.cpp.o
$CXX $FLAGS -c $SRC/logging/logger.cpp           -o $OBJ/logging/logger.cpp.o
$CXX $FLAGS -c $SRC/application/cli.cpp          -o $OBJ/application/cli.cpp.o
$CXX $FLAGS -c $SRC/application/application.cpp  -o $OBJ/application/application.cpp.o
$CXX $FLAGS -c $SRC/main.cpp                     -o $OBJ/main.o

# link
$CXX $FLAGS $(find $OBJ -name "*.o") -o $BIN/app.exe