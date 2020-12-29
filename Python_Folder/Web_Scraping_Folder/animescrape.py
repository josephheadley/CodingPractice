from bs4 import BeautifulSoup as bs
import requests
import csv 
import re 

source = requests.get("http://myanimelist.net/topanime.php").text

soup = bs(source, 'lxml')

csv_file = open("animescrape.csv", "w")

csv_writer = csv.writer(csv_file)
csv_writer.writerow(["Title", "Score", "Medium", "Number of Episodes", "Episode Length", "Start Date", "End Date", "Premier Season", "Source Material", "Age Rating", "Number of Members", "URLS", "Synopses", "Genre 1", "Genre 2", "Genre 3", "Genre 4", "Genre 5", "Genre 6", "Genre 7", "Genre 8"])

names = []
scores = []
media = []
ep_nums = []
ep_lens = []
start_dates = []
end_dates = []
seasons = []
materials = []
age_ratings = []
mem_nums = []
urls = []
synopses = []
gnrs = []
genre_1 = []
genre_2 = []
genre_3 = []
genre_4 = []
genre_5 = []
genre_6 = []
genre_7 = []
genre_8 = []

# print(soup.prettify())

# match = soup.find('div', class_='di-ib clearfix')
# print(match, "\n")

# name = match.a.text
# print(name)

for match in soup.find_all('div', class_='di-ib clearfix'):
    name = match.a.text
    names.append(name)

    url = match.a['href']
    urls.append(url)
    #print(name, "\n")
    # csv_writer.writerow([name])

# match = soup.find('div', class_='js-top-ranking-score-col di-ib al')
# # print(match, "\n")
# score = match.span.text
# print(score)

for match in soup.find_all('div', class_='js-top-ranking-score-col di-ib al'):
    score = match.span.text
    scores.append(score)
    # print(score, "\n")
    # csv_writer.writerow([score])

""" match = soup.find('div', class_='information di-ib mt4')
info = str(match.text).split('\n')
info = [i.strip() for i in info] """
# print(info[2].split(" - "))
## result = re.match(r'\d\d', info[1])
## print(result)
""" query = re.search(r'\d+', info[1]).group(0) """
## check = pattern.find(info[1])
# print(query)

# infolist = []
# infolist.append(re.search(r'\d+', info[1]).group(0))
# infolist.append(info[2].split(" - ")[0])
# infolist.append(info[2].split(" - ")[1])
# infolist.append(re.search(r'\d+,\d+,\d+', info[3]).group(0))
# print(infolist)

for match in soup.find_all('div', class_='information di-ib mt4'):
    info = str(match.text).split('\n')
    info = [i.strip() for i in info]

    medium = re.search(r'\w+', info[1]).group(0)

    try:
        ep_num = re.search(r'\d+', info[1]).group(0)
    except Exception as e:
        ep_num = None

    start_date = info[2].split(" - ")[0]

    try:
        end_date = info[2].split(" - ")[1]
    except Exception as e:
        end_date = None
    
    mem_num = re.search(r'\d+', "".join(info[3].split(','))).group(0)

    media.append(medium)
    ep_nums.append(ep_num)
    start_dates.append(start_date)
    end_dates.append(end_date)
    mem_nums.append(mem_num)

    # csv_writer.writerow([ep_num, start_date, end_date, mem_num])

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

""" def convtomins(time):
    mins = 0
    if time.group(2) == 'hr':
        mins += int(time.group(1))*60 
    if time.group(4) == 'min':
        mins += int(time.group(3))
    return mins """

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

for url in urls:
    newsoup = bs(requests.get(url).text, 'lxml')

    summary = str(newsoup.find('div', class_='js-scrollfix-bottom-rel').table.p.text)
    synopsis = " ".join(remove_all(re.split(r'\s',summary)))
    synopses.append(synopsis)

    studio = newsoup.find('span', class_='dark_text')

    for genre in newsoup.find_all('span', itemprop = "genre"):
        gnrs.append(genre.text)

    add_genres(gnrs)
    gnrs.clear()

    foundseason = False
    foundeplen = False
    foundagerat = False
    foundmaterial = False
    for item in newsoup.find_all('td', class_ = 'borderClass'):
        season = re.search(r"(Spring|Summer|Fall|Winter).\d{4}", item.text)
        ep_len = re.search(r"(\d{1,2})\s(min|hr)\.\s?([a-z0-9]+)?\s?(\w+)?\.?", item.text)
        age_rating = re.search(r"(R|PG)\s?[0-9+-]+\s?([0-9+]+)?", item.text)
        material = re.search(r"(Manga|Visual novel|Game|Original|Novel|Light novel|Web manga|Other)\s{2}", item.text)

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

    if foundseason == False:
        seasons.append(None)
    if foundeplen == False:
        ep_lens.append(None)
    if foundagerat == False:
        age_ratings.append(None)
    if foundmaterial == False:
        materials.append(None)

for i in range(len(names)):
    csv_writer.writerow([names[i], scores[i], media[i], ep_nums[i], ep_lens[i], start_dates[i], end_dates[i], seasons[i], materials[i], age_ratings[i], mem_nums[i], urls[i], synopses[i], genre_1[i], genre_2[i], genre_3[i], genre_4[i], genre_5[i], genre_6[i], genre_7[i], genre_8[i]])

csv_file.close()
