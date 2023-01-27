### Instructions to Run

- Install all the libraries imported in main.py
- Open a terminal 
- Type uvicorn main:api --reload
- (If you get error saying "uvicorn is not recognized as the name of cmdlet...) Type python -m uvicorn main:api --reload
- In the terminal an IP address will come. Follow the link. 
- In the URL after address write "/recommendations" (as we defined it in our main.py file)
- Enter a movie name say "Bad Boys". Click Submit and it will show you the similar movies along with their similarity score.


## 
Templates folder contain the web page that opens when you follow the link. Modify it according to your preferences
