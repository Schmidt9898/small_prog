print("lession 5")

import numpy as np

print(r"-*\d.*[^720p]")
print(r"(\d{3})")
print(r"([\D]*)\+|([\D]*)@")
print(r"<(\w*)")
print(r"(\w+).(jpg|png|gif)$")
print(r"List.(\w*)\((ListView.java):(\d{3,4})")



print(r"\w*.\w*@hallgato\.ppke\.hu")

print(r"^https:\/\/.*")

print(r"\[[\d,]*\]")

print(r"<b>(.*)<\/b>")

print("lines that have more than five words. I dont know")


import requests

url = 'https://en.wikipedia.org/wiki/Pythagorean_theorem'
r = requests.get(url)
#print(r.text)

import re

ret = re.findall(r"href=\"([-\w.\/:+=?]*)\"",r.text)
print("Links:")

for i in ret:
	print(i)
sum=0
for i in ret:
	if "mw-data" in i:
		sum+=1
print(sum)


