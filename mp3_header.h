#ifndef MP3_HEADER_H
#define MP3_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// error & help functions
void no_arg();
void help_mp3();
int is_mp3(const char *);

// view function (needs filename)
void view_mp3(const char *);

// convert function (takes int, returns int)
int convert(int );

// edit function (takes tag, new value, and filename)
void edit_mp3(const char *, const char *, const char *);

#endif
