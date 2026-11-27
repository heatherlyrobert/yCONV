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



const tROMAN S_roman [LEN_DESC] = {
   { "MMM"   , 3 ,  3000 },
   { "MM"    , 2 ,  2000 },
   { "M"     , 1 ,  1000 },
   { "CM"    , 2 ,   900 },
   { "DCCC"  , 4 ,   800 },
   { "DCC"   , 3 ,   700 },
   { "DC"    , 2 ,   600 },
   { "D"     , 1 ,   500 },
   { "CD"    , 2 ,   400 },
   { "CCC"   , 3 ,   300 },
   { "CC"    , 2 ,   200 },
   { "C"     , 1 ,   100 },
   { "XC"    , 2 ,    90 },
   { "LXXX"  , 4 ,    80 },
   { "LXX"   , 3 ,    70 },
   { "LX"    , 2 ,    60 },
   { "L"     , 1 ,    50 },
   { "XL"    , 2 ,    40 },
   { "XXX"   , 3 ,    30 },
   { "XX"    , 2 ,    20 },
   { "X"     , 1 ,    10 },
   { "IX"    , 2 ,     9 },
   { "VIII"  , 4 ,     8 },
   { "VII"   , 3 ,     7 },
   { "VI"    , 2 ,     6 },
   { "V"     , 1 ,     5 },
   { "IV"    , 2 ,     4 },
   { "III"   , 3 ,     3 },
   { "II"    , 2 ,     2 },
   { "I"     , 1 ,     1 },
   { "end-of", 0 ,     0 },
};



/*====================------------------------------------====================*/
/*===----                 support for string to number                 ----===*/
/*====================------------------------------------====================*/
static void      o___2SUPPORT________________o (void) {;}

