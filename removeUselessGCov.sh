#!/bin/bash
for f in *.gcov; do
	[ "$f" == '*.gcov' ] && break;
	c=${f%%.gcov}
	[ ! -f $c ] && /bin/rm "$f"
done

exit 0;
