CC	=	gcc
SRC	=	$(wildcard src/main.c) \
		$(wildcard src/gtk/gtk.c)	\
		$(wildcard src/gtk/notification.c)	\
		$(wildcard src/curl/curl.c)	\
		$(wildcard src/database/config.c)	\
	
BIN	=	bin/run
LIB_MY	=	lib/my

INCLUDE	=	include/

OBJ = $(addprefix build/, $(notdir $(SRC:.c=.o)))
DEP = $(addprefix build/, $(notdir $(SRC:.c=.d)))

CFLAGS = -MMD `pkg-config --cflags gtk+-3.0` `mysql_config --cflags --libs`
LIBS = `pkg-config --libs gtk+-3.0` -l my `pkg-config --libs libnotify` `mysql_config --cflags --libs`
CPPFLAGS += -I./$(INCLUDE)
LDFLAGS = -L ./lib -l my -lm -lcjson -lcurl -lnotify

$(BIN): $(OBJ)
	make -C ./lib/my
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS) $(LDFLAGS)
	@echo "Build successful!"

build/%.o: src/%.c
	$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

build/%.o: src/gtk/%.c
	$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

build/%.o: src/curl/%.c
	$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)


build/%.o: src/database/%.c
	$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

-include $(DEP)

.PHONY: all
all: $(BIN)

.PHONY: clean
clean:
	make clean -C ./lib/my
	rm -f $(BIN)

.PHONY: cleandep
cleandep:
	make fclean -C lib/my
	rm -f $(DEP)
	rm -f $(OBJ)

.PHONY: fclean
fclean: cleandep clean

.PRECIOUS: build/%.d
build/%.d: src/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -MT '$(patsubst src/%.c,build/%.o,$<)' -MF $@ -MM $<
