#!/usr/bin/python
import sys
USAGE = 'file2str a.glsl'

DEFAULT_PATH = 'app\src\main\cpp\shaders\\'
def toStr(line):
    out_str=''
    if '\n' in line:
        out_str = '"'+line[:-1]+'\\n"'+line[-1]
    else:
        out_str = '"'+line+'\\n"'
    return out_str
if __name__ == '__main__':
    if(len(sys.argv) != 2):
        print USAGE
        exit()
    input_file = DEFAULT_PATH + sys.argv[1]
    output_file = DEFAULT_PATH + sys.argv[1] +'.in'
    f_input = open(input_file, "r")
    f_output = open(output_file,'w')
    for line in f_input:
        f_output.write(toStr(line))
    f_input.close()
    f_output.close()