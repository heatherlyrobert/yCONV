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
/*===----                         debugging support                    ----===*/
/*====================------------------------------------====================*/
static void      o___DEBUGGING_______________o (void) {;}

char        yCONV_ver     [500];

char*
yCONV_version           (void)
{
   char    t [20] = "";
#if    __TINYC__ > 0
   strlcpy (t, "[tcc built  ]", 15);
#elif  __GNUC__  > 0
   strlcpy (t, "[gnu gcc    ]", 15);
#elif  __HEPH__  > 0
   strncpy (t, "[hephaestus ]", 15);
#else
   strlcpy (t, "[unknown    ]", 15);
#endif
   snprintf (yCONV_ver, 100, "%s   %s : %s", t, P_VERNUM, P_VERTXT);
   return yCONV_ver;
}



/*====================------------------------------------====================*/
/*===----                      validation support                      ----===*/
/*====================------------------------------------====================*/
static void      o___VALIDATION______________o (void) {;}

char
yconv_format_valid      (char a_fmt, char *r_range)
{
   char        rce         =  -10;
   char       *x_valid     = "?··yY·bB·oO·xX·zZ·  rR·tTdD··if·IF,·aA$·sS·cC#·pP·eE";
   /*---(default)------------------------*/
   if (r_range != NULL)  *r_range = '-';
   /*---(defense)------------------------*/
   --rce;  if (a_fmt == 0)           return rce;
   --rce;  if (a_fmt == ' ')         return rce;
   --rce;  if (a_fmt == '·')         return rce;
   /*---(check)--------------------------*/
   if (strchr (x_valid, a_fmt) == 0) return rce;
   /*---(save-back)----------------------*/
   if (r_range != NULL) {
      if      (strchr ("bBoOxXzZ", a_fmt) != NULL)  *r_range = 'u';
      else if (strchr ("rR"      , a_fmt) != NULL)  *r_range = 'r';
      else                                          *r_range = 'd';
   }
   /*---(complete)-----------------------*/
   return 0;
}

char
yconv_count_valid       (char a_cnt)
{
   char        rce         =  -10;
   --rce;  if (a_cnt < 0)  return rce;
   --rce;  if (a_cnt > 9)  return rce;
   return 0;
}



/*===[[ END ]]================================================================*/
