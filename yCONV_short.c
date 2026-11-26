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



/*====================------------------------------------====================*/
/*===----                     sizes and counts                         ----===*/
/*====================------------------------------------====================*/
static void      o___SIZE____________________o (void) {;}

char
yconv__size             (llong a_size, char a_base, char a_fmt, char r_size [LEN_SHORT])
{  /*---(notes)--------------------------*/
   /*
    *  scaled sizes are almost always more important to me than single unit.
    *  quicker for me to interpret.  it also only needs three chars.
    *  if i keep to one way of presenting, it is even easier, for me.
    *  build-once, use-often.
    *
    *  -  = normal lower case units (also 'n' type)
    *  u  = upper case for large units
    *  N  = fill spaces with '·'
    *  U  = both u and N options
    *  t  = shows less than 1,000 numbers (rather than <k)
    *  T  = t plus U and N
    *
    */
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   llong       x_size      =    0;
   char        x_unit      =  '-';
   int         x_mult      = 1000;
   /*---(default)------------------------*/
   if (r_size  != NULL)  strcpy (r_size, "   ·");
   /*---(defense)------------------------*/
   --rce;  if (r_size  == NULL)  return rce;
   --rce;  if (a_size  <  0)                                       { strcpy (r_size, "#/ne");  return rce; }
   --rce;  if (a_base  == 0 || strchr ("-b"     , a_base) == NULL) { strcpy (r_size, "#/bs");  return rce; }
   --rce;  if (a_fmt   == 0 || strchr ("-nNtTuU", a_fmt ) == NULL) { strcpy (r_size, "#/fm");  return rce; }
   /*---(prepare)------------------------*/
   x_size  = a_size;
   x_unit  = '´';
   if (a_base = 'b')  x_mult = 1024;
   else               x_mult = 1000;
   /*---(trivial size)-------------------*/
   if (x_size == 0) {
      if (strchr ("-ntu", a_fmt) != NULL)  strcpy (r_size, "  <´");
      else                                 strcpy (r_size, "··<´");
      return 0;
   }
   /*---(figure size)--------------------*/
   if (x_size >= x_mult) {
      x_size /= x_mult;
      x_unit  = 'k';
      if (x_size >= x_mult) {
         x_size /= x_mult;
         x_unit  = 'm';
         if (x_size >= x_mult) {
            x_size /= x_mult;
            x_unit  = 'g';
            if (x_size >= x_mult) {
               x_size /= x_mult;
               x_unit  = 't';
               if (x_size >= x_mult) {
                  strcpy (r_size, "#/hu");  /* 1,000+ exabytes */
                  return rce;
               }
            }
         }
      }
   }
   /*---(adjust for format)--------------*/
   if (strchr ("uU", a_fmt) != NULL) {
      switch (x_unit) {
      case 'k' :  x_unit = 'K';  break;
      case 'm' :  x_unit = 'M';  break;
      case 'g' :  x_unit = 'G';  break;
      case 't' :  x_unit = 'T';  break;
      }
   }
   /*---(save-back)----------------------*/
   if (strchr ("tT", a_fmt) != NULL && x_unit == '´') {
      strcpy  (r_size, "  <k");
   } else {
      sprintf (r_size, "%3d%c", x_size, x_unit);
   }
   /*---(check for fill)-----------------*/
   if (strchr ("NTU", a_fmt) != NULL) {
      if (r_size [0] == ' ')  r_size [0] = '·';
      if (r_size [1] == ' ')  r_size [1] = '·';
   }
   /*---(complete)-----------------------*/
   return 0;
}

char yconv_size  (llong a_size, char a_fmt, char r_used [LEN_SHORT])  { return yconv__size (a_size, '-', a_fmt, r_used);}
char yconv_count (llong a_size, char a_fmt, char r_count [LEN_SHORT]) { return yconv__size (a_size, '-', a_fmt, r_count); }

