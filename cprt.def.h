//
// Created by mario on 2024/9/1.
//

#ifndef CPRT_DEF_H
#define CPRT_DEF_H

#define FUNC_ASSERT(...)
#define __CPRTNAME__(s) CPrt ## s

typedef enum CPrtStyle {
    __CPRTNAME__(NoStyle) = 0,
    __CPRTNAME__(HighLight),
    __CPRTNAME__(Dark),
    __CPRTNAME__(UnderLine),
    __CPRTNAME__(Blink),
    __CPRTNAME__(Reverse),
    __CPRTNAME__(Hide)
}CPrtStyle;

typedef enum CPrtForeColorStyle {
    __CPRTNAME__(NoForeColor) = 0,
    __CPRTNAME__(ForeBlack),
    __CPRTNAME__(ForeRed),
    __CPRTNAME__(ForeGreen),
    __CPRTNAME__(ForeYellow),
    __CPRTNAME__(ForeBlue),
    __CPRTNAME__(ForePurple),
    __CPRTNAME__(ForeCyan),
    __CPRTNAME__(ForeWhite)
}CPrtForeColorStyle;

typedef enum CPrtBackColorStyle {
    __CPRTNAME__(NoBackColor) = 0,
    __CPRTNAME__(BackBlack),
    __CPRTNAME__(BackRed),
    __CPRTNAME__(BackGreen),
    __CPRTNAME__(BackYellow),
    __CPRTNAME__(BackBlue),
    __CPRTNAME__(BackPurple),
    __CPRTNAME__(BackCyan),
    __CPRTNAME__(BackWhite)
}CPrtBackColorStyle;

#undef __NAME

#endif //CPRT_DEF_H
