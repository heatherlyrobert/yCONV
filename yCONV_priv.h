/*===[[ HEADER GUARD ]]=======================================================*/
/*········´ ´···············guard·´ ´·········································*/
#ifndef     YCONV_priv_guard
#define     YCONV_priv_guard        loaded
/*········´ ´·····················´ ´·········································*/



/*===[[ BEG GNU GENERAL PUBLIC LICENSE (GPL) WARNING ]]=======================*/
/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */

#define  P_COPYRIGHT   \
   "copyright (c) 2026 robert.s.heatherly at balsashrike at gmail dot com"

#define  P_LICENSE     \
   "the only place you could have gotten this code is my github, my website,¦"   \
   "or illegal sharing. given that, you should be aware that this is GPL licensed."

#define  P_COPYLEFT    \
   "the GPL COPYLEFT REQUIREMENT means any modifications or derivative works¦"   \
   "must be released under the same GPL license, i.e, must be free and open."

#define  P_INCLUDE     \
   "the GPL DOCUMENTATION REQUIREMENT means that you must include the original¦" \
   "copyright notice and the full licence text with any resulting anything."

#define  P_AS_IS       \
   "the GPL NO WARRANTY CLAUSE means the software is provided without any¦"      \
   "warranty and the author cannot be held liable for damages."

#define  P_THEFT    \
   "if you knowingly violate the spirit of these ideas, i suspect you might¦"    \
   "find any number of freedom-minded hackers may take it quite personally ;)"

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
/*===[[ END GNU GENERAL PUBLIC LICENSE (GPL) WARNING ]]=======================*/



/*===[[ BEG ONE_LINERS ]]=====================================================*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*········· ··········· ´·····························´········································*/
#define     P_FOCUS     "PS (programming support)"
#define     P_NICHE     "st (string handling)"
#define     P_SUBJECT   "human-readable number formats"
#define     P_PURPOSE   "conversion to-and-from human-consumable number formats"
/*········· ··········· ´·····························´········································*/
#define     P_NAMESAKE  "gnosis (intuitive-knowledge)"
#define     P_PRONOUNCE "·"
#define     P_HERITAGE  "spirit of intuitive, experiential knowledge and insight"
#define     P_BRIEFLY   "spirit of intutive understanding"
#define     P_IMAGERY   ""
#define     P_REASON    "the library seeks to make numbers more understandable"
/*········· ··········· ´·····························´········································*/
#define     P_ONELINE   P_NAMESAKE " " P_SUBJECT
#define     P_FORMAL    P_NAMESAKE " " P_BRIEFLY
/*········· ··········· ´·····························´········································*/
#define     P_BASENAME  "libyCONV.so"
#define     P_HOMEDIR   "/home/system/yCONV.string_numeric_conversion"
#define     P_FULLPATH  "/usr/local/lib64/libyCONV.so"
#define     P_SUFFIX    "´"
#define     P_CONTENT   "´"
/*········· ··········· ´·····························´········································*/
#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_COMPILER  "gcc 5.3.0"
#define     P_CODESIZE  "small       (appoximately 1,000 slocl)"
/*········· ··········· ´·····························´········································*/
#define     P_DEPSTDC   "stdio,stdlib,string,unistd,math,time"
#define     P_DEPPOSIX  ""
#define     P_DEPSECURE ""
#define     P_DEPEXTEND ""
#define     P_DEPCORE   "yLOG,yURG"
#define     P_DEPVIKEY  ""
#define     P_DEPGRAPH  ""
#define     P_DEPOTHER  ""
#define     P_DEPSOLO   ""
#define     P_DEPALIEN  ""
/*········· ··········· ´·····························´········································*/
#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   "2013-09"
/*········· ··········· ´·····························´········································*/
#define     P_VERMAJOR  "1.--, production"
#define     P_VERMINOR  "1.0-, moving from ySTR"
#define     P_VERNUM    "1.0d"
#define     P_VERTXT    "yconv_2base, 2bin, _oct, _int, _hex, _mongo, _comma, _sci ported and unit-tested"
/*········· ··········· ´·····························´········································*/
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"
/*········· ··········· ´·····························´········································*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
/*===[[ END ONE_LINERS ]]=====================================================*/


