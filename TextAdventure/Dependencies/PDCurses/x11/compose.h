/* Public Domain Curses */

/* Tables and variables for the built-in compose key system. This file 
   is not included when PDCurses is built with XIM support. */

#define MAX_COMPOSE_CHARS 14
#define MAX_COMPOSE_PRE 60

static const char *compose_chars =
    "`'~^,/\"AaPpSs!?0123CcRr-_<>Xx.=Yy |EeIiOoUu+NnLlgDd:*TtMmVv";

/*
   ` :  À  È  Ì  Ò  Ù  à  è  ì  ò  ù
   ' :  ´  Á  É  Í  Ó  Ú  Ý  á  é  í  ó  ú  ý  ´
   ~ :  Ã  Ñ  Õ  ã  ñ  õ
   ^ :  Â  Ê  Î  Ô  Û  â  ê  î  ô  û  °  ¹  ²  ³
   , :  ¸  Ç  ç  ¸
   / :  Ø  ø  µ  µ
   " :  ¨  Ä  Ë  Ï  Ö  Ü  ä  ë  ï  ö  ü  ÿ  ¨
   A :  Æ  À  Á  Ã  Â  Å  Å  Ã  Â  ª
   a :  æ  à  á  ã  â  å  å  ã  â  ª
   P :  Þ  ¶  ¶
   p :  þ  ¶  ¶
   S :  §  §  §  º  ª
   s :  ß  §  ª  ¹  ²  ³  º  §
   ! :  ¡  ¡
   ? :  ¿  ¿
   0 :  °  °
   1 :  ¹  ½  ¼  ¹
   2 :  ²  ²
   3 :  ³  ¾  ³
   C :  ©  Ç  ¢  ¢
   c :  ¢  ©  ç  ¢  ¢
   R :  ®
   r :  ®
   - :  ­  ±  ¬  ­  ¯  ÷
   _ :  ¯  ¯
   < :  «
   > :  «
   X :  ¤  ×
   x :  ×  ¤  ×
   . :  ·  ·  ·
   = :  ¥  ¥
   Y :  ¥  Ý  ¥
   y :  ¥  ý  ÿ  ¥  ¥
     :
   | :  ¦  ¢  ¦  Þ  þ  ¦  £
   E :  È  É  Ê  Ë  Ê
   e :  è  é  ê  ë  ê
   I :  Ì  Í  Î  Ï  Î
   i :  ì  í  î  ï  î
   O :  Ò  Ó  Ô  Õ  Ö  Ø  ©  ®  Õ  Ô  Å  å
   o :  °  Å  å  ¤  õ  ò  ó  ô  õ  ö  ø  ô  º
   U :  Ù  Ú  Û  Ü  Û
   u :  ù  ú  û  ü  µ  û
   + :  ±
   N :  Ñ  Ñ  ¬
   n :  ñ  ñ  ¬
   L :  £  £  £
   l :  £  £  £
   g :  ¤
   D :  °  Ð
   d :  °  ð
   : :  ÷
   * :  µ  µ  å  Å
   T :  Þ
   t :  þ
   M :  ×
   m :  ×
   V :  ¦
   v :  ¦
*/

