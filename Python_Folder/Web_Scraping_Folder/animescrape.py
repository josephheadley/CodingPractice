from bs4 import BeautifulSoup as bs
import requests
import csv 
import re 

source = requests.get("http://myanimelist.net/topanime.php").text

soup = bs(source, 'lxml')

csv_file = open("animescrape.csv", "w")

csv_writer = csv.writer(csv_file)
csv_writer.writerow(["Title", "Score", "Medium", "Number of Episodes", "Start Date", "End Date", "Number of Members", "URLS", "Synopses", "Genres"])

names = []
scores = []
media = []
ep_nums = []
start_dates =[]
end_dates = []
mem_nums = []
urls = []
synopses = []
gnrs = []
genres = []

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
    ep_num = re.search(r'\d+', info[1]).group(0)
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
    for j in range(4): #3 of the summaries get cut off because of this for loop
        listobj.pop() #Consider changing this to check regex instead
    return listobj

for url in urls:
    newsource = requests.get(url).text
    newsoup = bs(newsource, 'lxml')

    match1 = newsoup.find('div', class_='js-scrollfix-bottom-rel')
    summary = str(match1.table.p.text)
    synopsis = " ".join(remove_all(re.split(r'\s',summary)))

    synopses.append(synopsis)

    for gnr in newsoup.find_all('span', itemprop = "genre"):
        genre = gnr.text
        gnrs.append(genre)

    gnrs_cp = gnrs[:]    
    genres.append(gnrs_cp)
    gnrs.clear()

for i in range(len(names)):
    csv_writer.writerow([names[i], scores[i], media[i], ep_nums[i], start_dates[i], end_dates[i], mem_nums[i], urls[i], synopses[i], genres[i]])

csv_file.close()
