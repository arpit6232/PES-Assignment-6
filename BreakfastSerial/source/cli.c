/*
 * cli.c
 *
 *  Created on: Nov 2, 2020
 *      Author: root
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "hexdump.h"
#include "cli.h"

typedef void (*separate_cmd)(const char* cmd); // Operating Using Function Pointers

typedef struct {
	const char* head;
	separate_cmd func_name;
} cmd_lookup_t;


/*
 * Prints Appropriate string for parsed command
 *
 * Parameters:
 *   str : String to Parse
 *
 * Returns:
 *   void
 */
static void auth(const char* cmd){
	printf("Arpit Savarkar\r\n");
}


/*
 * Prints Appropriate string for hexDump parsed command
 *
 * Parameters:
 *   str : String to Parse
 *
 * Returns:
 *   void
 */
static void dumpHexDump(const char* cmd){
	uint32_t start;
	size_t len;
	if(sscanf(cmd, "dump %x %i", &start, &len) == 2) {
		hexdump((void*) start, len);
	}
}


/*
 * Prints Appropriate string for unrecognized parsed command
 *
 * Parameters:
 *   str : String to Parse
 *
 * Returns:
 *   void
 */
static void unrecognized(const char* cmd){
	printf("Unknown Command: %s\r\n", cmd);
}

static const cmd_lookup_t cmds[] = {
		{"author", auth},
		{"dump", dumpHexDump},
		{"", unrecognized}
};


/*
 * Parse Command entered over UART to Segment and print appropriate result
 *
 * Parameters:
 *   str : String to Parse
 *
 * Returns:
 *   void
 */
void segment_cmd(char *str) {

	char temp[CLI_SIZE] = {0};
	char* tmp1 = &temp[0];
	char* tmp2 = &str[0];
	int flag = 1;
	char head[20];

	while(*tmp2 != '\0'){
		if(isspace(*tmp2)) {
			if(flag) {
				tmp2++;
			} else {
				*tmp1++ = ' ';
				flag = 1;
			}
		}
		else {
			*tmp1++ = tolower(*tmp2++);
			flag = 0;
		}
	}
	*tmp2 = '\0';

	sscanf(temp, "%s", head);

	int num = sizeof(cmds) / sizeof(cmd_lookup_t);
	for(int i=0; i<num-1; i++) {
		if(strcmp(head, cmds[i].head) == 0) {
			cmds[i].func_name(temp);
			tmp1 = &temp[0];
			tmp2 = &str[0];
			return;
		}
	}

	unrecognized(temp);
	tmp1 = &temp[0];
	tmp2 = &str[0];
	return;

}
