/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2019 André van Schoubroeck <andre@philosopher.it>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_41_PCLK_H
#define LIBOPENCM3_41_PCLK_H


#include <libopencm3/cm3/common.h>
#include "memorymap.h"

// PSoC 4 Architecture TRM Rev G page 57



// There are supposed to be 4 of each according to the Architecture TRM
// Since there is 40 betwen A and B, 

#define PCLK_DIVIDER_A	(PCLK_BASE + 0x0000)
#define PCLK_DIVIDER_B	(PCLK_BASE + 0x0004)
#define PCLK_DIVIDER_C	(PCLK_BASE + 0x0008)

#define PCLK_DIVIDER_FRAC_A	(PCLK_BASE + 0x0100)
#define PCLK_DIVIDER_FRAC_B	(PCLK_BASE + 0x0104)
#define PCLK_DIVIDER_FRAC_C	(PCLK_BASE + 0x0108)

// It is defined in the Register TRM as one register, but the Architecture
// TRM refers to it as PCLK_SELECT_N therefore I suppose it is as follows
#define PCLK_SELECT			(PCLK_BASE + 0x0200)

#define PCLK_SELECT_IMO ((PCLK_SELECT)+ 0*4)
#define PCLK_SELECT_SARPUMP ((PCLK_SELECT)+ 1*4)
#define PCLK_SELECT_SCB0 ((PCLK_SELECT)+ 2*4)
#define PCLK_SELECT_SCB1 ((PCLK_SELECT)+ 3*4)
#define PCLK_SELECT_LCD ((PCLK_SELECT)+ 4*4)
#define PCLK_SELECT_CSD1 ((PCLK_SELECT)+ 5*4)
#define PCLK_SELECT_CSD2 ((PCLK_SELECT)+ 6*4)
#define PCLK_SELECT_SAR ((PCLK_SELECT)+ 7*4)
#define PCLK_SELECT_TCPWM0 ((PCLK_SELECT)+ 8*4)
#define PCLK_SELECT_TCPWM1 ((PCLK_SELECT)+ 9*4)
#define PCLK_SELECT_TCPWM2 ((PCLK_SELECT)+ 10*4)
#define PCLK_SELECT_TCPWM3 ((PCLK_SELECT)+ 11*4)
#define PCLK_SELECT_UDB0 ((PCLK_SELECT)+ 12*4)
#define PCLK_SELECT_UDB1 ((PCLK_SELECT)+ 13*4)
#define PCLK_SELECT_UDB2 ((PCLK_SELECT)+ 14*4)
#define PCLK_SELECT_UDB3 ((PCLK_SELECT)+ 15*4)

/* --- Function prototypes ------------------------------------------------- */

BEGIN_DECLS

void pclk_set_divider(int divider_abc, int divider_n, int value);
void pclk_select(intptr_t select_peripheral, int divider_abc, int divider_n);

END_DECLS

#endif