import PyPDF2
import tabula
import pandas as pd
from pandas import DataFrame
#create file object variable
#opening method will be rb
pdffileobj=open('test.pdf','rb')
#df = tabula.read_pdf("test.pdf", multiple_tables=True)
#tabula.convert_into("test.pdf", "test.csv", output_format="csv")
tb = []
dfs = tabula.read_pdf("test.pdf", encoding='utf-8', stream=True, pages='all', format="CSV")
tabula.io.convert_into("test.pdf", "test.csv", output_format='csv', java_options=None)

print(dfs)



dfs[0].to_csv("test.csv")

#create reader variable that will read the pdffileobj
pdfreader=PyPDF2.PdfFileReader(pdffileobj)

#This will store the number of pages of this pdf file
x=pdfreader.numPages
if pdfreader.isEncrypted:
    pdfreader.decrypt('')
#create a variable that will select the selected number of pages
for i in range(x):
    pageobj=pdfreader.getPage(i)

    #(x+1) because python indentation starts with 0.
    #create text variable which will store all text datafrom pdf file
    text=pageobj.extractText()


    #save the extracted data from pdf to a txt file
    #we will use file handling here
    #dont forget to put r before you put the file path
    #go to the file location copy the path by right clicking on the file
    #click properties and copy the location path and paste it here.
    #put "\\your_txtfilename"
    file1=open(r"text.txt","a")
    file1.writelines(text)
