from bs4 import BeautifulSoup as bs
import requests
import csv 
import re 

source = requests.get("https://myanimelist.net/anime/33050/Fate_stay_night_Movie__Heavens_Feel_-_III_Spring_Song").text

soup = bs(source, 'lxml')

match1 = soup.find('div', class_='js-scrollfix-bottom-rel')
summary = str(match1.table.p.text)

def remove_all(listobj):
    temp = listobj[:]
    for val in temp:
        if str(val) == '':
            listobj.remove(val)
    for j in range(4):
        listobj.pop()
    return listobj

print(re.split(r'\s', summary))
# print(remove_all(re.split(r'\s', summary)))
# print(summary)
# print(" ".join(remove_all(re.split(r'\s',summary))))
# print(summary.split('\n'))

# synopsis = " ".join(remove_all(re.split(r'\s',summary)))
# print(synopsis)
# cred = re.search('[Written by Mal Rewrite]', synopsis)
# print(synopsis.replace('[Written by Mal Rewrite]', ''))

# match2 = soup.find('span', itemprop = "genre")
# genre = match2.text
# print(genre)

""" genres = []
gnrs = []
for gnr in soup.find_all('span', itemprop = "genre"):
    genre = gnr.text
    gnrs.append(genre)
    
print(gnrs)
gnrs_cp = gnrs[:]
genres.append(gnrs_cp)
print(genres)
gnrs.clear()
print(gnrs)
print(genres) """
    # print(genre)
