--- src/memory.c.orig	Sat Apr 29 02:13:47 2006
+++ src/memory.c	Sat Sep  9 18:12:36 2006
@@ -67,7 +67,7 @@
 MEM_READ_ENTRY mem_read_tab[0x10];
 MEM_WRITE_ENTRY mem_write_tab[0x10];
 
-Sint16 joy_x_min=0;joy_x_max=0;joy_y_min=0;joy_y_max=0;
+Sint16 joy_x_min=0,joy_x_max=0,joy_y_min=0,joy_y_max=0;
 
 void (*select_rom_page)(Uint16 adr,Uint8 v);
 void (*select_ram_page)(Uint16 adr,Uint8 v);
@@ -742,6 +742,13 @@
   if (!conf.play_movie) {
 
     if (conf.use_joy) {
+      Sint16 joy_x_pos=joy_axis[jmap[PAD_LEFT]];
+      Sint16 joy_y_pos=joy_axis[jmap[PAD_UP]];
+      Sint16 joy_x_mid=(joy_x_max-joy_x_min) / 2;
+      Sint16 joy_y_mid=(joy_y_max-joy_y_min) / 2;
+      Sint16 joy_x_qua=joy_x_mid / 2;
+      Sint16 joy_y_qua=joy_y_mid / 2;
+
       if ((joy_but[jmap[PAD_START]]) || (key[kmap[PAD_START]])) gb_pad|=0x08; /* Start */
       if ((joy_but[jmap[PAD_SELECT]]) || (key[kmap[PAD_SELECT]])) gb_pad|=0x04; /* Select */
       if ((joy_but[jmap[PAD_A]]) || (key[kmap[PAD_A]])) gb_pad|=0x01; /* A */
@@ -752,18 +759,10 @@
       if ((joy_axis[jmap[PAD_UP]]<-10000) ||  (key[kmap[PAD_UP]])) gb_pad|=0x40;
       if ((joy_axis[jmap[PAD_DOWN]]>10000) || (key[kmap[PAD_DOWN]])) gb_pad|=0x80;*/
 
-      Sint16 joy_x_pos=joy_axis[jmap[PAD_LEFT]];
-      Sint16 joy_y_pos=joy_axis[jmap[PAD_UP]];
-
       if (joy_x_pos>joy_x_max) joy_x_max=joy_x_pos;
       if (joy_x_pos<joy_x_min) joy_x_min=joy_x_pos;
       if (joy_y_pos>joy_y_max) joy_y_max=joy_y_pos;
       if (joy_y_pos<joy_y_min) joy_y_min=joy_y_pos;
-
-      Sint16 joy_x_mid=(joy_x_max-joy_x_min) / 2;
-      Sint16 joy_y_mid=(joy_y_max-joy_y_min) / 2;
-      Sint16 joy_x_qua=joy_x_mid / 2;
-      Sint16 joy_y_qua=joy_y_mid / 2;
 
       if ((joy_x_pos<(joy_x_mid-joy_x_qua)) || (key[kmap[PAD_LEFT]])) gb_pad|=0x20;
       if ((joy_x_pos>(joy_x_mid+joy_x_qua)) || (key[kmap[PAD_RIGHT]])) gb_pad|=0x10;
