/*
 * hexdump.c
 *
 *  Created on: Nov 2, 2020
 *      Author: arpit.savarkar@colorado.edu
 *
 *  Implementation inspired by Hexdump Implementation of
 *  Howdy Pierce, howdy.pierce@colorado.edu
 */


#include "hexdump.h"


/*
​ * ​ ​ @brief​ ​ Returns a character representation of the parameter
​ *
​ * ​ ​ Given​ ​a interger, function returns the character repsentation
 *
​ * ​ ​ @param​ ​ str : ​ Interger to be converted
 *
 *   @return​ ​ char
 */
char int_to_hexchar(int x) {
	if (x >=0 && x < 10)
		return '0' + x;
	else if (x >= 10 && x < 16)
		return 'A' + x - 10;
	else
		return '-';
}


/**
​ * ​ ​ @brief​ ​ Hex Dump of a memory location upto a selected number of bytes at a specified memory
 *           location
​ *
​ * ​ ​ Prints representing a “dump” of the nbytes of memory starting at loc. Bytes are
 *    printed up to 16 bytes per line, separated by newlines.
 *
​ * ​ ​ @param​ ​ loc : ​ Pointer to a char​ data​ set where the hex dump would be stored
 *   @param nbytes : Number of bytes upto which the hex values of the memory would be printed
 *
​ * ​ ​ @return​ ​ void
​ */
void hexdump(const void *loc, size_t nbyte) {


	  const uint8_t *buf = (uint8_t*) loc;
	  const uint8_t *max = (uint8_t*) loc + nbyte;

	  if (nbyte > MAX_HEXDUMP_SIZE) {
		  nbyte = MAX_HEXDUMP_SIZE;
	  }

	  while(buf < max ) {
		    putchar(int_to_hexchar(((uint32_t)(buf) & 0xF0000000) >> 28));
			putchar(int_to_hexchar(((uint32_t)(buf) & 0x0F000000) >> 24));
			putchar(int_to_hexchar(((uint32_t)(buf) & 0x00F00000) >> 20));
			putchar(int_to_hexchar(((uint32_t)(buf) & 0x000F0000) >> 16));
			putchar('_');
			putchar(int_to_hexchar(((uint32_t)(buf) & 0x0000F000) >> 12));
			putchar(int_to_hexchar(((uint32_t)(buf) & 0x00000F00) >>  8));
			putchar(int_to_hexchar(((uint32_t)(buf) & 0x000000F0) >>  4));
			putchar(int_to_hexchar((uint32_t)(buf) & 0x0000000F));
			putchar(' ');
			putchar(' ');
			for (int j=0; j < STRIDE && buf+j < max; j++) {
			  putchar(int_to_hexchar(buf[j] >> 4));
			  putchar(int_to_hexchar(buf[j] & 0x0f));
			  putchar(' ');
				}
			buf += STRIDE;
			putchar('\r');
			putchar('\n');

	  }
}
