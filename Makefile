#Compiler defines
CC				= gcc
LIBDIR			= lib
INCLUDEDIR		= include
CC_FLAGS		= -Wall -L$(LIBDIR) -I$(INCLUDEDIR) -ldiscord -lcurl -pthread -g

#Project defines
NAME			= MarvC
SRCDIR			= src
MAIN			= $(SRCDIR)/marvc.c
TMPDIR			= tmp
CONCORDDIR		= concord
COREDIR			= core
GENCODECSDIR	= gencodecs
_OBJS			= commands.o arguments.o
OBJS			= $(patsubst %, $(LIBDIR)/%, $(_OBJS))

all: $(NAME)

$(LIBDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(MAIN) $^ -o $@ $(CC_FLAGS)

setup: clone
#	Make and copy Concord 
	mkdir -p $(INCLUDEDIR)/$(CONCORDDIR)
	cp -a $(TMPDIR)/$(CONCORDDIR)/$(INCLUDEDIR)/. $(INCLUDEDIR)/$(CONCORDDIR)
	(cd $(TMPDIR)/$(CONCORDDIR) && make)
	cp $(TMPDIR)/$(CONCORDDIR)/$(LIBDIR)/libdiscord.a $(LIBDIR)
#	Make and copy core to $(INCLUDEDIR)/$(CONCORDDIR)
	cp $(TMPDIR)/$(CONCORDDIR)/$(COREDIR)/*.h $(INCLUDEDIR)/$(CONCORDDIR)
	(cd $(TMPDIR)/$(CONCORDDIR)/$(COREDIR) && make)
	cp $(TMPDIR)/$(CONCORDDIR)/$(COREDIR)/*.o $(LIBDIR)
#	Make and copy gencodecs to $(INCLUDEDIR)/$(CONCORDDIR)
	cp $(TMPDIR)/$(CONCORDDIR)/$(GENCODECSDIR)/*.h $(INCLUDEDIR)/$(CONCORDDIR)
	(cd $(TMPDIR)/$(CONCORDDIR)/$(GENCODECSDIR) && make)
	cp $(TMPDIR)/$(CONCORDDIR)/$(GENCODECSDIR)/*.o $(LIBDIR)
#	Delete tmp and it's contents
	rm -r $(TMPDIR)

clone:
	@ mkdir -p $(TMPDIR)
	@ if [ ! -d $(TMPDIR)/$(CONCORDDIR) ]; then\
	(cd $(TMPDIR) && git clone https://github.com/Cogmasters/concord.git)\
	fi

#TODO: create clean task

.PHONY: setup clone