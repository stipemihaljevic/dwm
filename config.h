/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int refresh_rate		= 60;				/* matches dwm's mouse event processing to your monitor's refresh rate for smoother window interactions */
static const unsigned int enable_noborder 	= 0;				/* toggles noborder feature (0=disabled, 1=enabled) */
static const unsigned int borderpx  		= 0;	        		/* border pixel of windows */
static const unsigned int snap 			= 32;  				/* snap pixel */
static const int swallowfloating          	= 1;		      		/* 1 means swallow floating windows by default */
static const unsigned int systraypinning  	= 1;      			/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft   	= 0;      			/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing  	= 2;      			/* systray spacing */
static const int systraypinningfailfirst  	= 1;      			/* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray              	= 1;      			/* 0 means no systray */
static const int showbar            		= 1;        			/* 0 means no bar */
static const int topbar             		= 1;        			/* 0 means bottom bar */
static const Bool viewontag              	= True;   			/* Switch view on tag switch */
static const char *fonts[]          		= { "MesloLGS Nerd Font Mono:size=16", "NotoColorEmoji:pixelsize=16:antialias=true:autohint=true"  };
static const char dmenufont[]       		= "MesloLGS Nerd Font Mono:size=14";
static const char col_1[]       = "#000000";
static const char col_2[]       = "#FFFFFF";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_2,     col_1,     col_1 },
	[SchemeSel]  = { col_2,     col_1,     col_1 },
};

static const char *const autostart[] = {
  "xsetroot", "-cursor_name", "left_ptr", NULL,
  "xset", "s", "off", NULL,
  "xset", "s", "noblank", NULL,
  "xset", "-dkms", NULL,
  "dbus-update-activation-environment", "--systemd", "--all", NULL,
  "sh", "-c", "/opt/git/dwm/scripts/status", NULL,
  "sh", "-c", "feh --randomize --bg-fill /opt/git/backgrounds/*", NULL,
  "dunst", NULL,
  "picom", NULL,
  NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };

static const char ptagf[] = "[%s %s]";  /* format of a tag label */
static const char etagf[] = "[%s]";     /* format of an empty tag */
static const int lcaselbl = 0;          /* 1 means make tag label lowercase */

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class     instance     title           tags mask     isfloating    monitor */
    { "St",      NULL,        NULL,           0,            0,            -1 },
    { "kitty",   NULL,        NULL,           0,            0,            -1 },
};


/* layout(s) */
static const float mfact     = 0.70; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */


static const Layout layouts[] = {
	/* symbol arrange function */
	{ "",	    tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "󰖯",      monocle },
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

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_1, "-nf", col_2, "-sb", col_1, "-sf", col_2, NULL };
static const char *termcmd[]  = { "kitty", NULL };

static const Key keys[] = {
	/* modifier                     	key        	function        	argument */
	{ MODKEY,                       	XK_r,      	spawn,          	{.v = dmenucmd } },
	{ MODKEY,		       		XK_x,	 	spawn,          	{.v = termcmd } },
	{ MODKEY,				XK_e,		spawn,			SHCMD ("thunar") },
	{ MODKEY,				XK_p,		spawn,			SHCMD ("pavucontrol") },
	{ MODKEY,                       	XK_b,      	spawn,      		SHCMD ("xdg-open https:")},
	{ 0,                            	0x1008ff02,	spawn,      		SHCMD ("brightnessctl s +10%")},
	{ 0,                            	0x1008ff03,	spawn,      		SHCMD ("brightnessctl s 10%-")},
	{ 0,					0x1008ff12,	spawn,			SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle") },
	{ 0,					0x1008ff11,	spawn,			SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5%") },
	{ 0,					0x1008ff13,	spawn,			SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5%") },
	{ MODKEY,	                 	XK_f,      	togglebar,      	{0} },
	{ MODKEY,                       	XK_j,      	focusstack,     	{.i = +1 } },
	{ MODKEY,                       	XK_k,      	focusstack,     	{.i = -1 } },
	{ MODKEY,                       	XK_i,      	incnmaster,     	{.i = +1 } },
	{ MODKEY,                       	XK_d,      	incnmaster,     	{.i = -1 } },
	{ MODKEY,                       	XK_h,      	setmfact,       	{.f = -0.05} },
	{ MODKEY,                       	XK_l,      	setmfact,       	{.f = +0.05} },
	{ MODKEY|ShiftMask,			XK_h,		setcfact,		{.f = +0.25} },
	{ MODKEY|ShiftMask,			XK_l,		setcfact,		{.f = -0.25} },
	{ MODKEY|ShiftMask,			XK_o,		setcfact,		{.f =  0.00} },
	{ MODKEY,                       	XK_Return, 	zoom,           	{0} },
	{ MODKEY,                       	XK_Tab,    	view,           	{0} },
	{ MODKEY,                       	XK_q,		killclient,         	{0} },
	{ MODKEY,                       	XK_t,      	setlayout,      	{.v = &layouts[0]} },
	{ MODKEY,                       	XK_f,      	setlayout,      	{.v = &layouts[1]} },
	{ MODKEY,                       	XK_m,      	fullscreen,      	{.v = &layouts[2]} },
	{ MODKEY,                       	XK_space,  	setlayout,      	{0} },
	{ MODKEY|ShiftMask,             	XK_space,  	togglefloating, 	{0} },
	{ MODKEY,                       	XK_0,      	view,           	{.ui = ~0 } },
	{ MODKEY|ShiftMask,             	XK_0,      	tag,            	{.ui = ~0 } },
	{ MODKEY,                       	XK_comma,  	focusmon,       	{.i = -1 } },
	{ MODKEY,                       	XK_period, 	focusmon,       	{.i = +1 } },
	{ MODKEY|ShiftMask,             	XK_comma,  	tagmon,         	{.i = -1 } },
	{ MODKEY|ShiftMask,             	XK_period, 	tagmon,         	{.i = +1 } },
	TAGKEYS(                        	XK_1,                      		0)
	TAGKEYS(                        	XK_2,                      		1)
	TAGKEYS(                        	XK_3,                      		2)
	TAGKEYS(                        	XK_4,                     		3)
	TAGKEYS(                        	XK_5,                     		4)
	TAGKEYS(                        	XK_6,                     		5)
	{ MODKEY|ShiftMask|ControlMask,		XK_q,      	quit,           	{0} },
	{ MODKEY|ControlMask|ShiftMask, 	XK_r,		spawn,              	SHCMD("systemctl reboot")},
	{ MODKEY|ControlMask|ShiftMask, 	XK_p,       	spawn,              	SHCMD("systemctl poweroff")},
	{ MODKEY|ControlMask|ShiftMask, 	XK_s,	    	spawn,       	    	SHCMD("systemctl suspend")},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 2} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

