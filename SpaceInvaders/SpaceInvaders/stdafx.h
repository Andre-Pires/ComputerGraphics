// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
#include "targetver.h"

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <time.h>

#if defined(__APPLE__) || defined(MACOSX) 
#include <GLUT/glut.h> 
#else
#include <GL/glut.h> 
#endif



// TODO: reference additional headers your program requires here
