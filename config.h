/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int refresh_rate        = 60;  /* matches dwm's mouse event processing to your monitor's refresh rate for smoother window interactions */
static const unsigned int enable_noborder     = 1;   /* toggles noborder feature (0=disabled, 1=enabled) */
static const unsigned int borderpx            = 1;   /* border pixel of windows */
static const unsigned int snap                = 36;  /* snap pixel */
static const unsigned int cornerrad           = 4;
static const unsigned int gappih              = 25;
static const unsigned int gappiv              = 25;
static const unsigned int gappoh              = 25;
static const unsigned int gappov              = 25;
static const int smartgaps                    = 1;
static const int swallowfloating              = 1;   /* 1 means swallow floating windows by default */
static const unsigned int systraypinning      = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft       = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing      = 5;   /* systray spacing */
static const int systraypinningfailfirst      = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor */
static const int showsystray                  = 1;   /* 0 means no systray */
static const int showbar                      = 1;   /* 0 means no bar */
static const int topbar                       = 1;   /* 0 means bottom bar */
#define ICONSIZE                              17     /* icon size */
#define ICONSPACING                           5      /* space between icon and title */
#define SHOWWINICON                           1      /* 0 means no winicon */
static const char *fonts[]                    = { "MesloLGS Nerd Font Mono:size=16", "NotoColorEmoji:pixelsize=16:antialias=true:autohint=true" };

// Couleurs Kimbox
static const char normbordercolor[]           = "#362712"; // bg2
static const char normbgcolor[]               = "#231A0C"; // burnt_coffee
static const char normfgcolor[]               = "#C2A383"; // fg3
static const char selbordercolor[]            = "#5E452B"; // bg4
static const char selbgcolor[]                = "#5E452B"; // bg4
static const char selfgcolor[]                = "#D9AE80"; // fg0

