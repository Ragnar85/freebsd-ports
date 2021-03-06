--- Makefile.PL.orig	2015-02-28 22:30:32.611673575 +0100
+++ Makefile.PL	2015-02-28 22:33:13.138276817 +0100
@@ -84,7 +84,7 @@
 # OpenSSL 1.0.0a 1 Jun 2010
 my $openssl_version_string = `$openssl_binary version`;
 my ($openssl_version_major, $openssl_version_minor, $openssl_version_fix, $openssl_version_patch);
-if ($openssl_version_string =~ m/\s*OpenSSL\s+(\d+)\.(\d+)\.(\d+)([a-zA-Z]+)/) {
+if ($openssl_version_string =~ m/\s*OpenSSL|LibreSSL\s+(\d+)\.(\d+)\.(\d+)([a-zA-Z]*)/) {
     # OpenSSL 0.9
     $openssl_version_major = $1;
     $openssl_version_minor = $2;
@@ -108,7 +108,8 @@
           ($openssl_version_minor == 9) &&
           ($openssl_version_fix   == 8)) or
          ($openssl_version_major == 1 &&
-          $openssl_version_minor == 0)) {
+          $openssl_version_minor == 0) or
+         ($openssl_version_major == 2)) {
     print STDERR "\n";
     print STDERR "ERROR: OpenSSL 0.9.8  or 1.0 is required.\n";
     print STDERR "Consider setting OPENSSL_PREFIX correctly.\n\n";
@@ -130,7 +131,7 @@
     $openxpki_version = `cat ../../VERSION`;
     chomp $openxpki_version;
 } elsif ( -e($vergen) ) {
-    $openxpki_version = `$vergen --format version`;
+    $openxpki_version = "0.25.0";
 
     if ($CHILD_ERROR != 0) {
         $openxpki_version = undef;
@@ -249,49 +250,6 @@
   print STDERR "Logger is not installed. Continue anyway.\n";
 }
 
-# check if we should add -shared
-# not all platforms support this feature
-my %flags = ();
-
-open $fh, '>test.c' or die "Cannot open test.c. Stopped";
-print $fh "int main() {}\n";
-close $fh;
-use Config;
-my $cc = $Config{'cc'};
-
-my $cc_supports_shared = 1;
-if (open $fh, "$cc -shared -o test test.c 2>&1 |") {
-    while (my $line = <$fh>) {
-        if ($line =~ m{ unrecognized .* option .* -shared }xms) {
-	    $cc_supports_shared = 0;
-        }
-    }
-    close $fh;
-    if ($CHILD_ERROR) {
-        $cc_supports_shared = 0;
-    }
-
-    if (! $cc_supports_shared)
-    {
-        print STDERR "C compiler does not support -shared.\n";
-    }
-    else {
-        if ($^O ne 'darwin') {
-            print STDERR "C compiler supports -share. Adding it to LDDLFLAGS.\n";
-            $flags{'LDDLFLAGS'} = '-shared';
-        }
-        else {
-            print STDERR "C compiler claims to support -share. But we are on Mac OS X, experience shows that it still does not work with -share, so we won't add it to LDDLFLAGS ...\n";
-        }
-    }
-}
-else {
-    print STDERR "Could not run C compiler. Continue anyway.\n";
-}
-
-unlink('test.c');
-unlink('test');
-
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile that is written.
 WriteMakefile(
@@ -299,7 +257,6 @@
     'VERSION'   => $openxpki_version,
     'LIBS'      => ["-L$openssl_lib_dir -lcrypto"],
     'INC'       => "-I. -I$openssl_inc_dir",
-    'CCFLAGS'   => '-O2 -g '.$Config{ccflags},
     'PREREQ_PM' => {
 #    'Class::Accessor::Fast'  => '0.31', # Constituent of module Class::Accessor
 #					 # which is a prerequisite of Class::Accessor::Chained, see below
@@ -397,5 +354,4 @@
                               't/cfg.binary.openssl']},
     'XSPROTOARG' => '-noprototypes',
     'EXE_FILES' => [ 'bin/openxpkictl','bin/openxpkicmd', 'bin/openxpkiadm', 'bin/openxpkicli'],    
-    %flags,
 );