char
yconv_size_full         (llong a_size, char a_fmt, char r_used [LEN_SHORT], char *r_large, llong a_alloc, char r_alloc [LEN_SHORT], char *r_pct, char *r_dense)
{
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   char        rc          =    0;
   char        x_large     =  '-';
   int         x_pct       =    0;
   char        x_dense     =  '-';
   /*---(default)------------------------*/
   if (r_used  != NULL)  strcpy (r_used , "----");
   if (r_large != NULL)  *r_large = '-';
   if (r_alloc != NULL)  strcpy (r_alloc, "----");
   if (r_pct   != NULL)  *r_pct   =  0;
   if (r_dense != NULL)  *r_dense = '-';
   /*---(defense)------------------------*/
   --rce;  if (r_used  == NULL)  return rce;
   --rce;  if (r_alloc == NULL)  return rce;
   /*---(true size)----------------------*/
   rc = yconv__size (a_size, 'b', a_fmt, r_used);
   --rce;  if (rc < 0)  return rce;
   /*---(calc largeness)-----------------*/
   if      (strchr ("´" , r_used [3])  != NULL) x_large  = '-';
   else if (strchr ("k" , r_used [3])  != NULL) {
      if (strchr ("54769", r_used [0]) == NULL) x_large  = '·';
      else                                      x_large  = '´';
   }
   else if (strchr ("mM", r_used [3])  != NULL) x_large  = 'Ï';
   else                                         x_large  = '°';
   /*---(allocated)----------------------*/
   rc = yconv__size (a_alloc, 'b', a_fmt, r_alloc);
   --rce;  if (rc < 0)  return rce;
   /*---(calc percent)-------------------*/
   if (a_size > 0 &&  a_alloc > 0) {
      x_pct  = round (((float) a_size / (float) a_alloc) * 100);
   }
   /*---(calc density)-------------------*/
   if      (x_pct ==  0)  x_dense = '-';
   else if (x_pct >= 80)  x_dense = '°';
   else if (x_pct >= 50)  x_dense = 'Ï';
   else if (x_pct >= 30)  x_dense = '´';
   else                   x_dense = '·';
   /*---(save-back)----------------------*/
   if (r_large != NULL)  *r_large = x_large;
   if (r_pct   != NULL)  *r_pct   = x_pct;
   if (r_dense != NULL)  *r_dense = x_dense;
   /*---(complete)-----------------------*/
   return 0;
}



/*====================------------------------------------====================*/
/*===----                     ages and duration                        ----===*/
/*====================------------------------------------====================*/
static void      o___AGE_____________________o (void) {;}

char
yconv__age              (long a_since, long a_now, char a_fmt, char r_age [LEN_SHORT], char *r_flag)
{  /*---(notes)--------------------------*/
   /*
    *  age is almost always more important to me than date, and
    *  quicker for me to interpret.  it also only needs three chars.
    *  if i keep to one way of presenting, it is even easier, for me.
    *  build-once, use-often.
    *
    *  -  = normal lower case units (also 'n' type)
    *  n  = normal
    *  N  = normal    prefixed with '·'
    *  t  = trivial   
    *  T  = trivial   prefixed with '·'
    *  u  = uppercase 
    *  U  = uppercase prefixed with '·'
    */
   /*---(locals)-------------------------*/
   char        rce         =  -10;
   long        x_age       =    0;
   char        x_unit      =  '-';
   char        x_flag      =  '-';
   /*---(default)------------------------*/
   if (r_age  != NULL)  strcpy (r_age, "---");
   if (r_flag != NULL)  *r_flag = '-';
   /*---(defense)------------------------*/
   --rce;  if (r_age   == NULL)  return rce;
   --rce;  if (a_since <  0)                                       { strcpy (r_age, "#/s");  return rce; }
   --rce;  if (a_now   <  0)                                       { strcpy (r_age, "#/n");  return rce; }
   --rce;  if (a_fmt   == 0 || strchr ("-nNtTuU", a_fmt ) == NULL) { strcpy (r_age, "#/f");  return rce; }
   /*---(time difference)----------------*/
   x_age = a_now - a_since;
   --rce;  if (x_age < 0) { strcpy (r_age, "#/a");  return rce; }
   /*---(trivial age)--------------------*/
   if (x_age == 0) {
      if (strchr ("-ntu", a_fmt) != NULL)  strcpy (r_age, " <s");
      else                                 strcpy (r_age, "·<s");
      if (r_flag != NULL)  *r_flag = '°';
      return 0;
   }
   /*---(figure age)---------------------*/
   x_unit = 's';
   --rce;  if (x_age >= 60) {
      x_age /= 60; x_unit = 'm';
      if (x_age >= 60) {
         x_age /= 60; x_unit = 'h';
         if (x_age >= 24) {
            x_age /= 24; x_unit = 'd';
            if (x_age >= 30) {                /* months avg 30 days, close ;) */
               x_age /= 30; x_unit = 'o';
               if (x_age >= 12) {
                  x_age /= 12; x_unit = 'y';
                  if (x_age >= 100) {
                     x_age /= 100; x_unit = 'c';
                     if (x_age >= 100) {
                        strcpy (r_age, "#/h");  /* huge date 100+ centuries */
                        return rce;
                     }
                  }
               }
            }
         }
      }
   }
   /*---(calc recent)--------------------*/
   if      (strchr ("sm", x_unit) != NULL)  x_flag = '°';
   else if (strchr ("h" , x_unit) != NULL)  x_flag = 'Ï';
   else if (strchr ("d" , x_unit) != NULL)  x_flag = '´';
   else                                     x_flag = '·';
   /*---(adjust for format)--------------*/
   if (a_fmt != 0 && strchr ("uU", a_fmt) != NULL) {
      switch (x_unit) {
      case 'o' :  x_unit = 'M';  break;
      case 'y' :  x_unit = 'Y';  break;
      case 'c' :  x_unit = 'C';  break;
      }
   }
   /*---(save-back)----------------------*/
   if (strchr ("tT", a_fmt) != NULL && strchr ("sm", x_unit) != NULL) {
      strcpy  (r_age, " <h");
   } else {
      sprintf (r_age, "%2d%c", x_age, x_unit);
   }
   /*---(check for fill)-----------------*/
   if (a_fmt != 0 && strchr ("NTU", a_fmt) != NULL) {
      if (r_age [0] == ' ')  r_age [0] = '·';
   }
   /*---(save-back)----------------------*/
   if (r_flag != NULL)  *r_flag = x_flag;
   /*---(complete)-----------------------*/
   return 0;
}

