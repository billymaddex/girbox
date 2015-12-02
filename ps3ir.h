/* 
Girbox

Copyright (C) 2015 Billy Maddex

This file is part of Girbox.

Girbox is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Girbox is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Girbox.  If not, see <http://www.gnu.org/licenses/>.

Author: Billy Maddex 
*/

//PS3 key Codes
#define	EJECT		0	
#define	AUDIO		1
#define	ANGLE		2
#define	SUBTITLE	3
#define	RED		4
#define	GREEN		5
#define	BLUE		6
#define	YELLOW		7
#define	CLEAR		8
#define	TIME		9
#define	ENTER		10
#define	DISPLAY		11
#define	TOP_MENU	12
#define	POPUP		13
#define	RETURN		14
#define	TRIANGLE	15
#define	CIRCLE		16	
#define	SQUARE		17
#define	BIG_X		18
#define	L1		19
#define	L2		20
#define	L3		21
#define	R1		22
#define	R2		23
#define	R3		24
#define	SELECT		25
#define	START		26
#define	SCAN_REV	27
#define	PLAY		28
#define	SCAN_FWD	29
#define	PREVIOUS	30
#define	STOP		31
#define	NEXT		128	
#define	SLOW_REV	129
#define	PAUSE		130
#define	SLOW_FWD	131
#define	UP		132
#define	LEFT		133
#define	RIGHT		134
#define	DOWN		135
#define	NUM_0		144	
#define	NUM_1		145
#define	NUM_2		146
#define	NUM_3		147
#define	NUM_4		148
#define	NUM_5		149
#define	NUM_6		150
#define	NUM_7		151
#define	NUM_8		152
#define	NUM_9		153
#define	PS		154

#define M1		241
#define M2		242
#define M3		243
#define M4		244
#define M5		245
#define M6		246
#define M7		247
#define M8		248
#define M9		249
#define M10		250
#define M11		251
#define D_OFF		252
#define D_ON		253
#define NONE		255

// ps3ir modes
#define TEACH_MODE 0x00
#define VIRTUAL_MODE 0x01

/* function prototypes */

/* open ps3 ir device & returns ps3_ir, file descriptor */
int ps3_open(char *device);

/* close ps3 ir device */
void ps3_close(int ps3_ir);

/* 00 = Teach Remote, 01 = Virtual Remote */
void ps3_set_mode(int ps3_ir, char mode);

/* execute factory reset */
void ps3_factory_reset(int ps3_ir);

/* delay function */
void delay(int milliseconds);

/* send key down signal */
void ps3_keydown(int ps3_ir, char command);

/* send key up signal */
void ps3_keyup(int ps3_ir);