static const char compose_lookups[MAX_COMPOSE_PRE][MAX_COMPOSE_CHARS] =
{
/* ` */ {'A','E','I','O','U','a','e','i','o','u',  0,  0,  0,  0},
/* ' */ {' ','A','E','I','O','U','Y','a','e','i','o','u','y', 39},
/* ~ */ {'A','N','O','a','n','o',  0,  0,  0,  0,  0,  0,  0,  0},
/* ^ */ {'A','E','I','O','U','a','e','i','o','u','0','1','2','3'},
/* , */ {' ','C','c',',',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* / */ {'O','o','u','U',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* " */ {' ','A','E','I','O','U','a','e','i','o','u','y','\"', 0},
/* A */ {'E','`', 39,'~','^','"','o','*','-','>','_',  0,  0,  0},
/* a */ {'e','`', 39,'~','^','"','o','*','-','>','_',  0,  0,  0},
/* P */ {' ','G','!',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* p */ {' ','g','!',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* S */ {'S','!','O','0','A',  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* s */ {'s','!','a','1','2','3','0','o',  0,  0,  0,  0,  0,  0},
/* ! */ {' ','!',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* ? */ {' ','?',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* 0 */ {'^','*',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* 1 */ {' ','2','4','^',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* 2 */ {' ','^',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* 3 */ {' ','4','^',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* C */ {'O',',','$','|',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* c */ {'|','o',',','/','$',  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* R */ {'O',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* r */ {'o',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* - */ {' ','+',',','-','^',':',  0,  0,  0,  0,  0,  0,  0,  0},
/* _ */ {'_','^',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* < */ {'<',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* > */ {'>',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* X */ {'O','X',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* x */ {' ','o','x',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* . */ {' ','^','.',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* = */ {'Y','y',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* Y */ {'=', 39,'-',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* y */ {'=', 39,'"','$','-',  0,  0,  0,  0,  0,  0,  0,  0,  0},
/*   */ {' ',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* | */ {' ','c','|','P','p','^','-',  0,  0,  0,  0,  0,  0,  0},
/* E */ {'`', 39,'^','"','>',  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* e */ {'`', 39,'^','"','>',  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* I */ {'`', 39,'^','"','>',  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* i */ {'`', 39,'^','"','>',  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* O */ {'`', 39,'^','~','"','/','C','R','-','>','A','a',  0,  0},
/* o */ {' ','A','a','x','-','`', 39,'^','~','"','/','>','_',  0},
/* U */ {'`', 39,'^','"','>',  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* u */ {'`', 39,'^','"',' ','>',  0,  0,  0,  0,  0,  0,  0,  0},
/* + */ {'-',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* N */ {'~','-','O',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* n */ {'~','-','o',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* L */ {'$','=','-',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* l */ {'$','=','-',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* g */ {'$',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* D */ {'E','-',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* d */ {'e','-',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* : */ {'-',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* * */ {'m','M','a','A',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* T */ {'H',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* t */ {'h',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* M */ {'U',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* m */ {'u',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* V */ {'B',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* v */ {'b',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
};

static const unsigned char compose_keys[MAX_COMPOSE_PRE][MAX_COMPOSE_CHARS] =
{
/* ` */ {192,200,204,210,217,224,232,236,242,249,  0,  0,  0,  0},
/* ' */ {180,193,201,205,211,218,221,225,233,237,243,250,253,180},
/* ~ */ {195,209,213,227,241,245,  0,  0,  0,  0,  0,  0,  0,  0},
/* ^ */ {194,202,206,212,219,226,234,238,244,251,176,185,178,179},
/* , */ {184,199,231,184,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* / */ {216,248,181,181,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* " */ {168,196,203,207,214,220,228,235,239,246,252,255,168,  0},
/* A */ {198,192,193,195,194,196,197,197,195,194,170,  0,  0,  0},
/* a */ {230,224,225,227,226,228,229,229,227,226,170,  0,  0,  0},
/* P */ {222,182,182,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* p */ {254,182,182,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* S */ {167,167,167,186,170,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* s */ {223,167,170,185,178,179,186,167,  0,  0,  0,  0,  0,  0},
/* ! */ {161,161,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* ? */ {191,191,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* 0 */ {176,176,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* 1 */ {185,189,188,185,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* 2 */ {178,178,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* 3 */ {179,190,179,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* C */ {169,199,162,162,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* c */ {162,169,231,162,162,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* R */ {174,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* r */ {174,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* - */ {173,177,172,173,175,247,  0,  0,  0,  0,  0,  0,  0,  0},
/* _ */ {175,175,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* < */ {171,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* > */ {187,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* X */ {164,215,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* x */ {215,164,215,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* . */ {183,183,183,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* = */ {165,165,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* Y */ {165,221,165,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* y */ {165,253,255,165,165,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/*   */ {160,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* | */ {166,162,166,222,254,166,163,  0,  0,  0,  0,  0,  0,  0},
/* E */ {200,201,202,203,202,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* e */ {232,233,234,235,234,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* I */ {204,205,206,207,206,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* i */ {236,237,238,239,238,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* O */ {210,211,212,213,214,216,169,174,213,212,197,229,  0,  0},
/* o */ {176,197,229,164,245,242,243,244,245,246,248,244,186,  0},
/* U */ {217,218,219,220,219,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* u */ {249,250,251,252,181,251,  0,  0,  0,  0,  0,  0,  0,  0},
/* + */ {177,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* N */ {209,209,172,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* n */ {241,241,172,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* L */ {163,163,163,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* l */ {163,163,163,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* g */ {164,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* D */ {176,208,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* d */ {176,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* : */ {247,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* * */ {181,181,229,197,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* T */ {222,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* t */ {254,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* M */ {215,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* u */ {215,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* V */ {166,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* v */ {166,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
};

static KeySym compose_key = 0;
static int compose_mask = 0;
