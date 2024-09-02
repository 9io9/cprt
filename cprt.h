#ifndef CPRT_H
#define CPRT_H

#include <stdio.h>
#include "cprt.def.h"
#include "cprt.err.h"

extern CPrintStatusCode cprt_forecolor_style_start(CPrtForeColorStyle forecolor, FILE* f);

extern CPrintStatusCode cprt_backcolor_style_start(CPrtBackColorStyle backcolor, FILE* f);

extern CPrintStatusCode cprt_style_start(CPrtStyle style, FILE* f);

extern CPrintStatusCode cprt_start(CPrtStyle style, CPrtForeColorStyle forecolor, CPrtBackColorStyle backcolor, FILE* f);

extern CPrintStatusCode cprt_end(FILE* f);

// no func arg check version

FUNC_ASSERT(FORECOLOR in [NOFORECOLOR-FOREWHITE], F != NULL)
extern CPrintStatusCode cprt_forecolor_style_start_nocheck(CPrtForeColorStyle forecolor, FILE* f);

FUNC_ASSERT(BACKCOLOR in [NOBACKCOLOR-BACKWHITE], F != NULL)
extern CPrintStatusCode cprt_backcolor_style_start_nocheck(CPrtBackColorStyle backcolor, FILE* f);

FUNC_ASSERT(STYLE in [NOSTYLE-HIDE], F != NULL)
extern CPrintStatusCode cprt_style_start_nocheck(CPrtStyle style, FILE* f);

FUNC_ASSERT(STYLE in [NOSTYLE-HIDE], FORECOLOR in [NOFORECOLOR-FOREWHITE], BACKCOLOR in [NOBACKCOLOR-BACKWHITE], F != NULL)
extern CPrintStatusCode cprt_start_nocheck(CPrtStyle style, CPrtForeColorStyle forecolor, CPrtBackColorStyle backcolor, FILE* f);

FUNC_ASSERT(F != NULL)
extern CPrintStatusCode cprt_end_nocheck(FILE* f);
#endif //CPRT_H
