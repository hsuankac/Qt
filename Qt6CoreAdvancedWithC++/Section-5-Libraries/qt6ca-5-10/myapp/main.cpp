/*
 * What
 * Use and external lib
 *
 * Why
 * See how to use libs outside out normal project
 *
 * How
 * Build the lib
 * Modify the app CMake
 * Build the app
 * :-1: error: library not found for -lmylib
 * Correct the path
 *
 * copy the compiled lib and includes to the source dir
 * Modify the CMakeLists.txt
 *
 *  add_library(mylib SHARED IMPORTED) # STATIC instead of SHARED
 *  set_target_properties(mylib PROPERTIES
 *      IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/libmylib.dylib"
 *      IMPORTED_IMPLIB "${CMAKE_SOURCE_DIR}/lib/libmylib.dll.a"
 *      INTERFACE_INCLUDE_DIRECTORIES "$}CMAKE_SOURCE_DIR}/inc
 *  )
 *  target_link_libraries(myapp mylib Qt${QT_VERSION_MAJOR}::Cour)
 *
 */

#include <QCoreApplication>
#include "inc/mylib_global.h"
#include "inc/mylib.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mylib lib;
    lib.test();

    return a.exec();
}
