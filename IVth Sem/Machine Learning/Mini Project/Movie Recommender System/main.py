import json
import json2html as json2html
import pandas as pd
from sklearn.neighbors import NearestNeighbors
from scipy.sparse import csr_matrix
from fastapi.responses import JSONResponse
from fastapi.middleware.cors import CORSMiddleware
from json2html import *
from fastapi.responses import HTMLResponse
from fastapi import FastAPI, Request, Form
from fastapi.templating import Jinja2Templates
api = FastAPI()
templates = Jinja2Templates(directory="templates2/")

api.add_middleware(
        CORSMiddleware,
        # allow_origins=["*"],
        allow_origin_regex='https?://.*',
        allow_credentials=True,
        allow_methods=["*"],
        allow_headers=["*"],
    )
def get_movie_recommendation(movie_name):
    movies = pd.read_csv("movies.csv")
    ratings = pd.read_csv("ratings1.csv")
    final_dataset = ratings.pivot(index='movieId', columns='userId', values='rating')
    final_dataset.fillna(0, inplace=True)
    no_user_voted = ratings.groupby('movieId')['rating'].agg('count')
    no_movies_voted = ratings.groupby('userId')['rating'].agg('count')
    final_dataset = final_dataset.loc[no_user_voted[no_user_voted > 10].index, :]
    final_dataset = final_dataset.loc[:, no_movies_voted[no_movies_voted > 50].index]
    csr_data = csr_matrix(final_dataset.values)
    final_dataset.reset_index(inplace=True)
    knn = NearestNeighbors(metric='cosine', algorithm='brute', n_neighbors=20, n_jobs=-1)
    knn.fit(csr_data)

    n_movies_to_reccomend = 10
    movie_list = movies[movies['title'].str.contains(movie_name)]
    if len(movie_list):
        movie_idx= movie_list.iloc[0]['movieId']
        movie_idx = final_dataset[final_dataset['movieId'] == movie_idx].index[0]
        distances , indices = knn.kneighbors(csr_data[movie_idx],n_neighbors=n_movies_to_reccomend+1)
        rec_movie_indices = sorted(list(zip(indices.squeeze().tolist(),distances.squeeze().tolist())),key=lambda x: x[1])[:0:-1]
        recommend_frame = []
        for val in rec_movie_indices:
            movie_idx = final_dataset.iloc[val[0]]['movieId']
            idx = movies[movies['movieId'] == movie_idx].index
            recommend_frame.append({'Title':movies.iloc[idx]['title'].values[0],'Distance':val[1]})
        df = pd.DataFrame(recommend_frame,index=range(1,n_movies_to_reccomend+1))
        return df
    else:
        return "No movies found. Please check your input"

@api.get("/recommendations/",response_class=HTMLResponse)
async def recommendations(request:Request):
   # if anime_name:
   #     recommendations = content_rec(anime_name, n_recommendations)
   #     recommendations = recommendations.to_json()
   #    infoFromJson = json.loads(recommendations)
   #    #return JSONResponse(json.loads(recommendations))
   # return json2html.convert(json=infoFromJson)
    result = "Anime:  "
    return templates.TemplateResponse('form2.html', context={'request': request, 'result': result})
    return JSONResponse(content={"Error": "The anime name is missing"}, status_code=400)

@api.post("/recommendations/",response_class=HTMLResponse)
def recommendations(request: Request, name: str = Form(...)):
    print(name)
    if name:
        recommendations = get_movie_recommendation(name)
        recommendations = recommendations.to_json()
        infoFromJson = json.loads(recommendations)

        result = json2html.convert(json=infoFromJson)

    #return templates.TemplateResponse('form2.html', context={'request': request, 'result': result})
    return result