char
yconv__2defense         (char a_src [LEN_HUND], ullong *r_ullong, double *r_double, char a_under, char a_pre, char a_greek, char *r_len, char *r_beg)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   int         x_len       =    0;
   char        x_1st       =  '-';
   char        x_2nd       =  '-';
   char        x_min       =   -1;               /* first translatable char   */
   char        x_beg       =  '-';
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_ullong != NULL)  *r_ullong =   0;
   if (r_double != NULL)  *r_double = 0.0;
   if (r_len    != NULL)  *r_len    =   0;
   if (r_beg    != NULL)  *r_beg    =   0;
   /*---(defense)------------------------*/
   DEBUG_YCONV   yLOG_spoint  (a_src);
   --rce; if (a_src == NULL || a_src [0] == '\0') {
      DEBUG_YCONV   yLOG_snote   ("a_src null/empty");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_snote   (a_src);
   DEBUG_YCONV   yLOG_spoint  (r_ullong);
   DEBUG_YCONV   yLOG_spoint  (r_double);
   --rce; if (r_ullong == NULL && r_double == NULL) {
      DEBUG_YCONV   yLOG_snote   ("a_ullong and r_double can not both be null");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce; if (r_ullong != NULL && r_double != NULL) {
      DEBUG_YCONV   yLOG_snote   ("a_ullong and r_double can not both be used");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(verify length)------------------*/
   x_len = strlen (a_src);
   DEBUG_YCONV   yLOG_sint    (x_len);
   DEBUG_YCONV   yLOG_sint    (a_under);
   --rce; if (x_len < a_under) {
      DEBUG_YCONV   yLOG_snote   ("a_src too short");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_pre == TYPE_BIN) {
      if (x_len >= LEN_HUND) {
         DEBUG_YCONV   yLOG_snote   ("a_src binary too long");
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   } else if (a_pre == TYPE_OCT) {
      if (x_len >= LEN_DESC) {
         DEBUG_YCONV   yLOG_snote   ("a_src octal too long");
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   } else if (x_len >= LEN_TITLE) {
      DEBUG_YCONV   yLOG_snote   ("a_src too long");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(quick-out)----------------------*/
   DEBUG_YCONV   yLOG_schar   (a_pre);
   DEBUG_YCONV   yLOG_schar   (a_greek);
   if (a_pre == 0 && a_greek == 0) {
      DEBUG_YCONV   yLOG_snote   ("no prefix to eval");
      if (r_len  != NULL)  *r_len   = x_len;
      DEBUG_YCONV   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   x_1st = tolower (a_src [0]);
   DEBUG_YCONV   yLOG_schar   (x_1st);
   x_2nd = tolower (a_src [1]);
   DEBUG_YCONV   yLOG_schar   (x_2nd);
   /*---(octal exception)----------------*/
   if (a_pre == TYPE_OCT && x_1st == '0') {
      DEBUG_YCONV   yLOG_snote   ("octal zero prefix");
      if (strchr ("oOö", x_2nd) == NULL) x_min  =  1;
      else                               x_min  =  2;
   }
   /*---(check prefixes)-----------------*/
   else if (a_pre != 0 && x_1st == a_pre) {
      DEBUG_YCONV   yLOG_snote   ("simple prefix");
      x_min  =  1;
   } else if (a_pre != 0 && x_1st == '0' && x_2nd == a_pre) {
      DEBUG_YCONV   yLOG_snote   ("zeroed prefix");
      x_min  =  2;
   } else if (a_greek != 0 && x_1st == a_greek) {
      DEBUG_YCONV   yLOG_snote   ("greek prefix");
      x_min  =  1;
   }
   DEBUG_YCONV   yLOG_sint    (x_min);
   if (x_min < 1) {
      DEBUG_YCONV   yLOG_snote   ("unknown prefix");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check for value)----------------*/
   x_beg = tolower (a_src [x_min]);
   --rce; if (x_beg == '\0') {
      if (a_pre == TYPE_OCT && x_1st == '0' && x_len == 1) {
         x_min = 0;
      } else {
         DEBUG_YCONV   yLOG_snote   ("prefix without value");
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(save-back)----------------------*/
   if (r_len  != NULL)  *r_len   = x_len;
   if (r_beg  != NULL)  *r_beg   = x_min;
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
yconv__2sign            (char b_src [LEN_TITLE], char *r_sign)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        x_src       [LEN_TITLE] = "";
   int         l           =    0;
   char        x_beg       =    0;
   char        x_sign      =    1;
   char        x_1st       =  ' ';
   char        x_2nd       =  ' ';
   int         i           =    0;
   /*---(default)------------------------*/
   if (r_sign  != NULL)  *r_sign  = +1;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_senter  (__FUNCTION__);
   /*---(defense)------------------------*/
   --rce;  if (b_src == NULL) {
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   ystrlcpy (x_src, b_src, LEN_TITLE);
   DEBUG_YCONV   yLOG_snote   (x_src);
   l = strlen (x_src);
   DEBUG_YCONV   yLOG_sint    (l);
   /*---(quick-out)----------------------*/
   if (l <= 1) {
      DEBUG_YCONV   yLOG_sexit   (__FUNCTION__);
      return 0;
   }
   /*---(leading padding)----------------*/
   for (i = x_beg; i < l; ++i) {
      if (x_src [i] == '\0')  break;
      if (strchr ("·²´',á:", x_src [i]) == NULL)  break;
      ++x_beg;
   }
   DEBUG_YCONV   yLOG_sint    (x_beg);
   l = strlen (x_src);
   DEBUG_YCONV   yLOG_sint    (l);
   /*---(kill leading dollar sign)--------*/
   x_1st = x_src [x_beg];
   DEBUG_YCONV   yLOG_schar   (x_1st);
   if (x_1st == '$') {
      ++x_beg;
      x_1st = x_src [x_beg];
      DEBUG_YCONV   yLOG_schar   (x_1st);
   }
   /*---(leading sign)-------------------*/
   switch (x_1st) {
   case '+' : x_sign = +1;   ++x_beg;  break;
   case '-' : x_sign = -1;   ++x_beg;  break;
   case '(' : x_sign = -1;   ++x_beg;  break;
   }
   DEBUG_YCONV   yLOG_sint    (x_sign);
   DEBUG_YCONV   yLOG_sint    (x_beg);
   /*---(post-sign padding)--------------*/
   for (i = x_beg; i < l; ++i) {
      if (x_src [i] == '\0')  break;
      if (strchr ("·²´',á:", x_src [i]) == NULL)  break;
      ++x_beg;
   }
   DEBUG_YCONV   yLOG_sint    (x_beg);
   l = strlen (x_src);
   DEBUG_YCONV   yLOG_sint    (l);
   /*---(trailing sign)------------------*/
   x_1st = x_src [l - 1];
   DEBUG_YCONV   yLOG_schar   (x_1st);
   x_2nd = x_src [l - 2];
   DEBUG_YCONV   yLOG_schar   (x_2nd);
   switch (x_1st) {
   case '+' : x_sign = +1;  x_src [l - 1] = '\0';  break;
   case '-' : x_sign = -1;  x_src [l - 1] = '\0';  break;  
   case ')' :               x_src [l - 1] = '\0';  break;
   }
   DEBUG_YCONV   yLOG_sint    (x_sign);
   /*---(trailing padding)---------------*/
   for (i = l; i > 0; --i) {
      if (strchr ("·²´',á:", x_src [i]) == NULL)  break;
      x_src [i] = '\0';
   }
   /*---(save-back)----------------------*/
   ystrlcpy (b_src, x_src + x_beg, LEN_TITLE);
   if (r_sign  != NULL)  *r_sign  = x_sign;
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_sexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----               convert specialty base to number               ----===*/
/*====================------------------------------------====================*/
static void      o___2BASES__________________o (void) {;}

char
yconv_2base               (char a_src [LEN_HUND], char a_charset [LEN_HUND], ullong *r_ullong)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         x_base      =    0;
   char        x_len       =    0;
   int         i           =    0;
   char        x_ch        =  '-';
   char       *p           = NULL;
   int         x_digit     =    0;               /* digit value               */
   ullong      x_place     =    1;               /* base position             */
   ullong      x_final     =    0;               /* final value               */
   char        c           =    0;               /* digits included           */
   ullong      x_new       =    0;
   ullong      x_avail     =    0;
   ullong      x_prev      =    0;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_ullong != NULL)  *r_ullong =   0;
   /*---(defense)------------------------*/
   DEBUG_YCONV   yLOG_point   ("a_src"     , a_src);
   --rce; if (a_src == NULL || a_src [0] == '\0') {
      DEBUG_YCONV   yLOG_note    ("a_src null/empty");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_info    ("a_src"     , a_src);
   DEBUG_YCONV   yLOG_point   ("a_charset" , a_charset);
   --rce; if (a_charset  == NULL || a_charset [0] == '\0') {
      DEBUG_YCONV   yLOG_note    ("charset null/empty");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_info    ("a_charset" , a_charset);
   /*---(prepare)------------------------*/
   x_len = strlen (a_src);
   DEBUG_YCONV   yLOG_value   ("x_len"     , x_len);
   x_base = strlen (a_charset);
   DEBUG_YCONV   yLOG_value   ("x_base"    , x_base);
   --rce;  if (x_base < 2) {
      DEBUG_YCONV   yLOG_note    ("base too small");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (x_base >= LEN_HUND) {
      DEBUG_YCONV   yLOG_note    ("base too large");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(walk string)--------------------*/
   --rce;  for (i = x_len - 1; i >= 0; --i) {
      /*---(select)----------------------*/
      x_ch = a_src [i];
      if (x_base < 36)  x_ch = tolower (x_ch);
      DEBUG_YCONV   yLOG_char    ("x_ch"      , x_ch);
      /*---(filter)----------------------*/
      if (x_base == 10 && x_ch == ',')   continue;
      if (strchr ("':á´", x_ch) != NULL)  continue;
      /*---(check)-----------------------*/
      if (strchr ("·²"  , x_ch) != NULL)  x_ch = '0';
      if (strchr ("³Ï°" , x_ch) != NULL)  x_ch = a_charset [x_base - 1];
      p = strchr (a_charset, x_ch);
      if (p == NULL) {
         DEBUG_YCONV   yLOG_note    ("BAD CHARACTER");
         DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      /*---(process)---------------------*/
      x_digit = p - a_charset;
      DEBUG_YCONV   yLOG_value   ("x_digit"   , x_digit);
      /*---(overflow)--------------------*/
      DEBUG_YCONV   yLOG_ullong  ("x_prev"    , x_prev);
      DEBUG_YCONV   yLOG_ullong  ("x_place"   , x_place);
      if (x_digit > 0 && x_place < x_prev) {
         DEBUG_YCONV   yLOG_note    ("TOO MANY SIGS");
         DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      /*---(calculate)-------------------*/
      x_new   = x_digit * x_place;
      DEBUG_YCONV   yLOG_ullong  ("x_new"     , x_new);
      if (x_digit > 0 && x_new == 0) {
         DEBUG_YCONV   yLOG_note    ("OVERFLOW");
         DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      /*---(check)-----------------------*/
      x_avail = MAX_ULLONG - x_final;
      DEBUG_YCONV   yLOG_ullong  ("x_avail"   , x_avail);
      if (x_new > x_avail) {
         DEBUG_YCONV   yLOG_note    ("OVERFLOW");
         DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      /*---(accumulate)------------------*/
      x_final += x_new;
      ++c;
      DEBUG_YCONV   yLOG_complex ("update"    , "%2dd, %2dc, %llup, %llun, %lluf, %llu", x_digit, c, x_place, x_new, x_final, x_prev);
      /*---(next)------------------------*/
      x_prev   = x_place;
      x_place *= x_base;
      /*---(done)------------------------*/
   }
   DEBUG_YCONV   yLOG_value   ("c"         , c);
   DEBUG_YCONV   yLOG_ullong  ("x_final"   , x_final);
   /*---(save-back)----------------------*/
   if (r_ullong != NULL)  *r_ullong = x_final;
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return c;
}

char         /*-> interpret binary numbers ----------------[ petal  [ 2f---- ]*/
yconv_2bin                (char a_src [LEN_HUND], ullong *r_ullong, double *r_double)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_beg       =   -1;               /* first translatable char   */
   ullong      x_final     =    0;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__2defense (a_src,  r_ullong, r_double, 2 , TYPE_BIN, 'é', NULL, &x_beg);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(translate)----------------------*/
   rc = yconv_2base (a_src + x_beg, YSTR_BINARY, &x_final);
   DEBUG_YCONV   yLOG_value   ("yconv_2base" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check range)--------------------*/
   DEBUG_YCONV   yLOG_ullong  ("x_final"   , x_final);
   --rce;  if (r_double != NULL  && x_final > MAX_DOUBLE) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_ullong != NULL)  *r_ullong = x_final;
   if (r_double != NULL)  *r_double = (double) x_final;
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return rc;
}

char         /*-> interpret octal numbers -----------------[ petal  [ 2e---- ]*/
yconv_2oct                (char a_src [LEN_DESC] , ullong *r_ullong, double *r_double)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;               /* return code for errors    */
   char        rc          =    0;
   char        x_beg       =   -1;               /* first translatable char   */
   ullong      x_final     =    0;               /* final value               */
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__2defense (a_src, r_ullong, r_double,  1 , TYPE_OCT, 'ö', NULL, &x_beg);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(translate)----------------------*/
   rc = yconv_2base (a_src + x_beg, YSTR_OCTAL , &x_final);
   DEBUG_YCONV   yLOG_value   ("yconv_2base" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check range)--------------------*/
   DEBUG_YCONV   yLOG_ullong  ("x_final"   , x_final);
   --rce;  if (r_double != NULL  && x_final > MAX_DOUBLE) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_ullong != NULL)  *r_ullong = x_final;
   if (r_double != NULL)  *r_double = (double) x_final;
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return rc;
}

char
yconv_2int                (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_src       [LEN_TITLE] = "";
   char        x_sign      =   +1;
   ullong      x_final     =    0;               /* final value               */
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__2defense (a_src, r_ullong, r_double,  1 , 0 , 0 , NULL, NULL);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(get the sign)-------------------*/
   ystrlcpy (x_src, a_src, LEN_TITLE);
   rc = yconv__2sign (x_src, &x_sign);
   DEBUG_YCONV   yLOG_value   ("yconv__2sign", rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_info    ("x_src"     , x_src);
   /*---(translate)----------------------*/
   rc = yconv_2base (x_src, YSTR_NUMBER, &x_final);
   DEBUG_YCONV   yLOG_value   ("yconv_2base" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check range)--------------------*/
   DEBUG_YCONV   yLOG_ullong  ("x_final"   , x_final);
   --rce;  if (r_double != NULL  && x_final > MAX_DOUBLE) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check range)--------------------*/
   DEBUG_YCONV   yLOG_value   ("x_sign"    , x_sign);
   --rce;  if (x_sign   == -1 && r_ullong != NULL) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_ullong != NULL)  *r_ullong = x_final;
   if (r_double != NULL)  *r_double = ((double) x_final) * x_sign;
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return rc;
}

char         /*-> interpret hexadecimal numbers -----------[ petal  [ 2f---- ]*/
yconv_2hex                (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;               /* return code for errors    */
   char        rc          =    0;
   char        x_beg       =   -1;               /* first translatable char   */
   ullong      x_final     =    0;               /* final value               */
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__2defense (a_src, r_ullong, r_double,  2 , TYPE_HEX, 'õ', NULL, &x_beg);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(translate)----------------------*/
   rc = yconv_2base (a_src + x_beg, YSTR_HEX   , &x_final);
   DEBUG_YCONV   yLOG_value   ("yconv_2base" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check range)--------------------*/
   DEBUG_YCONV   yLOG_ullong  ("x_final"   , x_final);
   --rce;  if (r_double != NULL  && x_final > MAX_DOUBLE) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_ullong != NULL)  *r_ullong = x_final;
   if (r_double != NULL)  *r_double = (double) x_final;
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return rc;
}

/*> #define     YSTR_MONGO    "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#"   <* 
 *> #define     YSTR_BASE64   "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"   <*/
/*
 *  999,999,999,999,999     DjX6kxn//    3ZN'wan'd¬¬
 *                          P//////////  0F¬'¬¬¬'¬¬¬'¬¬¬   
 *
 */

char
yconv_2mongo              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_beg       =   -1;               /* first translatable char   */
   ullong      x_final     =    0;               /* final value               */
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__2defense (a_src, r_ullong, r_double,  2 , TYPE_MONGO, 'í', NULL, &x_beg);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(translate)----------------------*/
   rc = yconv_2base (a_src + x_beg, YSTR_MONGO , &x_final);
   DEBUG_YCONV   yLOG_value   ("yconv_2base" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check range)--------------------*/
   DEBUG_YCONV   yLOG_ullong  ("x_final"   , x_final);
   --rce;  if (r_double != NULL  && x_final > MAX_DOUBLE) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_ullong != NULL)  *r_ullong = x_final;
   if (r_double != NULL)  *r_double = (double) x_final;
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return rc;
}



/*====================------------------------------------====================*/
/*===----              convert specialt formats to number              ----===*/
/*====================------------------------------------====================*/
static void      o___2SPECIAL________________o (void) {;}

char
yconv_2roman              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_src       [LEN_TITLE] = "";
   char        l           =    0;
   char       *p           = NULL;
   int         i           =    0;
   ullong      x_ullong    =    0;
   char        c           =    0;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__2defense (a_src, r_ullong, r_double,  1 ,  0 ,  0 , &l, NULL);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_value   ("l"         , l);
   /*---(quick-out)----------------------*/
   if (strcmp (a_src, "N") == 0 || strcmp (a_src, "n") == 0) {
      DEBUG_YCONV   yLOG_note    ("found N/n (zero)");
      DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
      return 1;
   }
   /*---(prepare)------------------------*/
   ystrlcpy   (x_src, a_src, LEN_TITLE);
   ystrlupper (x_src, LEN_TITLE);
   DEBUG_YCONV   yLOG_info    ("x_src"     , x_src);
   p = x_src;
   DEBUG_YCONV   yLOG_info    ("current"   , p);
   for (i = 0; i < LEN_DESC; ++i) {
      if (S_roman [i].r_wide == 0)   break;
      if (strncmp (p, S_roman [i].r_chars, S_roman [i].r_wide) == 0) {
         DEBUG_YCONV   yLOG_info    ("found"     , S_roman [i].r_chars);
         x_ullong += S_roman [i].r_value;
         p        += S_roman [i].r_wide;
         DEBUG_YCONV   yLOG_info    ("current"   , p);
         c += S_roman [i].r_wide;
      }
   }
   /*---(troubles)-----------------------*/
   DEBUG_YCONV   yLOG_point   ("end"       , x_src + l);
   --rce;  if (p < x_src + l) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_ullong  ("x_ullong"  , x_ullong);
   --rce;  if (x_ullong < 0 || x_ullong >= 4000) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_ullong != NULL)  *r_ullong = x_ullong;
   if (r_double != NULL)  *r_double = (double) x_ullong;
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return c;
}



/*====================------------------------------------====================*/
/*===----               convert normal formats to number               ----===*/
/*====================------------------------------------====================*/
static void      o___2REALS__________________o (void) {;}

char
yconv__2divide            (char a_src [LEN_TITLE], char r_int [LEN_TITLE], char r_dec [LEN_TITLE], char r_exp [LEN_TITLE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;               /* return code for errors    */
   char        rc          =    0;
   char        x_src       [LEN_TITLE] = "";
   int         l           =    0;
   char        n           =    0;
   char        c           =    0;
   char        x_dec       =  '-';
   char        x_exp       =  '-';
   char       *p           = NULL;
   char        x_sign      =  ' ';
   int         i           =    0;
   /*---(default)------------------------*/
   if (r_int   != NULL)  strcpy (r_int, "");
   if (r_dec   != NULL)  strcpy (r_dec, "");
   if (r_exp   != NULL)  strcpy (r_exp, "");
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_senter  (__FUNCTION__);
   /*---(prepare)------------------------*/
   ystrlcpy (x_src, a_src, LEN_TITLE);
   DEBUG_YCONV   yLOG_snote   (x_src);
   l = strlen (x_src);
   DEBUG_YCONV   yLOG_sint    (l);
   /*---(count decimal points)-----------*/
   c  = ystrlddcnt (x_src, '.', LEN_TITLE);
   c += ystrlddcnt (x_src, '', LEN_TITLE);
   DEBUG_YCONV   yLOG_sint    (c);
   --rce;  if (c > 1) {
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   if (c == 1)  x_dec = 'y';
   /*---(count exponent markers)---------*/
   c = n  = ystrlddcnt (x_src, 'Ë', LEN_TITLE);
   DEBUG_YCONV   yLOG_sint    (n);
   if (n == 1 && x_exp == '-')  x_exp = 'Ë';
   else {
      c += n = ystrlddcnt (x_src, 'e', LEN_TITLE);
      DEBUG_YCONV   yLOG_sint    (n);
      if (n == 1 && x_exp == '-')  x_exp = 'e';
      else {
         c += n = ystrlddcnt (x_src, 'E', LEN_TITLE);
         DEBUG_YCONV   yLOG_sint    (n);
         if (n == 1 && x_exp == '-')  x_exp = 'E';
      }
   }
   --rce;  if (c > 1) {
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(trailing sign)------------------*/
   DEBUG_YCONV   yLOG_schar   (x_src [l - 2]);
   DEBUG_YCONV   yLOG_schar   (x_src [l - 1]);
   --rce;  if (l >= 3 && x_src [l - 2] == ' ') {
      switch (x_src [l - 1]) {
      case '-' : x_sign = '-';        break;
      case '+' : x_sign = '+';        break;
      default  :
                 DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
                 return rce;
                 break;
      }
      l -= 2;
      x_src [l] = '\0';
   }
   /*---(trailing extra)-----------------*/
   if (x_src [l - 1] == ')') {
      x_src [--l] = '\0';
   }
   /*---(count delimiters)---------------*/
   c  = ystrlddcnt (x_src, ',' , LEN_TITLE);
   c += ystrlddcnt (x_src, '\'', LEN_TITLE);
   /*---(break off exponent)-------------*/
   DEBUG_YCONV   yLOG_schar   (x_exp);
   --rce;  if (x_exp != '-') {
      p = strchr (x_src, x_exp);
      DEBUG_YCONV   yLOG_spoint  (p);
      if (p == NULL) {
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      p [0] = '\0';
      ++p;
      DEBUG_YCONV   yLOG_snote   (p);
      if (strlen (p) == 0 || (strlen (p) == 1 && strchr ("+-", p [0]) != NULL)) {
         DEBUG_YCONV   yLOG_snote   ("no exp num");
         if (r_int  != NULL)  strcpy (r_int, "");
         if (r_dec  != NULL)  strcpy (r_dec, "");
         if (r_exp  != NULL)  strcpy (r_exp, "");
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      if (r_exp  != NULL)  ystrlcpy (r_exp, p    , LEN_TITLE);
   }
   /*---(break out decimal)--------------*/
   l = 0;
   p = strchr (x_src, '.');
   if (p == NULL)  p = strchr (x_src, '');
   DEBUG_YCONV   yLOG_spoint  (p);
   if (p != NULL) {
      p [0] = '\0';
      ++p;
      DEBUG_YCONV   yLOG_snote   (p);
      if (strlen (p) == 0) {
         DEBUG_YCONV   yLOG_snote   ("no dec num");
         if (r_int  != NULL)  strcpy (r_int, "");
         if (r_dec  != NULL)  strcpy (r_dec, "");
         if (r_exp  != NULL)  strcpy (r_exp, "");
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      l += strlen (p);
      for (i = l - 1; i > 0; --i) {
         if (p [i] != '0') break;
         p [i] = '\0';
      }
      if (r_dec  != NULL)  ystrlcpy (r_dec, p    , LEN_TITLE);
   }
   /*---(save integer)-------------------*/
   if (r_int  != NULL)  {
      DEBUG_YCONV   yLOG_snote   (x_src);
      if (x_src [0] == '(')  x_src [0] = '-';
      if (x_sign == '-')  snprintf (r_int, LEN_TITLE, "%c%s", x_sign, x_src);
      else                ystrlcpy (r_int, x_src, LEN_TITLE);
      if (strlen (x_src) == 0 || (strlen (x_src) == 1 && strchr ("+-", x_src [0]) != NULL)) {
         DEBUG_YCONV   yLOG_snote   ("no int num");
         if (r_int  != NULL)  strcpy (r_int, "");
         if (r_dec  != NULL)  strcpy (r_dec, "");
         if (r_exp  != NULL)  strcpy (r_exp, "");
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      l += strlen (x_src);
      if (strchr ("+-", x_src [0]) != NULL)  --l;
   }
   /*---(total significant)--------------*/
   l -= c;
   DEBUG_YCONV   yLOG_sint    (l);
   --rce;  if (l > 15) {
      DEBUG_YCONV   yLOG_snote   ("TOO MANY SIGS");
      if (r_int  != NULL)  strcpy (r_int, "");
      if (r_dec  != NULL)  strcpy (r_dec, "");
      if (r_exp  != NULL)  strcpy (r_exp, "");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
yconv__2part              (char a_part, char a_src [LEN_TITLE], llong *r_llong)
{  /*---(design notes)-------------------*/
   /*
    *  i = integer part
    *  d = decimal part
    *  e = exponent part
    *
    */
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_len       =    0;
   char        x_beg       =    0;
   char        x_sign      =    1;
   char        x_src       [LEN_TITLE] = "";
   int         i           =    0;
   char        x_ch        =  '-';
   char        n           =    0;
   char       *p           = NULL;
   ullong      x_ullong    =    0;
   llong       x_llong     =    0;
   char        c           =    0;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_llong  != NULL)  *r_llong  = 0.0;
   /*---(defense)------------------------*/
   rc = yconv__2defense (a_src, r_llong , NULL    ,  1 ,  0 ,  0 , &x_len, NULL);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(strip signs)--------------------*/
   DEBUG_YCONV   yLOG_char    ("a_part"    , a_part);
   /*> if      (a_src [x_beg] == '$' && a_part == 'i')   { ++x_beg;   }               <* 
    *> else if (a_src [x_beg] == '(' && a_part == 'i')   { ++x_beg; x_sign = -1; }    <*/
   if      (a_src [x_beg] == '+' && a_part != 'd')   { ++x_beg;   }
   else if (a_src [x_beg] == '-' && a_part != 'd')   { ++x_beg; x_sign = -1; }
   DEBUG_YCONV   yLOG_value   ("x_sign"    , x_sign);
   /*---(check for no payload)-----------*/
   DEBUG_YCONV   yLOG_value   ("x_beg"     , x_beg);
   --rce;  if (x_beg == x_len) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(leading zero)-------------------*/
   DEBUG_YCONV   yLOG_char    ("beg"       , a_src [x_beg]);
   --rce;  if (a_part == 'i' && x_beg + 1 < x_len && a_src [x_beg] == '0') {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(decimal trailing zeros)---------*/
   ystrlcpy (x_src, a_src + x_beg, LEN_TITLE);
   x_len = strlen (x_src);
   if (a_part == 'd') {
      for (i = x_len - 1; i > 0; --i) {
         if (x_src [i] != '0') break;
         x_src [i] = '\0';
      }
   }
   /*---(translate)----------------------*/
   rc = yconv_2base (x_src, YSTR_NUMBER, &x_ullong);
   DEBUG_YCONV   yLOG_value   ("yconv_2base" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(significant digits)-------------*/
   c = rc;
   DEBUG_YCONV   yLOG_value   ("c"         , c);
   --rce;  if (c > 15) {
      DEBUG_YCONV   yLOG_note    ("TOO MANY SIGS");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(integer range)------------------*/
   DEBUG_YCONV   yLOG_ullong  ("x_ullong"  , x_ullong);
   --rce;  if (x_ullong > MAX_DOUBLE) {
      DEBUG_YCONV   yLOG_note    ("DOUBLE OVERFLOW");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_llong  = (llong) x_ullong;
   x_llong *= x_sign;
   DEBUG_YCONV   yLOG_llong   ("x_llong"   , x_llong);
   /*---(exponent range)-----------------*/
   --rce;  if (a_part == 'e' && x_llong > 99) {
      DEBUG_YCONV   yLOG_note    ("EXP TOO BIG");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_llong  != NULL)  *r_llong  = x_llong;
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return c;
}

char
yconv_2float              (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;               /* return code for errors    */
   char        rc          =    0;
   char        x_src       [LEN_TITLE] = "";
   char        x_int       [LEN_TITLE] = "";
   llong       x_vint      =    0;
   char        x_dec       [LEN_TITLE] = "";
   llong       x_vdec      =    0;
   char        x_exp       [LEN_TITLE] = "";
   llong       x_vexp      =    0;
   char        x_sigs      =    0;
   double      x_decs      =  0.0;
   double      x_double    =  0.0;
   char        x_sign      =   +1;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_double != NULL)  *r_double = 0.0;
   /*---(defense)------------------------*/
   rc = yconv__2defense (a_src, r_ullong, r_double,  1 ,  0 ,  0 , NULL, NULL);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(get the sign)-------------------*/
   ystrlcpy (x_src, a_src, LEN_TITLE);
   rc = yconv__2sign (x_src, &x_sign);
   DEBUG_YCONV   yLOG_value   ("yconv__2sign", rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_info    ("x_src"     , x_src);
   /*---(parttion)-----------------------*/
   rc = yconv__2divide (x_src, x_int, x_dec, x_exp);
   DEBUG_YCONV   yLOG_value   ("divide"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(nothing case)-------------------*/
   --rce;  if (strcmp (x_int, "") == 0 && strcmp (x_dec, "") == 0) {
      DEBUG_YCONV   yLOG_note    ("both integer and decimal parts empty");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(integer part)-------------------*/
   DEBUG_YCONV   yLOG_info    ("x_int"     , x_int);
   --rce;  if (strcmp (x_int, "") != 0) {
      rc = yconv__2part     ('i', x_int, &x_vint);
      DEBUG_YCONV   yLOG_value   ("int"       , rc);
      if (rc < 0) {
         DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      DEBUG_YCONV   yLOG_llong   ("x_vint"    , x_vint);
      x_sigs  += rc;
      DEBUG_YCONV   yLOG_value   ("x_sigs"    , x_sigs);
      x_double += (double) x_vint;
      DEBUG_YCONV   yLOG_double  ("x_double"  , x_double);
   }
   /*---(decimal part)-------------------*/
   DEBUG_YCONV   yLOG_info    ("x_dec"     , x_dec);
   --rce;  if (strcmp (x_dec, "") != 0) {
      rc = yconv__2part     ('d', x_dec, &x_vdec);
      DEBUG_YCONV   yLOG_value   ("dec"       , rc);
      if (rc < 0) {
         DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      DEBUG_YCONV   yLOG_llong   ("x_vdec"    , x_vdec);
      x_sigs  += rc;
      DEBUG_YCONV   yLOG_value   ("x_sigs"    , x_sigs);
      x_decs   = ((double) x_vdec) * pow (10, -rc);
      DEBUG_YCONV   yLOG_double  ("x_decs"    , x_decs);
      x_double += x_decs;
      DEBUG_YCONV   yLOG_double  ("x_double"  , x_double);
   }
   /*---(check on sigs)------------------*/
   --rce;  if (x_sigs > 15) {
      DEBUG_YCONV   yLOG_note    ("TOO MANY TOTAL SIGS");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(exponent part)------------------*/
   DEBUG_YCONV   yLOG_info    ("x_exp"     , x_exp);
   --rce;  if (strcmp (x_exp, "") != 0) {
      rc = yconv__2part     ('e', x_exp, &x_vexp);
      DEBUG_YCONV   yLOG_value   ("exp"       , rc);
      if (rc < 0) {
         DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      DEBUG_YCONV   yLOG_llong   ("x_vexp"    , x_vexp);
      x_double *= pow (10, x_vexp);
      DEBUG_YCONV   yLOG_double  ("x_double"  , x_double);
   }
   /*---(save-back llong)----------------*/
   DEBUG_YCONV   yLOG_point   ("r_double"  , r_double);
   --rce;  if (r_ullong != NULL) {
      DEBUG_YCONV   yLOG_note    ("handle as ullong");
      if (x_sign == -1) {
         DEBUG_YCONV   yLOG_note    ("ULLONG CAN NOT BE NEG");
         DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
         return rce;
      }
      *r_ullong = x_vint;
   }
   /*---(save-back double)---------------*/
   if (r_double != NULL) {
      DEBUG_YCONV   yLOG_note    ("handle as double");
      DEBUG_YCONV   yLOG_value   ("x_sign"    , x_sign);
      *r_double = x_double * x_sign;
   }
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return x_sigs;
}

char yconv_2comma (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double) { return yconv_2float (a_src, r_ullong, r_double); }
char yconv_2real  (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double) { return yconv_2float (a_src, r_ullong, r_double); }
char yconv_2sci   (char a_src [LEN_TITLE], ullong *r_ullong, double *r_double) { return yconv_2float (a_src, r_ullong, r_double); }



/*====================------------------------------------====================*/
/*===----                    number to string driver                   ----===*/
/*====================------------------------------------====================*/
static void      o___2DRIVER_________________o (void) {;}

char
yconv__2type            (char a_src [LEN_HUND], char *r_range)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        l           =    0;
   char        x_1st       =  '-';
   char        x_2nd       =  '-';
   char        x_end       =  '-';
   int         i           =    0;
   char       *p           = NULL;
   char        x_type      =  '-';
   char       *x_norms     = "+-($";
   char       *x_bases     = "boxz";
   char       *x_greek     = "éöõí";
   char        n           =    0;
   char        c           =    0;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_range  != NULL)   *r_range = '-';
   /*---(defense)------------------------*/
   DEBUG_YCONV   yLOG_point   ("a_src"     , a_src);
   --rce;  if (a_src == NULL || a_src [0] == '\0') {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return TYPE_FAIL;
   }
   DEBUG_YCONV   yLOG_info    ("a_src"     , a_src);
   /*---(prepare)------------------------*/
   l = strlen (a_src);
   DEBUG_YCONV   yLOG_value   ("l"         , l);
   x_1st = a_src [0];
   DEBUG_YCONV   yLOG_char    ("x_1st"     , x_1st);
   /*---(handle single)------------------*/
   --rce;  if (l == 1) {
      if (strchr (YSTR_NUMBER, x_1st) != NULL) {
         DEBUG_YCONV   yLOG_note    ("single digit number");
         if (r_range != NULL)  *r_range = 'd';
         DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
         return TYPE_INT;
      }
      if (strchr (YSTR_ROMAN, tolower (x_1st)) != NULL) {
         DEBUG_YCONV   yLOG_note    ("single roman digit");
         if (r_range != NULL)  *r_range = 'r';
         DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
         return TYPE_ROMAN;
      }
      DEBUG_YCONV   yLOG_note    ("single non-number");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return TYPE_FAIL;
   }
   /*---(real numbers)-------------------*/
   c  = ystrldcnt (a_src, '.', LEN_HUND);
   c += ystrldcnt (a_src, '', LEN_HUND);
   c += ystrldcnt (a_src, 'Ë', LEN_HUND);
   DEBUG_YCONV   yLOG_value   ("c"         , c);
   if (c > 0) {
      DEBUG_YCONV   yLOG_note    ("real number decimal or exponent");
      if (r_range != NULL)  *r_range = 'd';
      DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
      return TYPE_FLOAT;
   }
   /*---(normal numbers)-----------------*/
   DEBUG_YCONV   yLOG_info    ("x_norms"   , x_norms);
   p = strchr (x_norms, x_1st);
   DEBUG_YCONV   yLOG_point   ("p"         , p);
   if (p != NULL) {
      DEBUG_YCONV   yLOG_note    ("integer prefixes");
      if (r_range != NULL)  *r_range = 'd';
      DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
      return TYPE_INT;
   }
   /*---(technical numbers)--------------*/
   x_end = a_src [l - 1];
   DEBUG_YCONV   yLOG_char    ("x_end"     , x_end);
   p = strchr ("+-", x_end);
   DEBUG_YCONV   yLOG_point   ("p"         , p);
   if (p != NULL) {
      DEBUG_YCONV   yLOG_note    ("integer suffixes");
      if (r_range != NULL)  *r_range = 'd';
      DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
      return TYPE_INT;
   }
   /*---(normal prefixes)----------------*/
   DEBUG_YCONV   yLOG_info    ("x_bases"   , x_bases);
   p = strchr (x_bases, tolower (x_1st));
   DEBUG_YCONV   yLOG_point   ("p"         , p);
   if (p != NULL) {
      DEBUG_YCONV   yLOG_note    ("single letter prefix");
      DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
      if (r_range != NULL)  *r_range = 'u';
      return tolower (x_1st);
   }
   /*---(normal greek)-------------------*/
   DEBUG_YCONV   yLOG_info    ("x_greek"   , x_greek);
   p = strchr (x_greek, x_1st);
   DEBUG_YCONV   yLOG_point   ("p"         , p);
   if (p != NULL) {
      DEBUG_YCONV   yLOG_note    ("greek letter prefix");
      n = (char) (p - x_greek);
      DEBUG_YCONV   yLOG_value   ("n"         , n);
      if (r_range != NULL)  *r_range = 'u';
      DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
      return x_bases [n];
   }
   /*---(zero-led prefixes)--------------*/
   x_2nd = a_src [1];
   DEBUG_YCONV   yLOG_char    ("x_2nd"     , x_2nd);
   if (x_1st == '0') {
      if (strchr (TYPE_BASES, tolower (x_2nd)) != NULL) {
         DEBUG_YCONV   yLOG_note    ("zero-led prefix");
         if (r_range != NULL)  *r_range = 'u';
         DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
         return tolower (x_2nd);
      } else if (strchr (YSTR_NUMBER, x_2nd) != NULL) {
         DEBUG_YCONV   yLOG_note    ("zero led octal");
         if (r_range != NULL)  *r_range = 'u';
         DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
         return TYPE_OCT;
      } else if (x_2nd == '.') {
         DEBUG_YCONV   yLOG_note    ("zero plus decimal real");
         if (r_range != NULL)  *r_range = 'd';
         DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
         return TYPE_FLOAT;
      }
   }
   /*---(check integer first)------------*/
   --rce;  if (x_type == '-') {
      for (i = 0; i < l; ++i) {
         /*---(filter everywhere sperators)-*/
         if (strchr ("':á"  , a_src [i]) != NULL)  continue;
         /*---(check commas)----------------*/
         if (strchr (YSTR_NUMPLUS, a_src [i]) != NULL)  { x_type = TYPE_INT; continue; }
         x_type = '-';
         break;
      }
   }
   /*---(then roman)---------------------*/
   --rce;  if (x_type == '-') {
      for (i = 0; i < l; ++i) {
         if (strchr (YSTR_ROMAN, a_src [i]) != NULL)  { x_type = TYPE_ROMAN; continue; }
         x_type = '-';
         break;
      }
   }
   /*---(complicated)--------------------*/
   --rce;  if (x_type == '-') {
      for (i = 0; i < l; ++i) {
         /*---(filter everywhere sperators)-*/
         if (strchr ("':á"  , a_src [i]) != NULL)  continue;
         /*---(check commas)----------------*/
         if (strchr ("oxz"  , x_type) == NULL && strchr (YSTR_BINARY, a_src [i]) != NULL)  { x_type = TYPE_BIN;   continue; }
         if (strchr ("xz"   , x_type) == NULL && strchr (YSTR_OCTAL , a_src [i]) != NULL)  { x_type = TYPE_OCT;   continue; }
         if (strchr ("z"    , x_type) == NULL && strchr (YSTR_HEXUP , a_src [i]) != NULL)  { x_type = TYPE_HEX;   continue; }
         if (strchr (YSTR_MONGO , a_src [i]) != NULL)  { x_type = TYPE_MONGO; continue; }
         /*---(trouble)---------------------*/
         DEBUG_YCONV   yLOG_note    ("found entirely illegal character");
         yLOG_exitr   (__FUNCTION__, rce);
         return TYPE_FAIL;
         /*---(done)------------------------*/
      }
   }
   /*---(save-back)----------------------*/
   if (r_range != NULL) {
      if      (strchr (x_bases, x_type) != NULL)  *r_range = 'u';
      else if (strchr (x_greek, x_type) != NULL)  *r_range = 'u';
      else if (x_type == TYPE_ROMAN)              *r_range = 'r';
      else                                        *r_range = 'd';
   }
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return x_type;
}

char
yconv_2main               (char a_src [LEN_HUND] , char *r_type, ullong *r_ullong, double *r_double)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =   -1;
   char        x_type      =  '-';
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_type    != NULL)  *r_type   = '-';
   if (r_ullong  != NULL)  *r_ullong =   0;
   if (r_double  != NULL)  *r_double = 0.0;
   /*---(defense)------------------------*/
   rc = yconv__2type (a_src, NULL);
   DEBUG_YCONV   yLOG_value   ("yconv__2type", rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-type)----------------------*/
   x_type = rc;
   DEBUG_YCONV   yLOG_char    ("x_type"    , x_type);
   --rce;  if (r_type    != NULL)  *r_type   = x_type;
   /*---(handle)-------------------------*/
   switch (x_type) {
   case TYPE_BIN   :
      DEBUG_YCONV   yLOG_note    ("binary");
      rc = yconv_2bin    (a_src, r_ullong, r_double);
      break;
   case TYPE_OCT   :
      DEBUG_YCONV   yLOG_note    ("octal");
      rc = yconv_2oct    (a_src, r_ullong, r_double);
      break;
   case TYPE_INT   :
      DEBUG_YCONV   yLOG_note    ("integer");
      rc = yconv_2int    (a_src, r_ullong,  r_double);
      break;
   case TYPE_HEX   :
      DEBUG_YCONV   yLOG_note    ("hexadecimal");
      rc = yconv_2hex    (a_src, r_ullong,  r_double);
      break;
   case TYPE_MONGO :
      DEBUG_YCONV   yLOG_note    ("mongo");
      rc = yconv_2mongo  (a_src, r_ullong, r_double);
      break;
   case TYPE_ROMAN :
      DEBUG_YCONV   yLOG_note    ("roman");
      rc = yconv_2roman  (a_src, r_ullong, r_double);
      break;
   case TYPE_FLOAT :
      DEBUG_YCONV   yLOG_note    ("comma");
      rc = yconv_2float  (a_src, r_ullong, r_double);
      break;
   default         :
      DEBUG_YCONV   yLOG_note    ("UNKNOWN");
      return rce;
      break;
   }
   /*---(check trouble)------------------*/
   DEBUG_YCONV   yLOG_value   ("return"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_double != NULL) {
      DEBUG_YCONV   yLOG_double  ("r_double"  , *r_double);
   }
   if (r_ullong != NULL) {
      DEBUG_YCONV   yLOG_ullong  ("r_ullong"  , *r_ullong);
   }
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return rc;
}

char yconv_2num   (char a_src [LEN_HUND] , double *r_double) { return yconv_2main (a_src, NULL, NULL, r_double); }




