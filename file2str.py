#!/usr/bin/python
import sys,os
USAGE = 'file2str [a|a.glsl]'

DEFAULT_PATH = 'app\src\main\cpp\shaders\\'
OUT_PATH = DEFAULT_PATH + 'include\\'

GLSL_SUFFIX = '.glsl'
INC_SUFFIX  = ".in"

def genInclude(file_in, file_out):
    print 'processing:',file_in
    f_input = open(file_in, "r")
    f_output = open(file_out,'w')
    for line in f_input:
        f_output.write(toStr(line))
    f_input.close()
    f_output.close()
def toStr(line):
    out_str=''
    if '\n' in line:
        out_str = '"'+line[:-1]+'\\n"'+line[-1]
    else:
        out_str = '"'+line+'\\n"'
    return out_str
if __name__ == '__main__':
    arg_length = len(sys.argv)
    if(arg_length > 2 or arg_length <=0):
        print USAGE
        exit()

    if arg_length == 1:
        #process all files end with .glsl
        all_files = os.listdir(DEFAULT_PATH)
        #print all_files
        for file in all_files:
            if file.endswith(GLSL_SUFFIX):
                genInclude(DEFAULT_PATH + file, OUT_PATH + file + INC_SUFFIX)
    elif arg_length == 2:
        #process a prefix match
        all_files = os.listdir(DEFAULT_PATH)
        for file in all_files:
            if file.startswith(sys.argv[1]):
                genInclude(DEFAULT_PATH + file, OUT_PATH + file + INC_SUFFIX)
    else:
        pass