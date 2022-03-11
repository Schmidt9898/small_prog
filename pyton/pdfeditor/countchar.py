from PyPDF2 import PdfFileWriter, PdfFileReader


print("PDF char counter!")




filename="countchar.pdf"

mypdf_reader=PdfFileReader(open(filename, "rb"))

print(mypdf_reader)


words=0
char=0
spaces=0


for page in mypdf_reader.pages:
	content: str=page.extractText()
	#print(content)
	chararray=content.split("\\n")
	for s in chararray:
		#print(s)
		result = ''.join([i for i in s if not i.isdigit()])
		char+=len(result)
	#print(chararray)
	#break
	

print("Szavak száma = ",char)
	











