/*
 * Commons.h
 *
 *  Created on: Jan 5, 2019
 *      Author: Islam Ahmed
 */

#ifndef COMMONS_H_
#define COMMONS_H_




#define   WORD_SIZE     (32)

 
#define COMMONS_BIT1(x)  (1<<x)

#define COMMONS_BIT0(x)  (~(BIT1(x)))

#define COMMONS_BITS_SetBit(REG,BitIndex)      ((REG)|=(1UL<<(BitIndex)))
#define COMMONS_BITS_ClearBit(REG,BitIndex)    ((REG)&=(~(1UL<<(BitIndex))))
#define COMMONS_BITS_ToggleBit(REG,BitIndex)   ((REG)^=(1UL<<(BitIndex)))
#define COMMONS_BITS_RotR(REG,BitIndex)        ((REG)=((REG)>>(BitIndex))|((REG)<<((WORD_SIZE)-(BitIndex))))
#define COMMONS_BITS_RotL(REG,BitIndex)        ((REG)=((REG)<<(BitIndex))|((REG)>>((WORD_SIZE)-(BitIndex))))
#define COMMONS_BITS_IsSet(REG,BitIndex)       ((REG)&(1UL<<(BitIndex)))
#define COMMONS_BITS_IsClear(REG,BitIndex)     (!((REG)&(1UL<<(BitIndex))))
#define COMMONS_BITS_ReadBit(REG,BitIndex)     ((REG)&(1UL<<(BitIndex)))




/*********************************************** Inlines **************************************************************************/


/*
 inline void BITS_WriteAdjBitS(uint32 REG , uint8 BitsCount,  uint8 LSBIndex, uint32 value) {

	//To write some data at certain bits without affecting the others

	//Clear these bits first
	BITS_ClearAdjBitS(REG, BitsCount, LSBIndex);  //macro to clear adjacent bits

	// check if the data > 0  to avoid unnecessary memory access (Just Cleared)
	if(value)   REG|=(value << LSBIndex);// write the data

}
*/

 /*********************************************** Declarations of Commons APIs Functions *******************************************/





#endif /* COMMONS_H_ */
