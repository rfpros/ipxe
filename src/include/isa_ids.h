#ifndef ISA_IDS_H
#define ISA_IDS_H

/* 
 * This file defines IDs as used by ISAPnP and EISA devices.  These
 * IDs have the format:
 *
 * vendor  byte 0 bit  7    must be zero
 *		  bits 6-2  first vendor char in compressed ASCII
 *		  bits 1-0  second vendor char in compressed ASCII (bits 4-3)
 *	   byte 1 bits 7-5  second vendor char in compressed ASCII (bits 2-0)
 *                bits 4-0  third vendor char in compressed ASCII
 * product byte 0 bits 7-4  first hex digit of product number
 *		  bits 3-0  second hex digit of product number
 *	   byte 1 bits 7-4  third hex digit of product number
 *		  bits 3-0  hex digit of revision level
 *
 */

#include "stdint.h"

#define	ISA_BUS_TYPE	2

/*
 * Construct a vendor ID from three ASCII characters
 *
 */
#define ISA_VENDOR(a,b,c)	(((((a)-'A'+1)&0x3f)<<2)|\
				((((b)-'A'+1)&0x18)>>3)|((((b)-'A'+1)&7)<<13)|\
				((((c)-'A'+1)&0x1f)<<8))
#define ISAPNP_VENDOR(a,b,c)	ISA_VENDOR(a,b,c)
#define EISA_VENDOR(a,b,c)	ISA_VENDOR(a,b,c)

#define	GENERIC_ISAPNP_VENDOR	ISAPNP_VENDOR('P','N','P')

/*
 * Extract product ID and revision from combined product field
 *
 */
#define ISA_PROD_ID_MASK	( 0xf0ff )
#define ISA_PROD_ID(product)	( (product) & ISA_PROD_ID_MASK )
#define ISA_PROD_REV(product)	( ( (product) & ~ISA_PROD_ID_MASK ) >> 8 )

/* Functions in isa_ids.c */
extern char * isa_id_string ( uint16_t vendor, uint16_t product );

#endif /* ISA_IDS_H */
