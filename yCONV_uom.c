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


static struct {
   char        u_uom;                     /* symbol of unit       */
   char        u_pow;                     /* power                */
   double      u_scale;                   /* multiplier           */
   char        u_name      [LEN_TERSE];   /* prefix               */
   char        u_sci       [LEN_SHORT];   /* scientific notation  */
   char        u_english   [LEN_LABEL];   /* scientific notation  */
} const S_scale [LEN_TITLE] = {
   /*---   pow   ---scale---------------------   --name--   -sci-   ----english---- */
   { '-' ,   0 ,  1.0                          , "def"   , "----" , ""              },
   /*---   pow   ---scale---------------------   --name--   -sci-   ----english---- */
   { 'Y' , +24 ,  1000000000000000000000000.0  , "yotta" , "Ë+24" , "septillion"    },
   { 'Z' , +21 ,  1000000000000000000000.0     , "zetta" , "Ë+21" , "sextillion"    },
   { 'E' , +18 ,  1000000000000000000.0        , "exa"   , "Ë+18" , "quintillion"   },
   { 'P' , +15 ,  1000000000000000.0           , "peta"  , "Ë+15" , "quadrillion"   },
   { 'T' , +12 ,  1000000000000.0              , "tera"  , "Ë+12" , "trillion"      },
   { 'G' ,  +9 ,  1000000000.0                 , "giga"  , "Ë+09" , "billion"       },
   { 'M' ,  +6 ,  1000000.0                    , "mega"  , "Ë+06" , "million"       },
   { 'K' ,  +3 ,  1000.0                       , "kilo"  , "Ë+03" , "thousand"      },
   { 'H' ,  +2 ,  100.0                        , "hecto" , "Ë+02" , "hundred"       },
   { 'D' ,  +1 ,  10.0                         , "deca"  , "Ë+01" , "ten"           },
   /*---   pow   ---scale---------------------   --name--   -sci-   ----english---- */
   { '.' ,   0 ,  1.0                          , ""      , "----" , ""              },
   /*---   pow   ---scale---------------------   --name--   -sci-   ----english---- */
   { 'd' ,  -1 ,  0.1                          , "deci"  , "Ë-01" , "tenth"         },
   { 'c' ,  -2 ,  0.01                         , "centa" , "Ë-02" , "hundredth"     },
   { 'm' ,  -3 ,  0.001                        , "milli" , "Ë-03" , "thousandth"    },
   { 'u' ,  -6 ,  0.000001                     , "micro" , "Ë-06" , "millionth"     },
   { 'n' ,  -9 ,  0.000000001                  , "nano"  , "Ë-09" , "billionth"     },
   { 'p' , -12 ,  0.000000000001               , "pico"  , "Ë-12" , "trillionth"    },
   { 'f' , -15 ,  0.000000000000001            , "femto" , "Ë-15" , "quadrillionth" },
   { 'a' , -18 ,  0.000000000000000001         , "atto"  , "Ë-18" , "quintillionth" },
   { 'z' , -21 ,  0.000000000000000000001      , "zepto" , "Ë-21" , "sextillionth"  },
   { 'y' , -24 ,  0.000000000000000000000001   , "yocto" , "Ë-24" , "septillionth"  },
   /*---   pow   ---scale---------------------   --name--   -sci-   ----english---- */
   {  0  ,   0 ,  0.0                          , ""      , ""     , ""              },
   /*---   pow   ---scale---------------------   --name--   -sci-   ----english---- */
};


#define   UOM_VALID     "-YZEPTGMKHD.dcmunpfazy"



/*====================------------------------------------====================*/
/*===----                 support for units                            ----===*/
/*====================------------------------------------====================*/
static void      o___SUPPORT_________________o (void) {;}

char
yconv_uom_valid         (char a_uom)
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   char       *p           = NULL;
   --rce;  if (a_uom == 0)      return rce;
   --rce;  if (a_uom == ' ')    return rce;
   --rce;  if (a_uom == '·')    return rce;
   p = strchr (UOM_VALID, a_uom);
   --rce;  if (p      == NULL)  return rce;
   return 0;
}

char
yconv__uoms             (char a_dir, char a_uom, double *b_value, char *r_pow, double *r_scale, char r_name [LEN_TERSE], char r_sci [LEN_SHORT], char r_english [LEN_LABEL])
{
   /*---(locals)-----------+-----------+-*/
   char        rce         =  -10;
   int         i           =    0;
   char       *x_valid     = "-YZEPTGMKHD.dcmunpfazy";
   /*---(default)------------------------*/
   if (r_pow     != NULL)  *r_pow    = 0;
   if (r_scale   != NULL)  *r_scale  = 0.0;
   if (r_name    != NULL)  strcpy (r_name   , "");
   if (r_sci     != NULL)  strcpy (r_sci    , "");
   if (r_english != NULL)  strcpy (r_english, "");
   /*---(units up)-----------------------*/
   for (i = 0; i < LEN_TITLE; ++i) {
      /*---(filter)----------------------*/
      if (S_scale [i].u_uom == 0)       break;
      if (S_scale [i].u_uom != a_uom)  continue;
      /*---(handle)----------------------*/
      if (b_value   != NULL) {
         if (a_dir == '>')  *b_value /= S_scale [i].u_scale;
         if (a_dir == '<')  *b_value *= S_scale [i].u_scale;
      }
      /*---(return data)-----------------*/
      if (r_pow     != NULL)  *r_pow    = S_scale [i].u_pow;
      if (r_scale   != NULL)  *r_scale  = S_scale [i].u_scale;
      if (r_name    != NULL)  strlcpy (r_name   , S_scale [i].u_name   , LEN_TERSE);
      if (r_sci     != NULL)  strlcpy (r_sci    , S_scale [i].u_sci    , LEN_SHORT);
      if (r_english != NULL)  strlcpy (r_english, S_scale [i].u_english, LEN_LABEL);
      return 0;
      /*---(done)------------------------*/
   }
   /*---(complete)-----------------------*/
   return rce;
}



/*====================------------------------------------====================*/
/*===----                        drivers                               ----===*/
/*====================------------------------------------====================*/
static void      o___PUBLIC__________________o (void) {;}

char yconv_uoms   (char a_uom, char *r_pow, double *r_scale, char r_name [LEN_TERSE], char r_sci [LEN_SHORT], char r_english [LEN_LABEL]) { return yconv__uoms ('.', a_uom, NULL, r_pow, r_scale, r_name, r_sci, r_english); }
char yconv_2uom   (char a_uom, double *b_value)   { return yconv__uoms ('>', a_uom, b_value, NULL, NULL, NULL, NULL, NULL); }
char yconv_4uom   (char a_uom, double *b_value)   { return yconv__uoms ('<', a_uom, b_value, NULL, NULL, NULL, NULL, NULL); }



