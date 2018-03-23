## CORE

## Notes
*  `-fno-var-tracking` added to CXXFLAGS in Makefile to speed up compilation time immensely, as the number of symbols in CMS3.{cc,h} is large. Might have to be disabled for debugging purposes, but -O2 is used by default anyways.
* For reference, `make -j15` takes 30 seconds after this optimization. For further checks, you can include `-v -ftime-report` as extra flags to print out verbose timing information.
