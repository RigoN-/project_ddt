#include <stdio.h>
#include <stdlib.h>
#include "textglut.h"

void glutDrawText(float x, float y, float z, char *string, int fontset)

{
  
  char *c;
  // set position to start drawing fonts
  glRasterPos3f(x, y, z);
  switch (fontset) {
		case 0:    for (c=string; *c != '\0'; c++) 
						{
						 glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
						 };break;
		case 1:    for (c=string; *c != '\0'; c++) 
						{
						 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
						 };break;
		case 2:    for (c=string; *c != '\0'; c++) 
						{
						 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
						 };break;
		case 3:    for (c=string; *c != '\0'; c++) 
						{
						 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
						 };break;
		case 4:    for (c=string; *c != '\0'; c++) 
						{
						 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
						 };break;
		case 5:    for (c=string; *c != '\0'; c++) 
						{
						 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
						 };break;
		case 6:    for (c=string; *c != '\0'; c++) 
						{
						 glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
						 };break;
		default: for (c=string; *c != '\0'; c++) 
						{
						 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
						 };break;
		}
}
