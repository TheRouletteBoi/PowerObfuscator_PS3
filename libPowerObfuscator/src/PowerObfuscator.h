#ifndef __POWEROBFUSCATOR_H__
#define __POWEROBFUSCATOR_H__

#include <types.h>
#include <stdint.h>
#include <string>
#undef vector
#include <vector>
#include <sys/process.h>

/* symbols generated by the linker! */
extern unsigned char const __start__Ztext[];
extern unsigned char const __start__Zdata[];
extern unsigned char const __start__Zrodata[];

#define STATIC_ALWAYS_INLINE    static inline   __attribute__((always_inline))
#define NO_STATIC_ALWAYS_INLINE inline          __attribute__((always_inline))
#define NO_INLINE                               __attribute__((noinline))

#define POBF_MAGIC 'P', 'O', 'B', 'F'
#define POBF_SIGNATURE 0xAABBCCDD, 0x12345678, 0xEEFFEEFF 
/* these values will be replaced by the real values using PowerObfuscatorGUI */
#define POBF_TEXT_SEGMENT_DUMMY_VALUES      0xDEADBEEF, 0x0BADCAFE, 0x00DDBA11 
#define POBF_DATA_SEGMENT_DUMMY_VALUES      0x5CA1AB1E, 0x0DEC0DED, 0x00EFFEC7 
#define POBF_RODATA_SEGMENT_DUMMY_VALUES    0x5E1EC7ED, 0x05EEDBED, 0x05CABB1E 
#define POBF_PLACEHOLDER_DUMMY_VALUES       0x00FF5E75, 0x0001ABE1, 0x000F100D 

namespace pobf
{
    struct opd_s
    {
        uint32_t func;
        uint32_t toc;
    };

    struct Pattern
    {
        const char* find;
        const char* mask;
        bool found;
    };

    struct pobfHeader
    {
        char magic[4];
        uint32_t signature1;
        uint32_t signature2;
        uint32_t signature3;
        uint32_t textSegmentStart;
        uint32_t textSegmentSize;
        uint32_t _padding1;
        uint32_t dataSegmentStart;
        uint32_t dataSegmentSize;
        uint32_t _padding2;
        uint32_t rodataSegmentStart;
        uint32_t rodataSegmentSize;
        uint32_t _padding3;
        uint32_t placeHolder1;
        uint32_t placeHolder2;
        uint32_t _padding4;
        char placeHolder5[60];
    };

    extern pobfHeader pobf_header;

}

#endif // __POWEROBFUSCATOR_H__

