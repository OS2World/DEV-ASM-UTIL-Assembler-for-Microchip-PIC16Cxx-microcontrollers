/*
 * devices.c -- picasm
 *
 * Timo Rossi <trossi@iki.fi>
 *
 */

#include <stdio.h>

#include "picasm.h"

/*
 * PIC device type table
 */

struct pic_type pic_types[] = {
/* name      prog   reg  eeprom  id_addr fuseaddr  fusetype      instrset */
	
/* 12-bit PICs */
{ "12C508",   512, 0x20,   0,     0x200,   0xfff,  FUSE_12C5XX,  PIC12BIT },
{ "12C509",  1024, 0x30,   0,     0x400,   0xfff,  FUSE_12C5XX,  PIC12BIT },
	
{ "16C52",    384, 0x20,   0,     0x180,   0xfff,  FUSE_16C5X,   PIC12BIT },
{ "16C54",    512, 0x20,   0,     0x200,   0xfff,  FUSE_16C5X,   PIC12BIT },
{ "16C54A",   512, 0x20,   0,     0x200,   0xfff,  FUSE_16C5X,   PIC12BIT },
{ "16C55",    512, 0x20,   0,     0x200,   0xfff,  FUSE_16C5X,   PIC12BIT },
{ "16C56",   1024, 0x20,   0,     0x400,   0xfff,  FUSE_16C5X,   PIC12BIT },
{ "16C57",   2048, 0x20,   0,     0x800,   0xfff,  FUSE_16C5X,   PIC12BIT },
{ "16C58A",  2048, 0x20,   0,     0x800,   0xfff,  FUSE_16C5X,   PIC12BIT },

/* 14-bit PICs */
{ "12C671",  1024, 0x80,   0,    0x2000,  0x2007,  FUSE_12C6XX,  PIC14BIT },
{ "12C672",  2048, 0x80,   0,    0x2000,  0x2007,  FUSE_12C6XX,  PIC14BIT },
	
{ "16C61",   1024, 0x30,   0,    0x2000,  0x2007,  FUSE_16CXX1,  PIC14BIT },
{ "16C71",   1024, 0x30,   0,    0x2000,  0x2007,  FUSE_16CXX1,  PIC14BIT },
{ "16C84",   1024, 0x30,  64,    0x2000,  0x2007,  FUSE_16CXX1,  PIC14BIT },

{ "16C62",   2048, 0x80,   0,    0x2000,  0x2007,  FUSE_16CXX2,  PIC14BIT },	
{ "16C64",   2048, 0x80,   0,    0x2000,  0x2007,  FUSE_16CXX2,  PIC14BIT },	
{ "16C65",   4096, 0x80,   0,    0x2000,  0x2007,  FUSE_16CXX2,  PIC14BIT },	
{ "16C73",   4096, 0x80,   0,    0x2000,  0x2007,  FUSE_16CXX2,  PIC14BIT },	
{ "16C74",   4096, 0x80,   0,    0x2000,  0x2007,  FUSE_16CXX2,  PIC14BIT },	

{ "16C62A",  2048, 0x80,   0,    0x2000,  0x2007,  FUSE_16C6XA,  PIC14BIT },	
{ "16C63",   4096, 0x80,   0,    0x2000,  0x2007,  FUSE_16C6XA,  PIC14BIT },	
{ "16C64A",  2048, 0x80,   0,    0x2000,  0x2007,  FUSE_16C6XA,  PIC14BIT },	
{ "16C65A",  4096, 0x80,   0,    0x2000,  0x2007,  FUSE_16C6XA,  PIC14BIT },	
{ "16C66",   8192, 0x80,   0,    0x2000,  0x2007,  FUSE_16C6XA,  PIC14BIT },
{ "16C67",   8192, 0x80,   0,    0x2000,  0x2007,  FUSE_16C6XA,  PIC14BIT },
{ "16C72",   2048, 0x80,   0,    0x2000,  0x2007,  FUSE_16C6XA,  PIC14BIT },	
{ "16C73A",  4096, 0x80,   0,    0x2000,  0x2007,  FUSE_16C6XA,  PIC14BIT },	
{ "16C74A",  4096, 0x80,   0,    0x2000,  0x2007,  FUSE_16C6XA,  PIC14BIT },
{ "16C76",   8192, 0x80,   0,    0x2000,  0x2007,  FUSE_16C6XA,  PIC14BIT },
{ "16C77",   8192, 0x80,   0,    0x2000,  0x2007,  FUSE_16C6XA,  PIC14BIT },
	
{ "16C710",   512, 0x20,   0,    0x2000,  0x2007,  FUSE_16C71X,  PIC14BIT },
{ "16C711",  1024, 0x30,   0,    0x2000,  0x2007,  FUSE_16C71X,  PIC14BIT },
	
{ "16C715",  2048, 0x80,   0,    0x2000,  0x2007,  FUSE_16C715,  PIC14BIT },
	
{ "16C83",    512, 0x30,  64,    0x2000,  0x2007,  FUSE_16F8X,   PIC14BIT },	
{ "16C84A",  1024, 0x50,  64,    0x2000,  0x2007,  FUSE_16F8X,   PIC14BIT },	
{ "16F84",   1024, 0x50,  64,    0x2000,  0x2007,  FUSE_16F8X,   PIC14BIT },

{ "16C620",   512, 0x70,   0,    0x2000,  0x2007,  FUSE_16C62X,  PIC14BIT },
{ "16C621",  1024, 0x70,   0,    0x2000,  0x2007,  FUSE_16C62X,  PIC14BIT },
{ "16C622",  2048, 0x80,   0,    0x2000,  0x2007,  FUSE_16C62X,  PIC14BIT },

{ "16C554",   512, 0x70,   0,    0x2000,  0x2007,  FUSE_16C55X,  PIC14BIT },
{ "16C554A",  512, 0x70,   0,    0x2000,  0x2007,  FUSE_16C55X,  PIC14BIT },
{ "16C556A", 1024, 0x70,   0,    0x2000,  0x2007,  FUSE_16C55X,  PIC14BIT },
{ "16C558",  2048, 0x80,   0,    0x2000,  0x2007,  FUSE_16C55X,  PIC14BIT },
{ "16C558A", 2048, 0x80,   0,    0x2000,  0x2007,  FUSE_16C55X,  PIC14BIT },
	
{ "16C923",  4096, 0x80,   0,    0x2000,  0x2007,  FUSE_16C55X,  PIC14BIT },
{ "16C924",  4096, 0x80,   0,    0x2000,  0x2007,  FUSE_16C55X,  PIC14BIT },
	
{ "14000",   4096, 0x80,   0,    0x2000,  0x2007,  FUSE_14000,   PIC14BIT },
{ "14C000",  4096, 0x80,   0,    0x2000,  0x2007,  FUSE_14000,   PIC14BIT },
	
{  NULL,       0,    0,   0,         0,       0,        0 }
};

