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
 *   ySTR is a set of shared functions for string handling and manipulation
 *   services for use by the calling program.  it was designed to take a
 *   repeditive, tedious, haphazard, and neglected set of functions and make
 *   them systematic, shared, testable, maintainable, and reliable.
 *
 *   in keeping with the refactoring motto of "DRY: don't repeat yourself", we
 *   will build this code into a single set of shared library so that we have
 *   a single, unambiguous, authoritative version of the functions.
 *
 *   ySTR will focus on supplementing "string.h" with functions that can
 *   increase security, eliminate hidden bugs, and reduce the code intensity
 *   in programs using it...
 *      - eliminate strcat, strcpy with their potential overruns
 *      - reduce hidden errors caused by misuse of strncat and strncpy
 *      - stop small possibility of overrun in strlen
 *      - create a standard for trimming whitespace which most program need
 *      - simplify and standardize delimiter handling
 *      - anything else clever i can think of ;)
 * 
 *   many existing libraries and utilities have been built by better programmers
 *   that are likely superior in speed, size, capability, and reliability; BUT,
 *   i would not have learned nearly as much using them, so follow the adage...
 * 
 *   TO TRULY LEARN> do not seek to follow in the footsteps of the men of old;
 *   seek what they sought ~ Matsuo Basho
 */



#include    "ySTR_solo.h"




/*===[[ yCONV_units.c ]]======================================================*/
/*········´ ´··············public·´ ´·········································*/
char        yconv_units             (char a_unit, char *r_pow, double *r_scale, char r_name [LEN_TERSE], char r_sci [LEN_SHORT], char r_english [LEN_LABEL]);
char        yconv_2unit             (char a_unit, double *b_value);
char        yconv_4unit             (char a_unit, double *b_value);
/*········´ ´················DONE·´ ´·········································*/




/*===[[ yCONV_short.c ]]======================================================*/
/*········´ ´················size·´ ´·········································*/
char        yconv_size              (llong a_size, char a_fmt, char r_used  [LEN_SHORT]);
char        yconv_count             (llong a_size, char a_fmt, char r_count [LEN_SHORT]);
char        yconv_size_full         (llong a_size, char a_fmt, char r_used  [LEN_SHORT], char *r_large, llong a_alloc, char r_size [LEN_SHORT], char *r_pct, char *r_dense);
/*········´ ´·················age·´ ´·········································*/
char        yconv_age               (long a_since, char a_fmt, char r_age [LEN_SHORT], char *r_flag);
char        yconv_age_full          (long a_since, long a_now, char a_fmt, char r_age [LEN_SHORT], char *r_flag);
char        yconv_dur               (long a_secs,  char a_fmt, char r_age [LEN_SHORT], char *r_flag);
char        yconv_unage             (char a_age [LEN_SHORT], long *r_secs);
/*········´ ´···············count·´ ´·········································*/
char        yconv_time2mongo        (long a_epoch, char *a_mongo);
char        yconv_time4mongo        (char *a_mongo, long *a_epoch);
/*········´ ´················DONE·´ ´·········································*/







/*> /+===[[ ySTR_nums.c ]]========================================================+/                                                                                                                           <* 
 *> /+········´ ´···············units·´ ´·········································+/                                                                                                                           <* 
 *> char        ystrunits               (char a_unit, char *r_pow, double *r_scale, char r_name [LEN_TERSE], char r_sci [LEN_SHORT], char r_english [LEN_LABEL]);                                              <* 
 *> char        ystr2unit               (char a_unit, double *b_value);                                                                                                                                        <* 
 *> char        ystr4unit               (char a_unit, double *b_value);                                                                                                                                        <* 
 *> /+········´ ´················sigs·´ ´·········································+/                                                                                                                           <* 
 *> char        ystrlsigs               (char a_charset [LEN_HUND], char a_dels [LEN_TERSE], char a_sigs, char a_mask, char a_max, char b_out [LEN_HUND]);                                                     <* 
 *> /+········´ ´··············2bases·´ ´·········································+/                                                                                                                           <* 
 *> char        ystr2base               (char a_src [LEN_HUND] , char a_charset [LEN_HUND], ullong *r_ullong);                                                                                                 <* 
 *> char        ystr2bin                (char a_src [LEN_HUND] , ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> char        ystr2oct                (char a_src [LEN_DESC] , ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> char        ystr2int                (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> char        ystr2hex                (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> char        ystr2mongo              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> /+········´ ´············2special·´ ´·········································+/                                                                                                                           <* 
 *> char        ystr2roman              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> /+········´ ´··············2reals·´ ´·········································+/                                                                                                                           <* 
 *> char        ystr2float              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> char        ystr2comma              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> char        ystr2real               (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> char        ystr2sci                (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> /+········´ ´·············2driver·´ ´·········································+/                                                                                                                           <* 
 *> char        ystr2main               (char a_src [LEN_HUND] , char *r_type, ullong *r_ullong, double *r_double);                                                                                            <* 
 *> char        ystr2num                (char a_src [LEN_HUND] , double *r_double);                                                                                                                            <* 
 *> /+········´ ´··············4bases·´ ´·········································+/                                                                                                                           <* 
 *> char        ystrl4base              (ullong a_ullong, double a_double, char a_prefix [LEN_SHORT], char a_charset [LEN_HUND], char a_spacing, char a_cnt, char a_fmt, char a_max, char r_out [LEN_HUND]);   <* 
 *> char        ystrl4bool              (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);                                                                        <* 
 *> char        ystrl4bin               (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_HUND]);                                                                         <* 
 *> char        ystrl4oct               (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_DESC]);                                                                         <* 
 *> char        ystrl4int               (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);                                                                        <* 
 *> char        ystrl4hex               (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);                                                                        <* 
 *> char        ystrl4mongo             (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);                                                                        <* 
 *> /+········´ ´············4special·´ ´·········································+/                                                                                                                           <* 
 *> char        ystrl4roman             (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);                                                                        <* 
 *> /+········´ ´··············4reals·´ ´·········································+/                                                                                                                           <* 
 *> char        ystrl4float             (ullong a_ullong, double a_double, char a_decs, char a_fmt, char a_unit, char a_max, char r_out [LEN_TITLE]);                                                          <* 
 *> char        ystrl4comma             (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_unit, char a_max, char r_out [LEN_TITLE]);                                                           <* 
 *> char        ystrl4sci               (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);                                                                        <* 
 *> char        ystrl4time              (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE]);                                                                        <* 
 *> /+········´ ´·············4driver·´ ´·········································+/                                                                                                                           <* 
 *> char        ystrl4main              (ullong a_ullong, double a_double, char a_bytes, char a_fmt, char a_unit, char a_max, char r_out [LEN_TITLE]);                                                         <* 
 *> char*       ystrl4quick             (double a_double, char a_ali, char a_fmt, char a_cnt, char a_uom, char a_fil, char a_zer, char a_neg, char a_max);                                                     <* 
 *> /+········´ ´·········specialized·´ ´·········································+/                                                                                                                           <* 
 *> char        ystrlbit2bin            (char *a_bits, char a_blen, char a_fmt, char a_max, char r_out [LEN_TITLE]);                                                                                           <* 
 *> char        ystrbin2bit             (char  a_src [LEN_TITLE], char *r_bits, char a_blen);                                                                                                                  <* 
 *> char        ystrbin2val             (char  a_src [LEN_TITLE], double *r_val);                                                                                                                              <* 
 *> /+········´ ´················DONE·´ ´·········································+/                                                                                                                           <*/



#endif
/*===[[ END ]]================================================================*/
