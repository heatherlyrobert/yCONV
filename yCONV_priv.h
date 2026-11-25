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
#define     P_PURPOSE   "conversion of human-readable number formats"
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
#define     P_VERNUM    "1.0a"
#define     P_VERTXT    "successfully transferred ySTR_format units functions and unit-tested"
/*········· ··········· ´·····························´········································*/
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"
/*········· ··········· ´·····························´········································*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
/*===[[ END ONE_LINERS ]]=====================================================*/



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

#include    <yURG.h>                    /* heatherly program logger            */
#include    <yLOG.h>                    /* heatherly program logger            */




typedef     struct   tm           tTIME;



/*===[[ unit testing helpers ]]===============================================*/
/*········´ ´············numerics·´ ´·········································*/
#define     MAX_ROMAN               3999.0                   /* classic roman range                  */
#define     MAX_DOUBLE              999999999999999.0        /* clean, precise 15 significant digits */
#define     MAX_LLONG               9223372036854775807ULL
#define     MAX_ULLONG              18446744073709551615ULL
/*········´ ´················DONE·´ ´·········································*/






/*===[[ yCONV_units.c ]]======================================================*/
/*········´ ´·············support·´ ´·········································*/
char        yconv__units            (char a_dir, char a_unit, double *b_value, char *r_pow, double *r_scale, char r_name [LEN_TERSE], char r_sci [LEN_SHORT], char r_english [LEN_LABEL]);
/*········´ ´··············public·´ ´·········································*/
char        yconv_units             (char a_unit, char *r_pow, double *r_scale, char r_name [LEN_TERSE], char r_sci [LEN_SHORT], char r_english [LEN_LABEL]);
char        yconv_2unit             (char a_unit, double *b_value);
char        yconv_4unit             (char a_unit, double *b_value);
/*········´ ´················DONE·´ ´·········································*/








/*> /+===[[ ySTR_format.c ]]======================================================+/                                                                                                                           <* 
 *> /+········´ ´···············units·´ ´·········································+/                                                                                                                           <* 
 *> char        ystr_units              (char a_dir, char a_unit, double *b_value, char *r_pow, double *r_scale, char r_name [LEN_TERSE], char r_sci [LEN_SHORT], char r_english [LEN_LABEL]);                 <* 
 *> char        ystrunits               (char a_unit, char *r_pow, double *r_scale, char r_name [LEN_TERSE], char r_sci [LEN_SHORT], char r_english [LEN_LABEL]);                                              <* 
 *> char        ystr2unit               (char a_unit, double *b_value);                                                                                                                                        <* 
 *> char        ystr4unit               (char a_unit, double *b_value);                                                                                                                                        <* 
 *> /+········´ ´················sigs·´ ´·········································+/                                                                                                                           <* 
 *> char        ystrlsigs               (char a_charset [LEN_HUND], char a_dels [LEN_TERSE], char a_sigs, char a_mask, char a_max, char b_out [LEN_HUND]);                                                     <* 
 *> /+········´ ´············2support·´ ´·········································+/                                                                                                                           <* 
 *> char        ystr2_defense           (char a_src [LEN_HUND] , ullong *a_ullong, double *a_double, char a_under, char a_pre, char a_greek, char *r_len, char *r_beg);                                        <* 
 *> char        ystr2_sign              (char b_src [LEN_TITLE], char *r_sign);                                                                                                                                <* 
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
 *> char        ystr2_divide            (char a_src [LEN_TITLE], char r_int [LEN_TITLE], char r_dec [LEN_TITLE], char r_exp [LEN_TITLE]);                                                                      <* 
 *> char        ystr2_part              (char a_part, char a_src [LEN_TITLE], llong *r_llong);                                                                                                                 <* 
 *> char        ystr2float              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> char        ystr2comma              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> char        ystr2real               (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> char        ystr2sci                (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double);                                                                                                          <* 
 *> /+········´ ´·············2driver·´ ´·········································+/                                                                                                                           <* 
 *> char        ystr2_type              (char a_src [LEN_HUND]);                                                                                                                                               <* 
 *> char        ystr2main               (char a_src [LEN_HUND] , char *r_type, ullong *r_ullong, double *r_double);                                                                                            <* 
 *> char        ystr2num                (char a_src [LEN_HUND] , double *r_double);                                                                                                                            <* 
 *> /+········´ ´············4support·´ ´·········································+/                                                                                                                           <* 
 *> char        ystr4_defense           (char a_type, char a_greek, ullong a_ullong, double a_double, char a_fmt, char a_max, char *r_source, char r_prefix [LEN_SHORT], char r_out [LEN_TITLE]);              <* 
 *> char        ystr4_space_open        (char a_pos, char a_insert [LEN_SHORT], char b_out [LEN_HUND], char *b_len);                                                                                           <* 
 *> char        ystr4_space_ints        (char a_every, char a_char, char b_out [LEN_HUND]);                                                                                                                    <* 
 *> char        ystr4_space_decs        (char a_every, char a_char, char b_out [LEN_HUND]);                                                                                                                    <* 
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
 *> char        ystr4_divide            (double a_source, char a_decs, char a_unit, char a_max, char *r_sign, llong *r_int, llong *r_dec, llong *r_exp, char r_unit [LEN_SHORT], char r_out [LEN_TITLE]);      <* 
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
