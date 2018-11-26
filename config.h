/* see LICENSE for copyright and license */

#ifndef CONFIG_H
#define CONFIG_H

/** modifiers **/
#define MOD1            Mod1Mask    /* ALT key */
#define MOD4            Mod4Mask    /* Super/Windows key */
#define CONTROL         ControlMask /* Control key */
#define SHIFT           ShiftMask   /* Shift key */

/** generic settings **/
#define MASTER_SIZE     0.52
#define SHOW_PANEL      False     /* show panel by default on exec */
#define TOP_PANEL       True      /* False means panel is on bottom */
#define PANEL_HEIGHT    18        /* 0 for no space for panel, thus no panel */
#define DEFAULT_MODE    FLOAT     /* initial layout/mode: TILE MONOCLE BSTACK GRID FLOAT */
#define ATTACH_ASIDE    True      /* False means new window is master */
#define FOLLOW_WINDOW   False     /* follow the window when moved to a different desktop */
#define FOLLOW_MOUSE    False     /* focus the window the mouse just entered */
#define CLICK_TO_FOCUS  True      /* focus an unfocused window when clicked  */
#define FOCUS_BUTTON    Button3   /* mouse button to be used along with CLICK_TO_FOCUS */
#define BORDER_WIDTH    0         /* window border width */
#define FOCUS           "#ffffff" /* focused window border color    */
#define UNFOCUS         "#1d383e" /* unfocused window border color  */
#define MINWSZ          50        /* minimum window size in pixels  */
#define DEFAULT_DESKTOP 0         /* the desktop to focus initially */
#define DESKTOPS        8         /* number of desktops - edit DESKTOPCHANGE keys to suit */

/**
 * open applications to specified desktop with specified mode.
 * if desktop is negative, then current is assumed
 */
static const AppRule rules[] = { \
    /*  class     desktop  follow  float */
    { "MPlayer",     3,    True,   False },
    { "Gimp",       -1,    False,  True  },
    { "Gimp",       -1,    False,  True  },
    { "Gimp",       -1,    False,  True  },
    { "Gimp",       -1,    False,  True  },
    { "Gimp",       -1,    False,  True  },
    { "Gimp",       -1,    False,  True  },
    { "Gimp",       -1,    False,  True  },
    { "Gimp",       -1,    False,  True  },
    { "Gimp",       -1,    False,  True  },
    { "Gimp",       -1,    False,  True  },
};

/* helper for spawning shell commands */
#define SHCMD(cmd) {.com = (const char*[]){"/bin/sh", "-c", cmd, NULL}}

/**
 * custom commands
 * must always end with ', NULL };'
 */
static const char *sakura[] = { "sakura", NULL };
static const char *urxvt[] = { "urxvt", NULL };
static const char *dmenu[] = { "dmenuu", NULL };
static const char *rofi[] = { "rofir", NULL };
static const char *lock[] = { "i3lock-next", NULL };
static const char *volup[] = { "volup", NULL };
static const char *voldown[] = { "voldown", NULL };
static const char *brightup[] = { "brightup", NULL };
static const char *brightdown[] = { "brightdownvolup", NULL };

#define DESKTOPCHANGE(K,N) \
    {  MOD4,             K,              change_desktop, {.i = N}}, \
    {  MOD4|ShiftMask,   K,              client_to_desktop, {.i = N}},

/**
 * keyboard shortcuts
 */
