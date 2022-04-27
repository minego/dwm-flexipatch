void
remembertagsview(const Arg *arg) {
	unsigned newtags = (1 << arg->i) & TAGMASK;
	int oldtag = selmon->createtag[selmon->seltags];
	int active = (oldtag == arg->i);
	unsigned int newcreate;

	if (oldtag < NUMTAGS) {
		selmon->remembered[oldtag].tagset = selmon->tagset[selmon->seltags];
	}

	selmon->seltags ^= 1;	/*toggle tagset*/

	if (-1 == arg->i) {
		/* A specific tag was not specified */
		active = 0;
		newcreate = selmon->createtag[selmon->seltags];
	} else {
		newcreate = arg->i;
	}

	if (active) {
		/* Select twice to isolate the tag */
		selmon->tagset[selmon->seltags] = newtags;
	} else if (arg->i < NUMTAGS) {
		/* Restore whatever was previously on this tag */
		selmon->tagset[selmon->seltags] = newtags | selmon->remembered[newcreate].tagset;
	}

	selmon->createtag[selmon->seltags] = newcreate;

	focus(NULL);
	arrange(selmon);
}

