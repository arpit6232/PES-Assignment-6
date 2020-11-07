/*
 * main.c - application entry point
 * 
 * Author Howdy Pierce, howdy.pierce@colorado.edu
 */

#include "MKL25Z4.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


#include "sysclock.h"
#include "queue.h"
#include "UART.h"
#include "hexdump.h"
#include "cli.h"
#include "test_queue.h"


int main(void)
{
  sysclock_init();
  Init_UART0(38400);

  test_queue();

  // Application Mode that sets the Command Line Interface
  application_mode();

  return 0 ;
}
