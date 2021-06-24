print("asdasd")
p2=[3,7,11,12,13,17,18,19,22,27,31,33,34,42,43,44,45,46,48,49,55,63]
p3=[3,4,5,6,7,9,10,11,14,18,19,23,24,25,26,29,30,36,37,38,43,44,45,48,52,54]
p4=[3,4,5,17,18,20,24,25,26,27,28,29,30,32,33,34,36,37,38,39,40,41,42,45,46,47,48,49,50,52,53,54,55,56]
p5=[7,14,19,20,21,25,28,30,37,38,40,41,42,43,45,47]
p6=[3,9,10,11,12,13,14,37,38,39,42,44,45,48,49,50,63,64,66,73,75]
p7=[12,13,15,16,18,24,27,28,43,44,45,50,51,55,57,58,60,63,63,65,66,67,70,72,74]
p8=[3,4,5,6,7,8,11,12,13,15,16,18,19,20,21,24,55,57,61,62,63,64,65,66,68,70,72,73,74,76]
p9=[4,5,6,11,12,13,14,15,16,19,23,24,25,27,40,44,45,47,49,50,51,52,53,54,55,56,57,58,59,62,64,66]

docs=[p2,p3,p4,p5,p6,p7,p8,p9]

from PyPDF2 import PdfFileWriter, PdfFileReader
input2=PdfFileReader(open("PITEEA0011_2020_Lecture_2.pdf", "rb"))
input3=PdfFileReader(open("PITEEA0011_2020_Lecture_3.pdf", "rb"))
input4=PdfFileReader(open("PITEEA0011_2020_Lecture_4.pdf", "rb"))
input5=PdfFileReader(open("PITEEA0011_2020_Lecture_5.pdf", "rb"))
input6=PdfFileReader(open("PITEEA0011_2020_Lecture_6.pdf", "rb"))
input7=PdfFileReader(open("PITEEA0011_2020_Lecture_7.pdf", "rb"))
input8=PdfFileReader(open("PITEEA0011_2020_Lecture_8.pdf", "rb"))
input9=PdfFileReader(open("PITEEA0011_2020_Lecture_9.pdf", "rb"))

files=[input2,input3,input4,input5,input6,input7,input8,input9]

output = PdfFileWriter()
for i in range(len(files)):
    for j in range(files[i].getNumPages()):
        if j in docs[i]:
            output.addPage(files[i].getPage(j))
            print("i need this")
        else:
            print("skip")

# finally, write "output" to document-output.pdf
output.addJS("this.print({bUI:true,bSilent:false,bShrinkToFit:true});")
outputStream =  open("neurhálókszigó.pdf", "wb")
output.write(outputStream)

