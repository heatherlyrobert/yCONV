/*============================[[    beg-code    ]]============================*/
/*········´ ´·············headers·´ ´·········································*/
#include    "yCONV.h"
#include    "yCONV_priv.h"
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



char
yconv_2leet             (char a_engl [LEN_HUND], char a_max, char r_leet [LEN_HUND])
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   int         x_len       =    0;
   int         i           =    0;
   char       *p           = NULL;
   char        x_ch        =  '-';
   char        x_leet      [LEN_HUND]  = "";
   /*---(default)------------------------*/
   if (r_leet  != NULL)  strcpy (r_leet, "");
   /*---(defense)------------------------*/
   --rce; if (a_engl == NULL || a_engl [0] == '\0') return rce;
   x_len = strlen (a_engl);
   --rce;  if (a_max < 1 || a_max >  LEN_HUND)      return rce;
   /*---(prepare)------------------------*/
   if (x_len > a_max)  x_len = a_max;
   /*---(walk)---------------------------*/
   for (i = 0; i < x_len; ++i) {
      /*---(filter)----------------------*/
      x_ch = a_engl [i];
      if (x_ch == '\0')  break;
      /*---(check lower-case)------------*/
      p = strchr (YSTR_LOWER, x_ch);
      if (p != NULL) { x_leet [i] = YSTR_LEET  [p - YSTR_LOWER]; continue; }
      /*---(check upper-case)------------*/
      p = strchr (YSTR_UPPER, x_ch);
      if (p != NULL) { x_leet [i] = YSTR_LEET  [p - YSTR_UPPER]; continue; }
      /*---(copy straight)---------------*/
      x_leet [i] = x_ch;
      /*---(done)------------------------*/
   }
   /*---(save-back)----------------------*/
   if (r_leet  != NULL)  ystrlcpy (r_leet, x_leet, LEN_HUND);
   /*---(complete)-----------------------*/
   return 0;
}

char
yconv_4leet        (char a_leet [LEN_HUND], char a_max, char r_engl [LEN_HUND])
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   int         x_len       =    0;
   int         i           =    0;
   char       *p           = NULL;
   char        x_ch        =  '-';
   char        x_engl      [LEN_HUND]  = "";
   /*---(default)------------------------*/
   if (r_engl  != NULL)  strcpy (r_engl, "");
   /*---(defense)------------------------*/
   --rce; if (a_leet == NULL || a_leet [0] == '\0') return rce;
   x_len = strlen (a_leet);
   --rce;  if (a_max < 1 || a_max >  LEN_HUND)      return rce;
   /*---(prepare)------------------------*/
   if (x_len > a_max)  x_len = a_max;
   /*---(walk)---------------------------*/
   for (i = 0; i < x_len; ++i) {
      /*---(filter)----------------------*/
      x_ch = a_leet [i];
      if (x_ch == '\0')  break;
      /*---(check lower-case)------------*/
      p = strchr (YSTR_LEET , x_ch);
      if (p != NULL) { x_engl [i] = YSTR_LOWER [p - YSTR_LEET ]; continue; }
      /*---(copy straight)---------------*/
      x_engl [i] = x_ch;
      /*---(done)------------------------*/
   }
   /*---(save-back)----------------------*/
   if (r_engl  != NULL)  ystrlcpy (r_engl, x_engl, LEN_HUND);
   /*---(complete)-----------------------*/
   return 0;
}

