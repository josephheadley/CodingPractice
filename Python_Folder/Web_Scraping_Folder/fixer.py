from bs4 import BeautifulSoup as bs
import requests
import re

newsoup = bs(requests.get("https://myanimelist.net/anime/2688/Akai_Koudan_Zillion").text, 'lxml')

# for item in newsoup.find_all('td', class_ = 'borderClass'):
#     material = re.search(r"\s{3}(Manga|Visual novel|Game|Original|Novel|Light novel|Web manga|Other|Unknown|Picture book|Music|Card game|4-koma manga|Book)\s{3}", item.text)
#     print(material.group(0))

for rank in newsoup.find_all('span', class_="numbers ranked"):
    print(rank.text.split("#")[1])