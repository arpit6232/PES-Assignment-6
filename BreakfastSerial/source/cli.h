/*
 * cli.h
 *
 *  Created on: Nov 2, 2020
 *      Author: root
 */

#ifndef CLI_H_
#define CLI_H_

#define CLI_SIZE 2048

/*
 * Parse Command entered over UART to Segment and print appropriate result
 *
 * Parameters:
 *   str : String to Parse
 *
 * Returns:
 *   void
 */
void segment_cmd(char *str);

#endif /* CLI_H_ */