static Key keys[] = {
    /* modifier          key            function           argument */
    {  MOD1,             XK_b,          togglepanel,       {NULL}},
    {  MOD1,             XK_BackSpace,  focusurgent,       {NULL}},
    {  MOD4|SHIFT,       XK_q,          killclient,        {NULL}},
    {  MOD1,             XK_Tab,        next_win,          {NULL}},
    {  MOD1,             XK_k,          prev_win,          {NULL}},
    {  MOD1,             XK_h,          resize_master,     {.i = -10}}, /* decrease size in px */
    {  MOD1,             XK_l,          resize_master,     {.i = +10}}, /* increase size in px */
    {  MOD1,             XK_o,          resize_stack,      {.i = -10}}, /* shrink   size in px */
    {  MOD1,             XK_p,          resize_stack,      {.i = +10}}, /* grow     size in px */
    {  MOD1|CONTROL,     XK_h,          rotate,            {.i = -1}},
    {  MOD1|CONTROL,     XK_l,          rotate,            {.i = +1}},
    {  MOD1|SHIFT,       XK_h,          rotate_filled,     {.i = -1}},
    {  MOD1|SHIFT,       XK_l,          rotate_filled,     {.i = +1}},
    {  MOD4,             XK_Tab,        last_desktop,      {NULL}},
    {  MOD1,             XK_Return,     swap_master,       {NULL}},
    {  MOD4|SHIFT,       XK_j,          move_down,         {NULL}},
    {  MOD4|SHIFT,       XK_k,          move_up,           {NULL}},
    {  MOD4|SHIFT,       XK_t,          switch_mode,       {.i = TILE}},
    {  MOD4|SHIFT,       XK_m,          switch_mode,       {.i = MONOCLE}},
    {  MOD4|SHIFT,       XK_b,          switch_mode,       {.i = BSTACK}},
    {  MOD4|SHIFT,       XK_g,          switch_mode,       {.i = GRID}},
    {  MOD4|SHIFT,       XK_f,          switch_mode,       {.i = FLOAT}},
    {  MOD1|CONTROL,     XK_r,          quit,              {.i = 0}}, /* quit with exit value 0 */
    {  MOD1|CONTROL,     XK_q,          quit,              {.i = 1}}, /* quit with exit value 1 */
    {  MOD4,             XK_Return,     spawn,             {.com = urxvt}},
    {  MOD4|SHIFT,       XK_Return,     spawn,             {.com = sakura}},
    {  MOD4,             XK_z,          spawn,             {.com = rofi}},
    {  MOD4,             XK_d,          spawn,             {.com = dmenu}},
    {  MOD4,             XK_ccedilla,   spawn,             {.com = lock}},
    {  MOD4,             XK_F12,        spawn,             {.com = volup}},
    {  MOD4,             XK_F11,        spawn,             {.com = voldown}},
    {  MOD4,             XK_F10,        spawn,             {.com = brightup}},
    {  MOD4,             XK_F9,         spawn,             {.com = brightdown}},
    {  MOD4,             XK_Down,       moveresize,        {.v = (int []){   0,  25,   0,   0 }}}, /* move down  */
    {  MOD4,             XK_Up,         moveresize,        {.v = (int []){   0, -25,   0,   0 }}}, /* move up    */
    {  MOD4,             XK_Right,      moveresize,        {.v = (int []){  25,   0,   0,   0 }}}, /* move right */
    {  MOD4,             XK_Left,       moveresize,        {.v = (int []){ -25,   0,   0,   0 }}}, /* move left  */
    {  MOD4|SHIFT,       XK_Down,       moveresize,        {.v = (int []){   0,   0,   0,  25 }}}, /* height grow   */
    {  MOD4|SHIFT,       XK_Up,         moveresize,        {.v = (int []){   0,   0,   0, -25 }}}, /* height shrink */
    {  MOD4|SHIFT,       XK_Right,      moveresize,        {.v = (int []){   0,   0,  25,   0 }}}, /* width grow    */
    {  MOD4|SHIFT,       XK_Left,       moveresize,        {.v = (int []){   0,   0, -25,   0 }}}, /* width shrink  */
       DESKTOPCHANGE(    XK_ampersand,                     0)
       DESKTOPCHANGE(    XK_eacute,                        1)
       DESKTOPCHANGE(    XK_quotedbl,                      2)
       DESKTOPCHANGE(    XK_apostrophe,                    3)
       DESKTOPCHANGE(    XK_parenleft,                     4)
       DESKTOPCHANGE(    XK_minus,                         5)
       DESKTOPCHANGE(    XK_egrave,                        6)
       DESKTOPCHANGE(    XK_underscore,                    7)
    // DESKTOPCHANGE(    XK_ccedilla,                      8)
    // DESKTOPCHANGE(    XK_agrave,                        9)
};

/**
 * mouse shortcuts
 */
static Button buttons[] = {
    {  MOD1,    Button1,     mousemotion,   {.i = MOVE}},
    {  MOD1,    Button3,     mousemotion,   {.i = RESIZE}},
};
#endif

/* vim: set expandtab ts=4 sts=4 sw=4 : */
