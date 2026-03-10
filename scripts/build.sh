SYSTEM_HEADERS="cstdlib iostream chrono exception source_location stdexcept string string_view utility"
ROOT=C:/dev/p

SRC=$ROOT/src
BUILD=$ROOT/build

OBJ=$BUILD/obj
BIN=$BUILD/bin

CXX=g++
FLAGS="-std=c++20 -fmodules-ts"

echo $(pwd)

mkdir -p $BUILD $OBJ/{application,exception,logging} $BIN

cd $BUILD

for header in $SYSTEM_HEADERS; do
    if [ ! -f "$BUILD/gcm.cache/C-/msys64/mingw64/include/c++/15.2.0/$header.gcm" ]; then
        $CXX $FLAGS -x c++-system-header $header
    fi
done

$CXX $FLAGS -c $SRC/exception/exception.cppm     -o $OBJ/exception/exception.cppm.o
$CXX $FLAGS -c $SRC/logging/log.cppm             -o $OBJ/logging/log.cppm.o
$CXX $FLAGS -c $SRC/logging/logging.cppm         -o $OBJ/logging/logging.cppm.o
$CXX $FLAGS -c $SRC/application/cli.cppm         -o $OBJ/application/cli.cppm.o
$CXX $FLAGS -c $SRC/application/application.cppm -o $OBJ/application/application.cppm.o

$CXX $FLAGS -c $SRC/logging/logger.cpp           -o $OBJ/logging/logger.cpp.o
$CXX $FLAGS -c $SRC/application/cli.cpp          -o $OBJ/application/cli.cpp.o
$CXX $FLAGS -c $SRC/application/application.cpp  -o $OBJ/application/application.cpp.o

$CXX $FLAGS -c $SRC/main.cpp -o $OBJ/main.o

$CXX $FLAGS $(find $OBJ -name "*.o") -o $BIN/app.exe