#! /usr/bin/make -rRf
#?
#? NAME
#?      Makefile.inc    - define missing macros for Makefile
#?
#? SYNOPSYS
#?      ifndef ALL.Makefiles
#?          include Makefile.inc
#?      endif
#?
#? DESCRIPTION
#?      Defines general macros used in Makefile if they are missing.
#?
#? VERSION
#?      @(#) Makefile.inc 1.8 18/08/21 00:55:00
#?
#? AUTHOR
#?      18-may-18 Achim Hoffmann
#?
# -----------------------------------------------------------------------------

_SID.inc        = 1.8

ALL.includes   += t/Makefile.inc

#_____________________________________________________________________________
#________________________________________________________________ variables __|

# NOTE: all definitions herein should be idempotent, so that this file could be
#       included sevaral times. That's why only  =  and no  +=  assignments are
#       used.

ifndef Project
    Project     = o-saft
endif

ifndef ProjectName
    ProjectName = O-Saft
endif

ifndef TEST.host
    TEST.host   = localhost
endif

ifndef TEST.init
    TEST.init   = --header
endif

ifndef TEST.dir
    TEST.dir    = t
endif

ifndef TEST.logdir
    TEST.logdir = $(TEST.dir)/log
endif

ifndef TMP.dir
    TMP.dir     = /tmp/$(Project)
endif

ifndef SRC.pl
    SRC.pl      = o-saft.pl
endif

ifndef SRC.cgi
    SRC.cgi     = o-saft.cgi
endif

ifndef SRC.tcl
    SRC.tcl     = o-saft.tcl
endif

ifndef MAKEFILE
    MAKEFILE    = $(firstword $(MAKEFILE_LIST))
    # define variable for myself, its the first file in MAKEFILE_LIST, usually
    # $(MAKEFILE)  will be used where any makefile is possible,  and  Makefile
    # is used when exactly Makefile file is meant.  $(ALL.Makefiles)  is used,
    # when all makefiles are needed.  Existance of  ALL.Makefiles  can also be
    # used to check if this file should be included.
endif

ifndef ALL.Makefiles
    MAKE        = $(MAKE_COMMAND) -f $(firstword $(MAKEFILE_LIST))
        # redefine  MAKE  with proper makefile if not called from  ../Makefile
        # makefile given with -f option is first in  MAKEFILE_LIST, usually
endif

# internal used tools (paths hardcoded!)
ifndef MAKE
    MAKE        = $(MAKE_COMMAND)
endif

ifndef ECHO
    ECHO        = /bin/echo -e
endif

ifndef EXE.pl
    EXE.pl      = o-saft.pl
endif

ifndef TAB
    TAB         = \\011
endif

ifndef _NL
    _NL         = \\012
endif

ifndef _CR
    _CR         = \\015
endif
