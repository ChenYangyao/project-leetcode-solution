#!/usr/bin/env bash

if [ $# -ne 2 ]
then
    echo "$0: Invalid number of arguments." >&2
    echo "... Generate problem file failed." >&2
    echo "Usage:" >&2
    echo "    ./ProblemGenerator.sh problemID website" >&2
    echo "e.g.:" >&2
    echo "    ./ProblemGenerator.sh 921 https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/" >&2
    exit 1
fi

pid=$1
webpage=$2
fname="problem$pid.md"

if [ "$(uname)" == "Darwin" ]
then
    command -v gsed >/dev/null 2>&1 || { echo "this script needs gsed!"; exit 1; }
    title=$(echo $webpage |
        cut -f 5 -d / |
        gsed -e 's/-\([[:alnum:]]\)/ \u\1/g' |
        gsed 's/^\([[:alnum:]]\)/\u\1/')
elif [ "$(uname)" == "Linux" ]
then
    title=$(echo $webpage |
        cut -f 5 -d / |
        sed -e 's/-\([[:alnum:]]\)/ \u\1/g' |
        sed 's/^\([[:alnum:]]\)/\u\1/')
else
    echo "unkown system"
fi

echo "generate file: $fname"
printf "## Problem $pid: $title\n\n" >$fname
printf "problem: [$title]($webpage)\n\n" >>$fname
printf "### Solution\n\n">>$fname
printf -- "- [Python](../python/problem$pid.py)\n\n">>$fname
printf -- "- [C++](../cpp/problem$pid.cpp)\n\n">>$fname
printf -- "- [Swift](../swift/problem$pid.swift)\n\n">>$fname
printf -- "- [Java](../java/problem$pid.java)\n\n">>$fname
printf "### Discussion\n\n" >>$fname
printf "TBD\n\n" >>$fname

echo "add problem:" $title " to README.md"
printf "[Problem $pid: $title]($fname)\n\n" >>README.md


