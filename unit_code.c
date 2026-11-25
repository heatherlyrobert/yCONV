/*============================[[    beg-code    ]]============================*/
/*········´ ´·············headers·´ ´·········································*/
#include    "yCONV.h"
#include    "yCONV_priv.h"
/*········´ ´·····················´ ´·········································*/



char       /*----: set up program urgents/debugging --------------------------*/
yCONV_unit_quiet        (void)
{
   return 0;
}

char       /*----: set up program urgents/debugging --------------------------*/
yCONV_unit_loud         (void)
{
   yLOGS_begin ("yCONV" , YLOG_SYS, YLOG_NOISE);
   yURG_by_name  ("kitchen"      , YURG_ON);
   /*> yURG_by_name  ("yconv"        , YURG_ON);                                      <*/
   /*> DEBUG_YSTR   yLOG_info     ("ySTR"    , ySTR_version   ());                    <*/
   return 0;
}

char       /*----: stop logging ----------------------------------------------*/
yCONV_unit_end          (void)
{
   DEBUG_YSTR  yLOGS_end     ();
   return 0;
}

