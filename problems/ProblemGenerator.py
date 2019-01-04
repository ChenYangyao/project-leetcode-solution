#! /usr/bin/python3

import sys
class ProblemGenerator:
    def __init__(self, pid, web):
        self.web = web
        self.pid = pid
        self.title = self.getTitle()

        fname = "problem%d.md"%self.pid
        f = open( fname, 'w' )
        f.write( self.getProblemFileString() )
        f.close()
        print("Generate problem file %s done!"%fname)

        f = open( "README.md", 'a' )
        f.write( self.getReadmeString() )
        f.close()
        print("Modify README.md done!")
    def getTitle(self):
        return ' '.join(self.web.strip('/').split(sep='/')[-1].split('-')).title()
    def getProblemFileString(self):
        s = "## Problem %d: %s\n\n"%(self.pid, self.title)
        s += "problem: [%s](%s)\n\n"%(self.title, self.web)
        s += "### Solution\n\n"
        s += self.getSolution('python','python','py')
        s += self.getSolution('c++','cpp','cpp')
        s += self.getSolution('swift','swift','swift')
        s += self.getSolution('java','java','java')
        s += "### Discussion\n\nTBD\n\n"
        return s
    def getSolution(self, lang, folder ,postfix):
        return "- [%s](../%s/problem%d.%s)\n\n"%( lang.capitalize(), folder, self.pid, postfix )
    def getReadmeString(self):
        return "[Problem %d: %s](problem%d.md)\n\n"%(self.pid, self.title, self.pid)

if len(sys.argv) != 3:
    print("invalid number of args? generate problem failed\n... check it!")
    print("Usage:")
    print("    ./ProblemGenerator.py problemID website")
    print("e.g.:")
    print("    ./ProblemGenerator.py 921 https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/")
    sys.exit(1)

pid = int(sys.argv[1])
web = sys.argv[2]
pg = ProblemGenerator( pid, web )
