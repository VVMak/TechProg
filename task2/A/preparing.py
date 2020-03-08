from sys import argv
script, path = argv
f = open(path + 'index.h','w')
code = "class A{\npublic:    int gcd( int a, int b );\n};\n"
f.write( code )
f.close();

