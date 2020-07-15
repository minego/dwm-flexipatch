int
width_stbutton(Monitor *m, BarWidthArg *a)
{
	return TEXTW(buttonbar);
}

int
draw_stbutton(Monitor *m, BarDrawArg *a)
{
	#if BAR_PANGO_PATCH
	return drw_text(drw, a->x, 0, a->w, bh, lrpad / 2, buttonbar, 0, False);
	#else
	return drw_text(drw, a->x, 0, a->w, bh, lrpad / 2, buttonbar, 0);
	#endif // BAR_PANGO_PATCH
}

int
click_stbutton(Monitor *m, Arg *arg, BarClickArg *a)
{
	return ClkButton;
}