static const char *colors[][3] = {
    /*               fg           bg           border   */
    [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
    [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor },
};

static const char *const autostart[] = {
    "xset", "s", "off", NULL,
    "xset", "s", "noblank", NULL,
    "xset", "-dpms", NULL,
    "dbus-update-activation-environment", "--systemd", "--all", NULL,
    "/usr/lib/mate-polkit/polkit-mate-authentication-agent-1", NULL,
    "flameshot", NULL,
    "dunst", NULL,
    "picom", "-b", NULL,
    "sh", "-c", "feh --randomize --bg-fill ~/Images/backgrounds/*", NULL,
/*    "synergy", NULL,*/
    "slstatus", NULL,
    NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };

static const char ptagf[] = "[%s %s]";  /* format of a tag label */
static const char etagf[] = "[%s]";     /* format of an empty tag */
static const int lcaselbl = 0;          /* 1 means make tag label lowercase */

static const Rule rules[] = {
    /* class                instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
    { "St",                 NULL,     NULL,           0,         0,          1,          0,         0 },
    { "kitty",              NULL,     NULL,           0,         0,          1,          0,         0 },
    { "Alacritty",          NULL,     NULL,           0,         0,          1,          0,         0 },
    { "terminator",         NULL,     NULL,           0,         0,          1,          0,         0 },
    { "lutris",             NULL,     NULL,           0,         1,          0,          0,         0 },
    { "steam_app_default",  NULL,     NULL,           0,         1,          0,          0,         0 },
    { "pcmanfm",            NULL,     NULL,           0,         1,          0,          0,         0 },
    { NULL,                 NULL,     "Event Tester", 0,         0,          0,          1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.6; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;   /* number of clients in master area */
static const int resizehints = 0;   /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "",      tile },    /* first entry is default */
    { "",      NULL },    /* no layout function means floating behavior */
    { "",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define STATUSBAR "dwmblocks"
/* commands */
static const char *launchercmd[] = { "rofi", "-show", "drun", NULL };
static const char *termcmd[]     = { "alacritty", NULL };

static Key keys[] = {
    /* modifier                     key                        function        argument */
    { MODKEY,                       XK_Return,                 spawn,          {.v = launchercmd} },
    { MODKEY|ControlMask,           XK_r,                      spawn,          SHCMD ("protonrestart")},
    { MODKEY,                       XK_t,                      spawn,          {.v = termcmd } },
    { MODKEY,                       XK_p,                      spawn,          SHCMD ("flameshot full -p ~/Images/")},
    { MODKEY|ShiftMask,             XK_p,                      spawn,          SHCMD ("flameshot gui -p ~/Images/")},
    { MODKEY|ControlMask,           XK_p,                      spawn,          SHCMD ("flameshot gui --clipboard")},
    { MODKEY,                       XK_c,                      spawn,          SHCMD ("looking-glass-client -F")},
    { MODKEY|ShiftMask,             XK_i,                      spawn,          SHCMD ("feh --randomize --bg-fill ~/Images/backgrounds/kimbox/*")},
    { 0,                            XF86XK_MonBrightnessUp,    spawn,          SHCMD ("xbacklight -inc 10")},
    { 0,                            XF86XK_MonBrightnessDown,  spawn,          SHCMD ("xbacklight -dec 10")},
    { 0,                            XF86XK_AudioLowerVolume,   spawn,          SHCMD ("amixer sset Master 5%- unmute")},
    { 0,                            XF86XK_AudioMute,          spawn,          SHCMD ("amixer sset Master $(amixer get Master | grep -q '\\[on\\]' && echo 'mute' || echo 'unmute')")},
    { 0,                            XF86XK_AudioRaiseVolume,   spawn,          SHCMD ("amixer sset Master 5%+ unmute")},
    { MODKEY|ShiftMask,             XK_b,                      togglebar,      {0} },
    { MODKEY|ControlMask,           XK_j,                      focusstack,     {.i = +1 } },
    { MODKEY|ControlMask,           XK_k,                      focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_j,                      movestack,      {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,                      movestack,      {.i = -1 } },
    { MODKEY,                       XK_i,                      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,                      incnmaster,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_h,                      setmfact,       {.f = -0.05} },
    { MODKEY|ShiftMask,             XK_l,                      setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask,             XK_h,                      setcfact,       {.f = +0.25} },
    { MODKEY|ShiftMask,             XK_l,                      setcfact,       {.f = -0.25} },
    { MODKEY|ShiftMask,             XK_o,                      setcfact,       {.f =  0.00} },
    { MODKEY,                       XK_Return,                 zoom,           {0} },
    { MODKEY,                       XK_Tab,                    view,           {0} },
    { MODKEY,                       XK_q,                      killclient,     {0} },
    { MODKEY|ShiftMask,             XK_t,                      setlayout,      {.v = &layouts[0]} },
    { MODKEY|ShiftMask,             XK_m,                      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,                      fullscreen,     {0} },
    { MODKEY,                       XK_space,                  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_m,                      togglefloating, {0} },
    { MODKEY|ShiftMask,             XK_y,                      togglefakefullscreen, {0} },
    { MODKEY,                       XK_equal,                  view,           {.ui = ~0 } },
    { MODKEY,                       XK_Left,                   focusmon,       {.i = -1 } },
    { MODKEY,                       XK_Right,                  focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_Left,                   tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_Right,                  tagmon,         {.i = +1 } },
    { MODKEY|ShiftMask,             XK_q,                      quit,           {0} },
    { MODKEY|ControlMask,           XK_q,                      spawn,          SHCMD("$HOME/.config/rofi/powermenu.sh")},
    { MODKEY|ControlMask|ShiftMask, XK_r,                      spawn,          SHCMD("systemctl reboot")},
    { MODKEY|ControlMask|ShiftMask, XK_s,                      spawn,          SHCMD("systemctl suspend")},
    { MODKEY,                       XK_f,                      spawn,          SHCMD("flatpak run org.mozilla.firefox") },
    { MODKEY,                       XK_b,                      spawn,          SHCMD("flatpak run com.brave.Browser") },
    { MODKEY,                       XK_w,                      spawn,          SHCMD("flatpak run io.gitlab.librewolf-community") },
    { MODKEY,                       XK_e,                      spawn,          SHCMD("pcmanfm") },
    { MODKEY,                       XK_j,                      spawn,          SHCMD("lutris") },
    { MODKEY,                       XK_s,                      spawn,          SHCMD("flatpak run com.github.micahflee.torbrowser-launcher") },
    { MODKEY,                       XK_l,                      spawn,          SHCMD("i3lock-fancy") },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    TAGKEYS(                        XK_0,                      9)
    { MODKEY,                       XK_1,      view,           {.ui = 1 << 0} },
    { MODKEY|ControlMask,           XK_1,      toggleview,     {.ui = 1 << 0} },
    { MODKEY|ShiftMask,             XK_1,      tag,            {.ui = 1 << 0} },
    { MODKEY|ControlMask|ShiftMask, XK_1,      toggletag,      {.ui = 1 << 0} },

    { MODKEY,                       XK_2,      view,           {.ui = 1 << 1} },
    { MODKEY|ControlMask,           XK_2,      toggleview,     {.ui = 1 << 1} },
    { MODKEY|ShiftMask,             XK_2,      tag,            {.ui = 1 << 1} },
    { MODKEY|ControlMask|ShiftMask, XK_2,      toggletag,      {.ui = 1 << 1} },

    { MODKEY,                       XK_3,      view,           {.ui = 1 << 2} },
    { MODKEY|ControlMask,           XK_3,      toggleview,     {.ui = 1 << 2} },
    { MODKEY|ShiftMask,             XK_3,      tag,            {.ui = 1 << 2} },
    { MODKEY|ControlMask|ShiftMask, XK_3,      toggletag,      {.ui = 1 << 2} },

    { MODKEY,                       XK_4,      view,           {.ui = 1 << 3} },
    { MODKEY|ControlMask,           XK_4,      toggleview,     {.ui = 1 << 3} },
    { MODKEY|ShiftMask,             XK_4,      tag,            {.ui = 1 << 3} },
    { MODKEY|ControlMask|ShiftMask, XK_4,      toggletag,      {.ui = 1 << 3} },

    { MODKEY,                       XK_5,      view,           {.ui = 1 << 4} },
    { MODKEY|ControlMask,           XK_5,      toggleview,     {.ui = 1 << 4} },
    { MODKEY|ShiftMask,             XK_5,      tag,            {.ui = 1 << 4} },
    { MODKEY|ControlMask|ShiftMask, XK_5,      toggletag,      {.ui = 1 << 4} },

    { MODKEY,                       XK_6,      view,           {.ui = 1 << 5} },
    { MODKEY|ControlMask,           XK_6,      toggleview,     {.ui = 1 << 5} },
    { MODKEY|ShiftMask,             XK_6,      tag,            {.ui = 1 << 5} },
    { MODKEY|ControlMask|ShiftMask, XK_6,      toggletag,      {.ui = 1 << 5} },

    { MODKEY,                       XK_7,      view,           {.ui = 1 << 6} },
    { MODKEY|ControlMask,           XK_7,      toggleview,     {.ui = 1 << 6} },
    { MODKEY|ShiftMask,             XK_7,      tag,            {.ui = 1 << 6} },
    { MODKEY|ControlMask|ShiftMask, XK_7,      toggletag,      {.ui = 1 << 6} },

    { MODKEY,                       XK_8,      view,           {.ui = 1 << 7} },
    { MODKEY|ControlMask,           XK_8,      toggleview,     {.ui = 1 << 7} },
    { MODKEY|ShiftMask,             XK_8,      tag,            {.ui = 1 << 7} },
    { MODKEY|ControlMask|ShiftMask, XK_8,      toggletag,      {.ui = 1 << 7} },

    { MODKEY,                       XK_9,      view,           {.ui = 1 << 8} },
    { MODKEY|ControlMask,           XK_9,      toggleview,     {.ui = 1 << 8} },
    { MODKEY|ShiftMask,             XK_9,      tag,            {.ui = 1 << 8} },
    { MODKEY|ControlMask|ShiftMask, XK_9,      toggletag,      {.ui = 1 << 8} },

    { MODKEY,                       XK_0,      view,           {.ui = 1 << 9} },
    { MODKEY|ControlMask,           XK_0,      toggleview,     {.ui = 1 << 9} },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = 1 << 9} },
    { MODKEY|ControlMask|ShiftMask, XK_0,      toggletag,      {.ui = 1 << 9} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
    { ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 2} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
