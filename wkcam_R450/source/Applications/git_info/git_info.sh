#!/bin/sh
#if ( [ -d ../.git ] || [ -d ./.git ]) then
CURR_PATH=`pwd`
MAIN_PATH=$(dirname `pwd`)
MAIN_PATH=$(dirname $MAIN_PATH)
echo "CURR_PATH = $CURR_PATH"
echo "MAIN_PATH = $MAIN_PATH"
git config --global --add safe.directory ${MAIN_PATH}

COMMIT_ID=`git log --oneline -n 1 --pretty=format:%h`
COMMIT_TIME=`git log --oneline -n 1 --pretty=format:%cd --date=local --date=format:'%Y-%m-%d %H:%M'`
CURR_DATE=`date "+%Y-%m-%d %H:%M"`

echo "set commit id $COMMIT_ID"
echo "set commit time $COMMIT_TIME"
echo "set compiling time $CURR_DATE"

version_info=`cat ${CURR_PATH}/Applications/git_info/conf_git_info.h | sed "s/RevTag/$COMMIT_ID/g" | sed "s/RevTIME/$COMMIT_TIME/g" | sed "s/RevCOMPLIE/$CURR_DATE/g"`
echo "$version_info" > ${CURR_PATH}/Applications/git_info/git_info.h
#fi