#if 0
/*
 * This PIC type table is not anywhere near complete...
 * (I don't have full data sheets of all the chips that I have
 * put in this table, so it may contain errors...)
 */

struct pic_type pic_types[] = {
  { "16C61",  1024,  0, 0x30, PIC14BIT },         /* RAM 36B  */

  { "16C62",  2048,  0, 0x80, PIC14BIT|PIC_CP2 }, /* RAM 128B */
  { "16C63",  4096,  0, 0x80, PIC14BIT|PIC_CP2 }, /* RAM 192B */
  { "16C64",  2048,  0, 0x80, PIC14BIT|PIC_CP2 }, /* RAM 128B */
  { "16C65",  4096,  0, 0x80, PIC14BIT|PIC_CP2 }, /* RAM 192B */

  { "16C71",  1024,  0, 0x30, PIC14BIT },         /* RAM 36B  */

  { "16C73",  4096,  0, 0x80, PIC14BIT|PIC_CP2 }, /* RAM 192B */
  { "16C74",  4096,  0, 0x80, PIC14BIT|PIC_CP2 }, /* RAM 192B */

  { "16C84",  1024, 64, 0x30, PIC14BIT },         /* RAM 36B  */

  { "16C83",   512, 64, 0x30, PIC14BIT|PIC_CP4|PIC_PWRT_INV },

  { "16C84A", 1024, 64, 0x50, PIC14BIT|PIC_CP4|PIC_PWRT_INV },
  { "16F84",  1024, 64, 0x50, PIC14BIT|PIC_CP4|PIC_PWRT_INV },

  /* RAM 80B (0x20-0x6f) */
  { "16C620",  512,  0, 0x70, PIC14BIT|PIC_CP3|PIC_BOD|PIC_PWRT_INV },
  { "16C621", 1024,  0, 0x70, PIC14BIT|PIC_CP3|PIC_BOD|PIC_PWRT_INV },
  /* RAM 128B (0x20-0x7f,0xa0-0xbf)*/
  { "16C622", 2048,  0, 0x80, PIC14BIT|PIC_CP3|PIC_BOD|PIC_PWRT_INV },

  /* RAM 192B (special case in config.c) */
  { "14000",  4096,  0, 0x80, PIC14BIT },
  { "14C000",  4096,  0, 0x80, PIC14BIT },

  { NULL,        0,  0,   0, -1} /* end marker */
};

#endif
