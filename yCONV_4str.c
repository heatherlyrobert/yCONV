/*============================[[    beg-code    ]]============================*/
/*∑∑∑∑∑∑∑∑¥ ¥∑∑∑∑∑∑∑∑∑∑∑∑∑headers∑¥ ¥∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑*/
#include    "yCONV.h"
#include    "yCONV_priv.h"
/*∑∑∑∑∑∑∑∑¥ ¥∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑¥ ¥∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑∑*/



/*===[[ BEG GNU GENERAL PUBLIC LICENSE (GPL) WARNING ]]=======================*/
/*¥¥∑∑∑∑∑∑∑∑∑1∑∑∑∑∑∑∑∑∑2∑∑∑∑∑∑∑∑∑3∑∑∑∑∑∑∑∑∑4∑∑∑∑∑∑∑∑∑5∑∑∑∑∑∑∑∑∑6∑∑∑∑∑∑∑∑∑7∑∑∑∑∑∑∑∑∑8  */

#define  P_COPYRIGHT   \
   "copyright (c) 2026 robert.s.heatherly at balsashrike at gmail dot com"

#define  P_LICENSE     \
   "the only place you could have gotten this code is my github, my website,¶"   \
   "or illegal sharing. given that, you should be aware that this is GPL licensed."

#define  P_COPYLEFT    \
   "the GPL COPYLEFT REQUIREMENT means any modifications or derivative works¶"   \
   "must be released under the same GPL license, i.e, must be free and open."

#define  P_INCLUDE     \
   "the GPL DOCUMENTATION REQUIREMENT means that you must include the original¶" \
   "copyright notice and the full licence text with any resulting anything."

#define  P_AS_IS       \
   "the GPL NO WARRANTY CLAUSE means the software is provided without any¶"      \
   "warranty and the author cannot be held liable for damages."

#define  P_THEFT    \
   "if you knowingly violate the spirit of these ideas, i suspect you might¶"    \
   "find any number of freedom-minded hackers may take it quite personally ;)"

/*¥¥∑∑∑∑∑∑∑∑∑1∑∑∑∑∑∑∑∑∑2∑∑∑∑∑∑∑∑∑3∑∑∑∑∑∑∑∑∑4∑∑∑∑∑∑∑∑∑5∑∑∑∑∑∑∑∑∑6∑∑∑∑∑∑∑∑∑7∑∑∑∑∑∑∑∑∑8  */
/*===[[ END GNU GENERAL PUBLIC LICENSE (GPL) WARNING ]]=======================*/



/*====================------------------------------------====================*/
/*===----                 support for number to string                 ----===*/
/*====================------------------------------------====================*/
static void      o___4SUPPORT________________o (void) {;}

