#!/bin/bash

INCLUDE_DIR=include
LIB_DIR=lib
CONCORD_DIR=concord
CORE_DIR=core

if [ ! -d $LIB_DIR/$CONCORD_DIR ]; then
	(cd $LIB_DIR && git clone https://github.com/Cogmasters/concord.git)
fi

if [ -d $LIB_DIR/$CONCORD_DIR ]; then
	mkdir -p $INCLUDE_DIR/$CONCORD_DIR
	cp -a $LIB_DIR/$CONCORD_DIR/$INCLUDE_DIR/. $INCLUDE_DIR/$CONCORD_DIR
	(cd $LIB_DIR/$CONCORD_DIR && make)
	cp $LIB_DIR/$CONCORD_DIR/$LIB_DIR/libdiscord.a $LIB_DIR

	mkdir -p $INCLUDE_DIR/$CORE_DIR
	cp $LIB_DIR/$CONCORD_DIR/$CORE_DIR/*.h $INCLUDE_DIR/$CORE_DIR
	(cd $LIB_DIR/$CONCORD_DIR/$CORE_DIR && make)
	cp $LIB_DIR/$CONCORD_DIR/$CORE_DIR/*.o $LIB_DIR
	rm -r $LIB_DIR/$CONCORD_DIR
fi