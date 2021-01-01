from bs4 import BeautifulSoup as bs
# from lxml import html
import requests
import csv 
import re 

source = requests.get("https://myanimelist.net/anime/37491/Gintama__Shirogane_no_Tamashii-hen_-_Kouhan-sen").text

soup = bs(source, 'lxml')

match1 = soup.find('div', class_='js-scrollfix-bottom-rel')
summary = str(match1.table.p.text)

def remove_all(listobj):
    temp = listobj[:]
    for val in temp:
        if str(val) == '':
            listobj.remove(val)
    if "(Source:" in listobj:
        listobj.pop()
        listobj.pop()
    elif "[Written" in listobj:
        listobj.pop()
        listobj.pop()
        listobj.pop()
        listobj.pop()
    return listobj

# print(re.split(r'\s', summary))
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

genre_1 = []
genre_2 = []
genre_3 = []
genre_4 = []
genre_5 = []
genre_6 = []
genre_7 = []
genre_8 = []

def add_genres(gnrs):
    genre_1.append(gnrs[0])

    if len(gnrs) == 2:
        genre_2.append(gnrs[1])
        genre_3.append(None)
        genre_4.append(None)
        genre_5.append(None)
        genre_6.append(None)
        genre_7.append(None)
        genre_8.append(None)

    if len(gnrs) == 3:
        genre_2.append(gnrs[1])
        genre_3.append(gnrs[2])
        genre_4.append(None)
        genre_5.append(None)
        genre_6.append(None)
        genre_7.append(None)
        genre_8.append(None)
    
    if len(gnrs) == 4:
        genre_2.append(gnrs[1])
        genre_3.append(gnrs[2])
        genre_4.append(gnrs[3])
        genre_5.append(None)
        genre_6.append(None)
        genre_7.append(None)
        genre_8.append(None)

    if len(gnrs) == 5:
        genre_2.append(gnrs[1])
        genre_3.append(gnrs[2])
        genre_4.append(gnrs[3])
        genre_5.append(gnrs[4])
        genre_6.append(None)
        genre_7.append(None)
        genre_8.append(None)

    if len(gnrs) == 6:
        genre_2.append(gnrs[1])
        genre_3.append(gnrs[2])
        genre_4.append(gnrs[3])
        genre_5.append(gnrs[4])
        genre_6.append(gnrs[5])
        genre_7.append(None)
        genre_8.append(None)

    if len(gnrs) == 7:
        genre_2.append(gnrs[1])
        genre_3.append(gnrs[2])
        genre_4.append(gnrs[3])
        genre_5.append(gnrs[4])
        genre_6.append(gnrs[5])
        genre_7.append(gnrs[6])
        genre_8.append(None)

    if len(gnrs) == 8:
        genre_2.append(gnrs[1])
        genre_3.append(gnrs[2])
        genre_4.append(gnrs[3])
        genre_5.append(gnrs[4])
        genre_6.append(gnrs[5])
        genre_7.append(gnrs[6])
        genre_8.append(gnrs[7])



""" genres = []
gnrs = []
for gnr in soup.find_all('span', itemprop = "genre"):
    gnrs.append(gnr.text)
    
add_genres(gnrs)
print(genre_1, genre_4, genre_8)
gnrs.clear()
print(genre_1, genre_4, genre_8) """

""" print(gnrs)
gnrs_cp = gnrs[:]
genres.append(gnrs_cp)
print(genres)
gnrs.clear()
print(gnrs)
print(genres) """


def convtomins(hr, minute):
    mins = 0
    if hr == 'hr':
        mins += int(hr)*60 
    if minute == 'min':
        mins += int(minute)
    return mins

test_source = requests.get("https://myanimelist.net/anime/2904/Code_Geass__Hangyaku_no_Lelouch_R2").text
testsoup = bs(test_source, 'lxml')

test_source2 = requests.get("https://myanimelist.net/anime/32935/Haikyuu__Karasuno_Koukou_vs_Shiratorizawa_Gakuen_Koukou").text
testsoup2 = bs(test_source2, 'lxml')

test_source3 = requests.get("https://myanimelist.net/anime/37491/Gintama__Shirogane_no_Tamashii-hen_-_Kouhan-sen").text
testsoup3 = bs(test_source3, 'lxml')

test_source4 = requests.get("https://myanimelist.net/anime/37510/Mob_Psycho_100_II").text
testsoup4 = bs(test_source4, 'lxml')

test_source5 = requests.get("https://myanimelist.net/anime/199/Sen_to_Chihiro_no_Kamikakushi").text
testsoup5 = bs(test_source5, 'lxml')

for item in testsoup3.find_all('td', class_ = 'borderClass'):
    if re.search(r"(Spring|Summer|Fall|Winter).\d{4}", item.text) != None:
        print(re.search(r"(Spring|Summer|Fall|Winter).\d{4}", item.text).group(1))


for item in testsoup3.find_all('td', class_ = 'borderClass'):
    eplen = re.search(r"(\d{1,2})\s(\w+)\.\s?([a-z0-9]+)\s?(\w+)\.?", item.text)
    if eplen != None:
        print(eplen)
        # print(convtomins(eplen.group(2), eplen.group(4)))

for item in testsoup3.find_all('td', class_ = 'borderClass'):
    agrating = re.search(r"(R|PG)(\s|\+|-)+([0-9+]{2,3})?", item.text)
    if agrating != None:
        if agrating.group(3) != None:
            print(agrating.group(1) + agrating.group(3))
        elif agrating.group(1) == "PG" and agrating.group(3) == None:
            print(agrating.group(1))

for item in testsoup3.find_all('td', class_ = 'borderClass'):
    if re.search(r"(Manga|Visual novel|Game|Original)\s{2}", item.text) != None:
        print(re.search(r"(Manga|Visual novel|Game|Original)\s{2}", item.text).group(1))

""" seasons = []
ep_lens = []
age_ratings = []
materials = []

foundseason = False
foundeplen = False
foundagerat = False
foundmaterial = False
for item in testsoup.find_all('td', class_ = 'borderClass'):
    season = re.search(r"(Spring|Summer|Fall|Winter).\d{4}", item.text)
    ep_len = re.search(r"(\d{1,2})\s(\w+)\.\s?([a-z0-9]+)\s?(\w+)\.?", item.text)
    age_rating = re.search(r"(R|PG)\s?[0-9+-]+\s?([0-9+]+)?", item.text)
    material = re.search(r"(Manga|Visual novel|Game|Original)\s{2}", item.text)

    if season != None:
        seasons.append(season.group(1))
        foundseason = True

    if ep_len != None:
        ep_lens.append(ep_len.group(0))
        foundeplen = True
        
    if age_rating != None:
        age_ratings.append(age_rating.group(0))
        foundagerat = True

    if material != None:
        materials.append(material.group(1))
        foundmaterial = True

if foundseason != True:
    seasons.append(None)
if foundeplen != True:
    ep_lens.append(None)
if foundagerat != True:
    age_ratings.append(None)
if foundmaterial != True:
    materials.append(None)

print(seasons, "\n", ep_lens, "\n", age_ratings, "\n", materials)
"""

""" tree = html.fromstring(source.content)
season = tree.xpath('/html/body/div[1]/div/div[3]/div[2]/table/tbody/tr/td[1]/div/div[13]/a.text')
print(season) """


""" from lxml import etree

newsoup = bs(source, 'html.parser')
dom = etree.HTML(str(newsoup))
print(dom.xpath('/html/body/div[1]/div/div[3]/div[2]/table/tbody/tr/td[1]/div/div[13]/a'))
 """
