import pandas as pd

# Reading all the datasets
df1 = pd.read_csv('small/movies.csv')
df2 = pd.read_csv('small/people.csv')
df3 = pd.read_csv('small/stars.csv')

# Renaming the columns
df1.rename(columns = {'id':'movie_id'}, inplace = True)
df2.rename(columns = {'id':'person_id'}, inplace = True)

# Merging the datasets
df = df3.merge(df1, on='movie_id', how='left').merge(df2, on='person_id', how='left')

#Dropping unnecessary columns
df = df.drop(['birth', 'person_id', 'movie_id'], axis = 1)

#Sorting the columns
df = df.sort_index(axis=1)

#Saving the dataset
df.to_csv('small.csv', index=False)