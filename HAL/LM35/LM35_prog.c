#include "../../Service/STD_types.h"
#include "../../Service/bit_math.h"
#include "LM35_int.h"

u16 LM35_u16GetTemp(f32 Copy_f32Data){
	u16 Analog;
	u16 Temp;
	Analog = Copy_f32Data * 5000.0/1024;
	Temp = Analog/10;
	return Temp;
}