char
yconv__4defense           (char a_type, char a_greek, ullong a_ullong, double a_double, char a_fmt, char a_max, char *r_source, char r_prefix [LEN_SHORT], char r_out [LEN_TITLE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        x_source    =  'd';
   int         x_len       =    0;
   char        x_1st       =  '-';
   char        x_2nd       =  '-';
   char        x_min       =   -1;               /* first translatable char   */
   char        x_beg       =  '-';
   double      x_max       =  0.0;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_senter  (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_source != NULL)   *r_source = 'd';
   if (r_prefix != NULL)   strcpy (r_prefix, "");
   if (r_out    != NULL)   strcpy (r_out   , "");
   /*---(defense)------------------------*/
   DEBUG_YCONV   yLOG_spoint  (r_out);
   --rce; if (r_out  == NULL) {
      DEBUG_YCONV   yLOG_snote   ("no out field");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check max length)---------------*/
   DEBUG_YCONV   yLOG_sint    (a_max);
   --rce; if (a_type == TYPE_BIN) {
      if (a_max > LEN_HUND) {
         DEBUG_YCONV   yLOG_snote   ("a_max binary too large");
         ystrlcpy (r_out, "#p/too", a_max);
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   } else if (a_type == TYPE_OCT) {
      if (a_max > LEN_DESC) {
         DEBUG_YCONV   yLOG_snote   ("a_max octal too large");
         ystrlcpy (r_out, "#p/too", a_max);
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   } else if (a_max > LEN_TITLE) {
      DEBUG_YCONV   yLOG_snote   ("a_max too large");
      ystrlcpy (r_out, "#p/too", a_max);
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check input type)---------------*/
   DEBUG_YCONV   yLOG_sint    (a_ullong);
   DEBUG_YCONV   yLOG_sdouble (a_double);
   --rce; if (a_ullong != 0 && a_double != 0) {
      DEBUG_YCONV   yLOG_snote   ("a_ullong and a_double can not both be used");
      ystrlcpy (r_out, "#p/inp", a_max);
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   if (a_ullong != 0)  x_source = 'l';
   DEBUG_YCONV   yLOG_schar   (x_source);
   /*---(check type)---------------------*/
   DEBUG_YCONV   yLOG_schar   (a_type);
   --rce; if (a_type == NULL || a_type == '∑' || strchr ("boixz∑rt∑fe", a_type) == NULL) {
      DEBUG_YCONV   yLOG_snote   ("illegal type");
      ystrlcpy (r_out, "#p/typ", a_max);
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(check double ranges)------------*/
   --rce; if (x_source == 'd') {
      /*---(minimum)---------------------*/
      if (strchr ("boixz∑rt", a_type) != NULL && a_double < 0) {
         DEBUG_YCONV   yLOG_snote   ("a_double can not be negative");
         ystrlcpy (r_out, "#p/neg", a_max);
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      /*---(range)-----------------------*/
      if (a_type != 'e' && (a_double > MAX_DOUBLE || a_double < -MAX_DOUBLE)) {
         DEBUG_YCONV   yLOG_snote   ("general overflow");
         ystrlcpy (r_out, "#p/ovr", a_max);
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
      /*---(roman)-----------------------*/
      if (a_type == TYPE_ROMAN && a_double > MAX_ROMAN) {
         DEBUG_YCONV   yLOG_snote   ("roman overflow");
         ystrlcpy (r_out, "#p/ovr", a_max);
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(check ullong ranges)------------*/
   else {
      if (a_type == TYPE_ROMAN && a_ullong > MAX_ROMAN) {
         DEBUG_YCONV   yLOG_snote   ("roman overflow");
         ystrlcpy (r_out, "#p/ovr", a_max);
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(check format)-------------------*/
   DEBUG_YCONV   yLOG_schar   (a_fmt);
   --rce;  if (a_fmt == NULL || a_fmt == '∑' || a_fmt == ' ') {
      DEBUG_YCONV   yLOG_snote   ("illegal format");
      ystrlcpy (r_out, "#p/fmt", a_max);
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (a_type == 'r') {
      DEBUG_YCONV   yLOG_snote   ("roman");
      if (a_fmt  == NULL || strchr ("rR"       , a_fmt ) == NULL) {
         DEBUG_YCONV   yLOG_snote   ("illegal format");
         ystrlcpy (r_out, "#p/fmt", a_max);
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   --rce;  if (a_type == 't') {
      DEBUG_YCONV   yLOG_snote   ("time");
      if (a_fmt  == NULL || strchr ("tT∑dD"    , a_fmt ) == NULL) {
         DEBUG_YCONV   yLOG_snote   ("illegal format");
         ystrlcpy (r_out, "#p/fmt", a_max);
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   --rce;  if (strchr ("boixz", a_type) != NULL) {
      DEBUG_YCONV   yLOG_snote   ("bases");
      if (a_fmt  == NULL || strchr ("-dsfcg:t#", a_fmt ) == NULL) {
         DEBUG_YCONV   yLOG_snote   ("illegal format");
         ystrlcpy (r_out, "#p/fmt", a_max);
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   --rce;  if (strchr ("fe"   , a_type) != NULL) {
      DEBUG_YCONV   yLOG_snote   ("reals");
      if (strchr ("?∑if∑IF,∑aA$∑sS∑cC#∑pP∑eE"   , a_type) == NULL) {
         DEBUG_YCONV   yLOG_snote   ("illegal format");
         ystrlcpy (r_out, "#p/fmt", a_max);
         DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
         return rce;
      }
   }
   /*---(assign prefix)------------------*/
   if (r_prefix != NULL && strchr ("boxz", a_type) != NULL) {
      switch (a_fmt) {
      case '-' : case 'd' :                            break;
      case 's' :  sprintf (r_prefix, "0%c", a_type);   break;
      case 'f' :  sprintf (r_prefix, "%c" , a_greek);  break;
      case 'c' :  sprintf (r_prefix, "%c'", a_type);   break;
      case 'g' :  sprintf (r_prefix, "%c'", a_greek);  break;
      case ':' :  sprintf (r_prefix, "%c:", a_greek);  break;
      case 't' :  sprintf (r_prefix, "%c·", a_greek);  break;
      case '#' :  sprintf (r_prefix, "%c·", a_greek);  break;
      }
   }
   /*---(save-back)----------------------*/
   if (r_source != NULL)   *r_source = x_source;
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char
yconv__space_ints        (char a_every, char a_char, char b_out [LEN_HUND])
{
   char        rce         =  -10;
   int         l           =    0;
   uchar       x_ch        =  '-';
   char        x_pos       =  '-';
   int         i           =    0;               /* iterator -- character     */
   char        c           =    0;
   char        x_mark      [LEN_SHORT] = "";
   /*---(prepare)------------------------*/
   --rce;  if (b_out    == NULL)  return rce;
   l = strlen (b_out);
   --rce;  if (l     <= 0)        return rce;
   x_ch  = a_char;
   --rce;  if (x_ch   < 32 )      return rce;
   --rce;  if (x_ch  == 127)      return rce;
   sprintf (x_mark, "%c", x_ch);
   /*---(walk)---------------------------*/
   for (i = (l - 1) / a_every; i > 0; --i) {
      /*---(open space)------------------*/
      x_pos = l - (i * a_every);
      ystrlins (x_pos, x_mark, LEN_HUND, b_out, &l);
      ++c;
      /*---(done)------------------------*/
   }
   return 0;
}

/*   bit?    Å≥≥≤≥å≤≥≥≥Å≤≥≥≤å≤≤≥≥Å≥≥≤≥å≤≥≥≥Å≥≥≤≥å≤≤≥≥Å≥≥≤≥å≤≥≥≥Å≤≥≥≤å≤≤≥≥Å≥≥≤≥å≤≥≥≥Å≥≤≥≥å≥≤≥≤Å */

char
yconv__space_decs        (char a_every, char a_char, char b_out [LEN_HUND])
{
   int         x_add       =    0;
   int         x_len       =    0;
   int         i           =    0;               /* iterator -- character     */
   /*---(defense)------------------------*/
   x_len = strlen (b_out);
   if (x_len <= a_every)    return 0;
   /*---(add padding)--------------------*/
   x_add = x_len % a_every;
   if (x_add > 0)  x_add = a_every - x_add;
   for (i = 0; i < x_add; ++i)   strcat (b_out, "0");
   yconv__space_ints     (a_every, a_char, b_out);
   x_len = strlen (b_out);
   for (i = 0; i < x_add; ++i)  b_out [--x_len] = '\0';
   return 0;
}

char
yconv_4sigs             (char a_charset [LEN_HUND], char a_dels [LEN_TERSE], char a_sigs, char a_mask, char a_max, char b_out [LEN_HUND])
{
   char        rce         =  -10;
   int         l           =    0;
   int         i           =    0;
   char        x_sigs      =    0;
   /*---(desfense)-----------------------*/
   --rce;  if (a_charset == NULL)  return rce;
   --rce;  if (a_dels    == NULL)  return rce;
   --rce;  if ((uchar) a_mask    <  32)    return rce;
   --rce;  if ((uchar) a_mask    == 127)   return rce;
   --rce;  if (b_out     == NULL)  return rce;
   /*---(range limits)-------------------*/
   if      (a_sigs <  0)  a_sigs = 100;
   /*---(prepare)------------------------*/
   l = strlen (b_out);
   /*> if (l > a_max)  l = a_max;                                                     <*/
   /*---(walk string)--------------------*/
   for (i = 0; i < l; ++i) {
      if (strchr (a_charset, b_out [i]) != NULL) {
         if (i < a_max && x_sigs >= a_sigs)  b_out [i] = a_mask;
         ++x_sigs;
      }
      if (i < a_max && x_sigs >= a_sigs && strchr (a_dels, b_out [i]) != NULL)  b_out [i] = a_mask;
   }
   /*---(complete)-----------------------*/
   return x_sigs;
}



/*====================------------------------------------====================*/
/*===----                  convert number to string                    ----===*/
/*====================------------------------------------====================*/
static void      o___4BASES__________________o (void) {;}

char
yconv_4base              (ullong a_ullong, double a_double, char a_prefix [LEN_SHORT], char a_charset [LEN_HUND], char a_spacing, char a_cnt, char a_fmt, char a_max, char r_out [LEN_HUND])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         l           =    0;
   char        x_source    =  'd';
   int         x_base      =    0;
   int         i           =    0;
   char        x_digit     =    0;
   ullong      x_place     =    0;
   ullong      x_num       =    0;
   char        c           =    0;
   char        x_revs      [LEN_HUND]  = "";
   char        x_pad       [LEN_TERSE] = "";
   char        x_suffix    [LEN_HUND]  = "";
   int         x_len       =    0;
   char        x_flip      [LEN_HUND]  = "";
   char        x_final     [LEN_HUND]  = "";
   char        n           =    0;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(default)------------------------*/
   if (r_out     != NULL)   strcpy (r_out    , "");
   /*---(defense)------------------------*/
   DEBUG_YCONV   yLOG_point   ("a_prefix"  , a_prefix);
   --rce; if (a_prefix   == NULL) {
      DEBUG_YCONV   yLOG_note    ("a_prefix null");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_info    ("a_prefix"  , a_prefix);
   DEBUG_YCONV   yLOG_point   ("a_charset" , a_charset);
   --rce; if (a_charset  == NULL || a_charset [0] == '\0') {
      DEBUG_YCONV   yLOG_note    ("a_charset null/empty");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_info    ("a_charset" , a_charset);
   DEBUG_YCONV   yLOG_point   ("r_out"     , r_out);
   --rce; if (r_out      == NULL) {
      DEBUG_YCONV   yLOG_note    ("r_out null");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check charset)------------------*/
   x_base = strlen (a_charset);
   DEBUG_YCONV   yLOG_value   ("x_base"    , x_base);
   --rce;  if (x_base < 2) {
      DEBUG_YCONV   yLOG_note    ("base too small");
      ystrlcpy (r_out, "#p/bas", a_max);
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (x_base >= LEN_HUND) {
      DEBUG_YCONV   yLOG_note    ("base too large");
      ystrlcpy (r_out, "#p/bas", a_max);
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(check inputs)-------------------*/
   DEBUG_YCONV   yLOG_ullong  ("a_ullong"  , a_ullong);
   DEBUG_YCONV   yLOG_double  ("a_double"  , a_double);
   --rce; if (a_ullong != 0 && a_double != 0) {
      DEBUG_YCONV   yLOG_note    ("a_ullong and a_double can not both be used");
      ystrlcpy (r_out, "#p/inp", a_max);
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   --rce;  if (x_source == 'd' && a_double < 0.0) {
      DEBUG_YCONV   yLOG_note    ("a_double can not be negative");
      ystrlcpy (r_out, "#p/neg", a_max);
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   if (a_ullong != 0)  x_source = 'l';
   DEBUG_YCONV   yLOG_char    ("x_source"  , x_source);
   /*---(prepare)------------------------*/
   if (x_source == 'd')  x_num = (ullong) a_double;
   else                  x_num = a_ullong;
   DEBUG_YCONV   yLOG_ullong  ("x_num"     , x_num);
   /*---(translate base)-----------------*/
   while (x_num > 0) {
      x_digit = x_num % x_base;
      x_revs [x_place++] = a_charset [x_digit];
      x_revs [x_place  ] = '\0';
      x_num /= x_base;
      ++c;
      DEBUG_YCONV   yLOG_complex ("update"    , "%2dd, %2dc, %llup, %llu", x_digit, c, x_place, x_final);
   }
   DEBUG_YCONV   yLOG_info    ("x_revs"    , x_revs);
   /*---(create pad)---------------------*/
   sprintf (x_pad, "%*.*s", a_spacing, a_spacing, "0000000000");
   DEBUG_YCONV   yLOG_info    ("x_pad"     , x_pad);
   /*---(handle zero)--------------------*/
   if (strcmp (x_revs, "") == 0) {
      if (a_fmt != ',')   strcpy   (x_revs, x_pad);
      else                strcpy   (x_revs, "0");
      DEBUG_YCONV   yLOG_info    ("x_revs"    , x_revs);
   }
   /*---(pad to spacing)-----------------*/
   x_len = strlen (x_revs);
   DEBUG_YCONV   yLOG_value   ("x_len"     , x_len);
   if (a_fmt != ',') {
      n     = x_len % a_spacing;
      DEBUG_YCONV   yLOG_value   ("n"         , n);
      if (n > 0) {
         DEBUG_YCONV   yLOG_note    ("padding small value");
         for (i = a_spacing; i > n; --i) {
            if (a_fmt != '.')  strcat (x_revs  , "0");
            else               strcat (x_suffix, "0");
         }
         x_len = strlen (x_revs);
         DEBUG_YCONV   yLOG_value   ("x_len"     , x_len);
      }
      DEBUG_YCONV   yLOG_info    ("x_revs"    , x_revs);
   }
   /*---(pad to a_cnt)-------------------*/
   if (a_fmt != ',') {
      for (i = x_len / a_spacing; i < a_cnt; ++i) {
         DEBUG_YCONV   yLOG_value   ("i"         , i);
         if (a_fmt != '.')  strcat (x_revs  , x_pad);
         else               strcat (x_suffix, x_pad);
      }
      DEBUG_YCONV   yLOG_info    ("x_revs"    , x_revs);
      x_len = strlen (x_revs);
      DEBUG_YCONV   yLOG_value   ("x_len"     , x_len);
   }
   /*---(flip)---------------------------*/
   DEBUG_YCONV   yLOG_value   ("x_len"     , x_len);
   --x_len;
   for (i = x_len; i >= 0; --i)  {
      /*> DEBUG_YCONV   yLOG_complex ("flip"      , "%c %3d>%3d %s", x_revs [i], i, x_len - i, x_flip);   <*/
      x_flip [x_len - i] = x_revs [i];
   }
   x_flip [++x_len] = '\0';
   DEBUG_YCONV   yLOG_info    ("x_flip"    , x_flip);
   if (a_fmt == '.') {
      strcat (x_flip, x_suffix);
      x_len = strlen (x_flip);
      DEBUG_YCONV   yLOG_info    ("x_flip"    , x_flip);
      DEBUG_YCONV   yLOG_value   ("x_len"     , x_len);
   }
   /*---(add separators)-----------------*/
   DEBUG_YCONV   yLOG_char    ("a_fmt"     , a_fmt);
   switch (a_fmt) {
   case 'd'  :  case 'c'  :  case 'g'  : yconv__space_ints (a_spacing, '\'', x_flip); break;
   case ':'  :                           yconv__space_ints (a_spacing, ':' , x_flip); break;
   case 't'  :  case '#'  :              yconv__space_ints (a_spacing, '·' , x_flip); break;
   case ','  :                           yconv__space_ints (a_spacing, ',' , x_flip); break;
   case '.'  :                           yconv__space_ints (a_spacing, '\'', x_flip); break;
   }
   /*---(tech version)-------------------*/
   if (a_fmt == '#') {
      if      (x_base == 2)  ystrldchg (x_flip, '0', '∑', LEN_HUND);
      else if (x_base != 10) {
         x_len = strlen (x_flip);
         for (i = 0; i < x_len; ++i) {
            if (strchr ("':·", x_flip [i]) != NULL)  continue;
            if (x_flip [i] != '0')                   break;;
            x_flip [i] = '∑';
         }
      }
   }
   /*---(add prefix)---------------------*/
   sprintf (x_final, "%s%s", a_prefix, x_flip);
   DEBUG_YCONV   yLOG_info    ("x_final"    , x_final);
   /*---(check length)-------------------*/
   x_len = strlen (x_final);
   DEBUG_YCONV   yLOG_value   ("x_len"     , x_len);
   --rce;  if (x_len >= a_max) {
      DEBUG_YCONV   yLOG_note    ("output longer than a_max");
      ystrlcpy (r_out, "#p/max", a_max);
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)----------------------*/
   if (r_out   != NULL)  ystrlcpy (r_out, x_final, a_max);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yconv_4bool              (ullong a_ullong, double a_val, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;               /* return code for errors    */
   long        x_num       =    0;
   int         x_len       =    0;
   int         i           =    0;               /* iterator -- character     */
   char        x_temp      [200] = "";
   char        x_final     [200] = "";
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_senter  (__FUNCTION__);
   /*---(defence)------------------------*/
   DEBUG_YCONV   yLOG_spoint  (r_out);
   --rce;  if (r_out == NULL) {
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   strcpy (r_out, " ");
   DEBUG_YCONV   yLOG_schar   (a_fmt);
   --rce;  if (strchr ("yY"    , a_fmt) == NULL) {
      ystrlcpy (r_out, "#p/fmt", a_max);
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_sint    (a_val);
   /*---(any binary)-----------*/
   if (a_val == 0) {
      switch (a_fmt) {
      case 'Y' :   strcpy  (r_out, "⁄");    break;
      case 'y' :   strcpy  (r_out, "∑");    break;
      }
   } else if (a_val < 0) {
      switch (a_fmt) {
      case 'Y' :   strcpy  (r_out, "€");    break;
      case 'y' :   strcpy  (r_out, "t");    break;
      }
   } else {
      switch (a_fmt) {
      case 'Y' :   strcpy  (r_out, "€");    break;
      case 'y' :   strcpy  (r_out, "T");    break;
      }
   }
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_sexit   (__FUNCTION__);
   return 0;
}

/*    0000·0011∑∑1000·1101∑∑0111·1110∑∑1010·0100∑∑1100·0110∑∑0111·1111∑∑1111·1111  */
/*    0000·0011∑∑1000·1101∑∑0111·1110∑∑1010·0100∑∑1100·0110∑∑0111·1111∑∑1111·1111  */

char         /*-> format binary numbers to string ---------[ petal  [ 2f---- ]*/
yconv_4bin           (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_HUND])
{ 
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_prefix    [LEN_SHORT] = "";
   int         l           =    0;
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__4defense  (TYPE_BIN, 'È', a_ullong, a_double, a_fmt, a_max, NULL, x_prefix, r_out);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   rc = yconv_4base (a_ullong, a_double, x_prefix, YSTR_BINARY, 4, a_cnt, a_fmt, a_max, r_out);
   DEBUG_YCONV   yLOG_value   ("yconv4base" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)------------*/
   DEBUG_YCONV   yLOG_info    ("r_out"     , r_out);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*-> format octal numbers to string ----------[ petal  [ 2f---- ]*/
yconv_4oct               (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_DESC])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;               /* return code for errors    */
   char        rc          =    0;
   char        x_prefix    [LEN_SHORT] = "";
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__4defense  (TYPE_OCT, 'ˆ', a_ullong, a_double, a_fmt, a_max, NULL, x_prefix, r_out);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(translate base)-------*/
   rc = yconv_4base (a_ullong, a_double, x_prefix, YSTR_OCTAL , 3, a_cnt, a_fmt, a_max, r_out);
   DEBUG_YCONV   yLOG_value   ("yconv4base" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)------------*/
   DEBUG_YCONV   yLOG_info    ("r_out"     , r_out);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yconv_4int               (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_DESC])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;               /* return code for errors    */
   char        rc          =    0;
   char        x_prefix    [LEN_SHORT] = "";
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__4defense  (TYPE_INT,  0 , a_ullong, a_double, a_fmt, a_max, NULL, x_prefix, r_out);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(translate base)-------*/
   rc = yconv_4base (a_ullong, a_double, x_prefix, YSTR_NUMBER, 3, a_cnt, a_fmt, a_max, r_out);
   DEBUG_YCONV   yLOG_value   ("yconv4base" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)------------*/
   DEBUG_YCONV   yLOG_info    ("r_out"     , r_out);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*-> format hexadecimal numbers to string ----[ petal  [ 2f---- ]*/
yconv_4hex           (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;               /* return code for errors    */
   char        rc          =    0;
   char        x_prefix    [LEN_SHORT] = "";
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__4defense  (TYPE_HEX, 'ı', a_ullong, a_double, a_fmt, a_max, NULL, x_prefix, r_out);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(translate base)-------*/
   rc = yconv_4base (a_ullong, a_double, x_prefix, YSTR_HEX   , 4, a_cnt, a_fmt, a_max, r_out);
   DEBUG_YCONV   yLOG_value   ("yconv4base" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)------------*/
   DEBUG_YCONV   yLOG_info    ("r_out"     , r_out);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yconv_4mongo         (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_prefix    [LEN_SHORT] = "";
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__4defense  (TYPE_MONGO, 'Ì', a_ullong, a_double, a_fmt, a_max, NULL, x_prefix, r_out);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   rc = yconv_4base (a_ullong, a_double, x_prefix, YSTR_MONGO , 4, a_cnt, a_fmt, a_max, r_out);
   DEBUG_YCONV   yLOG_value   ("yconv4base" , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save-back)------------*/
   DEBUG_YCONV   yLOG_info    ("r_out"     , r_out);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                  convert number to string                    ----===*/
/*====================------------------------------------====================*/
static void      o___4SPECIAL________________o (void) {;}

char
yconv_4roman         (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   int         x_len       =    0;
   int         x_int       =    0;
   char        x_final     [LEN_TITLE] = "";
   int         i           =    0;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__4defense  (TYPE_ROMAN,  0 , a_ullong, a_double, a_fmt, a_max, NULL, NULL, r_out);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)------------------------*/
   if (a_ullong > 0)  x_int = a_ullong;
   else               x_int = (int) a_double;
   DEBUG_YCONV   yLOG_value   ("x_int"     , x_int);
   /*---(quick out for zero)-------------*/
   if (x_int == 0) {
      DEBUG_YCONV   yLOG_note    ("handling zero");
      if (a_fmt == 'r')  ystrlcpy (r_out, "n", a_max);
      else               ystrlcpy (r_out, "N", a_max);
      DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
      return 0;
   }
   /*---(prepare)------------------------*/
   for (i = 0; i < LEN_DESC; ++i) {
      if (S_roman [i].r_wide == 0)   break;
      DEBUG_YCONV   yLOG_value   ("x_int"     , x_int);
      if (x_int - S_roman [i].r_value >= 0) {
         DEBUG_YCONV   yLOG_info    ("found"     , S_roman [i].r_chars);
         ystrlcat (x_final, S_roman [i].r_chars, LEN_TITLE);
         x_int -= S_roman [i].r_value;
      }
   }
   DEBUG_YCONV   yLOG_info    ("x_final"   , x_final);
   DEBUG_YCONV   yLOG_value   ("x_int"     , x_int);
   --rce;  if (x_int != 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(overflow)-----------------------*/
   DEBUG_YCONV   yLOG_value   ("a_max"     , a_max);
   x_len = strlen (x_final);
   DEBUG_YCONV   yLOG_value   ("x_len"     , x_len);
   --rce;  if (x_len > a_max) {
      ystrlcpy (r_out, "#p/max", a_max);
      DEBUG_YCONV   yLOG_note    ("too long");
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(handgle lower case)-------------*/
   if (a_fmt == 'r') {
      for (i = 0; i < x_len; ++i)  x_final [i] = tolower (x_final [i]);
      DEBUG_YCONV   yLOG_info    ("x_final"   , x_final);
   }
   /*---(save-back)----------------------*/
   if (r_out  != NULL)  ystrlcpy  (r_out, x_final, a_max);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                  convert number to string                    ----===*/
/*====================------------------------------------====================*/
static void      o___4REALS__________________o (void) {;}

char
yconv__4divide            (double a_source, char a_cnt, char a_uom, char a_max, char *r_sign, llong *r_int, llong *r_dec, llong *r_exp, char r_unit [LEN_SHORT], char r_out [LEN_TITLE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_sign      =    1;
   double      x_scaled    =  0.0;             /* scaled version                 */
   char        x_unit      [LEN_SHORT] = "";
   int         i           =    0;
   llong       x_pow       =    1;             /* exponent to round off          */
   double      x_round     =  0.0;             /* rounded off value              */
   llong       x_int       =    0;             /* integer part                   */
   llong       x_dec       =    0;             /* fractional part                */
   llong       x_exp       =    0;             /* exponent part                  */
   /*---(default)------------------------*/
   if (r_sign  != NULL)  *r_sign = 0;
   if (r_int   != NULL)  *r_int  = 0;
   if (r_dec   != NULL)  *r_dec  = 0;
   if (r_exp   != NULL)  *r_exp  = 0;
   if (r_unit  != NULL)  strcpy (r_unit, "");
   if (r_out   != NULL)  strcpy (r_out , "");
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(set sign)-----------------------*/
   DEBUG_YCONV   yLOG_double  ("a_source"  , a_source);
   if (a_source < 0.0)    x_sign  = -1;
   DEBUG_YCONV   yLOG_value   ("x_sign"    , x_sign);
   /*---(scale full number)--------------*/
   DEBUG_YCONV   yLOG_char    ("a_uom"     , a_uom);
   --rce;  if (a_cnt < 0 || a_cnt > 9) {
      DEBUG_YCONV   yLOG_note    ("a_cnt out of range (0-9)");
      if (r_out != NULL)  ystrlcpy (r_out, "#p/dec", a_max);
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   x_scaled = a_source;
   rc = yconv_4uom (a_uom, &x_scaled);
   DEBUG_YCONV   yLOG_value   ("units"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_note    ("a_uom not understood");
      if (r_out != NULL)  ystrlcpy (r_out, "#p/uni", a_max);
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(save unit)----------------------*/
   if      (a_uom == '-')   strcpy  (x_unit, "");
   else if (a_uom == '.')   sprintf (x_unit, "%c", G_CHAR_BIGDOT);
   else                      sprintf (x_unit, "%c", a_uom);
   DEBUG_YCONV   yLOG_info    ("x_unit"    , x_unit);
   /*---(parse out)----------------------*/
   for (i = 0; i < a_cnt; ++i)  x_pow *= 10;
   DEBUG_YCONV   yLOG_llong   ("x_pow"     , x_pow);
   x_round  = round (x_scaled * x_sign * x_pow);
   DEBUG_YCONV   yLOG_double  ("x_round"   , x_round);
   x_int    = x_round / x_pow;
   DEBUG_YCONV   yLOG_llong   ("x_int"     , x_int);
   x_dec    = x_round - (x_int * x_pow);
   DEBUG_YCONV   yLOG_llong   ("x_dec"     , x_dec);
   /*---(save-back)----------------------*/
   if (r_sign  != NULL)  *r_sign = x_sign;
   if (r_int   != NULL)  *r_int  = x_int;
   if (r_dec   != NULL)  *r_dec  = x_dec;
   if (r_exp   != NULL)  *r_exp  = x_exp;
   if (r_unit  != NULL)  strcpy (r_unit, x_unit);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return 0;
}

char
yconv_4float             (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_uom, char a_max, char r_out [LEN_TITLE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char        rc          =    0;
   double      x_source    =  0.0;
   char        x_sign      =    0;
   char        x_decs      =    0;
   llong       x_int       =    0;             /* integer part                   */
   llong       x_dec       =    0;             /* fractional part                */
   char        x_unit      [LEN_SHORT] = "";
   char        x_left      [LEN_TITLE] = "";
   char        x_right     [LEN_TITLE] = "";
   char        x_final     [LEN_TITLE] = "";
   int         i           =    0;
   int         l           =    0;
   char        x_sigs      =    0;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   rc = yconv__4defense  (TYPE_FLOAT,  0 , a_ullong, a_double, a_fmt, a_max, NULL, NULL, r_out);
   DEBUG_YCONV   yLOG_value   ("defense"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_char    ("a_fmt"     , a_fmt);
   /*---(prepare)------------------------*/
   if (a_ullong > 0)  x_source = (double)  a_ullong;
   else               x_source = a_double;
   if (strchr ("iI", a_fmt) != NULL)  x_decs = 0;
   else                               x_decs = a_cnt;
   /*---(divide)-------------------------*/
   DEBUG_YCONV   yLOG_char    ("a_uom"    , a_uom);
   rc = yconv__4divide (x_source, x_decs, a_uom, a_max, &x_sign, &x_int, &x_dec, NULL, x_unit, r_out);
   DEBUG_YCONV   yLOG_value   ("divide"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(prefix)-------------------------*/
   if (a_fmt == '$')  ystrlcpy (x_final, "$", LEN_TITLE);
   DEBUG_YCONV   yLOG_info    ("pre-prefix", x_final);
   /*---(pre-sign)-----------------------*/
   if (x_sign < 0) {
      if      (strchr ("iIfF,sSpP", a_fmt) != NULL)  ystrlcat (x_final, "-", LEN_TITLE);
      else if (strchr ("aA"       , a_fmt) != NULL)  ystrlcat (x_final, "(", LEN_TITLE);
   } else {
      if      (strchr ("sS"       , a_fmt) != NULL)  ystrlcat (x_final, "+", LEN_TITLE);
   }
   DEBUG_YCONV   yLOG_info    ("pre-sign"  , x_final);
   /*---(create left/integer)------------*/
   sprintf (x_left , "%lld", x_int);
   x_sigs += strlen (x_left);
   DEBUG_YCONV   yLOG_value   ("x_sigs"    , x_sigs);
   if  (strchr ("if", a_fmt) == NULL)  yconv__space_ints (3, ',' , x_left);
   ystrlcat (x_final, x_left, LEN_TITLE);
   DEBUG_YCONV   yLOG_info    ("left"      , x_final);
   /*---(add decimal)--------------------*/
   if (strchr ("iI" , a_fmt) == NULL && a_cnt > 0) {
      if (strchr ("cC" , a_fmt) != NULL)  ystrlcat (x_final, "Å", LEN_TITLE);
      else                                ystrlcat (x_final, ".", LEN_TITLE);
      DEBUG_YCONV   yLOG_info    ("decimal"   , x_final);
   }
   /*---(create right/decimals)----------*/
   DEBUG_YCONV   yLOG_value   ("a_cnt"    , a_cnt);
   if (strchr ("iI" , a_fmt) == NULL && a_cnt > 0) {
      sprintf (x_right, "%lld", x_dec);
      x_sigs += strlen (x_right);
      l      = strlen (x_right);
      for (i = l - 1; i > 0; --i) {
         if (strchr (YSTR_NUMBER, x_right [i]) != NULL)  break;
         --x_sigs;
      }
      if  (strchr ("if", a_fmt) == NULL)  yconv__space_decs (3, '\'', x_right);
      ystrlcat (x_final, x_right, LEN_TITLE);
      DEBUG_YCONV   yLOG_info    ("right"     , x_final);
   }
   /*---(check on sigs)------------------*/
   DEBUG_YCONV   yLOG_value   ("x_sigs"    , x_sigs);
   --rce;  if (x_sigs > 15) {
      DEBUG_YCONV   yLOG_note    ("double overflow");
      if (r_out != NULL)  ystrlcpy (r_out, "#p/ovr", a_max);
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(units)--------------------------*/
   ystrlcat (x_final, x_unit, LEN_TITLE);
   DEBUG_YCONV   yLOG_info    ("units"     , x_final);
   /*---(post-sign)----------------------*/
   if (x_sign < 0) {
      if      (strchr ("aA$", a_fmt) != NULL)  ystrlcat (x_final, ")" , LEN_TITLE);
      else if (strchr ("cC#", a_fmt) != NULL)  ystrlcat (x_final, "∑-", LEN_TITLE);
   } else {
      if      (strchr ("aA$", a_fmt) != NULL)  ystrlcat (x_final, "∑" , LEN_TITLE);
      else if (strchr ("cC#", a_fmt) != NULL)  ystrlcat (x_final, "∑+", LEN_TITLE);
   }
   if      (a_fmt == 'p') ystrlcat (x_final, ")", LEN_TITLE);
   else if (a_fmt == 'P') ystrlcat (x_final, "¥", LEN_TITLE);
   DEBUG_YCONV   yLOG_info    ("post-sign" , x_final);
   /*---(integer suffix padding)---------*/
   if (strchr ("iI" , a_fmt) != NULL) {
      for (i = 0; i <  a_cnt; ++i)    ystrlcat (x_final, "∑", LEN_TITLE);
      if (                a_cnt > 0)  ystrlcat (x_final, "∑", LEN_TITLE); /* for decimal point */
      if (a_fmt == 'I' && a_cnt > 3)  ystrlcat (x_final, "∑", LEN_TITLE);
      if (a_fmt == 'I' && a_cnt > 6)  ystrlcat (x_final, "∑", LEN_TITLE);
      DEBUG_YCONV   yLOG_info    ("padded"    , x_final);
   }
   /*---(save-back)----------------------*/
   DEBUG_YCONV   yLOG_info    ("x_final"   , x_final);
   if (r_out  != NULL)  ystrlcpy (r_out, x_final, LEN_TITLE);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return 0;
}

char         /*-> format hexadecimal numbers to string ----[ petal  [ 2f---- ]*/
yconv_4comma         (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_uom, char a_max, char r_out [LEN_TITLE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;               /* return code for errors    */
   char        rc          =    0;
   int         x_len       =    0;
   int         i           =    0;               /* iterator -- character     */
   char        x_temp      [200] = "";
   char        x_prefix    [200] = "";  /* temp working string            */
   char        x_suffix    [200] = "";  /* temp working string            */
   char        x_final     [200] = "";
   char        x_sign      =    1;
   double      x_scaled    = 0.0;           /* scaled version                 */
   char        x_unit      [LEN_SHORT];
   double      x_round     = 0.0;           /* rounded off value              */
   long      x_exp       = 1;             /* exponent to round off          */
   long      x_int       = 0;             /* whole part                     */
   long      x_frac      = 0;             /* fractional part                */
   long      x_pct       = 1;             /* fractional part                */
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_senter  (__FUNCTION__);
   /*---(defence)------------------------*/
   DEBUG_YCONV   yLOG_spoint  (r_out);
   --rce;  if (r_out == NULL) {
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   ystrlcpy (r_out, YSTR_EMPTY, a_max);
   DEBUG_YCONV   yLOG_schar   (a_fmt);
   --rce;  if (strchr ("iIfF,cCaAsS$#pP?", a_fmt) == NULL) {
      ystrlcpy (r_out, "#p/fmt", a_max);
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }

   if (a_double < 0.0)    x_sign  = -1;
   if (a_fmt == '?')   a_fmt   = 'i';
   if (a_fmt == 'i')   a_cnt  =  0;
   /*---(scale)--------------------------*/
   x_scaled = a_double;
   rc = yconv_4uom (a_uom, &x_scaled);
   --rce;  if (rc < 0) {
      ystrlcpy (r_out, "#p/uni", a_max);
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   if      (a_uom == '-')   strcpy  (x_unit, "");
   else if (a_uom == '.')   sprintf (x_unit, "%c", G_CHAR_BIGDOT);
   else                      sprintf (x_unit, "%c", a_uom);
   /*---(parse out)----------------------*/
   for (i = 0; i < a_cnt; ++i)  x_exp *= 10;
   x_round  = round (x_scaled * x_sign * x_exp * x_pct);
   x_int    = x_round / x_exp;
   x_frac   = x_round - (x_int * x_exp);
   /*---(assemble prefix)----------------*/
   if (tolower (a_fmt) == '$')  strcat (x_final, "$");
   if (x_sign < 0) {
      if (strchr ("iIf,cspP", tolower (a_fmt)) != NULL)  strcat (x_final, "-");
      if (strchr ("a$"      , tolower (a_fmt)) != NULL)  strcat (x_final, "(");
   } else {
      if (strchr ("s"       , tolower (a_fmt)) != NULL)  strcat (x_final, "+");
   }
   DEBUG_YCONV  yLOG_snote    (x_final);
   /*---(format integer part)------------*/
   sprintf (x_temp, "%lld", x_int);
   x_len = strlen (x_temp);
   if (strchr ("iIfF", a_fmt) == NULL)  yconv__space_ints (3, ',', x_temp);
   strcat (x_final, x_temp);
   DEBUG_YCONV  yLOG_snote    (x_temp);
   /*---(decimal part)-------------------*/
   if (strchr ("iI", a_fmt) == 0 && a_cnt > 0) {
      sprintf (x_temp, "%0*lld", a_cnt, x_frac);
      if (strchr ("ACS#F", a_fmt) != NULL)  yconv__space_decs (3, '\'', x_temp);
      strcat  (x_final, ".");
      strcat  (x_final, x_temp);
   }
   DEBUG_YCONV  yLOG_snote    (x_temp);
   /*---(assemble suffix)----------------*/
   strcat (x_final, x_unit);
   if (x_sign < 0) {
      switch (a_fmt) {
      case 'a' : case 'A' : case '$' : strcat (x_final, ")");  break;
      case 'p' :                       strcat (x_final, ")");  break;
      case 'P' :                       strcat (x_final, "¥");  break;
      case '#' :                       strcat (x_final, " -"); break;
      }
   } else {
      switch (a_fmt) {
      case 'a' : case 'A' : case '$' : strcat (x_final, "_");  break;
      case 'p' :                       strcat (x_final, ")");  break;
      case 'P' :                       strcat (x_final, "¥");  break;
      case '#' :                       strcat (x_final, " +"); break;
      }
   }
   if (a_fmt == 'I' && a_cnt > 0) {
      for (i = 0; i <= a_cnt; ++i)  strcat (x_final, " ");
   }
   DEBUG_YCONV  yLOG_snote    (x_final);
   /*---(create)---------------*/
   x_len = strlen (x_final);
   DEBUG_YCONV   yLOG_sint    (a_max);
   DEBUG_YCONV   yLOG_sint    (x_len);
   --rce;  if (x_len > a_max) {
      ystrlcpy (r_out, "#p/max", a_max);
      DEBUG_YCONV   yLOG_snote   ("too long");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   ystrlcpy  (r_out, x_final, a_max);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_sexit   (__FUNCTION__);
   return 0;
}

char         /*-> format hexadecimal numbers to string ----[ petal  [ 2f---- ]*/
yconv_4sci           (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;               /* return code for errors    */
   int         x_len       =    0;
   int         i           =    0;               /* iterator -- character     */
   char        x_temp      [200] = "";
   char        x_prefix    [200] = "";  /* temp working string            */
   char        x_suffix    [200] = "";  /* temp working string            */
   char        x_final     [200] = "";
   char        x_sign      =    1;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_senter  (__FUNCTION__);
   /*---(defence)------------------------*/
   DEBUG_YCONV   yLOG_spoint  (r_out);
   --rce;  if (r_out == NULL) {
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   ystrlcpy (r_out, YSTR_EMPTY, a_max);
   if (a_double < 0.0)  x_sign  = -1;
   DEBUG_YCONV   yLOG_schar   (a_fmt);
   --rce;  if (strchr ("eE", a_fmt) == NULL) {
      ystrlcpy (r_out, "#p/fmt", a_max);
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(prepare)---------------------*/
   if (a_double < 0.0)  x_sign  = -1;
   if (a_cnt == 0)  a_cnt  =  1;
   strcpy  (x_final, "");
   /*---(make prefix)-----------------*/
   if (x_sign < 0)          strcpy (x_final, "-");
   else if (a_fmt == 'E')   strcpy (x_final, "+");
   sprintf (x_temp, "%.*e", a_cnt, a_double * x_sign);
   strncat (x_final, x_temp, 2);
   /*---(save exponent/suffix)--------*/
   if (a_fmt == 'E')  strcpy  (x_suffix, x_temp + a_cnt + 2);
   else               sprintf (x_suffix, "À%d", atoi (x_temp + a_cnt + 3));
   x_temp  [a_cnt + 2] = '\0';
   /*---(parse decimals)--------------*/
   strcpy  (x_prefix, x_temp + 2);
   if (a_fmt == 'E' && a_cnt > 3)  yconv__space_decs (3, '\'', x_prefix);
   /*---(contat)----------------------*/
   strcat  (x_final, x_prefix);
   /*> if (a_fmt == 'E')  strcat  (x_final, " ");                                     <*/
   strcat  (x_final, x_suffix);
   /*---(create)---------------*/
   x_len = strlen (x_final);
   DEBUG_YCONV   yLOG_sint    (a_max);
   DEBUG_YCONV   yLOG_sint    (x_len);
   --rce;  if (x_len > a_max) {
      ystrlcpy (r_out, "#p/max", a_max);
      DEBUG_YCONV   yLOG_snote   ("too long");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   ystrldchg (x_final, 'e', 'À', a_max);
   ystrldchg (x_final, 'E', 'À', a_max);
   ystrlcpy  (r_out, x_final, a_max);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_sexit   (__FUNCTION__);
   return 0;
}

/*
 *   ˙:
 *
 *   midnight      23-01    mi     7   i   midn
 *   graveyard     02-04    gr     0   g   grav
 *   dawn          05-07    dw     1   d   dawn
 0   morning       08-10    mo     2   m   morn
 *   noon          11-13    oo     3   o   noon
 *   afternoon     14-16    af     4   a   aftr
 *   dusk          17-19    sk     5   u   dusk
 *   evening       20-22    ev     6   e   evng
 *
 *   yyyy mm dd hh mm ss shft w wy doy
 *   2245.07.04.12.00.00.3/oo.5.26.185
 *
 *   year mo dy hr mi se w wy doy shift-
 *
 *   ˙'2245.07.04.12.00.00.5.26.185.3/noon    2245 jul 07 12:00:00 th, 26woy
 *
 *   123456789-123456789-123456789-123456789-123456789-123456789-123456789-123456789-
 *   2245.07.04.5.12.00.00.3.26.185 ß 2245 jul 07 (th) 12:00 (noon), 26woy, 185doy ß
 *
 *   2245.07.04.12.00.00.5.26.185.3o
 *   45.07.04.12.00.00.5.26.185
 *
 */

char         /*-> format times into strings ---------------[ petal  [ 2f---- ]*/
yconv_4time          (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_max, char r_out [LEN_TITLE])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;               /* return code for errors    */
   int         x_len       =    0;
   int         x_int       =    0;
   char        x_final     [200] = "";
   int         i           =    0;
   long        x_now       = 0;
   tTIME      *x_time      = NULL;
   char        x_hrs       =    0;
   char        x_min       =    0;
   char        x_shift     =    0;
   char        t           [LEN_TERSE] = "";
   char       *x_shifts    = "gdmoauei";
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_senter  (__FUNCTION__);
   /*---(defence)------------------------*/
   DEBUG_YCONV   yLOG_spoint  (r_out);
   --rce;  if (r_out == NULL) {
      DEBUG_YCONV   yLOG_snote   ("r_out null");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   ystrlcpy (r_out, YSTR_EMPTY, a_max);
   DEBUG_YCONV   yLOG_schar   (a_fmt);
   --rce;  if (strchr ("tTdD", a_fmt) == NULL) {
      ystrlcpy (r_out, "#p/fmt", a_max);
      DEBUG_YCONV   yLOG_snote   ("format invalid");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_sint    (a_double);
   --rce;  if (a_double < 0) {
      ystrlcpy (r_out, "#p/neg", a_max);
      DEBUG_YCONV   yLOG_snote   ("epoch number negative");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   /*---(handle time/date formats)-------*/
   x_now  = (long) a_double;
   x_time = localtime (&x_now);
   switch (a_fmt) {
   case 'd': strftime (x_final, 50, "%Y-%b-%d", x_time);
             x_final [5] = tolower (x_final [5]);
             break;
   case 't': strftime (x_final, 50, "%H:%M", x_time);
             break;
   case 'D': strftime (x_final, 50, "%Y-%b-%d %H:%M", x_time);
             x_final [5] = tolower (x_final [5]);
             break;
   case 'T': strftime (x_final, 50, "%Y.%m.%d.%H.%M.%S.%u.%W.%j", x_time);
             sprintf (t, "%-2.2s", x_final + 11);
             x_hrs = atoi (t);
             sprintf (t, "%-2.2s", x_final + 14);
             x_min = atoi (t);
             switch (x_hrs) {
             case 23 : case  0 :
                x_shift = 7;  break;
             case  1 :
                if (x_min < 30) x_shift = 7;  else x_shift = 0;  break;
             case  2 : case  3 :
                x_shift = 0;  break;
             case  4 :
                if (x_min < 30) x_shift = 0;  else x_shift = 1;  break;
             case  5 : case  6 :
                x_shift = 1;  break;
             case  7 :
                if (x_min < 30) x_shift = 1;  else x_shift = 2;  break;
             case  8 : case  9 :
                x_shift = 2;  break;
             case 10 :
                if (x_min < 30) x_shift = 2;  else x_shift = 3;  break;
             case 11 : case 12 :
                x_shift = 3;  break;
             case 13 :
                if (x_min < 30) x_shift = 3;  else x_shift = 4;  break;
             case 14 : case 15 :
                x_shift = 4;  break;
             case 16 :
                if (x_min < 30) x_shift = 4;  else x_shift = 5;  break;
             case 17 : case 18 :
                x_shift = 5;  break;
             case 19 :
                if (x_min < 30) x_shift = 5;  else x_shift = 6;  break;
             case 20 : case 21 :
                x_shift = 6;  break;
             case 22 :
                if (x_min < 30) x_shift = 6;  else x_shift = 7;  break;
             }
             sprintf (t, ".%d%c", x_shift, x_shifts [x_shift]);
             strcat  (x_final, t);
             break;

   }
   /*---(create)---------------*/
   x_len = strlen (x_final);
   DEBUG_YCONV   yLOG_sint    (a_max);
   DEBUG_YCONV   yLOG_sint    (x_len);
   --rce;  if (x_len > a_max) {
      ystrlcpy (r_out, "#p/max", a_max);
      DEBUG_YCONV   yLOG_snote   ("too long");
      DEBUG_YCONV   yLOG_sexitr  (__FUNCTION__, rce);
      return rce;
   }
   ystrlcpy  (r_out, x_final, a_max);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_sexit   (__FUNCTION__);
   return 0;
}



/*====================------------------------------------====================*/
/*===----                    number to string driver                   ----===*/
/*====================------------------------------------====================*/
static void      o___4DRIVER_________________o (void) {;}

char
yconv_4main          (ullong a_ullong, double a_double, char a_cnt, char a_fmt, char a_uom, char a_max, char r_out [LEN_TITLE])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_YCONV   yLOG_enter   (__FUNCTION__);
   /*---(defense)------------------------*/
   DEBUG_YCONV   yLOG_char    ("a_fmt"     , a_fmt);
   if (yconv_check_format (a_fmt) < 0) {
      DEBUG_YCONV   yLOG_note    ("a_fmt illegal");
      ystrlcpy (r_out, "#p/fmt", a_max);
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   DEBUG_YCONV   yLOG_char    ("a_cnt"   , a_cnt);
   if (yconv_check_count (a_cnt) < 0) {
      DEBUG_YCONV   yLOG_note    ("a_cnt illegal");
      ystrlcpy (r_out, "#p/dec", a_max);
      DEBUG_YCONV   yLOG_exitr   (__FUNCTION__, rce);
      return rce;
   }
   /*---(call handler)-------------------*/
   switch (tolower (a_fmt)) {
   case 'y' : case 'Y' :
      DEBUG_YCONV   yLOG_note    ("selected boolean");
      rc = yconv_4bool  (a_ullong, a_double, a_cnt, a_fmt, a_max, r_out);
      break;
   case 'b' : case 'B' :
      DEBUG_YCONV   yLOG_note    ("selected binary");
      rc = yconv_4bin   (a_ullong, a_double, a_cnt, a_fmt, a_max, r_out);
      break;
   case 'o' : case 'O' :
      DEBUG_YCONV   yLOG_note    ("selected octal");
      rc = yconv_4oct   (a_ullong, a_double, a_cnt, a_fmt, a_max, r_out);
      break;
   case 'x' : case 'X' :
      DEBUG_YCONV   yLOG_note    ("selected hexadecimal");
      rc = yconv_4hex   (a_ullong, a_double, a_cnt, a_fmt, a_max, r_out);
      break;
   case 'z' : case 'Z' :
      DEBUG_YCONV   yLOG_note    ("selected base64/mongo");
      rc = yconv_4mongo (a_ullong, a_double, a_cnt, a_fmt, a_max, r_out);
      break;
   case 'e' : case 'E' :
      DEBUG_YCONV   yLOG_note    ("selected scientific notation");
      rc = yconv_4sci   (a_ullong, a_double, a_cnt, a_fmt, a_max, r_out);
      break;
   case 'r' : case 'R' :
      DEBUG_YCONV   yLOG_note    ("selected roman numerals");
      rc = yconv_4roman (a_ullong, a_double, a_cnt, a_fmt, a_max, r_out);
      break;
   case 'd' : case 't' : case 'D' : case 'T' :
      DEBUG_YCONV   yLOG_note    ("selected time/date");
      rc = yconv_4time  (a_ullong, a_double, a_cnt, a_fmt, a_max, r_out);
      break;
   default :
      DEBUG_YCONV   yLOG_note    ("selected comma");
      rc = yconv_4comma (a_ullong, a_double, a_cnt, a_fmt, a_uom, a_max, r_out);
      break;
   }
   DEBUG_YCONV   yLOG_value   ("rc"        , rc);
   /*---(complete)-----------------------*/
   DEBUG_YCONV   yLOG_exit    (__FUNCTION__);
   return rc;
}

char*
yconv_4quick             (double a_double, char a_ali, char a_fmt, char a_cnt, char a_uom, char a_fil, char a_zer, char a_neg, char a_max)
{
   char        rc          =    0;
   char        t           [LEN_HUND]  = "";
   static char x_print     [LEN_HUND]  = "";
   if      (a_zer != ' ' && a_double == 0.0)  sprintf (t, "%c", a_zer);
   else if (a_neg != ' ' && a_double <  0.0)  sprintf (t, "%c", a_neg);
   else    rc = yconv_4main (NULL, a_double, a_cnt, a_fmt, a_uom, a_max + 1, t);
   rc = ystrlpad   (t, x_print, a_fil, a_ali, a_max);
   return x_print;
}




