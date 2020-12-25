from selenium import webdriver
from selenium.webdriver.common.keys import Keys

browser = webdriver.Chrome("/Users/josephheadley/Documents/Personal_Projects_Folder/Coding_Folder/Coding_Projects/Python_Folder/Selenium_Folder/chromedriver")

browser.get('https://www.youtube.com')
browser.maximize_window()

searchBar = browser.find_element_by_xpath('/html/body/ytd-app/div/div/ytd-masthead/div[3]/div[2]/ytd-searchbox/form/div/div[1]/input')
searchBar.send_keys('My Mix')
searchBar.send_keys(Keys.RETURN)

