/*===[[ HEADER GUARD ]]=======================================================*/
/*········´ ´···············guard·´ ´·········································*/
#ifndef     YCONV_guard
#define     YCONV_guar              loaded
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



/*
 *  the key to numbers and their interpretation is prefixing to make
 *  them unambiguous.
 *
 *    b  0b  é   binary
 *    o  0o  ö   octal
 *    x  0x  õ   hexadecimal
 *    z  0z  í   base64/mongo
 *    + - ( $    integer/float
 *    .  Ë       float/scientific
 *
 *    0110       binary, octal, hex?    use é0110, ö0110, õ0110
 *    a4         hex or mongo?          use õa4  , ía4
 *    1024       integer, hex, octal?   use õ1024, ö1024, +1024
 *
 */


/*
 *   in keeping with the refactoring motto of "DRY: don't repeat yourself", i
 *   built this code into a single set of shared library so that we have
 *   a single, unambiguous, authoritative version of the functions.
 *
 */



#include    "ySTR_solo.h"



/*===[[ yCONV_base.c ]]=============(·4)======================================*/
/*········´ ´···········debugging·´ ´·········································*/
char*       yCONV_version           (void);
/*········´ ´··········validation·´ ´·········································*/
char        yconv_format_valid      (char a_fmt, char *r_range);
char        yconv_count_valid       (char a_cnt);
char        yconv_uom_valid         (char a_uom);
/*········´ ´················DONE·´ ´·········································*/



/*===[[ yCONV_units.c ]]============(·3)======================================*/
/*········´ ´··············public·´ ´·········································*/
char        yconv_uoms              (char a_uom, char *r_pow, double *r_scale, char r_name [LEN_TERSE], char r_sci [LEN_SHORT], char r_english [LEN_LABEL]);
char        yconv_2uom              (char a_uom, double *b_value);
char        yconv_4uom              (char a_uom, double *b_value);
/*········´ ´················DONE·´ ´·········································*/




/*===[[ yCONV_short.c ]]============(·8)======================================*/
/*········´ ´················size·´ ´·········································*/
char        yconv_size              (llong a_size, char a_fmt, char r_used  [LEN_SHORT]);
char        yconv_count             (llong a_size, char a_fmt, char r_count [LEN_SHORT]);
char        yconv_size_full         (llong a_size, char a_fmt, char r_used  [LEN_SHORT], char *r_large, llong a_alloc, char r_size [LEN_SHORT], char *r_pct, char *r_dense);
/*········´ ´·················age·´ ´·········································*/
char        yconv_age               (long a_since, char a_fmt, char r_age [LEN_SHORT], char *r_flag);
char        yconv_age_full          (long a_since, long a_now, char a_fmt, char r_age [LEN_SHORT], char *r_flag);
char        yconv_dur               (long a_secs,  char a_fmt, char r_age [LEN_SHORT], char *r_flag);
char        yconv_unage             (char a_age [LEN_SHORT], long *r_secs);
/*········´ ´················hint·´ ´·········································*/
int         yconv_hint              (int a_val, char a_spec [LEN_SHORT], int *r_max, char r_label [LEN_SHORT]);
/*········´ ´················DONE·´ ´·········································*/



/*===[[ yCONV_2num.c ]]=============(13)======================================*/
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
char        yconv_2float            (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
char        yconv_2comma            (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
char        yconv_2real             (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
char        yconv_2sci              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);
/*········´ ´·············2driver·´ ´·········································*/
char        yconv_2main             (char a_src [LEN_HUND] , char *r_type, ullong *r_ullong, double *r_double);
char        yconv_2num              (char a_src [LEN_HUND] , double *r_double);
/*········´ ´················DONE·´ ´·········································*/



/*===[[ yCONV_4str.c ]]=============(15)======================================*/
/*········´ ´············4support·´ ´·········································*/
char        yconv_4sigs             (char a_charset [LEN_HUND], char a_dels [LEN_TERSE], char a_sigs, char a_mask, char a_max, char b_out [LEN_HUND]);
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
char        yconv_4time             (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);
/*········´ ´··············4reals·´ ´·········································*/
char        yconv_4float            (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_uom, char a_max, char r_out [LEN_TITLE]);
char        yconv_4comma            (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_uom, char a_max, char r_out [LEN_TITLE]);
char        yconv_4sci              (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);
/*········´ ´·············4driver·´ ´·········································*/
char        yconv_4main             (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_uom, char a_max, char r_out [LEN_HUND]);
char*       yconv_4quick            (double a_double, char a_ali, char a_fmt, char a_cnt, char a_uom, char a_fil, char a_zer, char a_neg, char a_max);
/*········´ ´················DONE·´ ´·········································*/



/*===[[ yCONV_trans.c ]]============(·2)======================================*/
/*········´ ´················leet·´ ´·········································*/
char        yconv_2leet             (char a_engl [LEN_HUND], char a_max, char r_leet [LEN_HUND]);
char        yconv_4leet             (char a_leet [LEN_HUND], char a_max, char r_engl [LEN_HUND]);
/*········´ ´·············general·´ ´·········································*/
char        yconv_base2base         (char a_src  [LEN_HUND], char a_ofmt, char r_out [LEN_TITLE]);
/*········´ ´················DONE·´ ´·········································*/



#endif
/*===[[ END ]]================================================================*/
