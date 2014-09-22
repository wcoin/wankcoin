#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/wankcoin.png
ICON_DST=../../src/qt/res/icons/wankcoin.ico
convert ${ICON_SRC} -resize 16x16 wankcoin-16.png
convert ${ICON_SRC} -resize 32x32 wankcoin-32.png
convert ${ICON_SRC} -resize 48x48 wankcoin-48.png
convert wankcoin-16.png wankcoin-32.png wankcoin-48.png ${ICON_DST}

