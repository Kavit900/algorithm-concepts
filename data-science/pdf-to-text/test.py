'''
pip install --upgrade convertapi
'''

import convertapi
from os import path
from glob import glob
def find_ext(dr, ext):
    return glob(path.join(dr,"*.{}".format(ext)))

convertapi.api_secret = 'w9WaftMCWV2LY92i'

pdf_list = find_ext(".","pdf")

for i in pdf_list:
    file_name = i
    text_file_name = i+'.txt'
    convertapi.convert('txt', {
        'File': 'test.pdf',
    }, from_format = 'pdf').save_files(text_file_name)
