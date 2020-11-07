/*
 * hexdump.h
 *
 *  Created on: Nov 2, 2020
 *      Author: root
 */

#ifndef HEXDUMP_H_
#define HEXDUMP_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define STRIDE 16
#define MAX_HEXDUMP_SIZE 640

/*
​ * ​ ​ @brief​ ​ Returns a character representation of the parameter
​ *
​ * ​ ​ Given​ ​a interger, function returns the character repsentation
 *
​ * ​ ​ @param​ ​ str : ​ Interger to be converted
 *
 *   @return​ ​ char
 */
char int_to_hexchar(int x);


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
void hexdump(const void *loc, size_t nbytes);

#endif /* HEXDUMP_H_ */
