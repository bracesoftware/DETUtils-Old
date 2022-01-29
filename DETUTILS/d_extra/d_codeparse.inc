/*
 *
 * Code parse dependency
 *
 *
 *
 * DETUtils core
 *
 *
 */

#define DETUTILS_PARSE__ARRAY_COUNT

#if defined DETUTILS_PARSE__ARRAY_COUNT

#define ARRAY_COUNT:%1(%2) FUNC_PARSER(ARRAY_COUNT,ARR:NUM:)(%1(%2)) \
        stock const DETUTILS_ARR_PARAMS_%1 = 0; stock %1(%2)
#define ARRAY_COUNT_NUM(%9)%8$ %8$
#define ARRAY_COUNT_ARR(%9)%8$%0=%1; %8$%0=%1 + 1;
#define ARRAY_COUNT_END(%9)%8$ %8$
#define ARRAY_COUNT_NUL(%9)%8$ %8$

#else

#define ALL_COUNT:%1(%2) FUNC_PARSER(ALL_COUNT,ARR:NUM:EXT:STR:REF:)(%1(%2)) \
    stock const \
        refCount_%1 = 0, \
        extCount_%1 = 0, \
        arrCount_%1 = 0, \
        strCount_%1 = 0, \
        numCount_%1 = 0; \
    %1(%2)

#define ALL_COUNT_REF(%9)%8$%0,%1,%2,%3,%4; %8$%0 + 1,%1,%2,%3,%4;
#define ALL_COUNT_EXT(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1 + 1,%2,%3,%4;
#define ALL_COUNT_ARR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2 + 1,%3,%4;
#define ALL_COUNT_STR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3 + 1,%4;
#define ALL_COUNT_NUM(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3,%4 + 1;

#define ALL_COUNT_END(%9)%8$ %8$
#define ALL_COUNT_NUL(%9)%8$ %8$

#endif