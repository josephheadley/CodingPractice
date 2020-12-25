# Common Data Science Functions in Python by Joseph Headley
# This document is a list of common functions used in data science as inspired by Ken Jee's video on it. 

#########################
# Module Imports
#########################

# Data Manipulation Imports (numpy & pandas)
import numpy as np
import pandas as pd

# Static Data Visualization Imports (matplotlib & seaborn)
import matplotlib.pyplot as plt
import seaborn as sns
%matplotlib inline

# Interactive Data Visualization Imports (cufflinks & plotly)
import cufflinks as cf
cf.go_offline()

from plotly.offline import download_plotlyjs, init_notebook_mode, plot, iplot
init_notebook_mode(connected=True) 

# Machine Learning Imports
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import LogisticRegression