/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
#define  P_DISCLAIM    \
   "i am a crazy, selfish, dog-fooding c-programmer. my code tends to be¦"         \
   "experimental and constantly evolving. my point is NOT to be the best, it¦"     \
   "is to challenge myself, build from scratch, and allow fast problem solving."

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
#define  P_BOTHER      \
   "all my applications had their own unique code to create various iterations¦"   \
   "of human-consumable numbers; but, it was a ton of work with non-standard¦"     \
   "results.  it was frustrating."

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
#define  P_COVERS      \
   "broadly, this library covers string-versions of human-consumable numbers¦"     \
   "that i use on screens, in files, and within databases.  its job is to¦"        \
   "quick understanding and direct maintenance of numbers.

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
#define  P_SUBDISC     \
   "-- definition of standard prefixes for common bases (using my shrike font)¦"   \
   "-- creation and conversion of comma delimited integers up to ullong (19 sigs)¦"\
   "-- creation and conversion of comma delimited floats up to double (15 sigs)¦"  \
   "-- creation and conversion of various binary formats up to eight bytes¦"       \
   "-- creation and conversion of various octal formats up to eight bytes¦"        \
   "-- creation and conversion of various hexadecimal formats up to eight bytes¦"  \
   "-- creation and conversion of various base64/mongo formats up to eight bytes¦" \
   "-- creation and conversion of scientific notation formats up to double¦"       \
   "-- creation and conversion of bit-level data as a human compatible format¦"    \
   "-- conversion and representation in metric scales (yotta to yocto)¦"           \
   "-- various conversions into short-hand reporting of numbers"

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
#define  P_CURRENT     \
   "i tried to use printf formats, atof, strtoull, etc for as long as i cound¦     \
   "but the results required a lot of manual coding and some functions were¦"      \
   "prickly at best.  i use these formats everywhere, they nned to be good."

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
#define  P_VALUE       \
   "i am targeted faster, more intuitive consumption of numbers, either in¦"       \
   "clearer formats or rounded into accurate-enough represtentations or scales.¦"  \
   "additionally, human editable data to cut down on stupid editing screens."

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
#define  P_FEAR        \
   "this could become a weakness if this library is not stable or only suits¦"     \
   "the needs of a subset of my applications.  if i use separate code, its¦"       \
   "messier, but the applications are not all subject to the danger."

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
#define  P_MISSING     \
   "their are not base, ansi-c methods for producing pretty, intuitive numbers,¦"  \
   "but that is why c is fast and light.  so, every thing i am biulding here¦"     \
   "is outside the scope of standard libraries (rightfully so)."

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
#define  P_KEEPING     \
   "this library will be built on stadard ansi-c, so i am keeping everything¦"     \
   "just building on top of it."


/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
#define  P_PERK        \
   "i love not using other people's libraries and code as it makes my build¦"      \
   "skilss that all c-programmers should have.  also, i will not be dependent¦"    \
   "on other's plans, desires, modivations, or timetables."

/*´´·········1·········2·········3·········4·········5·········6·········7·········8  */
#define  P_SCOPE       \
   "focused entirely on converting to-and-from various human-consumable¦"          \
   "formats for use in nearly everyone of my programs so that numbers are¦         \
   "quick, intuitively formatted, and easy."



/*345678901-12345678901-123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
#define      _XOPEN_SOURCE
#include    <stdio.h>
#include    <stdlib.h>                  /* getenv()                            */
#include    <string.h>
#include    <unistd.h>
#include    <stddef.h>                  /* defines NULL                        */
#include    <math.h>  
#include    <time.h>         /* C_ANSI : time, strftime, localtime            */
#include    <errno.h>