char yconv_age        (long a_since, char a_fmt, char r_age [LEN_SHORT], char *r_flag)              { return yconv__age (a_since, time (NULL), a_fmt, r_age, r_flag); }
char yconv_age_full   (long a_since, long a_now, char a_fmt, char r_age [LEN_SHORT], char *r_flag)  { return yconv__age (a_since, a_now, a_fmt, r_age, r_flag); }
char yconv_dur        (long a_secs,  char a_fmt, char r_age [LEN_SHORT], char *r_flag)              { return yconv__age ( 1, a_secs + 1, a_fmt, r_age, r_flag); }

char
yconv_unage             (char a_age [LEN_SHORT], long *r_secs)
{  /*---(design notes)-------------------*/
   /*
    *  this is very, very approximate with 1-2 significant digits ;)
    */
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        x_age       [LEN_SHORT] = "";
   int         l           =    0;
   char        x_unit      =  '-';
   long        x_multi     =    0;
   long        x_num       =    0;
   /*---(default)------------------------*/
   if (r_secs != NULL)  *r_secs =  0;
   /*---(defense)------------------------*/
   --rce;  if (a_age == NULL)  return rce;
   strlcpy (x_age, a_age, LEN_SHORT);
   l = strlen (x_age);
   --rce;  if (l != 3)         return rce;
   /*---(grab unit)----------------------*/
   x_unit = x_age [l - 1];
   --rce;  switch (x_unit) {
   case  's' :             x_multi = 1;                         break;
   case  'm' :             x_multi = 60;                        break;
   case  'h' :             x_multi = 60 * 60;                   break;
   case  'd' :             x_multi = 60 * 60 * 24;              break;
   case  'o' : case  'M' : x_multi = 60 * 60 * 24 * 30;         break;
   case  'y' : case  'Y' : x_multi = 60 * 60 * 24 * 365;        break;
   case  'c' : case  'C' : x_multi = 60 * 60 * 24 * 365 * 100;  break;
   default   : return rce;
   }
   /*---(check legality)-----------------*/
   --rce;  if (strchr ("123456789 ·", x_age [0]) == NULL) return rce;
   --rce;  if (strchr ("0123456789<", x_age [1]) == NULL) return rce;
   /*---(clean up number)----------------*/
   if (x_age [0] == '·')  x_age [0] = ' ';
   /*---(quick-out)----------------------*/
   if   (strcmp (" <s", x_age) == 0) {
      if (r_secs != NULL)  *r_secs = 0;
      return 0;
   }
   if   (strcmp (" <h", x_age) == 0) {
      if (r_secs != NULL)  *r_secs = 60 * 60;
      return 0;
   }
   /*---(convert)------------------------*/
   x_age [l - 1] = '\0';
   x_num = atoi (x_age);
   /*---(check for trouble)--------------*/
   --rce;  if (x_num == 0 && strcmp (x_age, "0") != 0)  return rce;
   --rce;  if (x_num <  0)                              return rce;
   x_num *= x_multi;
   /*---(save-back)----------------------*/
   if (r_secs != NULL)  *r_secs = x_num;
   /*---(complete)-----------------------*/
   return 0;
}



