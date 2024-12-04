/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };

/* rules */
static const Rule rules[] = {
    /* class                instance         title           tags mask  isfloating  isterminal  noswallow  monitor */
    { "Alacritty",          NULL,            NULL,           1 << 1,    0,          1,          0,         -1 },
    { "firefox",            NULL,            NULL,           1 << 2,    0,          0,          -1,        -1 },
    { "librewolf",          NULL,            NULL,           1 << 3,    0,          0,          -1,        -1 },
    { "Tor Browser",        NULL,            NULL,           1 << 4,    0,          0,          -1,        -1 },
    { "Pcmanfm",            NULL,            NULL,           1 << 5,    0,          0,          -1,        -1 },
    { "lutris",             NULL,            NULL,           1 << 8,    1,          0,          -1,        -1 },
    { "Gimp",               NULL,            NULL,           1 << 7,    1,          0,          -1,        -1 },
    { NULL,                 NULL,            "Event Tester", 0,         0,          0,          1,        -1 },
};

/* key definitions */
static Key keys[] = {
    /* modifier                     key                        function        argument */
    { MODKEY,                       XK_t,                      spawn,          SHCMD("alacritty") },
    { MODKEY,                       XK_f,                      spawn,          SHCMD("flatpak run org.mozilla.firefox") },
    { MODKEY,                       XK_w,                      spawn,          SHCMD("flatpak run io.gitlab.librewolf-community") },
    { MODKEY,                       XK_e,                      spawn,          SHCMD("pcmanfm") },
    { MODKEY,                       XK_s,                      spawn,          SHCMD("flatpak run com.github.micahflee.torbrowser-launcher") },
    { MODKEY,                       XK_j,                      spawn,          SHCMD("lutris") },
    { MODKEY,                       XK_g,                      spawn,          SHCMD("gimp") },
    { MODKEY,                       XK_l,                      spawn,          SHCMD("betterlockscreen -l blur --blur 0.7") },

    /* Window manipulation (Windows-like shortcuts) */
    { MODKEY,                       XK_Left,                   setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_Right,                  setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Up,                     zoom,           {0} },
    { MODKEY,                       XK_Down,                   setlayout,      {.v = &layouts[0]} },
    { MODKEY|ShiftMask,             XK_Left,                   tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_Right,                  tagmon,         {.i = +1 } },

    /* Launcher and fullscreen */
    { MODKEY,                       XK_Return,                 spawn,          {.v = launchercmd } },
    { MODKEY,                       XK_m,                      setlayout,      {.v = &layouts[2]} },

    /* View all tags */
    { MODKEY,                       XK_equal,                  view,           {.ui = ~0 } },

    /* Tag keys */
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
};

/* Autostart */
static const char *const autostart[] = {
    "feh", "--bg-fill", "~/Pictures/Wallpapers/wallpaper.jpg", NULL,
    "slstatus", NULL,
    NULL
};
