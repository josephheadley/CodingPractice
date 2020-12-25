from selenium import webdriver
from selenium.webdriver.common.keys import Keys

browser = webdriver.Chrome("/Users/josephheadley/Documents/Personal_Projects_Folder/Coding_Folder/Coding_Projects/Python_Folder/Selenium_Folder/chromedriver")

browser.get('http://www.seleniumhq.org/')

elem = browser.find_element_by_link_text('Downloads')

elem.text
elem.get_attribute('href')
elem.click()

elem = browser.find_element_by_link_text('Projects')
elem.click()

#searchBar = browser.find_element_by_id('gsc-iw-id1')
#searchBar.send_keys('download')
#searchBar.send_keys(Keys.Enter)