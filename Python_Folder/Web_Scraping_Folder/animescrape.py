from bs4 import BeautifulSoup as bs
import requests
import csv 
import re 

source = requests.get("http://myanimelist.net/topanime.php").text

soup = bs(source, 'lxml')

csv_file = open("animescrape.csv", "w")

csv_writer = csv.writer(csv_file)
csv_writer.writerow(["Title", "Score", "Number of Episodes", "Start Date", "End Date", "Number of Members"])

names = []
scores = []
ep_nums = []
start_dates =[]
end_dates = []
mem_nums = []
# print(soup.prettify())

# match = soup.find('div', class_='di-ib clearfix')
# print(match, "\n")

# name = match.a.text
# print(name)

for match in soup.find_all('div', class_='di-ib clearfix'):
    name = match.a.text
    names.append(name)
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

    ep_num = re.search(r'\d+', info[1]).group(0)
    start_date = info[2].split(" - ")[0]

    try:
        end_date = info[2].split(" - ")[1]
    except Exception as e:
        end_date = None
    
    mem_num = re.search(r'\d+', "".join(info[3].split(','))).group(0)

    ep_nums.append(ep_num)
    start_dates.append(start_date)
    end_dates.append(end_date)
    mem_nums.append(mem_num)

    # csv_writer.writerow([ep_num, start_date, end_date, mem_num])

for i in range(len(names)):
    csv_writer.writerow([names[i], scores[i], ep_nums[i], start_dates[i], end_dates[i], mem_nums[i]])

csv_file.close()
