#define SYSTEM_TRAY_REQUEST_DOCK    0
#define _NET_SYSTEM_TRAY_ORIENTATION_HORZ 0

/* XEMBED messages */
#define XEMBED_EMBEDDED_NOTIFY      0
#define XEMBED_WINDOW_ACTIVATE      1
#define XEMBED_FOCUS_IN             4
#define XEMBED_MODALITY_ON         10

#define XEMBED_MAPPED              (1 << 0)
#define XEMBED_WINDOW_ACTIVATE      1
#define XEMBED_WINDOW_DEACTIVATE    2

#define VERSION_MAJOR               0
#define VERSION_MINOR               0
#define XEMBED_EMBEDDED_VERSION (VERSION_MAJOR << 16) | VERSION_MINOR

/* enums */
enum { Manager, Xembed, XembedInfo, XLast }; /* Xembed atoms */

typedef struct Systray Systray;
struct Systray {
	Window win;
	Client *icons;
	Monitor *mon;
};

/* bar integration */
static int width_systray(Monitor *m, BarWidthArg *a);
static int draw_systray(Monitor *m, BarDrawArg *a);
static int click_systray(Monitor *m, Arg *arg, BarClickArg *a);

/* function declarations */
static Atom getatomprop(Client *c, Atom prop);
static void removesystrayicon(Client *i);
static void resizerequest(XEvent *e);
static void updatesystray(void);
static void updatesystrayicongeom(Client *i, int w, int h);
static void updatesystrayiconstate(Client *i, XPropertyEvent *ev);
static Client *wintosystrayicon(Window w);

