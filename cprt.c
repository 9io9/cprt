#include <stdio.h>
#include <string.h>

#include "cprt.def.h"
#include "cprt.err.h"

#define STR(str) str, sizeof(str) - 1

const char* STYLE_STRS[] = { "0", "1", "2", "4", "5", "7", "8" };
const char* COLOR_STRS[] = { "0", "30", "31", "32", "33", "34", "35", "36", "37" };

CPrintStatusCode cprt_forecolor_style_start(CPrtForeColorStyle forecolor, FILE* f) {
    if (f == NULL || forecolor > CPrtForeWhite || forecolor < CPrtNoForeColor) {
        return CPrtFuncArgError;
    }

    fwrite(STR("\033[0;"), 1, f);
    fwrite(COLOR_STRS[forecolor], sizeof(char), strlen(COLOR_STRS[forecolor]), f);
    fwrite(STR("m"), 1, f);

    return CPrtSuccess;
}

CPrintStatusCode cprt_forecolor_style_start_nocheck(CPrtForeColorStyle forecolor, FILE* f) {
    fwrite(STR("\033[0;"), 1, f);
    fwrite(COLOR_STRS[forecolor], sizeof(char), strlen(COLOR_STRS[forecolor]), f);
    fwrite(STR("m"), 1, f);

    return CPrtSuccess;
}

CPrintStatusCode cprt_backcolor_style_start(CPrtBackColorStyle backcolor, FILE* f) {
    if (f == NULL || backcolor > CPrtBackWhite || backcolor < CPrtNoBackColor) {
        return CPrtFuncArgError;
    }

    fwrite(STR("\033[0;0;"), 1, f);
    fwrite(COLOR_STRS[backcolor], sizeof(char), strlen(COLOR_STRS[backcolor]), f);
    fwrite(STR("m"), 1, f);

    return CPrtSuccess;
}

CPrintStatusCode cprt_backcolor_style_start_nocheck(CPrtBackColorStyle backcolor, FILE* f) {
    fwrite(STR("\033[0;0;"), 1, f);
    fwrite(COLOR_STRS[backcolor], sizeof(char), strlen(COLOR_STRS[backcolor]), f);
    fwrite(STR("m"), 1, f);

    return CPrtSuccess;
}

CPrintStatusCode cprt_style_start(CPrtStyle style, FILE* f) {
    if (f == NULL || style > CPrtHide || style < CPrtNoStyle) {
        return CPrtFuncArgError;
    }

    fwrite(STR("\033["), 1, f);
    fwrite(STYLE_STRS[style], sizeof(char), strlen(STYLE_STRS[style]), f);
    fwrite(STR("m"), 1, f);

    return CPrtSuccess;
}

CPrintStatusCode cprt_style_start_nocheck(CPrtStyle style, FILE* f) {
    fwrite(STR("\033["), 1, f);
    fwrite(STYLE_STRS[style], sizeof(char), strlen(STYLE_STRS[style]), f);
    fwrite(STR("m"), 1, f);

    return CPrtSuccess;
}

CPrintStatusCode cprt_start(CPrtStyle style, CPrtForeColorStyle forecolor, CPrtBackColorStyle backcolor, FILE* f) {
    if (forecolor > CPrtForeWhite || forecolor < CPrtForeBlack) {
        return CPrtFuncArgError;
    }

    if (backcolor > CPrtBackWhite || backcolor < CPrtBackBlack) {
        return CPrtFuncArgError;
    }

    if (style > CPrtHide || style < CPrtHighLight) {
        return CPrtFuncArgError;
    }

    fwrite(STR("\033["), 1, f);
    fwrite(STYLE_STRS[style], sizeof(char), strlen(STYLE_STRS[style]), f);
    fwrite(STR(";"), 1, f);
    fwrite(COLOR_STRS[forecolor], sizeof(char), strlen(COLOR_STRS[forecolor]), f);
    fwrite(STR(";"), 1, f);
    fwrite(COLOR_STRS[backcolor], sizeof(char), strlen(COLOR_STRS[backcolor]), f);
    fwrite(STR("m"), 1, f);

    return CPrtSuccess;
}
CPrintStatusCode cprt_start_nocheck(CPrtStyle style, CPrtForeColorStyle forecolor, CPrtBackColorStyle backcolor, FILE* f) {
    fwrite(STR("\033["), 1, f);
    fwrite(STYLE_STRS[style], sizeof(char), strlen(STYLE_STRS[style]), f);
    fwrite(STR(";"), 1, f);
    fwrite(COLOR_STRS[forecolor], sizeof(char), strlen(COLOR_STRS[forecolor]), f);
    fwrite(STR(";"), 1, f);
    fwrite(COLOR_STRS[backcolor], sizeof(char), strlen(COLOR_STRS[backcolor]), f);
    fwrite(STR("m"), 1, f);

    return CPrtSuccess;
}


CPrintStatusCode cprt_end(FILE* f) {
    if (f == NULL) {
        return CPrtFuncArgError;
    }

    fwrite(STR("\033[0m"), 1, f);

    return CPrtSuccess;
}

CPrintStatusCode cprt_end_nocheck(FILE* f) {
    fwrite(STR("\033[0m"), 1, f);

    return CPrtSuccess;
}