#include    <yLOG.h>                    /* heatherly program logger            */
#include    <yURG.h>                    /* heatherly urgent handler            */
#include    <ySTR.h>                    /* heatherly string library            */




typedef     struct   tm           tTIME;



/*===[[ unit testing helpers ]]===============================================*/
/*········´ ´············numerics·´ ´·········································*/
#define     MAX_ROMAN               3999.0                   /* classic roman range                  */
#define     MAX_DOUBLE              999999999999999.0        /* clean, precise 15 significant digits */
#define     MAX_LLONG               9223372036854775807ULL
#define     MAX_ULLONG              18446744073709551615ULL
/*········´ ´················DONE·´ ´·········································*/


#define     TYPE_BIN    'b'
#define     TYPE_OCT    'o'
#define     TYPE_INT    'i'
#define     TYPE_HEX    'x'
#define     TYPE_MAYAN  ''
#define     TYPE_MONGO  'z'
#define     TYPE_ROMAN  'r'
#define     TYPE_FLOAT  'f'
#define     TYPE_SCI    'e'
#define     TYPE_TIME   't'
#define     TYPE_DATE   'd'
#define     TYPE_FAIL   '°'

#define     TYPE_BASES  "boxz"
#define     TYPE_NORMS  "+-($"



typedef struct cROMAN  tROMAN;
static struct cROMAN {  /* roman numerals classically only went 1 - 3999 */
   char        r_chars     [LEN_SHORT];
   char        r_wide;
   int         r_value;
};
extern const tROMAN S_roman [LEN_DESC];




/*===[[ yCONV_units.c ]]======================================================*/
/*········´ ´·············support·´ ´·········································*/
char        yconv__units            (char a_dir, char a_unit, double *b_value, char *r_pow, double *r_scale, char r_name [LEN_TERSE], char r_sci [LEN_SHORT], char r_english [LEN_LABEL]);
/*········´ ´··············public·´ ´·········································*/
char        yconv_units             (char a_unit, char *r_pow, double *r_scale, char r_name [LEN_TERSE], char r_sci [LEN_SHORT], char r_english [LEN_LABEL]);
char        yconv_2unit             (char a_unit, double *b_value);
char        yconv_4unit             (char a_unit, double *b_value);
/*········´ ´················DONE·´ ´·········································*/


/*===[[ yCONV_short.c ]]======================================================*/
/*········´ ´················size·´ ´·········································*/
char        yconv__size             (llong a_size, char a_base, char a_fmt, char r_size [LEN_SHORT]);
char        yconv_size              (llong a_size, char a_fmt, char r_used [LEN_SHORT]);
char        yconv_count             (llong a_size, char a_fmt, char r_count [LEN_SHORT]);
char        yconv_size_full         (llong a_size, char a_fmt, char r_used [LEN_SHORT], char *r_large, llong a_alloc, char r_size [LEN_SHORT], char *r_pct, char *r_dense);
/*········´ ´·················age·´ ´·········································*/
char        yconv__age              (long a_since, long a_now, char a_fmt, char r_age [LEN_SHORT], char *r_flag);
char        yconv_age               (long a_since, char a_fmt, char r_age [LEN_SHORT], char *r_flag);
char        yconv_age_full          (long a_since, long a_now, char a_fmt, char r_age [LEN_SHORT], char *r_flag);
char        yconv_dur               (long a_secs,  char a_fmt, char r_age [LEN_SHORT], char *r_flag);
char        yconv_unage             (char a_age [LEN_SHORT], long *r_secs);
/*········´ ´···············count·´ ´·········································*/
char        yconv_time2mongo        (long a_epoch, char *a_mongo);
char        yconv_time4mongo        (char *a_mongo, long *a_epoch);
/*········´ ´················DONE·´ ´·········································*/



