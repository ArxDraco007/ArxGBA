import pandas as pd

df = pd.read_csv("BOM.csv")
col_data = df['Component']
col_df = df[['Component']]
print(col_df)