char
yconv_base2base         (char a_src  [LEN_HUND], char a_ofmt, char r_out [LEN_TITLE])
{
   char        rce         =  -10;
   char        rc          =    0;
   char        x_ifmt      =  '-';
   char        x_irange    =  '-';
   char        x_orange    =  '-';
   char        x_use       =  '-';
   ullong      x_ullong    =    0;
   double      x_double    =  0.0;
   char        x_max       =    0;
   char        x_out       [LEN_HUND]  = "";
   char        x_type      =  '-';
   /*---(default)------------------------*/
   if (r_out   != NULL)  strcpy (r_out, "");
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(check input)--------------------*/
   x_ifmt    = yconv__2type (a_src, &x_irange);
   DEBUG_YCONV   yLOG_value   ("2type"    , rc);
   --rce;  if (x_ifmt < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_char    ("x_ifmt"   , x_ifmt);
   DEBUG_YCONV   yLOG_char    ("x_irange" , x_irange);
   /*---(check output)-------------------*/
   DEBUG_YCONV   yLOG_char    ("a_ofmt"   , a_ofmt);
   rc = yconv_format_valid (a_ofmt, &x_orange);
   DEBUG_YCONV   yLOG_value   ("valid"    , rc);
   --rce;  if (rc     < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_char    ("x_orange" , x_orange);
   /*---(determine range)----------------*/
   if      (x_irange == 'u' && x_irange == 'u')  x_use = 'u';
   else                                          x_use = 'd';
   DEBUG_YCONV   yLOG_char    ("x_use"    , x_use);
   /*---(convert input)------------------*/
   if (x_use == 'u')   rc = yconv_2main (a_src, &x_type, &x_ullong, NULL     );
   else                rc = yconv_2main (a_src, &x_type, NULL     , &x_double);
   DEBUG_YCONV   yLOG_value   ("2main"    , rc);
   --rce;  if (rc     < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_char    ("x_type"   , x_type);
   /*---(set max on output)--------------*/
   switch (a_ofmt) {
   case 'b' : case 'B' :  x_max = LEN_HUND;   break;
   case 'o' : case 'O' :  x_max = LEN_DESC;   break;
   default             :  x_max = LEN_TITLE;  break;
   }
   DEBUG_YCONV   yLOG_value   ("x_max"    , x_max);
   /*---(convert output)-----------------*/
   if (x_use == 'u')   rc = yconv_4main (x_ullong, 0.0     , 0, a_ofmt, '-', x_max, x_out);
   else                rc = yconv_4main (0       , x_double, 0, a_ofmt, '-', x_max, x_out);
   DEBUG_YCONV   yLOG_value   ("4main"    , rc);
   --rce;  if (rc     < 0)  {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(default)------------------------*/
   if (r_out   != NULL)  ystrlcpy (r_out, x_out, LEN_HUND);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yconv_time2mongo               (long a_epoch, char r_mongo [LEN_TERSE])
{
   /*---(locals)-----------+-----+-----+-*/
   long        x_now       =    0;
   tTIME      *x_broke     = NULL;
   /*---(set time)-----------------------*/
   if (a_epoch > 0)  x_now  = a_epoch;
   else              x_now  = time (NULL);
   /*---(break it down)------------------*/
   x_broke   = localtime (&x_now);
   /*---(take the pieces)----------------*/
   r_mongo [0] = YSTR_MONGO [x_broke->tm_year - 100];
   r_mongo [1] = YSTR_MONGO [x_broke->tm_mon];
   r_mongo [2] = YSTR_MONGO [x_broke->tm_mday - 1];
   r_mongo [3] = YSTR_MONGO [x_broke->tm_hour];
   r_mongo [4] = YSTR_MONGO [x_broke->tm_min];
   r_mongo [5] = YSTR_MONGO [x_broke->tm_sec];
   r_mongo [6] = '\0';
   /*---(complete)-----------------------*/
   return 0;
}

char
yconv_time4mongo               (char a_mongo [LEN_TERSE], long *r_epoch)
{
   /*---(locals)-----------+-----+-----+-*/
   tTIME       x_broke;
   /*---(take the pieces)----------------*/
   x_broke.tm_year  = strchr (YSTR_MONGO, a_mongo [0]) - YSTR_MONGO + 100;
   x_broke.tm_mon   = strchr (YSTR_MONGO, a_mongo [1]) - YSTR_MONGO;
   x_broke.tm_mday  = strchr (YSTR_MONGO, a_mongo [2]) - YSTR_MONGO + 1;
   x_broke.tm_hour  = strchr (YSTR_MONGO, a_mongo [3]) - YSTR_MONGO;
   x_broke.tm_min   = strchr (YSTR_MONGO, a_mongo [4]) - YSTR_MONGO;
   x_broke.tm_sec   = strchr (YSTR_MONGO, a_mongo [5]) - YSTR_MONGO;
   x_broke.tm_isdst = -1;
   /*---(break it down)------------------*/
   *r_epoch   = mktime (&x_broke);
   /*---(complete)-----------------------*/
   return 0;
}
/*> char                                                                                                  <* 
 *> ystrlbit2bin            (char *a_bits, char a_blen, char a_fmt, char a_max, char r_out [LEN_TITLE])   <* 
 *> {                                                                                                     <* 
 *>    int         i           =    0;                                                                    <* 
 *>    char        t           [LEN_LABEL] = "";                                                          <* 
 *>    strcpy (r_out, "");                                                                                <* 
 *>    for (i = 0; i < a_blen; ++i) {                                                                     <* 
 *>       if (i > 0 )  ystrlcat (r_out, ":", a_max);                                                      <* 
 *>       /+> ystrl4bin (a_bits [0], 2, a_fmt, LEN_LABEL, t);                             <+/             <* 
 *>       ystrlcat (r_out, t, a_max);                                                                     <* 
 *>    }                                                                                                  <* 
 *>    return 0;                                                                                          <* 
 *> }                                                                                                     <*/

/*> char                                                                                         <* 
 *> ystrlbin2bit            (char *a_src, char *r_bits, char a_blen)                  <* 
 *> {                                                                                            <* 
 *>    int         i           =    0;                                                           <* 
 *>    int         x_bits      =    0;                                                           <* 
 *>    int         x_byte      =    0;                                                           <* 
 *>    int         x_val       =    0;                                                           <* 
 *>    uchar       c           =  ' ';                                                           <* 
 *>    for (i = 0; i < x_bits; ++i) {                                                            <* 
 *>       x_val = pow (2, 15 - i);                                                               <* 
 *>       c = g_char [a_index].image [y][i];                                                     <* 
 *>       if (c == '#')  x_byte += x_val;                                                        <* 
 *>       DEBUG_YSTR    yLOG_complex ("loop"      , "%2d, %5d, %c, %5c", x, x_val, c, x_byte);   <* 
 *>    }                                                                                         <* 
 *> }                                                                                            <*/

/*> char                                                                                         <* 
 *> ystrlbin2val            (char  *a_src, double *r_val)                             <* 
 *> {                                                                                            <* 
 *>    int         x_byte      =    0;                                                           <* 
 *>    int         x_val       =    0;                                                           <* 
 *>    uchar       c           =  ' ';                                                           <* 
 *>    x_byte = 0;                                                                               <* 
 *>    for (x = 0; x < x_bits; ++x) {                                                            <* 
 *>       x_val = pow (2, 15 - x);                                                               <* 
 *>       c = g_char [a_index].image [y][x];                                                     <* 
 *>       if (c == '#')  x_byte += x_val;                                                        <* 
 *>       DEBUG_INPT    yLOG_complex ("loop"      , "%2d, %5d, %c, %5c", x, x_val, c, x_byte);   <* 
 *>    }                                                                                         <* 
 *>    ystrl4bin ((double) x_byte, 4, 'n', LEN_LABEL, t);                                        <* 
 *> }                                                                                            <*/