/*===[[ yCONV_2num.c ]]=======================================================*/
/*········´ ´············2support·´ ´·········································*/
char        yconv__2defense         (char a_src [LEN_HUND] , ullong *a_ullong, double *a_double, char a_under, char a_pre, char a_greek, char *r_len, char *r_beg);
char        yconv__2sign            (char b_src [LEN_TITLE], char *r_sign);
/*········´ ´··············2bases·´ ´·········································*/
char        yconv_2base             (char a_src [LEN_HUND] , char a_charset [LEN_HUND], ullong *r_ullong);
char        yconv_2bin              (char a_src [LEN_HUND] , ullong *r_ullong, double *r_double);
char        yconv_2oct              (char a_src [LEN_DESC] , ullong *r_ullong, double *r_double);
char        yconv_2int              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
char        yconv_2hex              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
char        yconv_2mongo            (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
/*········´ ´············2special·´ ´·········································*/
char        yconv_2roman            (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
/*········´ ´··············2reals·´ ´·········································*/
char        yconv__2divide          (char a_src [LEN_TITLE], char r_int [LEN_TITLE], char r_dec [LEN_TITLE], char r_exp [LEN_TITLE]);
char        yconv__2part            (char a_part, char a_src [LEN_TITLE], llong *r_llong);
char        yconv_2float            (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
char        yconv_2comma            (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
char        yconv_2real             (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
char        yconv_2sci              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
/*········´ ´·············2driver·´ ´·········································*/
char        yconv__2type            (char a_src [LEN_HUND]);
char        yconv_2main             (char a_src [LEN_HUND] , char *r_type, ullong *r_ullong, double *r_double);
char        yconv_2num              (char a_src [LEN_HUND] , double *r_double);
/*········´ ´················DONE·´ ´·········································*/



/*===[[ yCONV_4str.c ]]=======================================================*/
/*········´ ´············4support·´ ´·········································*/
char        yconv__4defense         (char a_type, char a_greek, ullong a_ullong, double a_double, char a_fmt, char a_max, char *r_source, char r_prefix [LEN_SHORT], char r_out [LEN_TITLE]);
char        yconv__space_ints       (char a_every, char a_char, char b_out [LEN_HUND]);
char        yconv__space_decs       (char a_every, char a_char, char b_out [LEN_HUND]);
/*········´ ´··············4bases·´ ´·········································*/
char        yconv_4base             (ullong a_ullong, double a_double, char a_prefix [LEN_SHORT], char a_charset [LEN_HUND], char a_spacing, char a_cnt, char a_fmt, char a_max, char r_out [LEN_HUND]);
char        yconv_4bool             (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);
char        yconv_4bin              (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_HUND]);
char        yconv_4oct              (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_DESC]);
char        yconv_4int              (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);
char        yconv_4hex              (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);
char        yconv_4mongo            (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);
/*········´ ´············4special·´ ´·········································*/
char        yconv_4roman            (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);
/*········´ ´··············4reals·´ ´·········································*/
char        yconv__4divide          (double a_source, char a_decs, char a_unit, char a_max, char *r_sign, llong *r_int, llong *r_dec, llong *r_exp, char r_unit [LEN_SHORT], char r_out [LEN_TITLE]);
char        yconv_4float            (ullong a_ullong, double a_double, char a_decs, char a_fmt, char a_unit, char a_max, char r_out [LEN_TITLE]);
char        yconv_4comma            (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_unit, char a_max, char r_out [LEN_TITLE]);
char        yconv_4sci              (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);
char        yconv_4time             (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);
/*········´ ´·············4driver·´ ´·········································*/
char        yconv_4main             (ullong a_ullong, double a_double, char a_bytes, char a_fmt, char a_unit, char a_max, char r_out [LEN_TITLE]);
char*       yconv_4quick            (double a_double, char a_ali, char a_fmt, char a_cnt, char a_uom, char a_fil, char a_zer, char a_neg, char a_max);
/*········´ ´················DONE·´ ´·········································*/


#endif
