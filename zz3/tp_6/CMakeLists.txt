# Project #-----------------------------------------------------------------------------------------
project ( tp6 )

cmake_minimum_required ( VERSION 2.8.9 )

find_package ( Threads )

option ( WITH_QT "Build with QT" on )

# C++ Warning Level #-------------------------------------------------------------------------------
if ( CMAKE_COMPILER_IS_GNUCXX )
 set ( CMAKE_CXX_FLAGS "-Wall -pedantic ${CMAKE_CXX_FLAGS}" )
endif()

# C++11 #-------------------------------------------------------------------------------------------
include ( CheckCXXCompilerFlag )

check_cxx_compiler_flag ( "-std=gnu++14" COMPILER_SUPPORTS_CPP14 )
check_cxx_compiler_flag ( "-std=gnu++1y" COMPILER_SUPPORTS_CPP1Y )
check_cxx_compiler_flag ( "-std=gnu++11" COMPILER_SUPPORTS_CPP11 )
check_cxx_compiler_flag ( "-std=gnu++0x" COMPILER_SUPPORTS_CPP0X )

if ( COMPILER_SUPPORTS_CPP14 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++14 ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP1Y )
 set ( CMAKE_CXX_FLAGS "-std=gnu++1y ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP11 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}" )
elseif( COMPILER_SUPPORTS_CPP0X )
 set ( CMAKE_CXX_FLAGS "-std=gnu++0x ${CMAKE_CXX_FLAGS}" )
else ()
 message ( STATUS "Compiler ${CMAKE_CXX_COMPILER} has no C++11/14 support." )
endif ()

if ( WITH_QT )
 set ( CMAKE_CXX_FLAGS "-DWITH_QT ${CMAKE_CXX_FLAGS}" )
endif ()

message ( STATUS "Compiler flags: ${CMAKE_CXX_FLAGS}" )

# Sources #-----------------------------------------------------------------------------------------
if ( WITH_QT )
 set ( ZZ3_QT_HEADERS
       src/interface_qt/colonneCartes.hpp
       src/interface_qt/fenetrePrincipale.hpp
       src/interface_qt/gestionnaireImageCarte.hpp
       src/interface_qt/labelCarte.hpp
       src/controleur_graphique.hpp
     )

 set ( ZZ3_QT_RESOURCES
       rcs/cards.qrc
     )

 set ( ZZ3_QT_SOURCES
       src/interface_qt/colonneCartes.cpp
       src/interface_qt/fenetrePrincipale.cpp
       src/interface_qt/gestionnaireImageCarte.cpp
       src/interface_qt/labelCarte.cpp
       src/controleur_graphique.cpp
     )
endif ()

set ( ZZ3_HEADERS
      src/controleur_texte.hpp
      src/interface_qt/idCarte.hpp
      src/interface_qt/idZone.hpp
      src/solitaire/carte.hpp
      src/solitaire/paquet.hpp
      src/solitaire/plateau.hpp
      src/solitaire/solitaire.hpp
    )

set( ZZ3_SOURCES
     src/controleur_texte.cpp
     src/solitaire/paquet.cpp
     src/solitaire/solitaire.cpp
     src/interface_qt/idCarte.cpp
     src/interface_qt/idZone.cpp
   )

include_directories ( src/ )

# QT Configuration #--------------------------------------------------------------------------------

if ( WITH_QT )
 set ( CMAKE_AUTOMOC ON )
 set ( CMAKE_INCLUDE_CURRENT_DIR ON )
 find_package ( Qt5Widgets REQUIRED )
 qt5_add_resources ( SAMPLE_RC_SRCS ${ZZ3_QT_RESOURCES} )
endif ()

# Executables #-------------------------------------------------------------------------------------
add_executable ( ${CMAKE_PROJECT_NAME}
                 src/test_solitaire.cpp
                 ${ZZ3_SOURCES}
                 ${ZZ3_QT_SOURCES}
                 ${ZZ3_HEADERS}
                 ${ZZ3_QT_HEADERS}
                 ${SAMPLE_MOC_SRCS}
                 ${SAMPLE_RC_SRCS}
               )

# Build #-------------------------------------------------------------------------------------------

if ( WITH_QT )
 qt5_use_modules ( ${CMAKE_PROJECT_NAME} Widgets Svg )
endif ()

set_target_properties ( ${CMAKE_PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C )
target_link_libraries ( ${CMAKE_PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} )
