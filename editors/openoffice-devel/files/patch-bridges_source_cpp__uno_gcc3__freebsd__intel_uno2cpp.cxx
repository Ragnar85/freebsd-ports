--- bridges/source/cpp_uno/gcc3_freebsd_intel/uno2cpp.cxx.orig	2014-09-19 17:51:13 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/uno2cpp.cxx
@@ -24,6 +24,10 @@
 // MARKER(update_precomp.py): autogen include statement, do not remove
 #include "precompiled_bridges.hxx"
 
+#include <typeinfo>
+#include <exception>
+#include <cstddef>
+#include <cxxabi.h>
 #include <stdlib.h>
 
 #include <com/sun/star/uno/genfunc.hxx>
@@ -39,6 +43,11 @@
 
 using namespace ::rtl;
 using namespace ::com::sun::star::uno;
+#ifdef __GLIBCXX__
+using CPPU_CURRENT_NAMESPACE::__cxa_get_globals;
+#else
+using __cxxabiv1::__cxa_get_globals;
+#endif
 
 namespace
 {
@@ -305,7 +314,7 @@ static void cpp_call(
  	catch (...)
  	{
   		// fill uno exception
-		fillUnoException( CPPU_CURRENT_NAMESPACE::__cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+		CPPU_CURRENT_NAMESPACE::fillUnoException( __cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
         
 		// temporary params
 		for ( ; nTempIndizes--; )
